// f_APropos.h     1.0     01/03/2016   Guitton Lucas

#ifndef __APropos_H
#define __APropos_H


/*
* Déclaration anticipée de la classe
*/
class f_APropos ;


/*
* Inclusion des fichiers EN-TÊTE
*/
#include <QDialog>
#include <QWidget>


/*
* Déclaration de la classe
*/
namespace Ui {
class f_APropos ;
}



class f_APropos : public QDialog
{
    Q_OBJECT

    public :
        explicit f_APropos(QWidget *parent = 0) ;
        ~f_APropos() ;


    private :
        Ui::f_APropos * ui ;

    private slots :
        void     on_actionValider_accepted() ;
        void     on_actionValider_rejected() ;
};

#endif // __ChoixProfil_H
