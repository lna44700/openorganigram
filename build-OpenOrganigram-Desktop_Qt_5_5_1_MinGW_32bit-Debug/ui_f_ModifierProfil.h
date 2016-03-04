/********************************************************************************
** Form generated from reading UI file 'f_ModifierProfil.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODIFIERPROFIL_H
#define UI_F_MODIFIERPROFIL_H

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

class Ui_f_ModifierProfil
{
public:
    QDialogButtonBox *BtBx_Valider;
    QFrame *Fr_Gestion;
    QRadioButton *RBt_OGestionProfil;
    QRadioButton *RBt_NGestionProfil;
    QLabel *Lb_Gestion;
    QLabel *Lb_AncienMdP;
    QLineEdit *LE_AncienMdP;
    QFrame *Fr_Config;
    QRadioButton *RBt_OConfig;
    QRadioButton *RBt_NConfig;
    QLabel *Lb_Config;
    QFrame *Fr_ProfilDefaut;
    QLabel *Lb_ProfilDefaut;
    QRadioButton *RBt_OProfilDefaut;
    QRadioButton *RBt_NProfilDefaut;
    QCheckBox *CkBx_NormeOrga;
    QFrame *Fr_NvMdP;
    QLineEdit *LE_NvMdP;
    QLabel *Lb_NvMdP;
    QLabel *Lb_ConfimMdP;
    QLineEdit *LE_ConfirmMdP;

    void setupUi(QDialog *f_ModifierProfil)
    {
        if (f_ModifierProfil->objectName().isEmpty())
            f_ModifierProfil->setObjectName(QStringLiteral("f_ModifierProfil"));
        f_ModifierProfil->resize(300, 370);
        BtBx_Valider = new QDialogButtonBox(f_ModifierProfil);
        BtBx_Valider->setObjectName(QStringLiteral("BtBx_Valider"));
        BtBx_Valider->setGeometry(QRect(70, 330, 160, 30));
        BtBx_Valider->setOrientation(Qt::Horizontal);
        BtBx_Valider->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Fr_Gestion = new QFrame(f_ModifierProfil);
        Fr_Gestion->setObjectName(QStringLiteral("Fr_Gestion"));
        Fr_Gestion->setGeometry(QRect(30, 190, 260, 15));
        Fr_Gestion->setFrameShape(QFrame::StyledPanel);
        Fr_Gestion->setFrameShadow(QFrame::Raised);
        RBt_OGestionProfil = new QRadioButton(Fr_Gestion);
        RBt_OGestionProfil->setObjectName(QStringLiteral("RBt_OGestionProfil"));
        RBt_OGestionProfil->setGeometry(QRect(130, 0, 82, 17));
        RBt_NGestionProfil = new QRadioButton(Fr_Gestion);
        RBt_NGestionProfil->setObjectName(QStringLiteral("RBt_NGestionProfil"));
        RBt_NGestionProfil->setGeometry(QRect(200, 0, 82, 17));
        Lb_Gestion = new QLabel(Fr_Gestion);
        Lb_Gestion->setObjectName(QStringLiteral("Lb_Gestion"));
        Lb_Gestion->setGeometry(QRect(0, 0, 100, 15));
        Lb_AncienMdP = new QLabel(f_ModifierProfil);
        Lb_AncienMdP->setObjectName(QStringLiteral("Lb_AncienMdP"));
        Lb_AncienMdP->setGeometry(QRect(30, 10, 110, 15));
        LE_AncienMdP = new QLineEdit(f_ModifierProfil);
        LE_AncienMdP->setObjectName(QStringLiteral("LE_AncienMdP"));
        LE_AncienMdP->setGeometry(QRect(160, 10, 110, 20));
        Fr_Config = new QFrame(f_ModifierProfil);
        Fr_Config->setObjectName(QStringLiteral("Fr_Config"));
        Fr_Config->setGeometry(QRect(30, 140, 260, 15));
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
        Fr_ProfilDefaut = new QFrame(f_ModifierProfil);
        Fr_ProfilDefaut->setObjectName(QStringLiteral("Fr_ProfilDefaut"));
        Fr_ProfilDefaut->setGeometry(QRect(30, 240, 260, 15));
        Fr_ProfilDefaut->setFrameShape(QFrame::StyledPanel);
        Fr_ProfilDefaut->setFrameShadow(QFrame::Raised);
        Lb_ProfilDefaut = new QLabel(Fr_ProfilDefaut);
        Lb_ProfilDefaut->setObjectName(QStringLiteral("Lb_ProfilDefaut"));
        Lb_ProfilDefaut->setGeometry(QRect(0, 0, 90, 15));
        RBt_OProfilDefaut = new QRadioButton(Fr_ProfilDefaut);
        RBt_OProfilDefaut->setObjectName(QStringLiteral("RBt_OProfilDefaut"));
        RBt_OProfilDefaut->setGeometry(QRect(130, 0, 82, 17));
        RBt_NProfilDefaut = new QRadioButton(Fr_ProfilDefaut);
        RBt_NProfilDefaut->setObjectName(QStringLiteral("RBt_NProfilDefaut"));
        RBt_NProfilDefaut->setGeometry(QRect(200, 0, 82, 17));
        CkBx_NormeOrga = new QCheckBox(f_ModifierProfil);
        CkBx_NormeOrga->setObjectName(QStringLiteral("CkBx_NormeOrga"));
        CkBx_NormeOrga->setGeometry(QRect(30, 290, 200, 15));
        Fr_NvMdP = new QFrame(f_ModifierProfil);
        Fr_NvMdP->setObjectName(QStringLiteral("Fr_NvMdP"));
        Fr_NvMdP->setGeometry(QRect(20, 40, 261, 80));
        Fr_NvMdP->setFrameShape(QFrame::StyledPanel);
        Fr_NvMdP->setFrameShadow(QFrame::Raised);
        LE_NvMdP = new QLineEdit(Fr_NvMdP);
        LE_NvMdP->setObjectName(QStringLiteral("LE_NvMdP"));
        LE_NvMdP->setGeometry(QRect(140, 10, 110, 20));
        Lb_NvMdP = new QLabel(Fr_NvMdP);
        Lb_NvMdP->setObjectName(QStringLiteral("Lb_NvMdP"));
        Lb_NvMdP->setGeometry(QRect(10, 10, 120, 15));
        Lb_ConfimMdP = new QLabel(Fr_NvMdP);
        Lb_ConfimMdP->setObjectName(QStringLiteral("Lb_ConfimMdP"));
        Lb_ConfimMdP->setGeometry(QRect(10, 50, 120, 15));
        LE_ConfirmMdP = new QLineEdit(Fr_NvMdP);
        LE_ConfirmMdP->setObjectName(QStringLiteral("LE_ConfirmMdP"));
        LE_ConfirmMdP->setGeometry(QRect(140, 50, 110, 20));

        retranslateUi(f_ModifierProfil);

        QMetaObject::connectSlotsByName(f_ModifierProfil);
    } // setupUi

    void retranslateUi(QDialog *f_ModifierProfil)
    {
        f_ModifierProfil->setWindowTitle(QApplication::translate("f_ModifierProfil", "Dialog", 0));
        RBt_OGestionProfil->setText(QApplication::translate("f_ModifierProfil", "Oui", 0));
        RBt_NGestionProfil->setText(QApplication::translate("f_ModifierProfil", "Non", 0));
        Lb_Gestion->setText(QApplication::translate("f_ModifierProfil", "Gestion de profill :", 0));
        Lb_AncienMdP->setText(QApplication::translate("f_ModifierProfil", "Ancien mot de passe :", 0));
        RBt_OConfig->setText(QApplication::translate("f_ModifierProfil", "Oui", 0));
        RBt_NConfig->setText(QApplication::translate("f_ModifierProfil", "Non", 0));
        Lb_Config->setText(QApplication::translate("f_ModifierProfil", "Configuration :", 0));
        Lb_ProfilDefaut->setText(QApplication::translate("f_ModifierProfil", "Profil par d\303\251faut :", 0));
        RBt_OProfilDefaut->setText(QApplication::translate("f_ModifierProfil", "Oui", 0));
        RBt_NProfilDefaut->setText(QApplication::translate("f_ModifierProfil", "Non", 0));
        CkBx_NormeOrga->setText(QApplication::translate("f_ModifierProfil", "Nouvelle norme d'organigramme ", 0));
        Lb_NvMdP->setText(QApplication::translate("f_ModifierProfil", "Nouveau mot de passe :", 0));
        Lb_ConfimMdP->setText(QApplication::translate("f_ModifierProfil", "Confirmer mot de passe :", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModifierProfil: public Ui_f_ModifierProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODIFIERPROFIL_H
