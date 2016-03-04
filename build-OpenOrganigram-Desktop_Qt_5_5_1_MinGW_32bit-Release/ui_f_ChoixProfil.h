/********************************************************************************
** Form generated from reading UI file 'f_ChoixProfil.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CHOIXPROFIL_H
#define UI_F_CHOIXPROFIL_H

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

class Ui_f_ChoixProfil
{
public:
    QLabel *Lb_MdP;
    QLineEdit *LE_MdP;
    QLabel *Lb_Profil;
    QDialogButtonBox *actionValider;
    QComboBox *Cb_Bx_Profil;

    void setupUi(QDialog *f_ChoixProfil)
    {
        if (f_ChoixProfil->objectName().isEmpty())
            f_ChoixProfil->setObjectName(QStringLiteral("f_ChoixProfil"));
        f_ChoixProfil->resize(320, 200);
        Lb_MdP = new QLabel(f_ChoixProfil);
        Lb_MdP->setObjectName(QStringLiteral("Lb_MdP"));
        Lb_MdP->setGeometry(QRect(40, 85, 70, 15));
        LE_MdP = new QLineEdit(f_ChoixProfil);
        LE_MdP->setObjectName(QStringLiteral("LE_MdP"));
        LE_MdP->setGeometry(QRect(140, 85, 110, 20));
        Lb_Profil = new QLabel(f_ChoixProfil);
        Lb_Profil->setObjectName(QStringLiteral("Lb_Profil"));
        Lb_Profil->setGeometry(QRect(40, 25, 70, 15));
        actionValider = new QDialogButtonBox(f_ChoixProfil);
        actionValider->setObjectName(QStringLiteral("actionValider"));
        actionValider->setGeometry(QRect(80, 145, 160, 40));
        actionValider->setOrientation(Qt::Horizontal);
        actionValider->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Cb_Bx_Profil = new QComboBox(f_ChoixProfil);
        Cb_Bx_Profil->setObjectName(QStringLiteral("Cb_Bx_Profil"));
        Cb_Bx_Profil->setGeometry(QRect(110, 20, 160, 25));

        retranslateUi(f_ChoixProfil);

        QMetaObject::connectSlotsByName(f_ChoixProfil);
    } // setupUi

    void retranslateUi(QDialog *f_ChoixProfil)
    {
        f_ChoixProfil->setWindowTitle(QApplication::translate("f_ChoixProfil", "Dialog", 0));
        Lb_MdP->setText(QApplication::translate("f_ChoixProfil", "Mot de passe :", 0));
        Lb_Profil->setText(QApplication::translate("f_ChoixProfil", "Profil :", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ChoixProfil: public Ui_f_ChoixProfil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CHOIXPROFIL_H
