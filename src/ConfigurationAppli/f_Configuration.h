// Configuration.h     2.0 20/04/2016 Guitton Lucas

#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H


/*
* Déclaration anticipée de la classe
*/
class f_Configuration ;


/*
* Inclusion des fichiers EN-TÊTE
*/
#include <QDialog>
#include "SupervisionWeb/Serveur/Serveur.h"
#include "f_MainWindow.h"


/*
* Déclaration de la classe
*/
namespace Ui {
class f_Configuration ;
}

class f_Configuration : public QDialog
{
    Q_OBJECT


    public :
        // Constructeur
        explicit f_Configuration(Serveur * pServeur, QWidget *  parent = 0) ;

        // Destructeur
        ~f_Configuration() ;

        // Retourne le QString correspondant au numéro de port
        QString Get_NumeroPort() ;

    protected :


    private :

        Ui::f_Configuration * ui ;
        //ServeurWeb pointeur
        Serveur * ServeurWeb;
        //MainWindow
        f_MainWindow MainWindow;
        //Contient le numéro de port enregistrer par l'utilisateur
        QString sNumeroPort ;
        //Contient le taux de rafraissement de la page Supervision.html
        QString sTauxRafraichissementPage ;


    private slots :
        // Est réaliser lors de l'appui sur le bouton de rejet
        void on_Bt_Validation_rejected() ;

        // Méthode de validation
        void on_Bt_Validation_accepted();

signals:
        EnvoieEtatServeur(bool EtatServeur);
};

#endif // __CONFIGURATION_H
