/********************************************************************************
** Form generated from reading UI file 'f_DefinirActionsEtTests.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_DEFINIRACTIONSETTESTS_H
#define UI_F_DEFINIRACTIONSETTESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_DefinirActionsEtTests
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *LE_Nom;
    QLabel *LB_Texte;
    QFormLayout *formLayout;
    QLabel *LB_Module;
    QComboBox *CB_Module;
    QLabel *LB_ARU;
    QLineEdit *LE_ARU;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Btn_Action;
    QPushButton *Btn_SupprAct;
    QListView *LV_Action;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Btn_Test;
    QPushButton *Btn_SupprTst;
    QListView *LV_Test;
    QDialogButtonBox *Btn_Ok;

    void setupUi(QDialog *f_DefinirActionsEtTests)
    {
        if (f_DefinirActionsEtTests->objectName().isEmpty())
            f_DefinirActionsEtTests->setObjectName(QStringLiteral("f_DefinirActionsEtTests"));
        f_DefinirActionsEtTests->resize(487, 594);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_DefinirActionsEtTests->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_DefinirActionsEtTests);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LE_Nom = new QLineEdit(f_DefinirActionsEtTests);
        LE_Nom->setObjectName(QStringLiteral("LE_Nom"));

        verticalLayout->addWidget(LE_Nom);

        LB_Texte = new QLabel(f_DefinirActionsEtTests);
        LB_Texte->setObjectName(QStringLiteral("LB_Texte"));

        verticalLayout->addWidget(LB_Texte);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        LB_Module = new QLabel(f_DefinirActionsEtTests);
        LB_Module->setObjectName(QStringLiteral("LB_Module"));

        formLayout->setWidget(0, QFormLayout::LabelRole, LB_Module);

        CB_Module = new QComboBox(f_DefinirActionsEtTests);
        CB_Module->setObjectName(QStringLiteral("CB_Module"));

        formLayout->setWidget(0, QFormLayout::FieldRole, CB_Module);

        LB_ARU = new QLabel(f_DefinirActionsEtTests);
        LB_ARU->setObjectName(QStringLiteral("LB_ARU"));

        formLayout->setWidget(1, QFormLayout::LabelRole, LB_ARU);

        LE_ARU = new QLineEdit(f_DefinirActionsEtTests);
        LE_ARU->setObjectName(QStringLiteral("LE_ARU"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LE_ARU);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        Btn_Action = new QPushButton(f_DefinirActionsEtTests);
        Btn_Action->setObjectName(QStringLiteral("Btn_Action"));

        horizontalLayout->addWidget(Btn_Action);

        Btn_SupprAct = new QPushButton(f_DefinirActionsEtTests);
        Btn_SupprAct->setObjectName(QStringLiteral("Btn_SupprAct"));

        horizontalLayout->addWidget(Btn_SupprAct);


        verticalLayout_2->addLayout(horizontalLayout);

        LV_Action = new QListView(f_DefinirActionsEtTests);
        LV_Action->setObjectName(QStringLiteral("LV_Action"));
        LV_Action->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(LV_Action);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 0, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        Btn_Test = new QPushButton(f_DefinirActionsEtTests);
        Btn_Test->setObjectName(QStringLiteral("Btn_Test"));

        horizontalLayout_3->addWidget(Btn_Test);

        Btn_SupprTst = new QPushButton(f_DefinirActionsEtTests);
        Btn_SupprTst->setObjectName(QStringLiteral("Btn_SupprTst"));

        horizontalLayout_3->addWidget(Btn_SupprTst);


        verticalLayout_3->addLayout(horizontalLayout_3);

        LV_Test = new QListView(f_DefinirActionsEtTests);
        LV_Test->setObjectName(QStringLiteral("LV_Test"));
        LV_Test->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(LV_Test);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_2);

        Btn_Ok = new QDialogButtonBox(f_DefinirActionsEtTests);
        Btn_Ok->setObjectName(QStringLiteral("Btn_Ok"));
        Btn_Ok->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(Btn_Ok);


        retranslateUi(f_DefinirActionsEtTests);

        QMetaObject::connectSlotsByName(f_DefinirActionsEtTests);
    } // setupUi

    void retranslateUi(QDialog *f_DefinirActionsEtTests)
    {
        f_DefinirActionsEtTests->setWindowTitle(QApplication::translate("f_DefinirActionsEtTests", "D\303\251finition des actions et des tests", 0));
        LE_Nom->setPlaceholderText(QApplication::translate("f_DefinirActionsEtTests", "Nom de l'\303\251l\303\251ment", 0));
        LB_Texte->setText(QApplication::translate("f_DefinirActionsEtTests", "TextLabel", 0));
        LB_Module->setText(QApplication::translate("f_DefinirActionsEtTests", "Module", 0));
        LB_ARU->setText(QApplication::translate("f_DefinirActionsEtTests", "Code d'arr\303\252t d'urgence", 0));
        Btn_Action->setText(QApplication::translate("f_DefinirActionsEtTests", "Ajouter une action", 0));
        Btn_SupprAct->setText(QApplication::translate("f_DefinirActionsEtTests", "Suppr une action", 0));
        Btn_Test->setText(QApplication::translate("f_DefinirActionsEtTests", "Ajouter un test", 0));
        Btn_SupprTst->setText(QApplication::translate("f_DefinirActionsEtTests", "Suppr une action", 0));
    } // retranslateUi

};

namespace Ui {
    class f_DefinirActionsEtTests: public Ui_f_DefinirActionsEtTests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_DEFINIRACTIONSETTESTS_H
