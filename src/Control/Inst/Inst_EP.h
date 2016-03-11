//  Inst_EP.h 1.0   11/03/2016  L. Guitton

#ifndef INST_EP_H
#define INST_EP_H

class Inst_EP;

//===== Headers standards =====

//=====   Headers Peros   =====
#include "../Instruction.h"

class Inst_EP : public Instruction
{
    public:
                                Inst_EP(unsigned int nId, Routine *pRoutine) ;                  //Constructeur
                                Inst_EP(DescEP DescriptionExecPara) ;

        inline  TypeCommande    getType()   { return EP ; }
                Compil_Inst*    Compiler() ;
                void            Executer() ;                                                    //Exécute l'élément
                QString         toString() ;                                                    //Génère la chaine de caractère à afficher dans dans le dessin de l'organigramme
        inline  bool            Modifier() ;

                void            setDesc(DescEP DescriptionExecPara);
                DescEP          getDesc();
                void            setActivation(bool Active);                                      //Mutateur d'activation
                bool            getEstActive();
              //void            setAttr(QString NomAttr, QStringRef Valeur);                    //Mutateur général
                void            Enregistrer(QXmlStreamWriter* Parser);                          //Enregistrement

    private:

                Inst_EP *       pInstPaire ;                                                    //Pointeur vers l'instruction paire
                bool            EstActive;                                                      //Activation de la boucle
                DescEP          DescriptionExecPara ;
                bool            LancerModification() ;                                          //Lance la modification
};
#endif // INST_EP_H

