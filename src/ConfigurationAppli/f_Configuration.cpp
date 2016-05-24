//------------------------------------------------------------------------------
/** @file       Configuration.cpp
* @brief        Fichier de gestion de la fonction de configuration de l'application.
*
* @author       AUBRY Jonathan
* @author       STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
* @since        21/02/2014
* @version      1.1
* @date         11/04/2016
*
* Fichier source de la classe Configuration. Permet la création de l'interface et la réalisation de différentes tâches comme le changement du numéro de port du serveur de supervision.
*
* Fabrication   OpenOrganigram.pro
*
* @todo         Besoin de pouvoir changer le numéro de port du serveur.
*
* @bug          <11/04/2016> - <CORRIGE> - <Erreur de Runtime quand l'appli chercher le fichier de config du serveur>
*/
//------------------------------------------------------------------------------

#include <QDialog>
#include <QSettings>
#include <QDir>
#include <QMessageBox>
#include <QtWidgets>
#include <QtNetwork>
#include <stdlib.h>

#include "f_Configuration.h"
#include "ui_f_Configuration.h"


/** Constructeur de la fenêtre de configuration
* @pre      L'utilisateur ai cliqué sur le menu "Configuration" de la fenêtre principale
* @see      f_Configuration::f_Configuration(), ui, setupUi
*/
f_Configuration::f_Configuration(Serveur * pServeur, QWidget *  parent) :
    QDialog (parent),
    ServeurWeb  (NULL) ,
    ui      (new Ui::f_Configuration)
{
    ui->setupUi(this) ;
    this->ServeurWeb = pServeur ;

    // Pour la configuration du serveur
    QSettings   ConfigurationServeurPort ("ConfigurationServeurWeb.ini", QSettings::IniFormat) ;
    QString sPort = ConfigurationServeurPort.value("listener/port","ConfigurationServeurWeb").toString();

    ui->label_Port->setText(sPort);

    QString sIpAdresse;
    QString listIp;
       QList<QHostAddress> ipAdressesList = QNetworkInterface::allAddresses();

      for (int i = 0; i < ipAdressesList.size(); ++i) {
           if (ipAdressesList.at(i) != QHostAddress::LocalHost &&
               ipAdressesList.at(i).toIPv4Address()) {
               sIpAdresse = ipAdressesList.at(i).toString();
               listIp=listIp+sIpAdresse;
           }
       }
       // if we did not find one, use IPv4 localhost
       if (sIpAdresse.isEmpty())
           sIpAdresse = QHostAddress(QHostAddress::LocalHost).toString();

       ui->statusLabel->setText(sIpAdresse);

       //Pour le rafraichissement de la page Supervision.html
       QSettings   ConfigurationServeurRafraichissement ("ConfigurationServeurWeb.ini", QSettings::IniFormat) ;
       QString sTauxRafraissement = ConfigurationServeurRafraichissement.value("www/dureeRafraichissement","ConfigurationServeurWeb").toString();
       ui->label_Temps->setText(sTauxRafraissement);

        // Connecter avec les lancer et stopper serveur

}


/** Destructeur de la fenêtre de configuration
* @pre      Que la fenêtre de configuration ai été lancée
* @see      f_Configuration::~f_Configuration(), ui
*/
f_Configuration::~f_Configuration()
{
    delete  ui ;
}


/** Méthode d'annulation
* @pre      Il faut que l'utilisateur soit entrain de configurer les paramètres de l'application
* @see      f_Configuration::on_Bt_Validation_rejected() ;
*/
void f_Configuration::on_Bt_Validation_rejected()
{
    this->close() ;
}


/** Méthode de validation
* @pre      Il faut que l'utilisateur soit entrain de configurer les paramètres de l'application
* @see      f_Configuration::on_Bt_Validation_accepted() ;
* @author Florian Philippeau
*/
void f_Configuration::on_Bt_Validation_accepted()
{

    // Ouverture du fichier INI
    QSettings   ConfigurationServeurPort ("ConfigurationServeurWeb.ini", QSettings::IniFormat) ;

//Serveur

    sNumeroPort = ui->LE_PortServeur->text() ;

    // Création du groupe [listener];
    ConfigurationServeurPort.beginGroup("listener");

    if(sNumeroPort == "")
    {
       // Création des différentes clés et valeurs correspondantes
        ConfigurationServeurPort.setValue("port", "80");
       QMessageBox::warning(this, "Attention", "Un numéro de port est obligatoire ! Le port 80 a donc été mit pas défault.");
    }
    else
    {
    // Création de le clé Port et de la valeur correspondante
      ConfigurationServeurPort.setValue("port", sNumeroPort);
    }

//Rafraichissement page Supervision.html

    sTauxRafraichissementPage = ui->LE_TauxRaffraichssementPage->text();
    // Ouverture du fichier INI
    QSettings   ConfigurationServeurRafraichissement ("ConfigurationServeurWeb.ini", QSettings::IniFormat) ;
    // Création du groupe [www];
    ConfigurationServeurRafraichissement.beginGroup("www");

    if(sTauxRafraichissementPage == "")
    {
       // Création des différentes clés et valeurs correspondantes
        ConfigurationServeurRafraichissement.setValue("dureeRafraichissement", "2");
       QMessageBox::warning(this, "Attention", "Un taux de rafraichissement de la page Supervision.html est obligatoire ! Une durée de 2 secondes a donc été mise pas défault.");
    }
    else
    {
    // Création de le clé dureeRafraichissement et de la valeur correspondante
      ConfigurationServeurRafraichissement.setValue("dureeRafraichissement", sTauxRafraichissementPage);
    }

    if(ServeurWeb->get_EtatServeur() == true)
    {
        ServeurWeb->stopperServeur();
        ServeurWeb->lancerServeur();
    }


    emit(EnvoieEtatServeur(ServeurWeb->get_EtatServeur()));


    QMessageBox::information(this, "Attention !", "Les paramètres du serveur on été modifiés !");
    this->close() ; // Ferme la fenêtre de configuration
}


/** Méthode de retour du numéro de port serveur
* @pre      Il faut que l'utilisateur soit entrain de configurer les paramètres de l'application
* @see      f_Configuration::Get_NumeroPort() ;
*/
QString f_Configuration::Get_NumeroPort()
{
    return this->sNumeroPort ;
}
