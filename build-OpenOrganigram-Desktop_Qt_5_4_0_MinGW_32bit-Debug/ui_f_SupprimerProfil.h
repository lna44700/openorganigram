/********************************************************************************
** Form generated from reading UI file 'f_SupprimerProfil.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_SUPPRIMERPROFIL_H
#define UI_F_SUPPRIMERPROFIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_f_SupprimerProfil
{
public:
    QLabel *Lb_Profil;
    QComboBox *Cb_Bx_Profil;
    QLabel *Lb_MDPAdmin;
    QLineEdit *LE_MDPAdmin;
    QDialogButtonBox *Bt_Bx_Valider;
    QLabel *Lb_MdP;
    QLineEdit *LE_MdP;

    void setupUi(QDialog *f_SupprimerProfil)
    {
        if (f_SupprimerProfil->objectName().isEmpty())
            f_SupprimerProfil->setObjectName(QStringLiteral("f_SupprimerProfil"));
        f_SupprimerProfil->resize(320, 215);
        Lb_Profil = new QLabel(f_SupprimerProfil);
        Lb_Profil->setObjectName(QStringLiteral("Lb_Profil"));
        Lb_Profil->setGeometry(QRect(30, 30, 100, 20));
        Cb_Bx_Profil = new QComboBox(f_SupprimerProfil);
        Cb_Bx_Profil->setObjectName(QStringLiteral("Cb_Bx_Profil"));
        Cb_Bx_Profil->setGeometry(QRect(160, 30, 150, 20));
        Lb_MDPAdmin = new QLabel(f_SupprimerProfil);
        Lb_MDPAdmin->setObjectName(QStringLiteral("Lb_MDPAdmin"));
        Lb_MDPAdmin->setGeometry(QRect(30, 80, 111, 20));
        Lb_MDPAdmin->setWordWrap(false);
        LE_MDPAdmin = new QLineEdit(f_SupprimerProfil);
        LE_MDPAdmin->setObjectName(QStringLiteral("LE_MDPAdmin"));
        LE_MDPAdmin->setGeometry(QRect(160, 80, 115, 20));
        Bt_Bx_Valider = new QDialogButtonBox(f_SupprimerProfil);
        Bt_Bx_Valider->setObjectName(QStringLiteral("Bt_Bx_Valider"));
        Bt_Bx_Valider->setGeometry(QRect(80, 180, 155, 25));
        Bt_Bx_Valider->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Lb_MdP = new QLabel(f_SupprimerProfil);
        Lb_MdP->setObjectName(QStringLiteral("Lb_MdP"));
        Lb_MdP->setGeometry(QRect(30, 130, 115, 15));
        LE_MdP = new QLineEdit(f_SupprimerProfil);
        LE_MdP->setObjectName(QStringLiteral("LE_MdP"));
        LE_MdP->setGeometry(QRect(160, 130, 115, 20));

        retranslateUi(f_SupprimerProfil);

        QMetaObject::connectSlotsByName(f_SupprimerProfil);
    } // setupUi

    void retranslateUi(QDialog *f_SupprimerProfil)
    {
        f_SupprimerProfil->setWindowTitle(QApplication::translate("f_SupprimerProfil", "Dialog", 0));
        Lb_Profil->setText(QApplication::translate("f_SupprimerProfil", "Profil \303\240 supprimer :", 0));
        Lb_MDPAdmin->setText(QApplication::translate("f_SupprimerProfil", "Mot de passe admin :", 0));
        Lb_MdP->setText(QApplication::translate("f_SupprimerProfil", "Mot de passe du profil :", 0));
    } // retranslateUi

};

namespace Ui {
    class f_SupprimerProfil: public Ui_f_SupprimerProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_SUPPRIMERPROFIL_H
