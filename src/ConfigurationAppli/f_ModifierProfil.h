// f_ModifierProfil.h     1.0     01.04   Jonathan Aubry

#ifndef __MODIFIERPROFIL_H
#define __MODIFIERPROFIL_H

/*
* Déclaration anticipée de la classe
*/
class f_ModifierProfil ;


/*
* Inclusion des fichiers EN-TÊTE
*/
#include <QDialog>


/*
* Déclaration de la classe
*/
namespace Ui {
class f_ModifierProfil ;
}

class f_ModifierProfil : public QDialog
{
    Q_OBJECT

    public :
        explicit f_ModifierProfil(QWidget *parent = 0) ;
        ~f_ModifierProfil() ;

    protected :

    private :
        Ui::f_ModifierProfil * ui ;

    private slots:
        void on_BtBx_Valider_rejected() ;
        void on_BtBx_Valider_accepted() ;
        void on_LE_AncienMdP_textChanged(const QString &arg1);
};
#endif // F_MODIFIERPROFIL_H
