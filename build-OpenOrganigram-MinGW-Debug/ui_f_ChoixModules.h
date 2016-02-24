/********************************************************************************
** Form generated from reading UI file 'f_ChoixModules.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CHOIXMODULES_H
#define UI_F_CHOIXMODULES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ChoixModules
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Btn_Ajouter;
    QPushButton *Btn_Suppr;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Prec;
    QPushButton *Btn_Suiv;

    void setupUi(QDialog *f_ChoixModules)
    {
        if (f_ChoixModules->objectName().isEmpty())
            f_ChoixModules->setObjectName(QStringLiteral("f_ChoixModules"));
        f_ChoixModules->resize(355, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ChoixModules->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ChoixModules);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(f_ChoixModules);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listView = new QListView(f_ChoixModules);
        listView->setObjectName(QStringLiteral("listView"));

        horizontalLayout->addWidget(listView);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        Btn_Ajouter = new QPushButton(f_ChoixModules);
        Btn_Ajouter->setObjectName(QStringLiteral("Btn_Ajouter"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/App/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Ajouter->setIcon(icon1);
        Btn_Ajouter->setFlat(false);

        verticalLayout_2->addWidget(Btn_Ajouter);

        Btn_Suppr = new QPushButton(f_ChoixModules);
        Btn_Suppr->setObjectName(QStringLiteral("Btn_Suppr"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/App/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Suppr->setIcon(icon2);

        verticalLayout_2->addWidget(Btn_Suppr);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Btn_Prec = new QPushButton(f_ChoixModules);
        Btn_Prec->setObjectName(QStringLiteral("Btn_Prec"));

        horizontalLayout_2->addWidget(Btn_Prec);

        Btn_Suiv = new QPushButton(f_ChoixModules);
        Btn_Suiv->setObjectName(QStringLiteral("Btn_Suiv"));
        Btn_Suiv->setEnabled(false);

        horizontalLayout_2->addWidget(Btn_Suiv);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(f_ChoixModules);

        QMetaObject::connectSlotsByName(f_ChoixModules);
    } // setupUi

    void retranslateUi(QDialog *f_ChoixModules)
    {
        f_ChoixModules->setWindowTitle(QApplication::translate("f_ChoixModules", "Choix des modules", 0));
        label->setText(QApplication::translate("f_ChoixModules", "Choisissez vos modules : ", 0));
        Btn_Ajouter->setText(QApplication::translate("f_ChoixModules", "Ajouter", 0));
        Btn_Suppr->setText(QApplication::translate("f_ChoixModules", "Supprimer", 0));
        Btn_Prec->setText(QApplication::translate("f_ChoixModules", "Pr\303\251c\303\251dent", 0));
        Btn_Suiv->setText(QApplication::translate("f_ChoixModules", "Suivant", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ChoixModules: public Ui_f_ChoixModules {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CHOIXMODULES_H
