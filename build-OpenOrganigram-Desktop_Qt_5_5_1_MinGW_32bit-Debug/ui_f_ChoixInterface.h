/********************************************************************************
** Form generated from reading UI file 'f_ChoixInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_CHOIXINTERFACE_H
#define UI_F_CHOIXINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_f_ChoixInterface
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *LB_Explic;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *LB_IntDispo;
    QListView *LV_Dispo;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QPushButton *Btn_Installer;
    QPushButton *Btn_supprimer;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *LB_IntInst;
    QListView *LV_Inst;
    QLabel *LB_Explic2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *LB_Apercu;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Btn_Prec;
    QPushButton *Btn_Suiv;

    void setupUi(QDialog *f_ChoixInterface)
    {
        if (f_ChoixInterface->objectName().isEmpty())
            f_ChoixInterface->setObjectName(QStringLiteral("f_ChoixInterface"));
        f_ChoixInterface->resize(635, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(f_ChoixInterface->sizePolicy().hasHeightForWidth());
        f_ChoixInterface->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_ChoixInterface->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_ChoixInterface);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        LB_Explic = new QLabel(f_ChoixInterface);
        LB_Explic->setObjectName(QStringLiteral("LB_Explic"));

        verticalLayout->addWidget(LB_Explic);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        LB_IntDispo = new QLabel(f_ChoixInterface);
        LB_IntDispo->setObjectName(QStringLiteral("LB_IntDispo"));

        verticalLayout_2->addWidget(LB_IntDispo);

        LV_Dispo = new QListView(f_ChoixInterface);
        LV_Dispo->setObjectName(QStringLiteral("LV_Dispo"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LV_Dispo->sizePolicy().hasHeightForWidth());
        LV_Dispo->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(LV_Dispo);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        Btn_Installer = new QPushButton(f_ChoixInterface);
        Btn_Installer->setObjectName(QStringLiteral("Btn_Installer"));
        Btn_Installer->setEnabled(false);

        verticalLayout_4->addWidget(Btn_Installer);

        Btn_supprimer = new QPushButton(f_ChoixInterface);
        Btn_supprimer->setObjectName(QStringLiteral("Btn_supprimer"));
        Btn_supprimer->setEnabled(false);

        verticalLayout_4->addWidget(Btn_supprimer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        LB_IntInst = new QLabel(f_ChoixInterface);
        LB_IntInst->setObjectName(QStringLiteral("LB_IntInst"));

        verticalLayout_3->addWidget(LB_IntInst);

        LV_Inst = new QListView(f_ChoixInterface);
        LV_Inst->setObjectName(QStringLiteral("LV_Inst"));

        verticalLayout_3->addWidget(LV_Inst);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        LB_Explic2 = new QLabel(f_ChoixInterface);
        LB_Explic2->setObjectName(QStringLiteral("LB_Explic2"));

        verticalLayout->addWidget(LB_Explic2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        frame = new QFrame(f_ChoixInterface);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LB_Apercu = new QLabel(frame);
        LB_Apercu->setObjectName(QStringLiteral("LB_Apercu"));

        gridLayout->addWidget(LB_Apercu, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(frame);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        Btn_Prec = new QPushButton(f_ChoixInterface);
        Btn_Prec->setObjectName(QStringLiteral("Btn_Prec"));

        horizontalLayout_3->addWidget(Btn_Prec);

        Btn_Suiv = new QPushButton(f_ChoixInterface);
        Btn_Suiv->setObjectName(QStringLiteral("Btn_Suiv"));

        horizontalLayout_3->addWidget(Btn_Suiv);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(f_ChoixInterface);

        Btn_Suiv->setDefault(true);


        QMetaObject::connectSlotsByName(f_ChoixInterface);
    } // setupUi

    void retranslateUi(QDialog *f_ChoixInterface)
    {
        f_ChoixInterface->setWindowTitle(QApplication::translate("f_ChoixInterface", "Choix de l'interface", 0));
        LB_Explic->setText(QApplication::translate("f_ChoixInterface", "Choisissez les interfaces \303\240 ajouter \303\240 la maquette", 0));
        LB_IntDispo->setText(QApplication::translate("f_ChoixInterface", "Interfaces disponibles", 0));
        Btn_Installer->setText(QApplication::translate("f_ChoixInterface", "Installer >", 0));
        Btn_supprimer->setText(QApplication::translate("f_ChoixInterface", "< Supprimer", 0));
        LB_IntInst->setText(QApplication::translate("f_ChoixInterface", "Interfaces install\303\251es", 0));
        LB_Explic2->setText(QApplication::translate("f_ChoixInterface", "Aper\303\247u de l'interface selectionn\303\251e \303\240 droite :", 0));
        LB_Apercu->setText(QString());
        Btn_Prec->setText(QApplication::translate("f_ChoixInterface", "Pr\303\251c\303\251dent", 0));
        Btn_Suiv->setText(QApplication::translate("f_ChoixInterface", "Suivant", 0));
    } // retranslateUi

};

namespace Ui {
    class f_ChoixInterface: public Ui_f_ChoixInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_CHOIXINTERFACE_H
