/**
  @file
  @author Florian Philippeau
*/

//Includes Perso
#include "ControleurFichierStatique.h"

//Includes QT
#include <QFileInfo>
#include <QDir>
#include <QDateTime>

ControleurFichierStatique::ControleurFichierStatique(QSettings* parametres, QObject* parent)
    :GestionnaireRequeteHTTP(parent)
{
    maxAge=parametres->value("maxAge","60000").toInt();
    codage=parametres->value("codage","UTF-8").toString();
    www=parametres->value("chemin",".").toString();
    if(!(www.startsWith(":/") || www.startsWith("qrc://")))
    {
        // Convert relative chemin to absolute, based on the directory of the config file.
        #ifdef Q_OS_WIN32
            if (QDir::isRelativePath(www) && parametres->format()!=QSettings::NativeFormat)
        #else
            if (QDir::isRelativePath(www))
        #endif
        {
            QFileInfo configFile(parametres->fileName());
            www=QFileInfo(configFile.absolutePath(),www).absoluteFilePath();
        }
    }
    qDebug("ControleurFichierStatique: www=%s, codage=%s, maxAge=%i",qPrintable(www),qPrintable(codage),maxAge);
   tailleFichierCacheMax=parametres->value("tailleFichierCacheMax","65536").toInt();
    cache.setMaxCost(parametres->value("cacheSize","1000000").toInt());
    cacheDelaiExpiration=parametres->value("cacheTime","60000").toInt();
    qDebug("ControleurFichierStatique: Delai cache=%i, size=%i",cacheDelaiExpiration,cache.maxCost());
}


void ControleurFichierStatique::service(RequeteHTTP& requete, HttpReponse& reponse)
{
    QByteArray chemin=requete.getChemin();
    // Check if we have the file in cache
    qint64 now=QDateTime::currentMSecsSinceEpoch();
    mutex.lock();
    CacheEntry* entry=cache.object(chemin);
    if (entry && (cacheDelaiExpiration==0 || entry->created>now-cacheDelaiExpiration))
    {
        QByteArray document=entry->document; //copy the cached document, because other threads may destroy the cached entry immediately after mutex unlock.
        QByteArray filename=entry->filename;
        mutex.unlock();
        qDebug("ControleurFichierStatique: Cache hit for %s",chemin.data());
        setTypeContenu(filename,reponse);
        reponse.definirHeader("Cache-Control","max-age="+QByteArray::number(maxAge/1000));
        reponse.ecrire(document);
    }
    else
    {
        mutex.unlock();
        // The file is not in cache.
        qDebug("ControleurFichierStatique: Cache miss for %s",chemin.data());
        // Forbid access to files outside the www directory
        if (chemin.contains("/.."))
        {
            qWarning("ControleurFichierStatique: detected forbidden characters in chemin %s",chemin.data());
            reponse.setStatus(403,"forbidden");
            reponse.ecrire("403 forbidden",true);
            return;
        }
        // If the filename is a directory, append index.html.
        if (QFileInfo(www+chemin).isDir())
        {
            chemin+="/index.html";
        }
        // Try to open the file
        QFile file(www+chemin);
        qDebug("ControleurFichierStatique: Open file %s",qPrintable(file.fileName()));
        if (file.open(QIODevice::ReadOnly))
        {
            setTypeContenu(chemin,reponse);
            reponse.definirHeader("Cache-Control","max-age="+QByteArray::number(maxAge/1000));
            if (file.size()<=tailleFichierCacheMax)
            {
                // Return the file content and store it also in the cache
                entry=new CacheEntry();
                while (!file.atEnd() && !file.error())
                {
                    QByteArray buffer=file.read(65536);
                    reponse.ecrire(buffer);
                    entry->document.append(buffer);
                }
                entry->created=now;
                entry->filename=chemin;
                mutex.lock();
                cache.insert(requete.getChemin(),entry,entry->document.size());
                mutex.unlock();
            }
            else
            {
                // Return the file content, do not store in cache
                while (!file.atEnd() && !file.error())
                {
                    reponse.ecrire(file.read(65536));
                }
            }
            file.close();
        }
        else {
            if (file.exists())
            {
                qWarning("ControleurFichierStatique: Cannot open existing file %s for reading",qPrintable(file.fileName()));
                reponse.setStatus(403,"forbidden");
                reponse.ecrire("Erreur 403 - Acces interdit !",true);
            }
            else
            {
                reponse.setStatus(404,"not found");
                reponse.ecrire("Erreur 404 - Fichier inexistant !",true);
            }
        }
    }
}

void ControleurFichierStatique::setTypeContenu(QString nomFichier, HttpReponse& reponse) const
{
    if (nomFichier.endsWith(".png"))
    {
        reponse.definirHeader("Content-Type", "image/png");
    }
    else if (nomFichier.endsWith(".jpg"))
    {
        reponse.definirHeader("Content-Type", "image/jpeg");
    }
    else if (nomFichier.endsWith(".gif"))
    {
        reponse.definirHeader("Content-Type", "image/gif");
    }
    else if (nomFichier.endsWith(".pdf"))
    {
        reponse.definirHeader("Content-Type", "application/pdf");
    }
    else if (nomFichier.endsWith(".txt"))
    {
        reponse.definirHeader("Content-Type", qPrintable("text/plain; charset="+codage));
    }
    else if (nomFichier.endsWith(".html") || nomFichier.endsWith(".htm"))
    {
        reponse.definirHeader("Content-Type", qPrintable("text/html; charset="+codage));
    }
   // else if (nomFichier.endsWith(".php"))
   //{
   //     reponse.definirHeader("Content-Type", qPrintable("text/php; charset="+codage));
    //}
    else if (nomFichier.endsWith(".css"))
    {
        reponse.definirHeader("Content-Type", "text/css");
    }
    else if (nomFichier.endsWith(".js"))
    {
        reponse.definirHeader("Content-Type", "text/javascript");
    }
    // Todo: add all of your content types
}
