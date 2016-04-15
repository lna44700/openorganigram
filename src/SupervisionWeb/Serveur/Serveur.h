#ifndef F_STARTSERVEUR_H
#define F_STARTSERVEUR_H

#include "GestionnaireConnexionHTTP.h"
#include <QThread>
#include <EcouteHTTP.h>


class Serveur: public QThread
{
public:
    Serveur();
    ~Serveur();
    void lancerServeur();
    void stopperServeur();
    void close();

private:
    QTcpSocket* socket;
    EcouteHTTP* listener;


private slots:


};

#endif // F_STARTSERVEUR_H
