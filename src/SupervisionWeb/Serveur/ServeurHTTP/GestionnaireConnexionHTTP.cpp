/**
  @file
  @author Florian Philippeau
*/


//Includes Perso
#include "GestionnaireConnexionHTTP.h"
#include "ReponseHTTP.h"

GestionnaireConnexionHTTP::GestionnaireConnexionHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete)
    : QThread()
{
    Q_ASSERT(parametres!=0);
    Q_ASSERT(gestionnaireRequete!=0);
    this->parametres=parametres;
    this->gestionnaireRequete=gestionnaireRequete;
    requeteActuelle=0;
    occupe=false;

    // Créer TCP
    creerSocket();

    // exécuter des signaux dans mon propre thread
    moveToThread(this);
    socket->moveToThread(this);
    lireTimer.moveToThread(this);

    // Connecter des signaux
    connect(socket, SIGNAL(readyRead()), SLOT(read()));
    connect(socket, SIGNAL(disconnected()), SLOT(disconnected()));
    connect(&lireTimer, SIGNAL(timeout()), SLOT(readTimeout()));
    lireTimer.setSingleShot(true);

    qDebug("GestionnaireConnexionHTTP (%p): construit", this);
    this->start();
}


GestionnaireConnexionHTTP::~GestionnaireConnexionHTTP()
{
    quit();
    wait();
    qDebug("GestionnaireConnexionHTTP (%p): détruit", this);
}


void GestionnaireConnexionHTTP::creerSocket()
{
    // créer une instance de QTcpSocket
    socket=new QTcpSocket();
}

void GestionnaireConnexionHTTP::supprimerSocket()
{
    delete socket;
}

void GestionnaireConnexionHTTP::run()
{
    qDebug("GestionnaireConnexionHTTP (%p): Thread débuté", this);
    try
    {
        exec();
    }
    catch (...)
    {
        qCritical("GestionnaireConnexionHTTP (%p): une exception uncatched a eu lieu dans le thread",this);
    }
    socket->close();
    delete socket;
    lireTimer.stop();
    qDebug("GestionnaireConnexionHTTP (%p): Thread stoppé", this);
}


void GestionnaireConnexionHTTP::gestionConnexion(tSocketDescriptor socketDescriptor)
{
    qDebug("GestionnaireConnexionHTTP (%p): gérer nouvelle connexion", this);
    occupe = true;
    Q_ASSERT(socket->isOpen()==false); // sinon, le gestionnaire est déjà occupée

    //UGLY workaround - nous avons besoin pour effacer le tampon d'ecrire avant d'utiliser ce socket
    //https://bugreports.qt-project.org/browse/QTBUG-28914
    socket->connectToHost("",0);
    socket->abort();

    if (!socket->setSocketDescriptor(socketDescriptor))
    {
        qCritical("GestionnaireConnexionHTTP (%p): ne peut initialiser socket: %s", this,qPrintable(socket->errorString()));
        return;
    }
    // Démarrer minuterie pour le delai d'attente
    int readTimeout=parametres->value("readTimeout",10000).toInt();
    lireTimer.start(readTimeout);
    // Supprimer la requete précédente
    delete requeteActuelle;
    requeteActuelle=0;
}


bool GestionnaireConnexionHTTP::estOccupe()
{
    return occupe;
}

void GestionnaireConnexionHTTP::setOccupe()
{
    this->occupe = true;
}


void GestionnaireConnexionHTTP::readTimeout()
{
    qDebug("GestionnaireConnexionHTTP (%p): le delai d'attente a eu lieu",this);

    //socket->ecrire("HTTP/1.1 408 request timeout\r\nConnection: close\r\n\r\n408 request timeout\r\n");

    socket->flush();
    socket->disconnectFromHost();
    delete requeteActuelle;
    requeteActuelle=0;
}


void GestionnaireConnexionHTTP::disconnected()
{
    qDebug("GestionnaireConnexionHTTP (%p): déconnecté ", this);
    socket->close();
    lireTimer.stop();
    occupe = false;
}

void GestionnaireConnexionHTTP::read()
{
    // La boucle ajoute le support pour pipelining HTTP
    while (socket->bytesAvailable())
    {
        #ifdef SUPERVERBOSE
            qDebug("GestionnaireConnexionHTTP (%p): lire l'entree",this);
        #endif

        // Créer un nouveau objet RequeteHTTP si nécessaire
        if (!requeteActuelle)
        {
            requeteActuelle=new RequeteHTTP(parametres);
        }

        // Recueillir des données pour l'objet de la requete
        while (socket->bytesAvailable() && requeteActuelle->getStatus()!=RequeteHTTP::complete && requeteActuelle->getStatus()!=RequeteHTTP::abort)
        {
            requeteActuelle->lireDansSocket(socket);
            if (requeteActuelle->getStatus()==RequeteHTTP::waitForBody)
            {
                // Redémarrer la temporisation pour le délai d'attente, sinon il serait
                // expire pendant téléchargements de fichiers volumineux.
                int readTimeout=parametres->value("readTimeout",10000).toInt();
                lireTimer.start(readTimeout);
            }
        }

        //Si la demande est annulée, retourner un message d'erreur et fermer la connexion
        if (requeteActuelle->getStatus()==RequeteHTTP::abort)
        {
            socket->write("HTTP/1.1 413 entity too large\r\nConnection: close\r\n\r\n413 Entity too large\r\n");
            socket->flush();
            socket->disconnectFromHost();
            delete requeteActuelle;
            requeteActuelle=0;
            return;
        }

        // Si la demande est complète, laissez l'envoi demande de mappeur
        if (requeteActuelle->getStatus()==RequeteHTTP::complete)
        {
            lireTimer.stop();
            qDebug("GestionnaireConnexionHTTP (%p): requète reçue",this);

            // Copiez la Connexion: fermer header pour la réponse
            HttpReponse response(socket);
            bool closeConnection=QString::compare(requeteActuelle->getHeader("Connection"),"close",Qt::CaseInsensitive)==0;
            if (closeConnection)
            {
                response.definirHeader("Connexion","ferme");
            }

            // En cas de protocole HTTP 1.0 ajouter le Connection: close header.
            // Cela garantit que le HttpResponse n'active pas le mode chunked, qui ne sont pas pris en charge par HTTP 1.0.
            else
            {
                bool http1_0=QString::compare(requeteActuelle->getVersion(),"HTTP/1.0",Qt::CaseInsensitive)==0;
                if (http1_0)
                {
                    closeConnection=true;
                    response.definirHeader("Connection","ferme");
                }
            }

            // Appelez la requête mappeur
            try
            {
                gestionnaireRequete->service(*requeteActuelle, response);
            }
            catch (...)
            {
                qCritical("GestionnaireConnexionHTTP (%p): Une exception uncatched a eu lieu dans le gestionnaire de requetes",this);
            }

            // Finaliser l'envoi de la réponse, si pas déjà fait
            if (!response.aEnvoyeDernierePartie())
            {
                response.ecrire(QByteArray(),true);
            }

            qDebug("GestionnaireConnexionHTTP (%p): requète terminé",this);

            // Pour savoir si la connexion doit être fermée
            if (!closeConnection)
            {
                // Peut-être le gestionnaire de requêtes ou de mapper ajouté un Connection: close-tête dans l'intervalle
                bool closeResponse=QString::compare(response.getHeaders().value("Connexion"),"ferme",Qt::CaseInsensitive)==0;
                if (closeResponse==true)
                {
                    closeConnection=true;
                }
                else
                {
                    // Si nous avons aucun en-tête Content-Length et ne pas utiliser le mode chunked, alors nous devons fermer la
                    // connexion pour indiquer au client HTTP que la fin de la réaction a été atteinte.
                    bool hasContentLength=response.getHeaders().contains("Content-Length");
                    if (!hasContentLength)
                    {
                        bool hasChunkedMode=QString::compare(response.getHeaders().value("Transfer-Encoding"),"chunked",Qt::CaseInsensitive)==0;
                        if (!hasChunkedMode)
                        {
                            closeConnection=true;
                        }
                    }
                }
            }

            // Fermer la connexion ou se préparer à la prochaine requête sur la même connexion.
            if (closeConnection)
            {
                socket->flush();
                socket->disconnectFromHost();
            }
            else
            {
                // Lancer la minuterie pour la prochaine requete
                int readTimeout=parametres->value("readTimeout",10000).toInt();
                lireTimer.start(readTimeout);
            }
            delete requeteActuelle;
            requeteActuelle=0;
        }
    }
}
