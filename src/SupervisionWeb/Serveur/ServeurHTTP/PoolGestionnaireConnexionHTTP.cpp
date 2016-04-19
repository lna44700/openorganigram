/**
  @file
  @author Florian Philippeau
*/


//Includes QT
#ifndef QT_NO_OPENSSL
    #include <QSslSocket>
    #include <QSslKey>
    #include <QSslCertificate>
    #include <QSslConfiguration>
#endif
#include <QDir>

//Includes Perso
#include "PoolGestionnaireConnexionHTTP.h"

PoolGestionnaireConnexionHTTP::PoolGestionnaireConnexionHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete)
    : QObject()
{
    Q_ASSERT(parametres!=0);
    this->parametres=parametres;
    this->gestionnaireRequete=gestionnaireRequete;
    this->sslConfiguration=NULL;
    chargerSslConfig();
    minuteurNettoyage.start(parametres->value("nettoyerInterval",1000).toInt());
    connect(&minuteurNettoyage, SIGNAL(timeout()), SLOT(nettoyer()));
}


PoolGestionnaireConnexionHTTP::~PoolGestionnaireConnexionHTTP()
{
    // delete all connection gestionnaires and wait until their threads are closed
    foreach(GestionnaireConnexionHTTP* gestionnaire, pool)
    {
       delete gestionnaire;
    }
    delete sslConfiguration;
    qDebug("PoolGestionnaireConnexionHTTP (%p): detruit", this);
}


GestionnaireConnexionHTTP* PoolGestionnaireConnexionHTTP::getGestionnaireConnexion()
{
    GestionnaireConnexionHTTP* gestionnaireDroits=0;
    mutex.lock();
    // find a free gestionnaire in pool
    foreach(GestionnaireConnexionHTTP* gestionnaire, pool)
    {
        if (!gestionnaire->estOccupe())
        {
            gestionnaireDroits=gestionnaire;
            gestionnaireDroits->setOccupe();
            break;
        }
    }
    // create a new gestionnaire, if necessary
    if (!gestionnaireDroits)
    {
        int gestionnaireConnexionMax=parametres->value("maxThreads",100).toInt();
        if (pool.count()<gestionnaireConnexionMax)
        {
            gestionnaireDroits=new GestionnaireConnexionHTTP(parametres,gestionnaireRequete,sslConfiguration);
            gestionnaireDroits->setOccupe();
            pool.append(gestionnaireDroits);
        }
    }
    mutex.unlock();
    return gestionnaireDroits;
}


void PoolGestionnaireConnexionHTTP::nettoyer()
{
    int gestionnaireInactiviteMax =parametres->value("minThreads",1).toInt();
    int compteurIinactivite=0;
    mutex.lock();
    foreach(GestionnaireConnexionHTTP* gestionnaire, pool)
    {
        if (!gestionnaire->estOccupe())
        {
            if (++compteurIinactivite > gestionnaireInactiviteMax )
            {
                delete gestionnaire;
                pool.removeOne(gestionnaire);
                qDebug("PoolGestionnaireConnexionHTTP: Suppression GestionnaireConnexion (%p), pool size is now %i",gestionnaire,pool.size());
                break; // remove only one gestionnaire in each interval
            }
        }
    }
    mutex.unlock();
}


void PoolGestionnaireConnexionHTTP::chargerSslConfig()
{
    // If certificate and key files are configured, then load them
    QString sslKeyFileName=parametres->value("sslKeyFile","").toString();
    QString sslCertFileName=parametres->value("sslCertFile","").toString();
    if (!sslKeyFileName.isEmpty() && !sslCertFileName.isEmpty())
    {
        #ifdef QT_NO_OPENSSL
            qWarning("PoolGestionnaireConnexionHTTP: SSL n'est pas supporte");
        #else
            // Convert relative fileNames to absolute, based on the directory of the config file.
            QFileInfo configFile(parametres->fileName());
            #ifdef Q_OS_WIN32
                if (QDir::isRelativePath(sslKeyFileName) && parametres->format()!=QSettings::NativeFormat)
            #else
                if (QDir::isRelativePath(sslKeyFileName))
            #endif
            {
                sslKeyFileName=QFileInfo(configFile.absolutePath(),sslKeyFileName).absoluteFilePath();
            }
            #ifdef Q_OS_WIN32
                if (QDir::isRelativePath(sslCertFileName) && parametres->format()!=QSettings::NativeFormat)
            #else
                if (QDir::isRelativePath(sslCertFileName))
            #endif
            {
                sslCertFileName=QFileInfo(configFile.absolutePath(),sslCertFileName).absoluteFilePath();
            }

            // Load the SSL certificate
            QFile certFile(sslCertFileName);
            if (!certFile.open(QIODevice::ReadOnly))
            {
                qCritical("PoolGestionnaireConnexionHTTP: ne peut pas ouvrir sslCertFile %s", qPrintable(sslCertFileName));
                return;
            }
            QSslCertificate certificate(&certFile, QSsl::Pem);
            certFile.close();

            // Load the key file
            QFile keyFile(sslKeyFileName);
            if (!keyFile.open(QIODevice::ReadOnly))
            {
                qCritical("PoolGestionnaireConnexionHTTP: ne peut pas ouvrir sslKeyFile %s", qPrintable(sslKeyFileName));
                return;
            }
            QSslKey sslKey(&keyFile, QSsl::Rsa, QSsl::Pem);
            keyFile.close();

            // Create the SSL configuration
            sslConfiguration=new QSslConfiguration();
            sslConfiguration->setLocalCertificate(certificate);
            sslConfiguration->setPrivateKey(sslKey);
            sslConfiguration->setPeerVerifyMode(QSslSocket::VerifyNone);
            sslConfiguration->setProtocol(QSsl::TlsV1SslV3);

            qDebug("PoolGestionnaireConnexionHTTP: Parametres SSL charge");
         #endif
    }
}
