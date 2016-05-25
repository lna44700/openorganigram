//-------------------------------------------------------------------------------
/**
 * @file        Inst_EP.cpp
 * @brief       Instruction Execution Parallele
 *
 * @author      L.Guitton
 * @author      STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
 * @since       11/03/16
 * @version     1.0
 * @date        11/03/16
 *
 * Représente une Exécution parallèle dans l'organigramme
 *
 * Fabrication  OpenOrganigram.pro
 *
 * @todo        /
 *
 * @bug         /
 */
//-------------------------------------------------------------------------------

//===== Headers standards =====

//=====   Headers Peros   =====
#include "Inst_EP.h"
#include "../Compil_Inst.h"
#include "../ModInst/f_ModInst_EP.h"



/**
 * Constructeur
 *
 * @brief Inst_EP::Inst_EP
 * @param nId       Identifiant de l'instruction
 * @param pRoutine  Routine parente
 */
Inst_EP::Inst_EP(unsigned int nId, Routine *pRoutine) :
    Instruction (nId, pRoutine),
    pInstPaire  (0),
    EstActive   (true)
{
    //Initialisation de l'execution parallele a executer
    this->DescriptionExecPara.nNombreDeBranches = 2;
}

Compil_Inst *Inst_EP::Compiler()
{
    Compil_Inst* Retour(new Compil_Inst(this));

    Retour->AjouterUnOpCode('\x0');
    Retour->AjouterLienVers(this->pRoutine->getInstruction(this->nIdSuivant[0])->getIdentifiantInst());

    return Retour;
}

/**
 * Execute les branches
 *
 * @brief   Inst_EP::Executer
 * @param   Manager Manager avec lequel éxecuter l'execution parallele
 * @return  L'identifiant de l'instruction suivante
 */
void Inst_EP::Executer()
{
    //Déclaration de l'identifiant des instructions suivantes
    for(int i=0; i<this->DescriptionExecPara.nNombreDeBranches; i++)
    {
        IdentifiantInst Identifiant[i];
    }

}


/**
 * Retourne une chaine de caractère affichable
 *
 * @brief   Inst_EP::toString
 * @return  La chaine affichable
 */
QString Inst_EP::toString()
{
    //Déclaration des variable
    QString     Retour;
    QStringList ListeChainePossible;

    return Retour ;
}

/**
 * Ouvre une fenetre de modification
 *
 * @brief Inst_EP::Modifier
 */
bool Inst_EP::Modifier()
{
    //Déclaraion des variables
    bool Retour (true);

    Retour = this->LancerModification();

    return Retour;
}

/**
 * Mutateur de la description de l'execution parallele
 *
 * @brief Inst_EP::setDesc
 * @param Description   La description de l'execution parallele
 */
void Inst_EP::setDesc(DescEP DescriptionExecPara)
{
    //Affectation à nos propres attributs
    this->DescriptionExecPara.nNombreDeBranches  = DescriptionExecPara.nNombreDeBranches ;
}

/**
 * Ascesseur de la desription
 * @brief Inst_EP::getDesc
 * @return retourne la description de l'execution parallele
 */
DescEP Inst_EP::getDesc()
{
    return DescriptionExecPara;
}

/**
 * Mutateur de l'activation de l'execution parallele
 * @brief Inst_EP::setActivation
 * @param Active la valeur de l'activation
 */
void Inst_EP::setActivation(bool Active)
{
    this->EstActive = Active;
}

/**
 * Ascesseur de l'activation de la maquette
 * @brief Inst_EP::getEstActive
 * @return la valeur de l'activation
 */
bool Inst_EP::getEstActive()
{
    return this->EstActive;
}

/**
 * Enregistre son contenu au format XML grâce au parseur fourni
 * @brief Inst_EP::Enregistrer
 * @param Parser Le parseur à utiliser
 */
void Inst_EP::Enregistrer(QXmlStreamWriter* Parser)
{
    //Ecriture des balises communes à toutes les instructions
    this->DebutBalise(Parser);

    Parser->writeEmptyElement("nNombreDeBranches");
    Parser->writeAttribute("valeur", QVariant(this->DescriptionExecPara.nNombreDeBranches).toString());

    //Ecriture de la fin de balise commune
    this->FinBalise(Parser);
}

/**
 * Ouvre une fenetre de modification
 *
 * @brief Inst_EP::LancerModification
 */
bool Inst_EP::LancerModification()
{
    //Déclaration des variables
    bool                Retour      (true);
    f_ModInst_EP        FenetreModif(this) ;
    int                 reponse     (0) ;

    //Exécution de la fenetre de modification
    reponse = FenetreModif.exec();

    //Si l'utilisateur a cliqué sur Ok
    if(reponse == QDialog::Accepted)
    {
        //On récupère la nouvelle description
        DescEP Description  (FenetreModif.getDescription()) ;

        //On la met en place dans l'élément
        this->setDesc(Description) ;
        //this->pInstPaire->setDesc(Description);
    }
    else
    {
        //Sinon on retourne faux
        Retour = false;
    }

    return Retour;
}
