//------------------------------------------------------------------------------
/** @file       f_ChoixProfil.cpp
* @brief        Fichier de gestion du choix du profil utilisateur.
*
* @author       AUBRY Jonathan
* @author       GUITTON Lucas
* @author       STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
* @since        18/03/2014
* @version      1.1
* @date         09/04/2016
*
* Fichier source de la classe f_ChoixProfil, permettant de choisir un profil parmis ceux présent dans le fichier de profil.
*
* Fabrication   OpenOrganigram.pro
*
* @todo         Rendre le mot de passe crypté lorsqu'il est inscrit dans le fichier .ini
*
* @bug          <date du bug> - <CORRIGE> - <Intitulé précis du bug>
*/
//------------------------------------------------------------------------------
#include <QSettings>
#include <QMessageBox>
#include <QCryptographicHash>

#include "f_MainWindow.h"
#include "f_ChoixProfil.h"
#include "ui_f_ChoixProfil.h"


/** Constructeur de la fenêtre de choix du profil utilisateur
* @brief    f_ChoixProfil::f_ChoixProfil()
* @see      f_ChoixProfil
*/
f_ChoixProfil::f_ChoixProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::f_ChoixProfil)
{
    QSettings   Profils ("Profils.ini", QSettings::IniFormat) ;
    QString  NumProfil ;
    QVariant Profil ;

    ui->setupUi(this) ;

    ui->LE_MdP->setVisible(false) ;
    ui->Lb_MdP->setVisible(false) ;
    ui->LE_MdP->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("Choix du profil utilisateur") ;

    int i =0 ;
    do
    {

        NumProfil = "Profils/Profilid" + QString::number( i ) ;
        Profil = Profils.value( NumProfil, "Inconnu" ) ;

        if( Profil != "Inconnu" )
        {
            ui->CBx_Profil->addItem( Profil.toString() ) ;
        }
        i++ ;
        this->NombreUtilisateurs = i-1 ;
    }while( Profil != "Inconnu" ) ;

    //sécurité dans la gestion de profil. Ceci rends la gestion dynamique et donc possible en toutes circonstances.
    if(!QFile::exists("Profils.ini"))
    {
        QSettings   Profils("Profils.ini", QSettings::IniFormat);
        QByteArray  MotDePasseBArray;
        QString     sMotDePasse("test");

        MotDePasseBArray = QCryptographicHash::hash(sMotDePasse.toLocal8Bit(), QCryptographicHash::Md5);

        Profils.setValue("Profils/Profilid0","Eleve");
        Profils.setValue("Profils/Profilid1", "Professeur");
        Profils.setValue("Mdp/mdpid0", "");
        Profils.setValue("Mdp/mdpid1", QString::fromLocal8Bit(MotDePasseBArray));

        MotDePasseBArray.remove(0, MotDePasseBArray.size()) ;
    }

}


/** Destructeur de la fenêtre de choix du profil utilisateur
* @brief    f_ChoixProfil::~f_ChoixProfil()
* @see      f_ChoixProfil
*/
f_ChoixProfil::~f_ChoixProfil()
{
    delete  ui ;
}


/** Validation du choix de profil utilisateur
* @brief    f_ChoixProfil::on_actionValider_accepted()
* @see      f_ChoixProfil
*/
void f_ChoixProfil::on_actionValider_accepted()
{
    QSettings   Profils ("Profils.ini", QSettings::IniFormat) ;
    QString  NumProfil ;
    QVariant ProfilSelectionne ;
    QVariant Profil ;
    QString NumMdp ;
    QString MdpEntre ;
    QString Mdp ;
    QByteArray  MotDePasseBArray;


    ProfilSelectionne = ui->CBx_Profil->currentText() ;

    if( ProfilSelectionne == "Eleve")
    {
        ProfilActif = ui->CBx_Profil->currentText() ;
        emit accept() ;
        f_ChoixProfil::close() ;

    }
    else
    {

        MdpEntre = ui->LE_MdP->text() ;

        NumProfil = "Profils/Profilid1";
        Profil = Profils.value( NumProfil, "Inconnu" ) ;
        NumMdp = "Mdp/mdpid1";
        Mdp = Profils.value ( NumMdp, "").toString() ;

        MotDePasseBArray = QCryptographicHash::hash(MdpEntre.toLocal8Bit(), QCryptographicHash::Md5);
        MdpEntre = QString::fromLocal8Bit(MotDePasseBArray);

        if( Mdp == MdpEntre )
        {
            this->ProfilActif = ui->CBx_Profil->currentText() ;

            QMessageBox::information(this, "Changement de profil.", "Vous êtes maintenant connecté en tant que : " + this->ProfilActif) ;
            emit accept() ;
            f_ChoixProfil::close() ;
        }
        else
        {
            QMessageBox::critical(this, "Erreur !", "Mot de passe incorrect.") ;
            ui->LE_MdP->clear() ;
            ui->Lb_MdP->setStyleSheet("border: 2px solid red") ;
        }
    }
}


/** Fermeture de la fenêtre de choix de profil
* @brief    f_ChoixProfil::on_actionValider_rejected()
* @see      f_ChoixProfil
*/
void f_ChoixProfil::on_actionValider_rejected()
{
    f_ChoixProfil::close() ;
}


/** Accesseur de lecture de l'attribut ProfilActif
* @brief    f_ChoixProfil::Get_ProfilActif()
* @see      f_ChoixProfil
*/
QString f_ChoixProfil::Get_ProfilActif()
{
    return (this->ProfilActif) ;
}


/**
 * Slot de récupération du profil sélectionné
 * @brief f_MainWindow::on_CBx_Profil_currentTextChanged
 * @param &arg1
 */
void f_ChoixProfil::on_CBx_Profil_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Professeur")
    {
        ui->LE_MdP->setVisible(true) ;
        ui->Lb_MdP->setVisible(true) ;
    }
    else
    {
        ui->LE_MdP->setVisible(false) ;
        ui->Lb_MdP->setVisible(false) ;
    }

}


/**
 * Event de fermeture
 * @brief f_MainWindow::closeEvent
 * @param *CloseEvent
 */
void f_ChoixProfil::closeEvent(QCloseEvent *CloseEvent)
{
    emit(EnvoieProfil(ProfilActif));
    CloseEvent->accept();
}
