/********************************************************************************
** Form generated from reading UI file 'f_SaisieNom.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_SAISIENOM_H
#define UI_F_SAISIENOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_SaisieNom
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Lb_Texte;
    QLineEdit *LE_Saisie;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_SaisieNom)
    {
        if (f_SaisieNom->objectName().isEmpty())
            f_SaisieNom->setObjectName(QStringLiteral("f_SaisieNom"));
        f_SaisieNom->resize(300, 70);
        f_SaisieNom->setMinimumSize(QSize(300, 70));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/App/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_SaisieNom->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(f_SaisieNom);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Lb_Texte = new QLabel(f_SaisieNom);
        Lb_Texte->setObjectName(QStringLiteral("Lb_Texte"));

        verticalLayout->addWidget(Lb_Texte);

        LE_Saisie = new QLineEdit(f_SaisieNom);
        LE_Saisie->setObjectName(QStringLiteral("LE_Saisie"));

        verticalLayout->addWidget(LE_Saisie);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(f_SaisieNom);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(f_SaisieNom);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_SaisieNom, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_SaisieNom, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_SaisieNom);
    } // setupUi

    void retranslateUi(QDialog *f_SaisieNom)
    {
        f_SaisieNom->setWindowTitle(QApplication::translate("f_SaisieNom", "Saisie de nom", 0));
        Lb_Texte->setText(QApplication::translate("f_SaisieNom", "Nom : ", 0));
    } // retranslateUi

};

namespace Ui {
    class f_SaisieNom: public Ui_f_SaisieNom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_SAISIENOM_H
