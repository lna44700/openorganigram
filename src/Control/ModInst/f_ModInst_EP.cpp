//-------------------------------------------------------------------------------
/**
 * @file        f_ModInst_EP.cpp
 * @brief       Fenetre de modification d'une insturction execution parallele
 *
 * @author      L. Guitton
 * @author      STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
 * @since       11/03/2016
 * @version     1.0
 * @date        11/03/2016
 *
 * Classe affichant une interface de modification des propriété d'une instruction "Execution Parallele"
 *
 * Fabrication  OpenOrganigram.pro
 *
 * @todo        /
 *
 * @bug         /
 */
//-------------------------------------------------------------------------------

//===== Headers standards =====

#include "f_ModInst_EP.h"
#include "ui_f_ModInst_EP.h"


/**
 * Constructeur
 *
 * @brief f_ModInst_EP::f_ModInst_EP
 * @param pInstructionAModifier Intruction à modifier
 * @param parent                Widget parent
 */
f_ModInst_EP::f_ModInst_EP(Inst_EP *pInstructionAModifier, QWidget *parent) :
    QDialog         (parent),
    pInstructionAModifier (pInstructionAModifier),
    ui(new Ui::f_ModInst_EP)
{
    ui->setupUi(this);
}

f_ModInst_EP::~f_ModInst_EP()
{
    delete ui;
}

/**
 * Renvois la description de l'éxecution parallèle modifiée
 *
 * @brief f_ModInst_EP::getDescription
 * @return La description
 */
DescEP f_ModInst_EP::getDescription()
{
    DescEP Retour ;

    if(this->ui->choix2->isChecked())
    {
        Retour.nNombreDeBranches = 2;
    }
    if(this->ui->choix3->isChecked())
    {
        Retour.nNombreDeBranches = 3;
    }
    if(this->ui->choix4->isChecked())
    {
        Retour.nNombreDeBranches = 4;
    }
    if(this->ui->choix5->isChecked())
    {
        Retour.nNombreDeBranches = 5;
    }

    return Retour ;
}

void f_ModInst_EP::on_BtnAccept_accepted()
{
    f_ModInst_EP::getDescription();
    f_ModInst_EP::close();
}



void f_ModInst_EP::on_BtnAccept_rejected()
{
    f_ModInst_EP::close();
}
