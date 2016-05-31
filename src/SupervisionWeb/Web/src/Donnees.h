#ifndef F_AFFICHERBROCHENOM_H
#define F_AFFICHERBROCHENOM_H

#include "SupervisionWeb/Serveur/Serveur.h"
#include "Supervision/f_Supervision.h"
#include "./Interface/Arduino.h"
#include "../../Interface/LibParser/muParser.h"

#include <QObject>
#include <QTimer>


class Donnees : public QObject
{

    Q_OBJECT

public:
    explicit Donnees();
    explicit Donnees(Arduino *pControleur, QObject * parent = 0);
    //explicit AfficherDonnees(Arduino * pArduino); // Pour récupération des valeurs
    ~Donnees();
    QTimer* Get_pTimer();
    void    Timer();
    void    StoperTimer();
    bool get_EtatTimer();

    QTimer*            pTimerRafraichissement;
    QTimer*            pTimerWeb;


private:
    Serveur             serveurWeb;
    f_Supervision *     pSupervision;

    //Ajout le 27/04/2016
    Arduino *          pArduino;     //Contient l'adresse de l'Arduino.
    QByteArray         RetourCommande;     //Retour de la commande supervision.
    bool               bAttenteReponse;    //Bool d'attente de réponse de l'arduino
    QQueue<QString>    ListeCommandes; //Liste des commandes
    unsigned int       Compteur ;

    //Ajout le 15/05/2016
    mu::Parser      Parser;
    QString         Expression;
    double          val;

    //Ajout le 20/05/2016
    bool bEtatTimer;


public slots:
    void    on_EcrireDonneesDansPageHTML();


};

#endif // F_AFFICHERBROCHENOM_H
