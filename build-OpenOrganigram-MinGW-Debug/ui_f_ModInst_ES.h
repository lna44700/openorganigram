/********************************************************************************
** Form generated from reading UI file 'f_ModInst_ES.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_ES_H
#define UI_F_MODINST_ES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_ES
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *Grp_Liste;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QGroupBox *Grp_Commande;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ModInst_ES)
    {
        if (f_ModInst_ES->objectName().isEmpty())
            f_ModInst_ES->setObjectName(QStringLiteral("f_ModInst_ES"));
        f_ModInst_ES->resize(237, 159);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Items/icones.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ModInst_ES->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ModInst_ES);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Grp_Liste = new QGroupBox(f_ModInst_ES);
        Grp_Liste->setObjectName(QStringLiteral("Grp_Liste"));
        Grp_Liste->setFlat(false);
        Grp_Liste->setCheckable(true);
        verticalLayout_2 = new QVBoxLayout(Grp_Liste);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        comboBox = new QComboBox(Grp_Liste);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);


        verticalLayout->addWidget(Grp_Liste);

        Grp_Commande = new QGroupBox(f_ModInst_ES);
        Grp_Commande->setObjectName(QStringLiteral("Grp_Commande"));
        Grp_Commande->setCheckable(true);
        Grp_Commande->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(Grp_Commande);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lineEdit = new QLineEdit(Grp_Commande);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_3->addWidget(lineEdit);


        verticalLayout->addWidget(Grp_Commande);

        buttonBox = new QDialogButtonBox(f_ModInst_ES);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_ModInst_ES);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ModInst_ES, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ModInst_ES, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_ModInst_ES);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_ES)
    {
        f_ModInst_ES->setWindowTitle(QApplication::translate("f_ModInst_ES", "Configuration d'entr\303\251e/sortie", 0));
        Grp_Liste->setTitle(QApplication::translate("f_ModInst_ES", "Actions Pr\303\251d\303\251finies", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("f_ModInst_ES", "Entr\303\251e/Sortie", 0)
        );
        Grp_Commande->setTitle(QApplication::translate("f_ModInst_ES", "Commande Brute", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_ES: public Ui_f_ModInst_ES {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_ES_H
