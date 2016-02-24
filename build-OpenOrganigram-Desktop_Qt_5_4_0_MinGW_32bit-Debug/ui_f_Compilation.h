/********************************************************************************
** Form generated from reading UI file 'f_Compilation.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_COMPILATION_H
#define UI_F_COMPILATION_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_Compilation
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *Grp_Module;
    QHBoxLayout *horizontalLayout;
    QComboBox *CB_Module;
    QPushButton *Btn_Compiler;
    QGroupBox *Grp_Slot;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *LB_Taille;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *CB_Slot;
    QPushButton *Btn_Envoyer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_Compilation)
    {
        if (f_Compilation->objectName().isEmpty())
            f_Compilation->setObjectName(QStringLiteral("f_Compilation"));
        f_Compilation->resize(400, 197);
        verticalLayout = new QVBoxLayout(f_Compilation);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Grp_Module = new QGroupBox(f_Compilation);
        Grp_Module->setObjectName(QStringLiteral("Grp_Module"));
        horizontalLayout = new QHBoxLayout(Grp_Module);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CB_Module = new QComboBox(Grp_Module);
        CB_Module->setObjectName(QStringLiteral("CB_Module"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CB_Module->sizePolicy().hasHeightForWidth());
        CB_Module->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(CB_Module);

        Btn_Compiler = new QPushButton(Grp_Module);
        Btn_Compiler->setObjectName(QStringLiteral("Btn_Compiler"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/build.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Compiler->setIcon(icon);

        horizontalLayout->addWidget(Btn_Compiler);


        verticalLayout->addWidget(Grp_Module);

        Grp_Slot = new QGroupBox(f_Compilation);
        Grp_Slot->setObjectName(QStringLiteral("Grp_Slot"));
        Grp_Slot->setEnabled(false);
        verticalLayout_2 = new QVBoxLayout(Grp_Slot);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(Grp_Slot);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        LB_Taille = new QLabel(Grp_Slot);
        LB_Taille->setObjectName(QStringLiteral("LB_Taille"));

        horizontalLayout_2->addWidget(LB_Taille);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, -1);
        CB_Slot = new QComboBox(Grp_Slot);
        CB_Slot->setObjectName(QStringLiteral("CB_Slot"));
        sizePolicy.setHeightForWidth(CB_Slot->sizePolicy().hasHeightForWidth());
        CB_Slot->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(CB_Slot);

        Btn_Envoyer = new QPushButton(Grp_Slot);
        Btn_Envoyer->setObjectName(QStringLiteral("Btn_Envoyer"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/App/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Envoyer->setIcon(icon1);

        horizontalLayout_3->addWidget(Btn_Envoyer);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(Grp_Slot);

        buttonBox = new QDialogButtonBox(f_Compilation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_Compilation);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_Compilation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_Compilation, SLOT(reject()));

        QMetaObject::connectSlotsByName(f_Compilation);
    } // setupUi

    void retranslateUi(QDialog *f_Compilation)
    {
        f_Compilation->setWindowTitle(QApplication::translate("f_Compilation", "Dialog", 0));
        Grp_Module->setTitle(QApplication::translate("f_Compilation", "Choix du module", 0));
        Btn_Compiler->setText(QApplication::translate("f_Compilation", "Compiler", 0));
        Grp_Slot->setTitle(QApplication::translate("f_Compilation", "Choix du l'emplacement m\303\251moire", 0));
        label->setText(QApplication::translate("f_Compilation", "Taille du module compil\303\251 : ", 0));
        LB_Taille->setText(QString());
        Btn_Envoyer->setText(QApplication::translate("f_Compilation", "Envoyer", 0));
    } // retranslateUi

};

namespace Ui {
    class f_Compilation: public Ui_f_Compilation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_COMPILATION_H
