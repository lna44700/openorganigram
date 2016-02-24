/********************************************************************************
** Form generated from reading UI file 'f_EditerActionTest.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_EDITERACTIONTEST_H
#define UI_F_EDITERACTIONTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_EditerActionTest
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *LE_Nom;
    QLabel *label_2;
    QLineEdit *LE_Commade;
    QCheckBox *CB_Activer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_EditerActionTest)
    {
        if (f_EditerActionTest->objectName().isEmpty())
            f_EditerActionTest->setObjectName(QStringLiteral("f_EditerActionTest"));
        f_EditerActionTest->resize(370, 128);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_EditerActionTest->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_EditerActionTest);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(f_EditerActionTest);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        LE_Nom = new QLineEdit(f_EditerActionTest);
        LE_Nom->setObjectName(QStringLiteral("LE_Nom"));

        formLayout->setWidget(0, QFormLayout::FieldRole, LE_Nom);

        label_2 = new QLabel(f_EditerActionTest);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        LE_Commade = new QLineEdit(f_EditerActionTest);
        LE_Commade->setObjectName(QStringLiteral("LE_Commade"));

        formLayout->setWidget(1, QFormLayout::FieldRole, LE_Commade);

        CB_Activer = new QCheckBox(f_EditerActionTest);
        CB_Activer->setObjectName(QStringLiteral("CB_Activer"));
        CB_Activer->setChecked(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, CB_Activer);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(f_EditerActionTest);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_EditerActionTest);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_EditerActionTest, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_EditerActionTest, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_EditerActionTest);
    } // setupUi

    void retranslateUi(QDialog *f_EditerActionTest)
    {
        f_EditerActionTest->setWindowTitle(QApplication::translate("f_EditerActionTest", "D\303\251finition d'un nouvel \303\251l\303\251ment", 0));
        label->setText(QApplication::translate("f_EditerActionTest", "Nom :", 0));
        LE_Nom->setPlaceholderText(QApplication::translate("f_EditerActionTest", "Ex : \"Demarrer Moteur\" ou \"Btn enfonc\303\251?\"", 0));
        label_2->setText(QApplication::translate("f_EditerActionTest", "Commande : ", 0));
        LE_Commade->setPlaceholderText(QApplication::translate("f_EditerActionTest", "Ex : R** ou E**0", 0));
        CB_Activer->setText(QApplication::translate("f_EditerActionTest", "Activer", 0));
    } // retranslateUi

};

namespace Ui {
    class f_EditerActionTest: public Ui_f_EditerActionTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_EDITERACTIONTEST_H
