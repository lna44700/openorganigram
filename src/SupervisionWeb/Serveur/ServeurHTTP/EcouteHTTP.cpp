/**
  @file
  @author Florian Philippeau
*/


//Includes Perso
#include "EcouteHTTP.h"
#include "GestionnaireConnexionHTTP.h"
#include "PoolGestionnaireConnexionHTTP.h"

//Includes QT
#include <QCoreApplication>

EcouteHTTP::EcouteHTTP()
{
    close();
}

EcouteHTTP::EcouteHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete, QObject *parent)
    : QTcpServer(parent)
{
    Q_ASSERT(parametres!=0);
    Q_ASSERT(gestionnaireRequete!=0);
    pool=NULL;
    this->parametres=parametres;
    this->gestionnaireRequete=gestionnaireRequete;
    // Reqister type of socketDescriptor for signal/slot handling
    qRegisterMetaType<tSocketDescriptor>("tSocketDescriptor");
    // Start listening
    listen();
}


EcouteHTTP::~EcouteHTTP()
{
    close();
    qDebug("EcouteHTTP: détruit");
}


void EcouteHTTP::listen()
{
    if (!pool)
    {
        pool=new PoolGestionnaireConnexionHTTP(parametres,gestionnaireRequete);
    }
    QString host = parametres->value("host").toString();
    int port=parametres->value("port").toInt();
    QTcpServer::listen(host.isEmpty() ? QHostAddress::Any : QHostAddress(host), port);
    if (!isListening())
    {
        qCritical("EcouteHTTP: Ne peut pas écouter sur le port %i: %s",port,qPrintable(errorString()));
    }
    else {
        qDebug("EcouteHTTP: Ecoute sur le port %i",port);
    }
}


void EcouteHTTP::close() {
    QTcpServer::close();
    qDebug("EcouteHTTP: ferme");
    if (pool) {
        delete pool;
        pool=NULL;
    }
}

void EcouteHTTP::incomingConnection(tSocketDescriptor socketDescriptor) {
#ifdef SUPERVERBOSE
    qDebug("EcouteHTTP: Nouvelle connexion");
#endif

    GestionnaireConnexionHTTP* freeHandler=NULL;
    if (pool)
    {
        freeHandler=pool->getGestionnaireConnexion();
    }

    // Let the handler process the new connection.
    if (freeHandler)
    {
        // The descriptor is passed via signal/slot because the handler lives in another
        // thread and cannot open the socket when directly called by another thread.
        connect(this,SIGNAL(gestionConnexion(tSocketDescriptor)),freeHandler,SLOT(gestionConnexion(tSocketDescriptor)));
        emit gestionConnexion(socketDescriptor);
        disconnect(this,SIGNAL(gestionConnexion(tSocketDescriptor)),freeHandler,SLOT(gestionConnexion(tSocketDescriptor)));
    }
    else
    {
        // Reject the connection
        qDebug("EcouteHTTP: Too many incoming connections");
        QTcpSocket* socket=new QTcpSocket(this);
        socket->setSocketDescriptor(socketDescriptor);
        connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
        socket->write("HTTP/1.1 503 too many connections\r\nConnection: close\r\n\r\nToo many connections\r\n");
        socket->disconnectFromHost();
    }
}
