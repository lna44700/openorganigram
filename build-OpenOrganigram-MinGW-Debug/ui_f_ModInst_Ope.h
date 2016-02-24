/********************************************************************************
** Form generated from reading UI file 'f_ModInst_Ope.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MODINST_OPE_H
#define UI_F_MODINST_OPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ModInst_Ope
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *CB_Variable;
    QLabel *label;
    QGroupBox *GrpB_ChoixAction;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *Radio_Affecter;
    QRadioButton *Radio_Ajouter;
    QRadioButton *Radio_Soustraire;
    QSpacerItem *verticalSpacer_3;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QRadioButton *Radio_Inc;
    QRadioButton *Radio_Dec;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_5;
    QSpinBox *SB_Valeur;
    QSpacerItem *verticalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_ModInst_Ope)
    {
        if (f_ModInst_Ope->objectName().isEmpty())
            f_ModInst_Ope->setObjectName(QStringLiteral("f_ModInst_Ope"));
        f_ModInst_Ope->resize(400, 220);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Items/iconop.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ModInst_Ope->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ModInst_Ope);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(f_ModInst_Ope);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        CB_Variable = new QComboBox(f_ModInst_Ope);
        CB_Variable->setObjectName(QStringLiteral("CB_Variable"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CB_Variable->sizePolicy().hasHeightForWidth());
        CB_Variable->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(CB_Variable);

        label = new QLabel(f_ModInst_Ope);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);


        horizontalLayout->addLayout(horizontalLayout_2);

        GrpB_ChoixAction = new QGroupBox(f_ModInst_Ope);
        GrpB_ChoixAction->setObjectName(QStringLiteral("GrpB_ChoixAction"));
        horizontalLayout_3 = new QHBoxLayout(GrpB_ChoixAction);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Radio_Affecter = new QRadioButton(GrpB_ChoixAction);
        Radio_Affecter->setObjectName(QStringLiteral("Radio_Affecter"));
        Radio_Affecter->setChecked(true);

        verticalLayout_3->addWidget(Radio_Affecter);

        Radio_Ajouter = new QRadioButton(GrpB_ChoixAction);
        Radio_Ajouter->setObjectName(QStringLiteral("Radio_Ajouter"));

        verticalLayout_3->addWidget(Radio_Ajouter);

        Radio_Soustraire = new QRadioButton(GrpB_ChoixAction);
        Radio_Soustraire->setObjectName(QStringLiteral("Radio_Soustraire"));

        verticalLayout_3->addWidget(Radio_Soustraire);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        line = new QFrame(GrpB_ChoixAction);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        Radio_Inc = new QRadioButton(GrpB_ChoixAction);
        Radio_Inc->setObjectName(QStringLiteral("Radio_Inc"));

        verticalLayout_3->addWidget(Radio_Inc);

        Radio_Dec = new QRadioButton(GrpB_ChoixAction);
        Radio_Dec->setObjectName(QStringLiteral("Radio_Dec"));

        verticalLayout_3->addWidget(Radio_Dec);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_5);

        SB_Valeur = new QSpinBox(GrpB_ChoixAction);
        SB_Valeur->setObjectName(QStringLiteral("SB_Valeur"));
        SB_Valeur->setMaximum(65025);

        verticalLayout_4->addWidget(SB_Valeur);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout->addWidget(GrpB_ChoixAction);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(f_ModInst_Ope);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_ModInst_Ope);
        QObject::connect(Radio_Affecter, SIGNAL(toggled(bool)), SB_Valeur, SLOT(setEnabled(bool)));
        QObject::connect(Radio_Ajouter, SIGNAL(toggled(bool)), SB_Valeur, SLOT(setEnabled(bool)));
        QObject::connect(Radio_Dec, SIGNAL(toggled(bool)), SB_Valeur, SLOT(setDisabled(bool)));
        QObject::connect(Radio_Inc, SIGNAL(toggled(bool)), SB_Valeur, SLOT(setDisabled(bool)));
        QObject::connect(Radio_Soustraire, SIGNAL(toggled(bool)), SB_Valeur, SLOT(setEnabled(bool)));
        QObject::connect(buttonBox, SIGNAL(accepted()), f_ModInst_Ope, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_ModInst_Ope, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_ModInst_Ope);
    } // setupUi

    void retranslateUi(QDialog *f_ModInst_Ope)
    {
        f_ModInst_Ope->setWindowTitle(QApplication::translate("f_ModInst_Ope", "Modification de l'op\303\251ration", 0));
        label_2->setText(QApplication::translate("f_ModInst_Ope", "Prendre la valeur de ", 0));
        CB_Variable->clear();
        CB_Variable->insertItems(0, QStringList()
         << QApplication::translate("f_ModInst_Ope", "A", 0)
         << QApplication::translate("f_ModInst_Ope", "B", 0)
         << QApplication::translate("f_ModInst_Ope", "C", 0)
         << QApplication::translate("f_ModInst_Ope", "D", 0)
         << QApplication::translate("f_ModInst_Ope", "E", 0)
         << QApplication::translate("f_ModInst_Ope", "F", 0)
         << QApplication::translate("f_ModInst_Ope", "G", 0)
         << QApplication::translate("f_ModInst_Ope", "H", 0)
         << QApplication::translate("f_ModInst_Ope", "I", 0)
         << QApplication::translate("f_ModInst_Ope", "J", 0)
         << QApplication::translate("f_ModInst_Ope", "K", 0)
         << QApplication::translate("f_ModInst_Ope", "L", 0)
         << QApplication::translate("f_ModInst_Ope", "M", 0)
         << QApplication::translate("f_ModInst_Ope", "N", 0)
         << QApplication::translate("f_ModInst_Ope", "O", 0)
         << QApplication::translate("f_ModInst_Ope", "P", 0)
         << QApplication::translate("f_ModInst_Ope", "Q", 0)
         << QApplication::translate("f_ModInst_Ope", "R", 0)
         << QApplication::translate("f_ModInst_Ope", "S", 0)
         << QApplication::translate("f_ModInst_Ope", "T", 0)
         << QApplication::translate("f_ModInst_Ope", "U", 0)
         << QApplication::translate("f_ModInst_Ope", "V", 0)
         << QApplication::translate("f_ModInst_Ope", "W", 0)
         << QApplication::translate("f_ModInst_Ope", "X", 0)
         << QApplication::translate("f_ModInst_Ope", "Y", 0)
         << QApplication::translate("f_ModInst_Ope", "Z", 0)
        );
        label->setText(QApplication::translate("f_ModInst_Ope", "et : ", 0));
        GrpB_ChoixAction->setTitle(QApplication::translate("f_ModInst_Ope", "Action", 0));
        Radio_Affecter->setText(QApplication::translate("f_ModInst_Ope", "lui affecter la valeur", 0));
        Radio_Ajouter->setText(QApplication::translate("f_ModInst_Ope", "lui ajouter", 0));
        Radio_Soustraire->setText(QApplication::translate("f_ModInst_Ope", "lui soustraire", 0));
        Radio_Inc->setText(QApplication::translate("f_ModInst_Ope", "l'incr\303\251menter", 0));
        Radio_Dec->setText(QApplication::translate("f_ModInst_Ope", "la d\303\251cr\303\251menter", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ModInst_Ope: public Ui_f_ModInst_Ope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MODINST_OPE_H
