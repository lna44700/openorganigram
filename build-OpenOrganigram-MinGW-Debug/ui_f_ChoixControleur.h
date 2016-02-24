/********************************************************************************
** Form generated from reading UI file 'f_ChoixControleur.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CHOIXCONTROLEUR_H
#define UI_F_CHOIXCONTROLEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ChoixControleur
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *LE_NomProjet;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *CB_Controleur;
    QLabel *LB_Controleur;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Prec;
    QPushButton *Btn_Suiv;

    void setupUi(QDialog *f_ChoixControleur)
    {
        if (f_ChoixControleur->objectName().isEmpty())
            f_ChoixControleur->setObjectName(QStringLiteral("f_ChoixControleur"));
        f_ChoixControleur->resize(400, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(f_ChoixControleur->sizePolicy().hasHeightForWidth());
        f_ChoixControleur->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ChoixControleur->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ChoixControleur);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(f_ChoixControleur);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        LE_NomProjet = new QLineEdit(f_ChoixControleur);
        LE_NomProjet->setObjectName(QStringLiteral("LE_NomProjet"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LE_NomProjet);


        verticalLayout->addLayout(formLayout);

        groupBox = new QGroupBox(f_ChoixControleur);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        CB_Controleur = new QComboBox(groupBox);
        CB_Controleur->setObjectName(QStringLiteral("CB_Controleur"));

        verticalLayout_2->addWidget(CB_Controleur);

        LB_Controleur = new QLabel(groupBox);
        LB_Controleur->setObjectName(QStringLiteral("LB_Controleur"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LB_Controleur->sizePolicy().hasHeightForWidth());
        LB_Controleur->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(LB_Controleur);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Btn_Prec = new QPushButton(f_ChoixControleur);
        Btn_Prec->setObjectName(QStringLiteral("Btn_Prec"));
        Btn_Prec->setEnabled(false);
        Btn_Prec->setAutoDefault(true);

        horizontalLayout->addWidget(Btn_Prec);

        Btn_Suiv = new QPushButton(f_ChoixControleur);
        Btn_Suiv->setObjectName(QStringLiteral("Btn_Suiv"));
        Btn_Suiv->setDefault(true);

        horizontalLayout->addWidget(Btn_Suiv);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(f_ChoixControleur);

        QMetaObject::connectSlotsByName(f_ChoixControleur);
    } // setupUi

    void retranslateUi(QDialog *f_ChoixControleur)
    {
        f_ChoixControleur->setWindowTitle(QApplication::translate("f_ChoixControleur", "Etape 1 - Choix du contr\303\264leur", 0));
        label->setText(QApplication::translate("f_ChoixControleur", "Nom du projet", 0));
        groupBox->setTitle(QApplication::translate("f_ChoixControleur", "Choix du contr\303\264leur", 0));
        LB_Controleur->setText(QString());
        Btn_Prec->setText(QApplication::translate("f_ChoixControleur", "Pr\303\251c\303\251dent", 0));
        Btn_Suiv->setText(QApplication::translate("f_ChoixControleur", "Suivant", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ChoixControleur: public Ui_f_ChoixControleur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CHOIXCONTROLEUR_H
