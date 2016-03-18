//------------------------------------------------------------------------------
/** @file       f_ChoixProfil.cpp
* @brief        Fichier de gestion du choix du profil utilisateur.
*
* @author       AUBRY Jonathan
* @author       STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
* @since        18/03/2014
* @version      1.0
* @date         18/03/2014
*
* Fichier source de la classe f_ChoixProfil, permettant de choisir un profil parmis ceux présent dans le fichier de profil.
*
* Fabrication   OpenOrganigram.pro
*
* @todo         Besoin de vérifier si le fichier d'utilisateur existe, puis lire à l'intérieur et y trouver les différents profils existant.
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
            ui->Cb_Bx_Profil->addItem( Profil.toString() ) ;
        }
        i++ ;
        this->NombreUtilisateurs = i-1 ;
    }while( Profil != "Inconnu" ) ;


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
/*    QSettings   Utilisateur ("C:\\Users\\Gaetan\\Documents\\PROJET\\openorganigram\\Profils.ini", QSettings::IniFormat) ;
    QCryptographicHash  HashMDP (QCryptographicHash::Md5) ;
    QByteArray          ArrayHashMDP ;

    ArrayHashMDP = ui->LE_MdP->text().toLocal8Bit() ;
    HashMDP.addData(ArrayHashMDP) ;

    if (HashMDP.result() != Utilisateur.value(ui->Cb_Bx_Profil->currentText()+"/MdP"))
    {
        QMessageBox::critical(this, "Erreur !", "Mot de passe incorrect.") ;
        ui->LE_MdP->clear() ;
        ui->Lb_MdP->setStyleSheet("border: 2px solid red") ;
    }
    else
    {
        this->ProfilActif = ui->Cb_Bx_Profil->currentText() ;

        QMessageBox::information(this, "Changement de profil.", "Vous êtes maintenant connecté en tant que : " + this->ProfilActif) ;
        emit accept() ;
        f_ChoixProfil::close() ;
    }

*/
    QSettings   Profils ("Profils.ini", QSettings::IniFormat) ;
    QSettings   Mdps ("Profils.ini", QSettings::IniFormat) ;
    QString  NumProfil ;
    QVariant ProfilSelectionne ;
    QVariant Profil ;
    QString NumMdp ;
    QVariant MdpEntre ;
    QVariant Mdp ;

    ProfilSelectionne = ui->Cb_Bx_Profil->currentText() ;
    MdpEntre = ui->LE_MdP->text() ;

    if( ProfilSelectionne == "Eleve")
    {
        ProfilActif = ui->Cb_Bx_Profil->currentText() ;
    }

    int i = 0 ;
    do
    {

        NumProfil = "Profils/Profilid" + QString::number( i ) ;
        Profil = Profils.value( NumProfil, "Inconnu" ) ;
        NumMdp = "Mdp/mdpid" + QString::number( i ) ;
        Mdp = Mdps.value ( NumMdp, "") ;

        if( Mdp == MdpEntre )
        {
            this->ProfilActif = ui->Cb_Bx_Profil->currentText() ;

            QMessageBox::information(this, "Changement de profil.", "Vous êtes maintenant connecté en tant que : " + this->ProfilActif) ;
            emit accept() ;
            f_ChoixProfil::close() ;
        }
        i++ ;
    }while( Mdp != MdpEntre && i < NombreUtilisateurs ) ;
    if( Mdp != MdpEntre )
    {
        QMessageBox::critical(this, "Erreur !", "Mot de passe incorrect.") ;
        ui->LE_MdP->clear() ;
        ui->Lb_MdP->setStyleSheet("border: 2px solid red") ;
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


void f_ChoixProfil::on_Cb_Bx_Profil_currentTextChanged(const QString &arg1)
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


void f_ChoixProfil::closeEvent(QCloseEvent *CloseEvent)
{
    emit(EnvoieProfil(ProfilActif));
    CloseEvent->accept();
}
