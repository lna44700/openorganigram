#ifndef F_STARTSERVEUR_H
#define F_STARTSERVEUR_H

#include "GestionnaireConnexionHTTP.h"
#include <QThread>
#include <EcouteHTTP.h>


/**
Serveur permet la mise en marche du serveur Web depuis le bouton
"actionDemarrerServeurWeb" dans f_MainWindow et son arret depuis le bouton "actionArreterServeurWeb".
*/

class Serveur: public QThread
{
public:
    Serveur();
    ~Serveur();
    void lancerServeur();
    void stopperServeur();                              
    bool get_EtatServeur();             //Teste si le serveur est sauvé ou non

private:
   // QTcpSocket* socket;
    EcouteHTTP* listener;


    bool bEtatServeur;

};

#endif // F_STARTSERVEUR_H
