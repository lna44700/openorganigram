//------------------------------------------------------------------------------
/** @file       f_APropos.cpp
* @brief        Fichier pour "A propos".
*
* @author       PHILIPPEAU Florian
* @author       STS SNIR, Lycée Nicolas APPERT, ORVAULT (FRANCE)
* @since        11/04/2016
* @version      1.0
* @date         11/05/2016
*
* Fichier source de la classe f_APropos, permettant l'affichage de la fenêtre à propos.
*
* Fabrication   OpenOrganigram.pro
*
* @todo         à propos de l'application.
*
* @bug          <date du bug> - <CORRIGE> - <Intitulé précis du bug>
*/
//------------------------------------------------------------------------------

#include "f_APropos.h"
#include "ui_f_APropos.h"


/** Constructeur de la fenêtre de choix du profil utilisateur
* @brief    f_ChoixProfil::f_ChoixProfil()
* @see      f_ChoixProfil
*/
f_APropos::f_APropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::f_APropos)
{
    ui->setupUi(this) ;

    this->setWindowTitle("A propos de l'application") ;


}


/** Destructeur de la fenêtre de choix du profil utilisateur
* @brief    f_ChoixProfil::~f_ChoixProfil()
* @see      f_ChoixProfil
*/
f_APropos::~f_APropos()
{
    delete  ui ;
}


/** Validation du choix de profil utilisateur
* @brief    f_ChoixProfil::on_actionValider_accepted()
* @see      f_ChoixProfil
*/
void f_APropos::on_actionValider_accepted()
{
    f_APropos::close() ;
}


/** Fermeture de la fenêtre de choix de profil
* @brief    f_ChoixProfil::on_actionValider_rejected()
* @see      f_ChoixProfil
*/
void f_APropos::on_actionValider_rejected()
{
    f_APropos::close() ;
}
