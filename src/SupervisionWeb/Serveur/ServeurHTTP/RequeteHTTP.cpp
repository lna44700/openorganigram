/**
  @file
  @author Florian Philippeau
*/

//Includes Perso
#include "RequeteHTTP.h"

//Includes QT
#include <QList>
#include <QDir>

RequeteHTTP::RequeteHTTP(QSettings* settings)
{
    status=waitForRequest;
    tailleActuelle=0;
    tailleBody=0;
    tailleMax=settings->value("maxRequestSize","16000").toInt();
    maxMultiPartTaille=settings->value("maxMultiPartSize","1000000").toInt();
}

void RequeteHTTP::lireRequete(QTcpSocket* socket)
{
    #ifdef SUPERVERBOSE
        qDebug("RequeteHTTP: requête de lecture");
    #endif
    int toRead=tailleMax-tailleActuelle+1; // permettre à un octet d'être capable de détecter le débordement
    lineBuffer.append(socket->readLine(toRead));
    tailleActuelle+=lineBuffer.size();
    if (!lineBuffer.contains('\r') && !lineBuffer.contains('\n'))
    {
        #ifdef SUPERVERBOSE
            qDebug("RequeteHTTP: recueillir plusieurs parties jusqu'à la rupture de la ligne");
        #endif
        return;
    }
    QByteArray newData=lineBuffer.trimmed();
    lineBuffer.clear();
    if (!newData.isEmpty())
    {
        QList<QByteArray> list=newData.split(' ');
        if (list.count()!=3 || !list.at(2).contains("HTTP"))
        {
            qWarning("RequeteHTTP: requête HTTP cassée reçu, première ligne invalide");
            status=abort;
        }
        else {
            method=list.at(0).trimmed();
            path=list.at(1);
            version=list.at(2);
            peerAddress = socket->peerAddress();
            status=waitForHeader;
        }
    }
}

void RequeteHTTP::lireHeader(QTcpSocket* socket)
{
    #ifdef SUPERVERBOSE
        qDebug("Requete HTTP: Lecture entete");
    #endif
    int toRead=tailleMax-tailleActuelle+1; // permettre à un octet d'être capable de détecter le débordement
    lineBuffer.append(socket->readLine(toRead));
    tailleActuelle+=lineBuffer.size();
    if (!lineBuffer.contains('\r') && !lineBuffer.contains('\n'))
    {
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: Collecte de plusieurs parties jusqu'à la rupture de la ligne");
        #endif
        return;
    }
    QByteArray newData=lineBuffer.trimmed();
    lineBuffer.clear();
    int colon=newData.indexOf(':');
    if (colon>0)
    {
        //Reçu une ligne avec deux points - un en-tête
       headerActuelle=newData.left(colon);
        QByteArray value=newData.mid(colon+1).trimmed();
        headers.insert(headerActuelle,value);
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: Entete recu %s: %s",headerActuelle.data(),value.data());
        #endif
    }
    else if (!newData.isEmpty())
    {
        // reçu une autre ligne - appartient à l'en-tête précédente
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: Lecture de ligne suplémentaire de l'header");
        #endif
        // reçu une autre ligne - appartient à hearder précédente
        if (headers.contains(headerActuelle)) {
            headers.insert(headerActuelle,headers.value(headerActuelle)+" "+newData);
        }
    }
    else
    {
        // reçu une ligne vide - fin de header atteint
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: header complet");
        #endif
        // Ligne vide reçu = signifie que tous les headers ont été reçus
        // Vérifier multipart form-data
        QByteArray contentType=headers.value("Content-Type");
        if (contentType.startsWith("multipart/form-data"))
        {
            int posi=contentType.indexOf("frontieres=");
            if (posi>=0) {
                frontieres=contentType.mid(posi+9);
                if  (frontieres.startsWith('"') && frontieres.endsWith('"'))
                {
                   frontieres = frontieres.mid(1,frontieres.length()-2);
                }
            }
        }
        QByteArray contentLength=getHeader("Content-Length");
        if (!contentLength.isEmpty())
        {
            tailleBody=contentLength.toInt();
        }
        if (tailleBody==0)
        {
            #ifdef SUPERVERBOSE
                qDebug("Requete HTTP: attendre aucun body");
            #endif
            status=complete;
        }
        else if (frontieres.isEmpty() && tailleBody+tailleActuelle>tailleMax)
        {
            qWarning("Requete HTTP: body attendu trop grand");
            status=abort;
        }
        else if (!frontieres.isEmpty() && tailleBody>maxMultiPartTaille)
        {
            qWarning("Requete HTTP: body multipart attendu trop grand");
            status=abort;
        }
        else {
            #ifdef SUPERVERBOSE
                qDebug("Requete HTTP: attendre %i octets body",tailleBody);
            #endif
            status=waitForBody;
        }
    }
}

void RequeteHTTP::lireBody(QTcpSocket* socket)
{
    Q_ASSERT(tailleBody!=0);
    if (frontieres.isEmpty())
    {
        // body normal, pas multipart
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: Body recu");
        #endif
        int lire=tailleBody-bodyData.size();
        QByteArray newData=socket->read(lire);
        tailleActuelle+=newData.size();
        bodyData.append(newData);
        if (bodyData.size()>=tailleBody)
        {
            status=complete;
        }
    }
    else
    {
        // body multipart, stocker dans un fichier temporaire
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: réception corps multipart");
        #endif
        if (!fichierTempo.isOpen())
        {
            fichierTempo.open();
        }
        // Transferer les données dans des blocs de 64 ko
        int tailleFichier=fichierTempo.size();
        int lire=tailleBody-tailleFichier;
        if (lire>65536)
        {
            lire=65536;
        }
        tailleFichier+=fichierTempo.write(socket->read(lire));
        if (tailleFichier>=maxMultiPartTaille)
        {
            qWarning("Requete HTTP: recu trop d'octets multipart");
            status=abort;
        }
        else if (tailleFichier>=tailleBody)
        {
        #ifdef SUPERVERBOSE
            qDebug("Requete HTTP: Ensemble recu du body multipart");
        #endif
            fichierTempo.flush();
            if (fichierTempo.error())
            {
                qCritical("Requete HTTP: Erreur écriture du fichier temporaire pour le body multipart");
            }
            analyserFichierMultiPart();
            fichierTempo.close();
            status=complete;
        }
    }
}

void RequeteHTTP::decodeParametresRequete()
{
    #ifdef SUPERVERBOSE
        qDebug("RequeteHTTP: extraire et décoder les paramètres de requête");
    #endif
    // Obtenir les paramètres d'URL
    QByteArray rawparametres;
    int questionMark=path.indexOf('?');
    if (questionMark>=0)
    {
        rawparametres=path.mid(questionMark+1);
        path=path.left(questionMark);
    }
    // Obtenir les paramètres du body de demande
    QByteArray contentType=headers.value("Content-Type");
    if (!bodyData.isEmpty() && (contentType.isEmpty() || contentType.startsWith("application/x-www-form-urlencoded")))
    {
        if (!rawparametres.isEmpty())
        {
            rawparametres.append('&');
            rawparametres.append(bodyData);
        }
        else
        {
            rawparametres=bodyData;
        }
    }
    // Diviser les paramètres en paires de valeur et de nom
    QList<QByteArray> list=rawparametres.split('&');
    foreach (QByteArray part, list)
    {
        int equalsChar=part.indexOf('=');
        if (equalsChar>=0)
        {
            QByteArray nom=part.left(equalsChar).trimmed();
            QByteArray value=part.mid(equalsChar+1).trimmed();
            parametres.insert(urlDecode(nom),urlDecode(value));
        }
        else if (!part.isEmpty())
        {
            // Nom sans valeur
            parametres.insert(urlDecode(part),"");
        }
    }
}


void RequeteHTTP::lireDansSocket(QTcpSocket* socket)
{
    Q_ASSERT(status!=complete);
    if (status==waitForRequest)
    {
        lireRequete(socket);
    }
    else if (status==waitForHeader)
    {
        lireHeader(socket);
    }
    else if (status==waitForBody)
    {
        lireBody(socket);
    }
    if ((frontieres.isEmpty() && tailleActuelle>tailleMax) || (!frontieres.isEmpty() && tailleActuelle>maxMultiPartTaille))
    {
        qWarning("RequeteHTTP: reçu trop d'octets");
        status=abort;
    }
    if (status==complete)
    {
        // Extraire et décoder les paramètres de requête de URL et le body
        decodeParametresRequete();

    }
}


RequeteHTTP::StatusRequete RequeteHTTP::getStatus() const
{
    return status;
}


QByteArray RequeteHTTP::getMethode() const
{
    return method;
}


QByteArray RequeteHTTP::getChemin() const
{
    return urlDecode(path);
}


const QByteArray& RequeteHTTP::getCheminBrut() const
{
    return path;
}


QByteArray RequeteHTTP::getVersion() const
{
    return version;
}


QByteArray RequeteHTTP::getHeader(const QByteArray& nom) const
{
    return headers.value(nom);
}

QList<QByteArray> RequeteHTTP::getHeaders(const QByteArray& nom) const
{
    return headers.values(nom);
}

QMultiMap<QByteArray,QByteArray> RequeteHTTP::getHeaderMap() const
{
    return headers;
}

QByteArray RequeteHTTP::getParametre(const QByteArray& nom) const
{
    return parametres.value(nom);
}

QList<QByteArray> RequeteHTTP::getParametres(const QByteArray& nom) const
{
    return parametres.values(nom);
}

QMultiMap<QByteArray,QByteArray> RequeteHTTP::getParametreMap() const
{
    return parametres;
}

QByteArray RequeteHTTP::getBody() const
{
    return bodyData;
}

QByteArray RequeteHTTP::urlDecode(const QByteArray source)
{
    QByteArray buffer(source);
    buffer.replace('+',' ');
    int percentChar=buffer.indexOf('%');
    while (percentChar>=0)
    {
        bool ok;
        char byte=buffer.mid(percentChar+1,2).toInt(&ok,16);
        if (ok)
        {
            buffer.replace(percentChar,3,(char*)&byte,1);
        }
        percentChar=buffer.indexOf('%',percentChar+1);
    }
    return buffer;
}


void RequeteHTTP::analyserFichierMultiPart()
{
    qDebug("RequeteHTTP: analyse du fichier temp multipart");
    fichierTempo.seek(0);
    bool finished=false;
    while (!fichierTempo.atEnd() && !finished && !fichierTempo.error())
    {
        #ifdef SUPERVERBOSE
            qDebug("RequeteHTTP: lecture des headers multipart");
        #endif
        QByteArray nomDomaine;
        QByteArray nomFichier;
        while (!fichierTempo.atEnd() && !finished && !fichierTempo.error())
        {
            QByteArray line=fichierTempo.readLine(65536).trimmed();
            if (line.startsWith("Content-Disposition:"))
            {
                if (line.contains("form-data"))
                {
                    int start=line.indexOf(" nom=\"");
                    int end=line.indexOf("\"",start+7);
                    if (start>=0 && end>=start)
                    {
                        nomDomaine=line.mid(start+7,end-start-7);
                    }
                    start=line.indexOf(" nomFichier=\"");
                    end=line.indexOf("\"",start+11);
                    if (start>=0 && end>=start)
                    {
                        nomFichier=line.mid(start+11,end-start-11);
                    }
                    #ifdef SUPERVERBOSE
                        qDebug("RequeteHTTP: champ multipart=%s, nomFichier=%s",nomDomaine.data(),nomFichier.data());
                    #endif
                }
                else
                {
                    qDebug("RequeteHTTP: en ignorant une partie du contenu non pris en charget %s",line.data());
                }
            }
            else if (line.isEmpty())
            {
                break;
            }
        }

        #ifdef SUPERVERBOSE
            qDebug("RequeteHTTP: lecture des données multipart");
        #endif
        QTemporaryFile* fichierEnvoye=0;
        QByteArray fieldValue;
        while (!fichierTempo.atEnd() && !finished && !fichierTempo.error())
        {
            QByteArray line=fichierTempo.readLine(65536);
            if (line.startsWith("--"+frontieres))
            {
                // Frontière trouvé. Jusqu'à présent, nous avons recueilli 2 octets de trop,
                // afin de les retirer du dernier résultat
                if (nomFichier.isEmpty() && !nomDomaine.isEmpty())
                {
                    // dernier champ est un champ de formulaire
                    fieldValue.remove(fieldValue.size()-2,2);
                    parametres.insert(nomDomaine,fieldValue);
                    qDebug("RequeteHTTP: set parametre %s=%s",nomDomaine.data(),fieldValue.data());
                }
                else if (!nomFichier.isEmpty() && !nomDomaine.isEmpty())
                {
                    // dernier champ était un fichier
                    #ifdef SUPERVERBOSE
                        qDebug("RequeteHTTP: finissage écrit au fichier déposé");
                    #endif
                    fichierEnvoye->resize(fichierEnvoye->size()-2);
                    fichierEnvoye->flush();
                    fichierEnvoye->seek(0);
                    parametres.insert(nomDomaine,nomFichier);
                    qDebug("RequeteHTTP: set parametre %s=%s",nomDomaine.data(),nomFichier.data());
                    fichiersEnvoyes.insert(nomDomaine,fichierEnvoye);
                    qDebug("RequeteHTTP: la taille du fichier uploaded est %i",(int) fichierEnvoye->size());
                }
                if (line.contains(frontieres+"--"))
                {
                    finished=true;
                }
                break;
            }
            else
            {
                if (nomFichier.isEmpty() && !nomDomaine.isEmpty())
                {
                    // ceci est un champ de formulaire.
                   tailleActuelle+=line.size();
                    fieldValue.append(line);
                }
                else if (!nomFichier.isEmpty() && !nomDomaine.isEmpty())
                {
                    // ceci est un fichier
                    if (!fichierEnvoye)
                    {
                        fichierEnvoye=new QTemporaryFile();
                        fichierEnvoye->open();
                    }
                    fichierEnvoye->write(line);
                    if (fichierEnvoye->error())
                    {
                        qCritical("RequeteHTTP: Erreur d'ecriture fichier temporaire, %s",qPrintable(fichierEnvoye->errorString()));
                    }
                }
            }
        }
    }
    if (fichierTempo.error())
    {
        qCritical("RequeteHTTP: ne peut pas lire le fichier temporaire, %s",qPrintable(fichierTempo.errorString()));
    }
    #ifdef SUPERVERBOSE
        qDebug("RequeteHTTP: l'analyse du fichier temp multipart termine");
    #endif
}

RequeteHTTP::~RequeteHTTP()
{
    foreach(QByteArray key, fichiersEnvoyes.keys())
    {
        QTemporaryFile* file=fichiersEnvoyes.value(key);
        file->close();
        delete file;
    }
}

QTemporaryFile* RequeteHTTP::getFichierEnvoye(const QByteArray nomDomaine) const
{
    return fichiersEnvoyes.value(nomDomaine);
}


