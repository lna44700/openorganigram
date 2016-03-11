/********************************************************************************
** Form generated from reading UI file 'f_MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F_MAINWINDOW_H
#define UI_F_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_f_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *actionOuvrir;
    QAction *actionFermer;
    QAction *actionQuitter;
    QAction *actionAide;
    QAction *actionA_propos;
    QAction *actionEnregistrer;
    QAction *actionEnregistrer_sous;
    QAction *actionExecuter;
    QAction *actionArreter;
    QAction *actionSV;
    QAction *actionDebug;
    QAction *actionJump;
    QAction *actionConvert;
    QAction *actionProjet;
    QAction *actionConfiguration;
    QAction *actionNouveauProfil;
    QAction *actionChoisirProfil;
    QAction *actionAgrandir;
    QAction *actionRetrecir;
    QAction *actionInterpreteur;
    QAction *actionSupprimerProfil;
    QAction *actionModifierProfil;
    QAction *actionGestionMem;
    QAction *actionImporter;
    QAction *actionServeur_Web;
    QAction *actionRedemarrer_la_maquette;
    QAction *actionGestion_des_composants_I2C;
    QAction *actionConfiguration_Application;
    QAction *actionCreer_profil;
    QAction *actionModifier_profil;
    QAction *actionSupprimer_profil;
    QAction *actionChanger_profil;
    QAction *actionDemarrerServeurWeb;
    QAction *actionArreterServeurWeb;
    QAction *actionRafraichirConfigurationServeurWeb;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAide;
    QMenu *menuAffichage;
    QMenu *menuOptions;
    QMenu *menuGestion_des_profils;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *DockBtn;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QDockWidget *DockProjet;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QDockWidget *DockSV;
    QWidget *dockWidgetContents_3;

    void setupUi(QMainWindow *f_MainWindow)
    {
        if (f_MainWindow->objectName().isEmpty())
            f_MainWindow->setObjectName(QStringLiteral("f_MainWindow"));
        f_MainWindow->resize(737, 576);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(f_MainWindow->sizePolicy().hasHeightForWidth());
        f_MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/App/icons_simple.png"), QSize(), QIcon::Normal, QIcon::Off);
        f_MainWindow->setWindowIcon(icon);
        actionNouveau = new QAction(f_MainWindow);
        actionNouveau->setObjectName(QStringLiteral("actionNouveau"));
        actionNouveau->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/App/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNouveau->setIcon(icon1);
        actionOuvrir = new QAction(f_MainWindow);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionOuvrir->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/App/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrir->setIcon(icon2);
        actionFermer = new QAction(f_MainWindow);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionFermer->setEnabled(false);
        actionQuitter = new QAction(f_MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionAide = new QAction(f_MainWindow);
        actionAide->setObjectName(QStringLiteral("actionAide"));
        actionA_propos = new QAction(f_MainWindow);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        actionEnregistrer = new QAction(f_MainWindow);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionEnregistrer->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/App/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer->setIcon(icon3);
        actionEnregistrer_sous = new QAction(f_MainWindow);
        actionEnregistrer_sous->setObjectName(QStringLiteral("actionEnregistrer_sous"));
        actionEnregistrer_sous->setEnabled(false);
        actionExecuter = new QAction(f_MainWindow);
        actionExecuter->setObjectName(QStringLiteral("actionExecuter"));
        actionExecuter->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/App/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExecuter->setIcon(icon4);
        actionArreter = new QAction(f_MainWindow);
        actionArreter->setObjectName(QStringLiteral("actionArreter"));
        actionArreter->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/App/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArreter->setIcon(icon5);
        actionSV = new QAction(f_MainWindow);
        actionSV->setObjectName(QStringLiteral("actionSV"));
        actionSV->setCheckable(true);
        actionSV->setChecked(false);
        actionSV->setEnabled(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Images/App/SupV.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSV->setIcon(icon6);
        actionDebug = new QAction(f_MainWindow);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        actionDebug->setCheckable(true);
        actionDebug->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Images/App/bug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebug->setIcon(icon7);
        actionJump = new QAction(f_MainWindow);
        actionJump->setObjectName(QStringLiteral("actionJump"));
        actionJump->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Images/App/jump.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionJump->setIcon(icon8);
        actionConvert = new QAction(f_MainWindow);
        actionConvert->setObjectName(QStringLiteral("actionConvert"));
        actionConvert->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Images/App/build.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConvert->setIcon(icon9);
        actionProjet = new QAction(f_MainWindow);
        actionProjet->setObjectName(QStringLiteral("actionProjet"));
        actionProjet->setCheckable(true);
        actionProjet->setChecked(true);
        actionConfiguration = new QAction(f_MainWindow);
        actionConfiguration->setObjectName(QStringLiteral("actionConfiguration"));
        actionNouveauProfil = new QAction(f_MainWindow);
        actionNouveauProfil->setObjectName(QStringLiteral("actionNouveauProfil"));
        actionChoisirProfil = new QAction(f_MainWindow);
        actionChoisirProfil->setObjectName(QStringLiteral("actionChoisirProfil"));
        actionAgrandir = new QAction(f_MainWindow);
        actionAgrandir->setObjectName(QStringLiteral("actionAgrandir"));
        actionAgrandir->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Images/App/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAgrandir->setIcon(icon10);
        actionRetrecir = new QAction(f_MainWindow);
        actionRetrecir->setObjectName(QStringLiteral("actionRetrecir"));
        actionRetrecir->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Images/App/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRetrecir->setIcon(icon11);
        actionInterpreteur = new QAction(f_MainWindow);
        actionInterpreteur->setObjectName(QStringLiteral("actionInterpreteur"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Images/App/prog.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInterpreteur->setIcon(icon12);
        actionSupprimerProfil = new QAction(f_MainWindow);
        actionSupprimerProfil->setObjectName(QStringLiteral("actionSupprimerProfil"));
        actionModifierProfil = new QAction(f_MainWindow);
        actionModifierProfil->setObjectName(QStringLiteral("actionModifierProfil"));
        actionGestionMem = new QAction(f_MainWindow);
        actionGestionMem->setObjectName(QStringLiteral("actionGestionMem"));
        actionGestionMem->setEnabled(true);
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Images/App/sim.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGestionMem->setIcon(icon13);
        actionImporter = new QAction(f_MainWindow);
        actionImporter->setObjectName(QStringLiteral("actionImporter"));
        actionServeur_Web = new QAction(f_MainWindow);
        actionServeur_Web->setObjectName(QStringLiteral("actionServeur_Web"));
        actionServeur_Web->setCheckable(true);
        actionRedemarrer_la_maquette = new QAction(f_MainWindow);
        actionRedemarrer_la_maquette->setObjectName(QStringLiteral("actionRedemarrer_la_maquette"));
        actionGestion_des_composants_I2C = new QAction(f_MainWindow);
        actionGestion_des_composants_I2C->setObjectName(QStringLiteral("actionGestion_des_composants_I2C"));
        actionConfiguration_Application = new QAction(f_MainWindow);
        actionConfiguration_Application->setObjectName(QStringLiteral("actionConfiguration_Application"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Images/App/configuration.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfiguration_Application->setIcon(icon14);
        actionCreer_profil = new QAction(f_MainWindow);
        actionCreer_profil->setObjectName(QStringLiteral("actionCreer_profil"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Images/App/ajouter-utilisateur-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreer_profil->setIcon(icon15);
        actionModifier_profil = new QAction(f_MainWindow);
        actionModifier_profil->setObjectName(QStringLiteral("actionModifier_profil"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Images/App/modifier-utilisateur-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModifier_profil->setIcon(icon16);
        actionSupprimer_profil = new QAction(f_MainWindow);
        actionSupprimer_profil->setObjectName(QStringLiteral("actionSupprimer_profil"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Images/App/supprimer-utilisateur-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupprimer_profil->setIcon(icon17);
        actionChanger_profil = new QAction(f_MainWindow);
        actionChanger_profil->setObjectName(QStringLiteral("actionChanger_profil"));
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/Images/App/changer-utilisateurs-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChanger_profil->setIcon(icon18);
        actionDemarrerServeurWeb = new QAction(f_MainWindow);
        actionDemarrerServeurWeb->setObjectName(QStringLiteral("actionDemarrerServeurWeb"));
        actionDemarrerServeurWeb->setEnabled(false);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/Images/App/webstart-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDemarrerServeurWeb->setIcon(icon19);
        actionArreterServeurWeb = new QAction(f_MainWindow);
        actionArreterServeurWeb->setObjectName(QStringLiteral("actionArreterServeurWeb"));
        actionArreterServeurWeb->setEnabled(false);
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/Images/App/webstop-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArreterServeurWeb->setIcon(icon20);
        actionRafraichirConfigurationServeurWeb = new QAction(f_MainWindow);
        actionRafraichirConfigurationServeurWeb->setObjectName(QStringLiteral("actionRafraichirConfigurationServeurWeb"));
        actionRafraichirConfigurationServeurWeb->setEnabled(false);
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/Images/App/webrefresh-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRafraichirConfigurationServeurWeb->setIcon(icon21);
        centralWidget = new QWidget(f_MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        f_MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(f_MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 737, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QStringLiteral("menuAffichage"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuGestion_des_profils = new QMenu(menuOptions);
        menuGestion_des_profils->setObjectName(QStringLiteral("menuGestion_des_profils"));
        menuGestion_des_profils->setToolTipDuration(0);
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/Images/App/gerer-utilisateurs-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuGestion_des_profils->setIcon(icon22);
        f_MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(f_MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setMovable(false);
        mainToolBar->setIconSize(QSize(16, 16));
        f_MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(f_MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        f_MainWindow->setStatusBar(statusBar);
        DockBtn = new QDockWidget(f_MainWindow);
        DockBtn->setObjectName(QStringLiteral("DockBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DockBtn->sizePolicy().hasHeightForWidth());
        DockBtn->setSizePolicy(sizePolicy2);
        DockBtn->setMinimumSize(QSize(150, 50));
        DockBtn->setMaximumSize(QSize(500, 524287));
        DockBtn->setContextMenuPolicy(Qt::NoContextMenu);
        DockBtn->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dockWidgetContents->sizePolicy().hasHeightForWidth());
        dockWidgetContents->setSizePolicy(sizePolicy3);
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        DockBtn->setWidget(dockWidgetContents);
        f_MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DockBtn);
        DockProjet = new QDockWidget(f_MainWindow);
        DockProjet->setObjectName(QStringLiteral("DockProjet"));
        sizePolicy2.setHeightForWidth(DockProjet->sizePolicy().hasHeightForWidth());
        DockProjet->setSizePolicy(sizePolicy2);
        DockProjet->setMinimumSize(QSize(168, 240));
        DockProjet->setFloating(false);
        DockProjet->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        sizePolicy3.setHeightForWidth(dockWidgetContents_2->sizePolicy().hasHeightForWidth());
        dockWidgetContents_2->setSizePolicy(sizePolicy3);
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView = new QTreeView(dockWidgetContents_2);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy4);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setSelectionMode(QAbstractItemView::SingleSelection);
        treeView->setAnimated(true);
        treeView->header()->setVisible(false);

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        DockProjet->setWidget(dockWidgetContents_2);
        f_MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), DockProjet);
        DockSV = new QDockWidget(f_MainWindow);
        DockSV->setObjectName(QStringLiteral("DockSV"));
        sizePolicy2.setHeightForWidth(DockSV->sizePolicy().hasHeightForWidth());
        DockSV->setSizePolicy(sizePolicy2);
        DockSV->setMinimumSize(QSize(300, 80));
        DockSV->setFloating(true);
        DockSV->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        DockSV->setWidget(dockWidgetContents_3);
        f_MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(4), DockSV);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addAction(actionImporter);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_sous);
        menuFichier->addAction(actionFermer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuEdition->addAction(actionExecuter);
        menuEdition->addAction(actionArreter);
        menuEdition->addSeparator();
        menuEdition->addAction(actionDebug);
        menuEdition->addAction(actionJump);
        menuEdition->addSeparator();
        menuEdition->addAction(actionConvert);
        menuEdition->addAction(actionGestionMem);
        menuEdition->addAction(actionGestion_des_composants_I2C);
        menuEdition->addAction(actionRedemarrer_la_maquette);
        menuAide->addAction(actionAide);
        menuAide->addSeparator();
        menuAide->addAction(actionA_propos);
        menuAffichage->addAction(actionProjet);
        menuAffichage->addAction(actionSV);
        menuOptions->addSeparator();
        menuOptions->addAction(actionInterpreteur);
        menuOptions->addAction(actionConfiguration_Application);
        menuOptions->addAction(menuGestion_des_profils->menuAction());
        menuGestion_des_profils->addAction(actionCreer_profil);
        menuGestion_des_profils->addAction(actionChanger_profil);
        menuGestion_des_profils->addAction(actionModifier_profil);
        menuGestion_des_profils->addAction(actionSupprimer_profil);
        mainToolBar->addAction(actionNouveau);
        mainToolBar->addAction(actionOuvrir);
        mainToolBar->addAction(actionEnregistrer);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExecuter);
        mainToolBar->addAction(actionArreter);
        mainToolBar->addAction(actionJump);
        mainToolBar->addAction(actionDebug);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAgrandir);
        mainToolBar->addAction(actionRetrecir);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSV);
        mainToolBar->addAction(actionConvert);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDemarrerServeurWeb);
        mainToolBar->addAction(actionArreterServeurWeb);
        mainToolBar->addAction(actionRafraichirConfigurationServeurWeb);

        retranslateUi(f_MainWindow);
        QObject::connect(actionSV, SIGNAL(triggered(bool)), DockSV, SLOT(setVisible(bool)));
        QObject::connect(DockSV, SIGNAL(visibilityChanged(bool)), actionSV, SLOT(setChecked(bool)));
        QObject::connect(actionProjet, SIGNAL(toggled(bool)), DockProjet, SLOT(setVisible(bool)));
        QObject::connect(DockProjet, SIGNAL(visibilityChanged(bool)), actionProjet, SLOT(setChecked(bool)));

        QMetaObject::connectSlotsByName(f_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *f_MainWindow)
    {
        f_MainWindow->setWindowTitle(QApplication::translate("f_MainWindow", "Open-Organigram", 0));
        actionNouveau->setText(QApplication::translate("f_MainWindow", "Nouveau", 0));
        actionNouveau->setShortcut(QApplication::translate("f_MainWindow", "Ctrl+N", 0));
        actionOuvrir->setText(QApplication::translate("f_MainWindow", "Ouvrir", 0));
        actionOuvrir->setShortcut(QApplication::translate("f_MainWindow", "Ctrl+O", 0));
        actionFermer->setText(QApplication::translate("f_MainWindow", "Fermer", 0));
        actionQuitter->setText(QApplication::translate("f_MainWindow", "Quitter", 0));
        actionAide->setText(QApplication::translate("f_MainWindow", "Aide", 0));
        actionA_propos->setText(QApplication::translate("f_MainWindow", "A propos", 0));
        actionEnregistrer->setText(QApplication::translate("f_MainWindow", "Enregistrer", 0));
        actionEnregistrer->setShortcut(QApplication::translate("f_MainWindow", "Ctrl+S", 0));
        actionEnregistrer_sous->setText(QApplication::translate("f_MainWindow", "Enregistrer sous..", 0));
        actionExecuter->setText(QApplication::translate("f_MainWindow", "Executer", 0));
        actionExecuter->setShortcut(QApplication::translate("f_MainWindow", "Ctrl+R", 0));
        actionArreter->setText(QApplication::translate("f_MainWindow", "Arr\303\252ter", 0));
        actionArreter->setShortcut(QApplication::translate("f_MainWindow", "Esc", 0));
        actionSV->setText(QApplication::translate("f_MainWindow", "Mode Supervision", 0));
#ifndef QT_NO_TOOLTIP
        actionSV->setToolTip(QApplication::translate("f_MainWindow", "Mode Supervision", 0));
#endif // QT_NO_TOOLTIP
        actionDebug->setText(QApplication::translate("f_MainWindow", "Mode pas \303\240 pas", 0));
        actionJump->setText(QApplication::translate("f_MainWindow", "Passer \303\240 l'\303\251tape suivante", 0));
        actionJump->setShortcut(QApplication::translate("f_MainWindow", "F10", 0));
        actionConvert->setText(QApplication::translate("f_MainWindow", "Convertir en programme", 0));
        actionProjet->setText(QApplication::translate("f_MainWindow", "Projet", 0));
        actionConfiguration->setText(QApplication::translate("f_MainWindow", "Configuration", 0));
        actionNouveauProfil->setText(QApplication::translate("f_MainWindow", "Nouveau profil", 0));
        actionChoisirProfil->setText(QApplication::translate("f_MainWindow", "Choisir un profil", 0));
        actionAgrandir->setText(QApplication::translate("f_MainWindow", "Agrandir", 0));
        actionRetrecir->setText(QApplication::translate("f_MainWindow", "R\303\251trecir", 0));
        actionInterpreteur->setText(QApplication::translate("f_MainWindow", "Interpreteur", 0));
        actionSupprimerProfil->setText(QApplication::translate("f_MainWindow", "Supprimer un profil", 0));
        actionModifierProfil->setText(QApplication::translate("f_MainWindow", "Modifier un profil", 0));
        actionGestionMem->setText(QApplication::translate("f_MainWindow", "Gestion de la m\303\251moire", 0));
        actionImporter->setText(QApplication::translate("f_MainWindow", "Nouveau \303\240 partir d'un plan de c\303\242blage...", 0));
        actionServeur_Web->setText(QApplication::translate("f_MainWindow", "Serveur Web", 0));
        actionRedemarrer_la_maquette->setText(QApplication::translate("f_MainWindow", "R\303\251initialiser la maquette", 0));
        actionGestion_des_composants_I2C->setText(QApplication::translate("f_MainWindow", "Gestion des composants I2C", 0));
        actionConfiguration_Application->setText(QApplication::translate("f_MainWindow", "Configuration", 0));
        actionCreer_profil->setText(QApplication::translate("f_MainWindow", "Cr\303\251er profil", 0));
        actionModifier_profil->setText(QApplication::translate("f_MainWindow", "Modifier un profil", 0));
        actionSupprimer_profil->setText(QApplication::translate("f_MainWindow", "Supprimer un profil", 0));
        actionChanger_profil->setText(QApplication::translate("f_MainWindow", "Changer de profil", 0));
        actionDemarrerServeurWeb->setText(QApplication::translate("f_MainWindow", "Demarrer Serveur Web", 0));
#ifndef QT_NO_TOOLTIP
        actionDemarrerServeurWeb->setToolTip(QApplication::translate("f_MainWindow", "Demarrer Serveur Web", 0));
#endif // QT_NO_TOOLTIP
        actionArreterServeurWeb->setText(QApplication::translate("f_MainWindow", "Arr\303\252ter Serveur Web", 0));
#ifndef QT_NO_TOOLTIP
        actionArreterServeurWeb->setToolTip(QApplication::translate("f_MainWindow", "Arr\303\252ter Serveur Web", 0));
#endif // QT_NO_TOOLTIP
        actionRafraichirConfigurationServeurWeb->setText(QApplication::translate("f_MainWindow", "Rafra\303\256chir Configuration Serveur Web", 0));
#ifndef QT_NO_TOOLTIP
        actionRafraichirConfigurationServeurWeb->setToolTip(QApplication::translate("f_MainWindow", "Rafra\303\256chir Configuration Serveur Web", 0));
#endif // QT_NO_TOOLTIP
        menuFichier->setTitle(QApplication::translate("f_MainWindow", "Fichier", 0));
        menuEdition->setTitle(QApplication::translate("f_MainWindow", "Organigrammes", 0));
        menuAide->setTitle(QApplication::translate("f_MainWindow", "Aide", 0));
        menuAffichage->setTitle(QApplication::translate("f_MainWindow", "Affichage", 0));
        menuOptions->setTitle(QApplication::translate("f_MainWindow", "Options", 0));
        menuGestion_des_profils->setTitle(QApplication::translate("f_MainWindow", "Gestion des profils", 0));
        DockBtn->setWindowTitle(QApplication::translate("f_MainWindow", "Items", 0));
        DockProjet->setWindowTitle(QApplication::translate("f_MainWindow", "Projet", 0));
        DockSV->setWindowTitle(QApplication::translate("f_MainWindow", "Supervision", 0));
    } // retranslateUi

};

namespace Ui {
    class f_MainWindow: public Ui_f_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F_MAINWINDOW_H
