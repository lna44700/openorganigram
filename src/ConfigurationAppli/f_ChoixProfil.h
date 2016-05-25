// f_ChoixProfil.h     1.0     01/03/2016   Guitton Lucas

#ifndef __ChoixProfil_H
#define __ChoixProfil_H


/*
* Déclaration anticipée de la classe
*/
class f_ChoixProfil ;


/*
* Inclusion des fichiers EN-TÊTE
*/
#include <QDialog>
#include <QWidget>


/*
* Déclaration de la classe
*/
namespace Ui {
class f_ChoixProfil ;
}

class f_ChoixProfil : public QDialog
{
    Q_OBJECT

    signals :
        EnvoieProfil(QString ProfilActif) ;

    public :
        explicit f_ChoixProfil(QWidget *parent = 0) ;
        ~f_ChoixProfil() ;
        QString  Get_ProfilActif() ;

    private :
        Ui::f_ChoixProfil * ui ;
        QString ProfilActif ;
        int NombreUtilisateurs ;
        void     closeEvent(QCloseEvent *CloseEvent) ;

    private slots :
        void     on_actionValider_accepted() ;
        void     on_actionValider_rejected() ;

        //void on_CBx_Profil_activated(const QString &arg1);
        void on_CBx_Profil_currentTextChanged(const QString &arg1);
};

#endif // __ChoixProfil_H
