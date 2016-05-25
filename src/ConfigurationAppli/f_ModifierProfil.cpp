//------------------------------------------------------------------------------
/** @file       f_ModifierProfil.cpp
* @brief        Fichier de gestion de modification d'un profil utilisateur.
*
* @author       AUBRY Jonathan, GUITTON Lucas
* @author       STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
* @since        04/04/2014
* @version      2.0
* @date         0/0/2016
*
* Fichier source de la classe f_ModifierProfil, permettant de modifier un profil parmis ceux présent dans le fichier de profil.
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

#include "f_ModifierProfil.h"
#include "ui_f_ModifierProfil.h"


/** Constructeur de la fenêtre de modification du profil utilisateur
* @brief    f_ModifierProfil::f_ModifierProfil()
* @see      f_ModifierProfil
*/
f_ModifierProfil::f_ModifierProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::f_ModifierProfil)
{
    ui->setupUi(this) ;
    ui->LE_NvMdP->hide();
    ui->Lb_NvMdP->hide();
    ui->LE_ConfirmMdP->hide();
    ui->Lb_ConfimMdP->hide();

    ui->LE_NvMdP->setEchoMode(QLineEdit::Password);
    ui->LE_ConfirmMdP->setEchoMode(QLineEdit::Password);

    this->setWindowTitle("Modifier le profil") ;
}


/** Destructeur de la fenêtre de modification du profil utilisateur
* @brief    f_ModifierProfil::~f_ModifierProfil()
* @see      f_ModifierProfil
*/
f_ModifierProfil::~f_ModifierProfil()
{
    delete ui;
}


/** Annulation de la modification du profil
* @brief    f_ModifierProfil::on_BtBx_Valider_rejected()
* @see      f_ModifierProfil
*/
void f_ModifierProfil::on_BtBx_Valider_rejected()
{
    f_ModifierProfil::close() ;
}


/** Accepte le changement de mot de passe du profil
* @brief    f_ModifierProfil::on_BtBx_Valider_accepted()
* @see      f_ModifierProfil
*/
void f_ModifierProfil::on_BtBx_Valider_accepted()
{
    QSettings    Profils("Profils.ini", QSettings::IniFormat) ;

    if(ui->LE_NvMdP->text() == ui->LE_AncienMdP->text())
    {
        QMessageBox::information(this, "Erreur", "Veuillez rentrer un mot de passe différent que l'ancien");
        ui->LE_NvMdP->clear();
        ui->LE_ConfirmMdP->clear();
        ui->LE_NvMdP->setStyleSheet("border: 2px solid red") ;
    }
    else
    {
        if(ui->LE_ConfirmMdP->text() != ui->LE_NvMdP->text())
        {
            QMessageBox::information(this, "Erreur", "Les mots de passes sont différents.") ;
            ui->LE_ConfirmMdP->clear();
            ui->LE_ConfirmMdP->setStyleSheet("border: 2px solid red") ;
            ui->LE_NvMdP->clear();
            ui->LE_NvMdP->setStyleSheet("border: 2px solid red") ;
        }
        else
        {
            QCryptographicHash  MotDePasseHash (QCryptographicHash::Md5) ;
            QByteArray          MotDePasseBArray ;
            QString sMotDePasse("");
            MotDePasseBArray = ui->LE_AncienMdP->text().toLocal8Bit() ;
            MotDePasseHash.addData(MotDePasseBArray) ;
            sMotDePasse = Profils.value("Mdp/mdpid1", "").toString();
            if (QString::fromLocal8Bit(MotDePasseHash.result()) == sMotDePasse)
            {
                MotDePasseBArray.remove(0, MotDePasseBArray.size()) ;
                MotDePasseHash.reset() ;
                MotDePasseBArray = ui->LE_NvMdP->text().toLocal8Bit() ;
                MotDePasseHash.addData(MotDePasseBArray) ;
                Profils.remove("Mdp/mdpid1");
                Profils.setValue("Mdp/mdpid1", QString::fromLocal8Bit(MotDePasseHash.result()));

                QMessageBox::information(this, "Profil modifié.", "Le mot de passe à été correctement modifié.") ;
                f_ModifierProfil::close();
            }
            else
            {
                ui->LE_AncienMdP->clear() ;
                ui->LE_AncienMdP->setStyleSheet("border: 2px solid red") ;

                QMessageBox::critical(this, "Profil à modifié.", "L'ancien mot de passe est incorrect.") ;
            }
        }
    }
}


void f_ModifierProfil::on_LE_AncienMdP_textChanged(const QString &arg1)
{
    QSettings Profils("Profils.ini", QSettings::IniFormat) ;
    QString sMotDePasse("");
    QString MdpEntre ("");
    QByteArray MotDePasseArray;

    MdpEntre = arg1;
    MotDePasseArray = QCryptographicHash::hash(MdpEntre.toLocal8Bit(), QCryptographicHash::Md5);

    MdpEntre = QString::fromLocal8Bit(MotDePasseArray);
    sMotDePasse = Profils.value("Mdp/mdpid1", "").toString();
    if(MdpEntre == sMotDePasse)
    {
        ui->LE_NvMdP->show();
        ui->Lb_NvMdP->show();
        ui->LE_ConfirmMdP->show();
        ui->Lb_ConfimMdP->show();
    }

    MotDePasseArray.remove(0, MotDePasseArray.size());
}
