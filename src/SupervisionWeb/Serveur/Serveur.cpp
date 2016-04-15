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


/** Controller for static files */
    extern ControleurFichierStatique* controleurFichierStatique;

    /** Search the configuration file */

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
    // Find the configuration file
       // QString configFileName=searchConfigFile();


        // Configure static file controller
        //QSettings* fileSettings=new QSettings(configFileName,QSettings::IniFormat);
        QSettings* ConfigurationFichiers=new QSettings("OpenOrganigram.ini", QSettings::IniFormat) ;
        //fileSettings->beginGroup("www");
        ConfigurationFichiers->beginGroup("www");
        //controleurFichierStatique=new ControleurFichierStatique(fileSettings);
        controleurFichierStatique=new ControleurFichierStatique(ConfigurationFichiers);

        // Configure and start the TCP listener
       // QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat);
        QSettings* ConfigurationPort=new QSettings("OpenOrganigram.ini", QSettings::IniFormat) ;
        //listenerSettings->beginGroup("listener");
        ConfigurationPort->beginGroup("listener");
        //listener = new EcouteHTTP(listenerSettings,new RequeteMapper());
        listener = new EcouteHTTP(ConfigurationPort,new RequeteMapper());
}

void Serveur::stopperServeur()
{
   listener->close();
   delete listener;
   remove ("www/Supervision.html");

}









