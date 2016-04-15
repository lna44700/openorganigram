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




/** Search the configuration file */
/*
QString searchConfigFileIni()
{
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QString fileName(appName+".ini");

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir+"src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../../src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../"+appName+"src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../../"+appName+"src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../../../"+appName+"src/SupervisionWeb/Web/etc/etc");
    searchList.append(binDir+"/../../../../"+appName+"src/SupervisionWeb/Web/etc/etc");
    searchList.append(binDir+"/../../../../../"+appName+"src/SupervisionWeb/Web/etc/etc");
    searchList.append(QDir::rootPath()+"src/SupervisionWeb/Web/etc/opt");
    searchList.append(QDir::rootPath()+"etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir+"/"+fileName);
        if (file.exists())
        {
            // found
            fileName=QDir(file.fileName()).canonicalPath();
            qDebug("Utiliser le fichier de configuration %s",qPrintable(fileName));
            return fileName;
        }
    }

    // not found
    foreach (QString dir, searchList)
    {
        qWarning("%s/%s pas trouve",qPrintable(dir),qPrintable(fileName));
    }
    qFatal("ne trouve pas le fichier de configuration %s",qPrintable(fileName));
    return 0;
}

QStringList getAllIpV4Addr()
{
    QStringList result;
    foreach ( const QHostAddress &addr, QNetworkInterface::allAddresses() )
    {
        if ( addr.protocol() == QAbstractSocket::IPv4Protocol && addr != QHostAddress(QHostAddress::LocalHost) )
            result.append(addr.toString());
    }
    return result;
}

*/



/** Constructeur de la fenêtre de configuration
* @pre      L'utilisateur ai cliqué sur le menu "Configuration" de la fenêtre principale
* @see      f_Configuration::f_Configuration(), ui, setupUi
*/
f_Configuration::f_Configuration(QWidget *  parent) :
    QDialog (parent),
    ui      (new Ui::f_Configuration)
{
    ui->setupUi(this) ;

    QSettings   ConfigurationServeur ("OpenOrganigram.ini", QSettings::IniFormat) ;
/*
    // Find the configuration file
    QString configFileName=searchConfigFileIni();


    // Ouverture du fichier INI
    QSettings fileSettings(configFileName, QSettings::IniFormat);

    // On récupère la valeur du port
    QString port = fileSettings.value("listener/port","OpenOrganigram").toString();
    */
    QString Port = ConfigurationServeur.value("listener/port","OpenOrganigram").toString();

    ui->label_Port->setText(Port);

    //


    QString ipAddress;
    QString listIp;
       QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
       // use the first non-localhost IPv4 address
      for (int i = 0; i < ipAddressesList.size(); ++i) {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               ipAddress = ipAddressesList.at(i).toString();
               listIp=listIp+ipAddress;



           }
       }
       // if we did not find one, use IPv4 localhost
       if (ipAddress.isEmpty())
           ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

       ui->statusLabel->setText(ipAddress);




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
    NumeroPort = ui->LE_PortServeur->text() ;

    // Find the configuration file
        //QString configFileName=searchConfigFileIni();


    // Ouverture du fichier INI
    //QSettings fileSettings(configFileName, QSettings::IniFormat);
    QSettings   ConfigurationServeur ("OpenOrganigram.ini", QSettings::IniFormat) ;

    // Création du groupe [listener]
    //fileSettings.beginGroup("listener");
    ConfigurationServeur.beginGroup("listener");

    if(NumeroPort == "")
    {
       // Création des différentes clés et valeurs correspondantes
       // fileSettings.setValue("port", "80");
        ConfigurationServeur.setValue("port", "80");
       QMessageBox::warning(this, "Attention", "Un numéro de port est obligatoire ! Le port 80 à donc été mit pas défault.");

    }
    else
    {
    // Création des différentes clés et valeurs correspondantes
   // fileSettings.setValue("port", NumeroPort);
      ConfigurationServeur.setValue("port", NumeroPort);
    }

    this->close() ;

}


/** Méthode de retour du numéro de port serveur
* @pre      Il faut que l'utilisateur soit entrain de configurer les paramètres de l'application
* @see      f_Configuration::Get_NumeroPort() ;
*/
QString f_Configuration::Get_NumeroPort()
{
    return this->NumeroPort ;
}
