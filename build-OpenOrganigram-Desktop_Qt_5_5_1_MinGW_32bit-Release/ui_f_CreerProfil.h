/********************************************************************************
** Form generated from reading UI file 'f_CreerProfil.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CREERPROFIL_H
#define UI_F_CREERPROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_f_CreerProfil
{
public:
    QLabel *Lb_MdP;
    QLineEdit *LE_Mdp;
    QLineEdit *LE_NomProfil;
    QLabel *Lb_NomProfil;
    QDialogButtonBox *BtBx_Valider;
    QFrame *Fr_Config;
    QRadioButton *RBt_OConfig;
    QRadioButton *RBt_NConfig;
    QLabel *Lb_Config;
    QFrame *Fr_Gestion;
    QRadioButton *RBt_OProfil;
    QRadioButton *RBt_NProfil;
    QLabel *Lb_Gestion;
    QFrame *Fr_ProfilDefaut;
    QLabel *Lb_ProfilDefaut;
    QRadioButton *RBt_ODefaut;
    QRadioButton *RBt_NDefaut;
    QCheckBox *CkBx_NormeOrga;

    void setupUi(QDialog *f_CreerProfil)
    {
        if (f_CreerProfil->objectName().isEmpty())
            f_CreerProfil->setObjectName(QStringLiteral("f_CreerProfil"));
        f_CreerProfil->resize(330, 345);
        f_CreerProfil->setMinimumSize(QSize(0, 0));
        f_CreerProfil->setMaximumSize(QSize(16777215, 16777215));
        Lb_MdP = new QLabel(f_CreerProfil);
        Lb_MdP->setObjectName(QStringLiteral("Lb_MdP"));
        Lb_MdP->setGeometry(QRect(50, 70, 90, 15));
        LE_Mdp = new QLineEdit(f_CreerProfil);
        LE_Mdp->setObjectName(QStringLiteral("LE_Mdp"));
        LE_Mdp->setGeometry(QRect(180, 68, 110, 20));
        LE_NomProfil = new QLineEdit(f_CreerProfil);
        LE_NomProfil->setObjectName(QStringLiteral("LE_NomProfil"));
        LE_NomProfil->setGeometry(QRect(180, 18, 110, 20));
        Lb_NomProfil = new QLabel(f_CreerProfil);
        Lb_NomProfil->setObjectName(QStringLiteral("Lb_NomProfil"));
        Lb_NomProfil->setGeometry(QRect(50, 20, 90, 15));
        BtBx_Valider = new QDialogButtonBox(f_CreerProfil);
        BtBx_Valider->setObjectName(QStringLiteral("BtBx_Valider"));
        BtBx_Valider->setGeometry(QRect(80, 310, 160, 30));
        BtBx_Valider->setOrientation(Qt::Horizontal);
        BtBx_Valider->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Fr_Config = new QFrame(f_CreerProfil);
        Fr_Config->setObjectName(QStringLiteral("Fr_Config"));
        Fr_Config->setGeometry(QRect(50, 120, 260, 15));
        Fr_Config->setFrameShape(QFrame::StyledPanel);
        Fr_Config->setFrameShadow(QFrame::Raised);
        RBt_OConfig = new QRadioButton(Fr_Config);
        RBt_OConfig->setObjectName(QStringLiteral("RBt_OConfig"));
        RBt_OConfig->setGeometry(QRect(130, 0, 82, 17));
        RBt_NConfig = new QRadioButton(Fr_Config);
        RBt_NConfig->setObjectName(QStringLiteral("RBt_NConfig"));
        RBt_NConfig->setGeometry(QRect(200, 0, 82, 17));
        Lb_Config = new QLabel(Fr_Config);
        Lb_Config->setObjectName(QStringLiteral("Lb_Config"));
        Lb_Config->setGeometry(QRect(0, 0, 80, 15));
        Fr_Gestion = new QFrame(f_CreerProfil);
        Fr_Gestion->setObjectName(QStringLiteral("Fr_Gestion"));
        Fr_Gestion->setGeometry(QRect(50, 170, 260, 15));
        Fr_Gestion->setFrameShape(QFrame::StyledPanel);
        Fr_Gestion->setFrameShadow(QFrame::Raised);
        RBt_OProfil = new QRadioButton(Fr_Gestion);
        RBt_OProfil->setObjectName(QStringLiteral("RBt_OProfil"));
        RBt_OProfil->setGeometry(QRect(130, 0, 82, 17));
        RBt_NProfil = new QRadioButton(Fr_Gestion);
        RBt_NProfil->setObjectName(QStringLiteral("RBt_NProfil"));
        RBt_NProfil->setGeometry(QRect(200, 0, 82, 17));
        Lb_Gestion = new QLabel(Fr_Gestion);
        Lb_Gestion->setObjectName(QStringLiteral("Lb_Gestion"));
        Lb_Gestion->setGeometry(QRect(0, 0, 100, 15));
        Fr_ProfilDefaut = new QFrame(f_CreerProfil);
        Fr_ProfilDefaut->setObjectName(QStringLiteral("Fr_ProfilDefaut"));
        Fr_ProfilDefaut->setGeometry(QRect(50, 220, 260, 15));
        Fr_ProfilDefaut->setFrameShape(QFrame::StyledPanel);
        Fr_ProfilDefaut->setFrameShadow(QFrame::Raised);
        Lb_ProfilDefaut = new QLabel(Fr_ProfilDefaut);
        Lb_ProfilDefaut->setObjectName(QStringLiteral("Lb_ProfilDefaut"));
        Lb_ProfilDefaut->setGeometry(QRect(0, 0, 90, 15));
        RBt_ODefaut = new QRadioButton(Fr_ProfilDefaut);
        RBt_ODefaut->setObjectName(QStringLiteral("RBt_ODefaut"));
        RBt_ODefaut->setGeometry(QRect(130, 0, 82, 17));
        RBt_NDefaut = new QRadioButton(Fr_ProfilDefaut);
        RBt_NDefaut->setObjectName(QStringLiteral("RBt_NDefaut"));
        RBt_NDefaut->setGeometry(QRect(200, 0, 82, 17));
        CkBx_NormeOrga = new QCheckBox(f_CreerProfil);
        CkBx_NormeOrga->setObjectName(QStringLiteral("CkBx_NormeOrga"));
        CkBx_NormeOrga->setGeometry(QRect(50, 270, 221, 17));

        retranslateUi(f_CreerProfil);

        QMetaObject::connectSlotsByName(f_CreerProfil);
    } // setupUi

    void retranslateUi(QDialog *f_CreerProfil)
    {
        f_CreerProfil->setWindowTitle(QApplication::translate("f_CreerProfil", "Dialog", 0));
        Lb_MdP->setText(QApplication::translate("f_CreerProfil", "Mot de passe :", 0));
        Lb_NomProfil->setText(QApplication::translate("f_CreerProfil", "Nom du profil :", 0));
        RBt_OConfig->setText(QApplication::translate("f_CreerProfil", "Oui", 0));
        RBt_NConfig->setText(QApplication::translate("f_CreerProfil", "Non", 0));
        Lb_Config->setText(QApplication::translate("f_CreerProfil", "Configuration :", 0));
        RBt_OProfil->setText(QApplication::translate("f_CreerProfil", "Oui", 0));
        RBt_NProfil->setText(QApplication::translate("f_CreerProfil", "Non", 0));
        Lb_Gestion->setText(QApplication::translate("f_CreerProfil", "Gestion de profill :", 0));
        Lb_ProfilDefaut->setText(QApplication::translate("f_CreerProfil", "Profil par d\303\251faut :", 0));
        RBt_ODefaut->setText(QApplication::translate("f_CreerProfil", "Oui", 0));
        RBt_NDefaut->setText(QApplication::translate("f_CreerProfil", "Non", 0));
        CkBx_NormeOrga->setText(QApplication::translate("f_CreerProfil", "Affichage nouvelle norme d'orgagniramme", 0));
    } // retranslateUi

};

namespace Ui {
    class f_CreerProfil: public Ui_f_CreerProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CREERPROFIL_H
