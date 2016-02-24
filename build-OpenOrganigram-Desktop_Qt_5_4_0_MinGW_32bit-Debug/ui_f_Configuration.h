/********************************************************************************
** Form generated from reading UI file 'f_Configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CONFIGURATION_H
#define UI_F_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_f_Configuration
{
public:
    QDialogButtonBox *Bt_Validation;
    QLineEdit *LE_PortServeur;
    QLabel *Lb_Port;

    void setupUi(QDialog *f_Configuration)
    {
        if (f_Configuration->objectName().isEmpty())
            f_Configuration->setObjectName(QStringLiteral("f_Configuration"));
        f_Configuration->resize(290, 130);
        Bt_Validation = new QDialogButtonBox(f_Configuration);
        Bt_Validation->setObjectName(QStringLiteral("Bt_Validation"));
        Bt_Validation->setGeometry(QRect(70, 90, 150, 25));
        Bt_Validation->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        LE_PortServeur = new QLineEdit(f_Configuration);
        LE_PortServeur->setObjectName(QStringLiteral("LE_PortServeur"));
        LE_PortServeur->setGeometry(QRect(150, 40, 110, 20));
        Lb_Port = new QLabel(f_Configuration);
        Lb_Port->setObjectName(QStringLiteral("Lb_Port"));
        Lb_Port->setGeometry(QRect(40, 40, 100, 15));

        retranslateUi(f_Configuration);

        QMetaObject::connectSlotsByName(f_Configuration);
    } // setupUi

    void retranslateUi(QDialog *f_Configuration)
    {
        f_Configuration->setWindowTitle(QApplication::translate("f_Configuration", "Dialog", 0));
        Lb_Port->setText(QApplication::translate("f_Configuration", "Port du serveur :", 0));
    } // retranslateUi

};

namespace Ui {
    class f_Configuration: public Ui_f_Configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CONFIGURATION_H
