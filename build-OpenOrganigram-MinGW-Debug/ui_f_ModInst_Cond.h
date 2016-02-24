/********************************************************************************
** Form generated from reading UI file 'f_ModInst_Cond.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_COND_H
#define UI_F_MODINST_COND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_Cond
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *Grp_CondLog;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Lb_Verifier;
    QComboBox *CB_Variable;
    QComboBox *CB_Condition;
    QSpinBox *SB_Valeur;
    QGroupBox *Grp_CondMat;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Lb_Verifier_2;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ModInst_Cond)
    {
        if (f_ModInst_Cond->objectName().isEmpty())
            f_ModInst_Cond->setObjectName(QStringLiteral("f_ModInst_Cond"));
        f_ModInst_Cond->resize(341, 159);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Items/iconcond.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ModInst_Cond->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ModInst_Cond);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Grp_CondLog = new QGroupBox(f_ModInst_Cond);
        Grp_CondLog->setObjectName(QStringLiteral("Grp_CondLog"));
        Grp_CondLog->setFlat(false);
        Grp_CondLog->setCheckable(true);
        horizontalLayout_2 = new QHBoxLayout(Grp_CondLog);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Lb_Verifier = new QLabel(Grp_CondLog);
        Lb_Verifier->setObjectName(QStringLiteral("Lb_Verifier"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Lb_Verifier->sizePolicy().hasHeightForWidth());
        Lb_Verifier->setSizePolicy(sizePolicy);
        Lb_Verifier->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(Lb_Verifier);

        CB_Variable = new QComboBox(Grp_CondLog);
        CB_Variable->setObjectName(QStringLiteral("CB_Variable"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CB_Variable->sizePolicy().hasHeightForWidth());
        CB_Variable->setSizePolicy(sizePolicy1);
        CB_Variable->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(CB_Variable);

        CB_Condition = new QComboBox(Grp_CondLog);
        CB_Condition->setObjectName(QStringLiteral("CB_Condition"));
        CB_Condition->setMinimumSize(QSize(150, 0));
        CB_Condition->setMaxVisibleItems(10);

        horizontalLayout_2->addWidget(CB_Condition);

        SB_Valeur = new QSpinBox(Grp_CondLog);
        SB_Valeur->setObjectName(QStringLiteral("SB_Valeur"));
        SB_Valeur->setMaximumSize(QSize(90, 16777215));
        SB_Valeur->setMaximum(65535);

        horizontalLayout_2->addWidget(SB_Valeur);

        SB_Valeur->raise();
        CB_Variable->raise();
        CB_Condition->raise();
        Lb_Verifier->raise();

        verticalLayout->addWidget(Grp_CondLog);

        Grp_CondMat = new QGroupBox(f_ModInst_Cond);
        Grp_CondMat->setObjectName(QStringLiteral("Grp_CondMat"));
        Grp_CondMat->setEnabled(true);
        Grp_CondMat->setCheckable(true);
        Grp_CondMat->setChecked(false);
        horizontalLayout_3 = new QHBoxLayout(Grp_CondMat);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Lb_Verifier_2 = new QLabel(Grp_CondMat);
        Lb_Verifier_2->setObjectName(QStringLiteral("Lb_Verifier_2"));
        sizePolicy.setHeightForWidth(Lb_Verifier_2->sizePolicy().hasHeightForWidth());
        Lb_Verifier_2->setSizePolicy(sizePolicy);
        Lb_Verifier_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(Lb_Verifier_2);

        comboBox = new QComboBox(Grp_CondMat);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout->addWidget(Grp_CondMat);

        buttonBox = new QDialogButtonBox(f_ModInst_Cond);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_ModInst_Cond);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ModInst_Cond, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ModInst_Cond, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_ModInst_Cond);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_Cond)
    {
        f_ModInst_Cond->setWindowTitle(QApplication::translate("f_ModInst_Cond", "Modification de la condition", 0));
        Grp_CondLog->setTitle(QApplication::translate("f_ModInst_Cond", "Condition logicielle", 0));
        Lb_Verifier->setText(QApplication::translate("f_ModInst_Cond", "V\303\251rifier si", 0));
        CB_Variable->clear();
        CB_Variable->insertItems(0, QStringList()
         << QApplication::translate("f_ModInst_Cond", "A", 0)
         << QApplication::translate("f_ModInst_Cond", "B", 0)
         << QApplication::translate("f_ModInst_Cond", "C", 0)
         << QApplication::translate("f_ModInst_Cond", "D", 0)
         << QApplication::translate("f_ModInst_Cond", "E", 0)
         << QApplication::translate("f_ModInst_Cond", "F", 0)
         << QApplication::translate("f_ModInst_Cond", "G", 0)
         << QApplication::translate("f_ModInst_Cond", "H", 0)
         << QApplication::translate("f_ModInst_Cond", "I", 0)
         << QApplication::translate("f_ModInst_Cond", "J", 0)
         << QApplication::translate("f_ModInst_Cond", "K", 0)
         << QApplication::translate("f_ModInst_Cond", "L", 0)
         << QApplication::translate("f_ModInst_Cond", "M", 0)
         << QApplication::translate("f_ModInst_Cond", "N", 0)
         << QApplication::translate("f_ModInst_Cond", "O", 0)
         << QApplication::translate("f_ModInst_Cond", "P", 0)
         << QApplication::translate("f_ModInst_Cond", "Q", 0)
         << QApplication::translate("f_ModInst_Cond", "R", 0)
         << QApplication::translate("f_ModInst_Cond", "S", 0)
         << QApplication::translate("f_ModInst_Cond", "T", 0)
         << QApplication::translate("f_ModInst_Cond", "U", 0)
         << QApplication::translate("f_ModInst_Cond", "V", 0)
         << QApplication::translate("f_ModInst_Cond", "W", 0)
         << QApplication::translate("f_ModInst_Cond", "X", 0)
         << QApplication::translate("f_ModInst_Cond", "Y", 0)
         << QApplication::translate("f_ModInst_Cond", "Z", 0)
        );
        CB_Condition->clear();
        CB_Condition->insertItems(0, QStringList()
         << QApplication::translate("f_ModInst_Cond", "est \303\251gual \303\240 ( = )", 0)
         << QApplication::translate("f_ModInst_Cond", "est strictement sup\303\251rieur \303\240 ( > )", 0)
         << QApplication::translate("f_ModInst_Cond", "est strictement inf\303\251rieur \303\240 ( < )", 0)
         << QApplication::translate("f_ModInst_Cond", "est superieur ou \303\251gual \303\240 ( >= )", 0)
         << QApplication::translate("f_ModInst_Cond", "est inf\303\251rieur ou egual \303\240 ( <= )", 0)
         << QApplication::translate("f_ModInst_Cond", "est diff\303\251rent de ( <> )", 0)
        );
        Grp_CondMat->setTitle(QApplication::translate("f_ModInst_Cond", "Condition mat\303\251rielle", 0));
        Lb_Verifier_2->setText(QApplication::translate("f_ModInst_Cond", "V\303\251rifier si", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_Cond: public Ui_f_ModInst_Cond {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_COND_H
