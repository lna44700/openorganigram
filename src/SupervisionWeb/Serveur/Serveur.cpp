/**
  @file
  @author Florian Philippeau
*/

//Includes QT
#include <QCoreApplication>
#include <QDir>
#include <QThread>
#include <QTcpServer>


//Include Perso
#include "EcouteHTTP.h"
#include "ControleurFichierStatique.h"
#include "GestionnaireConnexionHTTP.h"
#include "RequeteMapper.h"
#include "Serveur.h"
#include "EcouteHTTP.h"
#include "f_MainWindow.h"


/** Controlleur pour les fichiers statiques */
    extern ControleurFichierStatique* controleurFichierStatique;


/** Constructeur de la class Serveur
* @see     Serveur::Serveur()
*/
Serveur::Serveur()
{

}

/** Destructeur de la class Serveur
* @see     Serveur::~Serveur()
*/
Serveur::~Serveur()
{

}


/** Actions qui s'executent quand un utilisateur lance le serveur web depuis f_MainWindow
* @see     Serveur::lancerServeur()
*/
void Serveur::lancerServeur()
{
    //Supprime le fichier Supervision.html si cela n'a pas été fait (en cas de beug)
    //remove ("www/Supervision.html");

        // Configure le contrôleur de fichier statique
        QSettings* ConfigurationFichiers=new QSettings("ConfigurationServeurWeb.ini", QSettings::IniFormat) ;
        ConfigurationFichiers->beginGroup("www");
        controleurFichierStatique=new ControleurFichierStatique(ConfigurationFichiers);

        // Configure et démarre le serveur TCP
        QSettings* ConfigurationPort=new QSettings("ConfigurationServeurWeb.ini", QSettings::IniFormat) ;
        ConfigurationPort->beginGroup("listener");
        listener = new EcouteHTTP(ConfigurationPort,new RequeteMapper());
        bEtatServeur = true;
        qDebug()  << "Serveur: construit";
}

/** Actions qui s'executent quand un utilisateur stoppe le serveur web depuis f_MainWindow
* @see     Serveur::stopperServeur()
*/
void Serveur::stopperServeur()
{
   listener->close();
   delete listener;
   //remove ("www/Supervision.html");
   bEtatServeur = false;
   qDebug()  << "Serveur: détruit";

}

bool Serveur::get_EtatServeur()
{
    return bEtatServeur;
}







