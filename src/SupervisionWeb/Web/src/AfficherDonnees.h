#ifndef F_AFFICHERBROCHENOM_H
#define F_AFFICHERBROCHENOM_H

#include "SupervisionWeb/Serveur/Serveur.h"
#include "Supervision/f_Supervision.h"
//#include "./Interface/Arduino.h"


class AfficherDonnees : public Serveur
{
public:
    explicit AfficherDonnees();
    ~AfficherDonnees();
    AfficherNomBroche();


private:
    Serveur                 serveurWeb;
    //f_Supervision           donnees;


};

#endif // F_AFFICHERBROCHENOM_H
