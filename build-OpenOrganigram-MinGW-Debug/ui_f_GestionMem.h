/********************************************************************************
** Form generated from reading UI file 'f_GestionMem.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_GESTIONMEM_H
#define UI_F_GESTIONMEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_GestionMem
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *Configuration;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *LB_SlotBank3;
    QComboBox *CB_Bank2;
    QComboBox *CB_Bank3;
    QLabel *LB_SlotBank2;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *LB_SlotBank1;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *CB_Bank0;
    QComboBox *CB_Bank1;
    QLabel *label_7;
    QLabel *LB_SlotBank0;
    QPushButton *Btn_Format_Arduino;
    QPushButton *Btn_Format_Bank0;
    QPushButton *Btn_Format_Bank1;
    QPushButton *Btn_Format_Bank2;
    QPushButton *Btn_Format_Bank3;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QCommandLinkButton *ActiverAutorun;
    QCommandLinkButton *DesactiverAutorun;
    QCommandLinkButton *LancerProg;
    QSpacerItem *verticalSpacer;
    QWidget *Visualisation;
    QVBoxLayout *verticalLayout_3;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Btn_Actualiser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *f_GestionMem)
    {
        if (f_GestionMem->objectName().isEmpty())
            f_GestionMem->setObjectName(QStringLiteral("f_GestionMem"));
        f_GestionMem->resize(527, 396);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/sim.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_GestionMem->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(f_GestionMem);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(f_GestionMem);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Configuration = new QWidget();
        Configuration->setObjectName(QStringLiteral("Configuration"));
        verticalLayout_2 = new QVBoxLayout(Configuration);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(Configuration);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        LB_SlotBank3 = new QLabel(Configuration);
        LB_SlotBank3->setObjectName(QStringLiteral("LB_SlotBank3"));

        gridLayout->addWidget(LB_SlotBank3, 4, 2, 1, 1);

        CB_Bank2 = new QComboBox(Configuration);
        CB_Bank2->setObjectName(QStringLiteral("CB_Bank2"));

        gridLayout->addWidget(CB_Bank2, 3, 1, 1, 1);

        CB_Bank3 = new QComboBox(Configuration);
        CB_Bank3->setObjectName(QStringLiteral("CB_Bank3"));

        gridLayout->addWidget(CB_Bank3, 4, 1, 1, 1);

        LB_SlotBank2 = new QLabel(Configuration);
        LB_SlotBank2->setObjectName(QStringLiteral("LB_SlotBank2"));

        gridLayout->addWidget(LB_SlotBank2, 3, 2, 1, 1);

        label_3 = new QLabel(Configuration);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(Configuration);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 1, 1, 1);

        LB_SlotBank1 = new QLabel(Configuration);
        LB_SlotBank1->setObjectName(QStringLiteral("LB_SlotBank1"));

        gridLayout->addWidget(LB_SlotBank1, 2, 2, 1, 1);

        label_2 = new QLabel(Configuration);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(Configuration);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        CB_Bank0 = new QComboBox(Configuration);
        CB_Bank0->setObjectName(QStringLiteral("CB_Bank0"));

        gridLayout->addWidget(CB_Bank0, 1, 1, 1, 1);

        CB_Bank1 = new QComboBox(Configuration);
        CB_Bank1->setObjectName(QStringLiteral("CB_Bank1"));

        gridLayout->addWidget(CB_Bank1, 2, 1, 1, 1);

        label_7 = new QLabel(Configuration);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        LB_SlotBank0 = new QLabel(Configuration);
        LB_SlotBank0->setObjectName(QStringLiteral("LB_SlotBank0"));

        gridLayout->addWidget(LB_SlotBank0, 1, 2, 1, 1);

        Btn_Format_Arduino = new QPushButton(Configuration);
        Btn_Format_Arduino->setObjectName(QStringLiteral("Btn_Format_Arduino"));
        Btn_Format_Arduino->setEnabled(true);

        gridLayout->addWidget(Btn_Format_Arduino, 0, 3, 1, 1);

        Btn_Format_Bank0 = new QPushButton(Configuration);
        Btn_Format_Bank0->setObjectName(QStringLiteral("Btn_Format_Bank0"));
        Btn_Format_Bank0->setEnabled(false);

        gridLayout->addWidget(Btn_Format_Bank0, 1, 3, 1, 1);

        Btn_Format_Bank1 = new QPushButton(Configuration);
        Btn_Format_Bank1->setObjectName(QStringLiteral("Btn_Format_Bank1"));
        Btn_Format_Bank1->setEnabled(false);

        gridLayout->addWidget(Btn_Format_Bank1, 2, 3, 1, 1);

        Btn_Format_Bank2 = new QPushButton(Configuration);
        Btn_Format_Bank2->setObjectName(QStringLiteral("Btn_Format_Bank2"));
        Btn_Format_Bank2->setEnabled(false);

        gridLayout->addWidget(Btn_Format_Bank2, 3, 3, 1, 1);

        Btn_Format_Bank3 = new QPushButton(Configuration);
        Btn_Format_Bank3->setObjectName(QStringLiteral("Btn_Format_Bank3"));
        Btn_Format_Bank3->setEnabled(false);

        gridLayout->addWidget(Btn_Format_Bank3, 4, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        line = new QFrame(Configuration);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        ActiverAutorun = new QCommandLinkButton(Configuration);
        ActiverAutorun->setObjectName(QStringLiteral("ActiverAutorun"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/App/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActiverAutorun->setIcon(icon1);

        horizontalLayout->addWidget(ActiverAutorun);

        DesactiverAutorun = new QCommandLinkButton(Configuration);
        DesactiverAutorun->setObjectName(QStringLiteral("DesactiverAutorun"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/App/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DesactiverAutorun->setIcon(icon2);

        horizontalLayout->addWidget(DesactiverAutorun);


        verticalLayout_2->addLayout(horizontalLayout);

        LancerProg = new QCommandLinkButton(Configuration);
        LancerProg->setObjectName(QStringLiteral("LancerProg"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/App/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        LancerProg->setIcon(icon3);

        verticalLayout_2->addWidget(LancerProg);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(Configuration, QString());
        Visualisation = new QWidget();
        Visualisation->setObjectName(QStringLiteral("Visualisation"));
        verticalLayout_3 = new QVBoxLayout(Visualisation);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listView = new QListView(Visualisation);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(listView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Btn_Actualiser = new QPushButton(Visualisation);
        Btn_Actualiser->setObjectName(QStringLiteral("Btn_Actualiser"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/App/actualier.png"), QSize(), QIcon::Normal, QIcon::Off);
        Btn_Actualiser->setIcon(icon4);
        Btn_Actualiser->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(Btn_Actualiser);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(Visualisation, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(f_GestionMem);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(f_GestionMem);
        QObject::connect(buttonBox, SIGNAL(accepted()), f_GestionMem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), f_GestionMem, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(f_GestionMem);
    } // setupUi

    void retranslateUi(QDialog *f_GestionMem)
    {
        f_GestionMem->setWindowTitle(QApplication::translate("f_GestionMem", "Gestion de m\303\251moire", 0));
        label_5->setText(QApplication::translate("f_GestionMem", "Banque n\302\260 3 :", 0));
        LB_SlotBank3->setText(QString());
        CB_Bank2->clear();
        CB_Bank2->insertItems(0, QStringList()
         << QApplication::translate("f_GestionMem", "Aucune", 0)
         << QApplication::translate("f_GestionMem", "24C32", 0)
         << QApplication::translate("f_GestionMem", "24C64", 0)
         << QApplication::translate("f_GestionMem", "24C128", 0)
         << QApplication::translate("f_GestionMem", "24C256", 0)
        );
        CB_Bank3->clear();
        CB_Bank3->insertItems(0, QStringList()
         << QApplication::translate("f_GestionMem", "Aucune", 0)
         << QApplication::translate("f_GestionMem", "24C32", 0)
         << QApplication::translate("f_GestionMem", "24C64", 0)
         << QApplication::translate("f_GestionMem", "24C128", 0)
         << QApplication::translate("f_GestionMem", "24C256", 0)
        );
        LB_SlotBank2->setText(QString());
        label_3->setText(QApplication::translate("f_GestionMem", "Banque n\302\260 1 :", 0));
        label_6->setText(QApplication::translate("f_GestionMem", "M\303\251moire interne de l'Arduino", 0));
        LB_SlotBank1->setText(QString());
        label_2->setText(QApplication::translate("f_GestionMem", "Banque n\302\260 0 : ", 0));
        label_4->setText(QApplication::translate("f_GestionMem", "Banque n\302\260 2 :", 0));
        CB_Bank0->clear();
        CB_Bank0->insertItems(0, QStringList()
         << QApplication::translate("f_GestionMem", "Aucune", 0)
         << QApplication::translate("f_GestionMem", "24C32", 0)
         << QApplication::translate("f_GestionMem", "24C64", 0)
         << QApplication::translate("f_GestionMem", "24C128", 0)
         << QApplication::translate("f_GestionMem", "24C256", 0)
        );
        CB_Bank1->clear();
        CB_Bank1->insertItems(0, QStringList()
         << QApplication::translate("f_GestionMem", "Aucune", 0)
         << QApplication::translate("f_GestionMem", "24C32", 0)
         << QApplication::translate("f_GestionMem", "24C64", 0)
         << QApplication::translate("f_GestionMem", "24C128", 0)
         << QApplication::translate("f_GestionMem", "24C256", 0)
        );
        label_7->setText(QApplication::translate("f_GestionMem", "1 slot m\303\251moire", 0));
        LB_SlotBank0->setText(QString());
        Btn_Format_Arduino->setText(QApplication::translate("f_GestionMem", "Formater", 0));
        Btn_Format_Bank0->setText(QApplication::translate("f_GestionMem", "Formater", 0));
        Btn_Format_Bank1->setText(QApplication::translate("f_GestionMem", "Formater", 0));
        Btn_Format_Bank2->setText(QApplication::translate("f_GestionMem", "Formater", 0));
        Btn_Format_Bank3->setText(QApplication::translate("f_GestionMem", "Formater", 0));
        ActiverAutorun->setText(QApplication::translate("f_GestionMem", "Activer l'ex\303\251cution auto", 0));
        DesactiverAutorun->setText(QApplication::translate("f_GestionMem", "D\303\251sactiver l'ex\303\251cution auto", 0));
        LancerProg->setText(QApplication::translate("f_GestionMem", "Lancer les programmes compil\303\251", 0));
        tabWidget->setTabText(tabWidget->indexOf(Configuration), QApplication::translate("f_GestionMem", "Configuration", 0));
        Btn_Actualiser->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Visualisation), QApplication::translate("f_GestionMem", "Visualisation", 0));
    } // retranslateUi

};

namespace Ui {
    class f_GestionMem: public Ui_f_GestionMem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_GESTIONMEM_H
