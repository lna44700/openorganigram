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

Serveur::Serveur()
{

}

Serveur::~Serveur()
{

}

void Serveur::lancerServeur()
{
    //Supprime le fichier Supervision.html si cela n'a pas été fait (en cas de beug)
    remove ("www/Supervision.html");



        // Configure le contrôleur de fichier statique
        QSettings* ConfigurationFichiers=new QSettings("OpenOrganigram.ini", QSettings::IniFormat) ;
        ConfigurationFichiers->beginGroup("www");
        controleurFichierStatique=new ControleurFichierStatique(ConfigurationFichiers);

        // Configure et démarre le serveur TCP
        QSettings* ConfigurationPort=new QSettings("OpenOrganigram.ini", QSettings::IniFormat) ;
        ConfigurationPort->beginGroup("listener");
        listener = new EcouteHTTP(ConfigurationPort,new RequeteMapper());
}

void Serveur::stopperServeur()
{
   listener->close();
   delete listener;
   remove ("www/Supervision.html");

}









