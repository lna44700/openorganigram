//-------------------------------------------------------------------------------
/**
 * @file        f_MainWindow.cpp
 * @brief       Fenêtre principale du programme
 *
 * @author      N.Jarnoux
 * @author      L. Guitton, F. Philippeau
 * @author      STS IRIS, Lycée Nicolas APPERT, ORVAULT (FRANCE)
 * @since       18/02/14
 * @version     1.0
 * @date        03/03/14
 *
 * Fenêtre principale de l'application, gère la plupart des actions et coordonnes celles ci à travers
 * les différents modules
 *
 * Fabrication  OpenOrganigram.pro
 *
 * @todo        A completer avec les fonctions manquantes... J'attend mes collègues
 *
 * @bug         03/03/14 - Docks qui apparaissent trop grand
 */
//-------------------------------------------------------------------------------

//===== Headers standards =====
#include <QLabel>
#include <QStandardItemModel>
#include <QGraphicsView>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QSettings>
#include <QInputDialog>
#include <QXmlStreamReader>
#include <QStringRef>
#include <QProgressBar>
#include <QTemporaryFile>
#include <QTimer>
#include <QStandardPaths>


//=====   Headers Peros   =====
#include "f_MainWindow.h"
#include "ui_f_MainWindow.h"
#include "ConfigurationMaquette/AssistantConfiguration.h"
//#include "Supervision/f_Supervision.h"
#include "ConfigurationAppli/f_Configuration.h"
#include "ConfigurationAppli/f_CreerProfil.h"
#include "ConfigurationAppli/f_SupprimerProfil.h"
#include "ConfigurationAppli/f_ChoixProfil.h"
#include "ConfigurationAppli/f_ModifierProfil.h"
#include "ConfigurationAppli/f_APropos.h"
#include "Interface/f_InterpreteurCommandes.h"
#include "Control/Inst/Inst_Boucle.h"
#include "Interface/f_GestionMem.h"
#include "Interface/f_Compilation.h"
#include "Interface/f_ConfigI2C.h"
#include "PoolGestionnaireConnexionHTTP.h"
#include "ControleurFichierStatique.h"
#include "EcouteHTTP.h"
#include "GestionnaireConnexionHTTP.h"
#include "GestionnaireRequeteHTTP.h"
#include "ReponseHTTP.h"
#include "RequeteHTTP.h"
#include "GlobalHTTP.h"
#include "SupervisionWeb/Serveur/RequeteMapper.h"
#include "SupervisionWeb/Serveur/Serveur.h"
#include "SupervisionWeb/Web/src/Donnees.h"

/**
 * Constructeur de la fenêtre, cette methode met en place toute l'interface
 * graphique et met le logiciel en position d'attente de la première action de
 * l'utilisateur
 *
 * @brief   f_MainWindow::f_MainWindow(QWidget *    parent = 0)
 * @param   parent Pointeur vers l'objet QObject ou dérivé parent.
 * @see     ProgManager, EtatProjet, f_MainWindow::InitialiserBt_ItemDock()
 */
f_MainWindow::f_MainWindow(QWidget *    pParent) :
    QMainWindow             (pParent) ,
    pStIt_Projet            (0) ,
    pStIt_ListeModules      (0) ,
    pArduino                (new Arduino),
    pEtatConnexion          (new QLabel),
    serveurWeb              (),
    ui                      (new Ui::f_MainWindow),
    RepertoireProjets       (QDir::currentPath())
{

    // Initialisation générale
    this->ui->setupUi(this) ;
    this->ui->actionInterpreteur->setShortcut(tr("ALT+F8"));
//    f_Supervision * Sup (new f_Supervision(pArduino));
    DonneesWeb = new Donnees(pArduino);
//    this->ui->DockSV->setWidget(Sup);
//    connect(this->ui->DockSV, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), Sup, SLOT(EmplacementSupervision(Qt::DockWidgetArea)));

    this->ui->DockSV->hide() ;
    this->ui->actionSV->setEnabled(false);
    this->InitialiserBt_ItemDock() ;

    //initialisation repertoire courant
    QString CheminRepertoireCourant(QApplication::applicationDirPath());
    QDir RepertoireCourant(QDir::currentPath());
    RepertoireCourant.setCurrent(CheminRepertoireCourant);

    // Ini. avec utilisateur de base
    on_envoieProfil("Eleve");

    // Création du fichier .ini si le fichier n'existe pas.
    if(!QFile::exists("Profils.ini"))
    {
        QSettings   Profils("Profils.ini", QSettings::IniFormat);
        QByteArray  MotDePasseBArray;
        QString     sMotDePasse("test");

        MotDePasseBArray = QCryptographicHash::hash(sMotDePasse.toLocal8Bit(), QCryptographicHash::Md5);

        Profils.setValue("Profils/Profilid0","Eleve");
        Profils.setValue("Profils/Profilid1", "Professeur");
        Profils.setValue("Mdp/mdpid0", "");
        Profils.setValue("Mdp/mdpid1", QString::fromLocal8Bit(MotDePasseBArray));

        MotDePasseBArray.remove(0, MotDePasseBArray.size()) ;
    }

    //Partie Kévin Interpréteur-----------------------------
    this->ui->actionInterpreteur->setIcon(QIcon(":/Images/App/prog.png"));  //Affiche un icone dans le menu d'action
    //-------------------------------------------------------

    this->pEtatConnexion->setText("Maquette non connectée");
    this->ui->statusBar->addWidget(this->pEtatConnexion) ;
    this->connect(this->pArduino,           SIGNAL(ArduinoConnect(int, QString)),
                  this,                     SLOT(slot_EtatConnexion(int, QString)) );

    //Initialisation de l'etat du projet
    this->EtatProjetenCours.Etat.ProjetOuvert = 0;
    this->EtatProjetenCours.Etat.ProjetEnregistre = 0;
    this->EtatProjetenCours.Etat.ModuleCharge = 0;
    this->EtatProjetenCours.sCheminVersProjet = "";

    //Création du répertoire des projets
    QString CheminRepertoireProjets ("");
    CheminRepertoireProjets = this->RepertoireProjets.absolutePath()+"/Projets";
    if(!QDir(CheminRepertoireProjets).exists())
    {
        this->RepertoireProjets.setCurrent(CheminRepertoireProjets);
        this->RepertoireProjets.mkdir(CheminRepertoireProjets);
    }
    this->CheminRepertoirePojets = CheminRepertoireProjets;

    //Désactivation des actions
    this->ActiverActions(false);

}

/**
 * Destruction de la fenetre, cette méthode se charge de remetre de valeur
 * par défault dans tous les attributs
 *
 * @brief   f_MainWindow::~f_MainWindow()
 * @see     f_MainWindow::Fermer()
 */
f_MainWindow::~f_MainWindow()
{
    if(this->EtatProjetenCours.Etat.ProjetOuvert == 1)
    {
        this->Fermer() ;
    }

    delete this->pEtatConnexion;
    delete ui ;
}

/**
 * Gestion du clic simple sur le bouton item à gauche de la fenetre
 * @brief f_MainWindow::Click_BtnItem
 * @param Type
 */
void f_MainWindow::Click_BtnItem(TypeCommande Type)
{
    //On ajoute une instruction simple en début d'organigramme
    QTabWidget *    TabWidget   (qobject_cast<QTabWidget*>(this->centralWidget()));
    Vue *           VueActive   (qobject_cast<Vue*>(TabWidget->currentWidget()));
    VueActive->getRoutineAffichee()->AjouterInstruction(Type);
    VueActive->Rafraichir();
}

/**
 * Gestion de l'évenement de fermeture de l'application, vérification que
 * le projet est bien enregistré.
 *
 * @brief   f_MainWindow::closeEvent(QCloseEvent *  e)
 * @param   e     C'est l'événement donné correspondant à l'évenement déclenché.
 * @see     f_MainWindow::ProjetSauve()
 */
void f_MainWindow::closeEvent(QCloseEvent *    pEvent)
{
    //Si le projet est sauvé, alors on peut quitter
    if(this->ProjetSauve())
    {
        pEvent->accept() ;
    }
    else
    {
        pEvent->ignore() ;
    }
}

/**
 * Initialise le dock de gestion de projet à gauche
 * @brief f_MainWindow::InitialiserGestionProjet
 */
void f_MainWindow::InitialiserGestionProjet()
{
    QIcon   IconProjet  (":/Images/App/folder.png") ;

    QStandardItemModel * pModel (new QStandardItemModel) ;
    this->pStIt_Projet              = new QStandardItem (IconProjet, "Projet sans nom") ;
    pModel->appendRow(pStIt_Projet) ;

    //1er Item enfant : plan de câblage

    QIcon               IconPlan    (":/Images/App/sim.png") ;
    QStandardItem *     pStIt_Plan  (new QStandardItem(IconPlan, "Plan de câblage")) ;

    this->pStIt_Projet->appendRow(pStIt_Plan) ;

    //2nd item enfant : Liste des modules

    QIcon   IconModule          (":/Images/Items/iconmeth.png") ;
    this->pStIt_ListeModules    = new QStandardItem(IconModule, "Liste des modules") ;

    this->pStIt_Projet->appendRow(this->pStIt_ListeModules) ;

    //Affichage dans la dock correspondant

    this->ui->treeView->setModel(pModel) ;
    this->ui->treeView->expandAll() ;
}

/**
 * Initialise les 6 boutons permettant d'ajouter des éléments graphiques à
 * l'organigramme.
 *
 * @brief   f_MainWindow::InitialiserBt_ItemDock()
 * @see     f_MainWindow::ActiverBt_ItemDock()
 */
void f_MainWindow::InitialiserBt_ItemDock()
{
    //Création
    this->pBt_ItemDock[0] = new BtnItem  (OPE, this)   ;
    this->pBt_ItemDock[1] = new BtnItem  (COND, this)  ;
    this->pBt_ItemDock[2] = new BtnItem  (BOUCLE, this)  ;
    this->pBt_ItemDock[3] = new BtnItem  (ES, this)    ;
    this->pBt_ItemDock[4] = new BtnItem  (ROUT, this)  ;
    this->pBt_ItemDock[5] = new BtnItem  (EP, this);
    this->pBt_ItemDock[6] = new BtnItem  (TEMPO, this) ;
    this->pBt_ItemDock[7] = new BtnItem  (COM, this)   ;

    //temporaire tant que l'execution parallèle ne peut être codée.
    this->pBt_ItemDock[5]->setEnabled(false);

    //Préparation du dock
    this->ui->DockBtn->setWidget(new QWidget) ;
    this->ui->DockBtn->widget()->setLayout(new QVBoxLayout) ;

    //Ajout des boutons dans le dock
    for(register unsigned int i=0; i<8; i++)
    {
        this->ui->DockBtn->widget()->layout()->addWidget(pBt_ItemDock[i]) ;
    }

    //Désactivation des boutons
    this->ActiverBt_ItemDock(false) ;
}

/**
 * Active ou desactive les boutons dockés
 *
 * @brief   f_MainWindow::ActiverBt_ItemDock(bool en)
 */
void f_MainWindow::ActiverBt_ItemDock(bool en)
{
    for(register unsigned int i=0; i<8; i++)
    {
        this->pBt_ItemDock[i]->setEnabled(en);
    }
}

/**
 * Active ou desactive les actions des menus
 *
 * @brief   f_MainWindow::ActiverActions(bool en)
 */
void f_MainWindow::ActiverActions(bool bActive)
{
    //this->ui->actionArreter->setEnabled(bActive) ;
    this->ui->actionEnregistrer->setEnabled(bActive) ;
    this->ui->actionEnregistrer_sous->setEnabled(bActive) ;
    this->ui->actionFermer->setEnabled(bActive) ;
    this->ui->actionConvert->setEnabled(bActive) ;
    this->ui->actionDebug->setEnabled(bActive) ;

    if(this->EtatProjetenCours.Etat.ModuleCharge == 1)
    {
        this->ui->actionAgrandir->setEnabled(bActive) ;
        this->ui->actionRetrecir->setEnabled(bActive) ;
        this->ui->actionExecuter->setEnabled(bActive) ;
        this->ui->actionDebug->setEnabled(bActive) ;
        this->ui->actionDemarrerServeurWeb->setEnabled(bActive) ;
        this->ui->actionSV->setEnabled(bActive) ;
        this->ui->actionVueGlobale->setEnabled(bActive);
    }
}

/**
 * Lance la procédure de sauvegarde du projet
 *
 * @brief   f_MainWindow::Sauver()
 * @see     EtatProjet
 */
bool f_MainWindow::Sauver()
{
    bool bRetour(false);

    //Si le nom du fichier est vide, on demande à l'utilisateur d'en fournir un
    if(this->EtatProjetenCours.sCheminVersProjet.isEmpty())
    {
        this->ObtenirEmplacementProjet(false) ;
    }

    //S'il est toujours vide c'est que l'utilisateur a annuler cette opération
    //Donc on arrête tout seur place
    if(!this->EtatProjetenCours.sCheminVersProjet.isEmpty())
    {
        QFile FichierXml    (this->EtatProjetenCours.sCheminVersProjet);

        //Si on arrive à ouvrir le fichier
        if(FichierXml.open(QFile::ReadWrite))
        {
            //On le remet à zéro et on le réécrit entierement
            FichierXml.resize(0);
            QXmlStreamWriter    Parser      (&FichierXml);

            //Calcul pour la balise "Resume"
            int                 NbreModules (0);
            int                 NbreRoutine (0);
            int                 NbreInst    (0);

            for(register int i = 0; i < Lst_pManagers.length(); i++)
            {
                NbreModules++;
                NbreRoutine +=  Lst_pManagers[i]->getNbreRoutine();
                NbreInst    +=  Lst_pManagers[i]->getNbreInst();
            }

            Parser.setAutoFormatting(true);
            Parser.writeStartDocument();

            Parser.writeStartElement("Projet");
            Parser.writeAttribute("sNom", pStIt_Projet->text());

            Parser.writeEmptyElement("Resume");
            Parser.writeAttribute("nNbreModule", QVariant(NbreModules).toString());
            Parser.writeAttribute("nNbreRoutine", QVariant(NbreRoutine).toString());
            Parser.writeAttribute("nNbreInstructions", QVariant(NbreInst).toString());

            //Balise config
            Parser.writeTextElement("Config", QString(this->ConfigurationArduinoCourante));

            //Demande à chaque module de s'enregistrer lui meme
            for(register int i = 0; i < Lst_pManagers.length(); i++)
            {
                Lst_pManagers[i]->Enregistrer(&Parser);
            }

            //Ecriture de la fin du document
            Parser.writeEndElement();
            Parser.writeEndDocument();
        }
        else
        {
            QMessageBox::warning(this, "Erreur", "Le fichier selectionné ne peut pas être ouvert convenablement. (" + FichierXml.errorString() + ")");
        }


        //changement d'état du projet
        this->EtatProjetenCours.Etat.ProjetEnregistre = 1;
        bRetour = true;
    }

    return bRetour;
}

/**
 * Lance la procédure de fermeture du projet
 *
 * @brief   f_MainWindow::Fermer()
 * @see     EtatProjet
 */
void f_MainWindow::Fermer()
{
    //On retire les fenetre de la supervision
    //qobject_cast<f_Supervision*>(this->ui->DockSV->widget())->PurgerListeFenetre();

    //Si on est en pleine exécution, on l'arrete
    if(this->ui->actionArreter->isEnabled())
    {
        this->on_actionArreter_triggered();
    }

    //On remet le widget central à zéro
    this->setCentralWidget(new QWidget(this));

    //Suppression de la liste des modules
    this->ui->treeView->model()->deleteLater();
    this->ui->treeView->setModel(0);
    this->pStIt_ListeModules = 0;
    this->pStIt_Projet = 0 ;

    //Suppression des managers de modules
    int len (this->Lst_pManagers.length()) ;

    for(register int i = 0; i < len; i++)
    {
        disconnect(Lst_pManagers[i], SIGNAL(EtatExec(int)), this, SLOT(slot_EtatExecution(int)));
        delete this->Lst_pManagers[i] ;
        this->Lst_pManagers[i] = 0 ;
    }

    Lst_pManagers.clear() ;

    //Désactivation des actions
    this->ActiverActions(false);

    //RAZ de l'etat du projet
    this->EtatProjetenCours.sCheminVersProjet.clear() ;
    this->EtatProjetenCours.Etat.ModuleCharge = 0;
    this->EtatProjetenCours.Etat.ProjetEnregistre = 0;
    this->EtatProjetenCours.Etat.ProjetOuvert = 0;

    //Désactivation des boutons items
    this->ActiverBt_ItemDock(false);
}

/**
 * Ouvre un projet à partir d'un fichier au format .oorg
 * @brief f_MainWindow::Ouvrir
 */
void f_MainWindow::Ouvrir()
{
    if(this->ProjetSauve())                                             //Si le projet est sauvegardé ou qu'il n'y a pas de projet ouvert
    {
        this->Fermer();                                                 //On ferme le projet en cours s'il y en a un et on remet l'espace de travail à zéro

        QProgressBar *      pBarreChargement    (new QProgressBar) ;    //Initialisation de la barre de progression de chargement.
                                                                        //|
        pBarreChargement->setRange(0, 100);                             //|
        pBarreChargement->setTextVisible(true);                         //|
        this->ui->statusBar->addWidget(pBarreChargement) ;              //|

        this->ObtenirEmplacementProjet(true);                           //Boite de dialog pour aller chercher le fichier
        if(!this->EtatProjetenCours.sCheminVersProjet.isEmpty())
        {
            if(this->EtatProjetenCours.sCheminVersProjet.right(4) == "oorg")             //Si le fichier à la bonne extension
            {
                QFile   FichierOrganigramme (this->EtatProjetenCours.sCheminVersProjet) ;//On le charge dans un objet manipulateur de fichier

                if(FichierOrganigramme.open(QFile::ReadOnly))               //Si on peu l'ouvrir on le parse
                {
                    this->ParserLeFichier(FichierOrganigramme, pBarreChargement);
                }
                else    //Sinon si le fichier n'existe pas physiquement ou n'est pas précisé
                {
                    QMessageBox::warning(this, "Erreur d'ouverture", "Le fichier donné n'a pas put être ouvert pour la raison suivant : " + FichierOrganigramme.errorString(), QMessageBox::Ok);
                }
                FichierOrganigramme.close();
            }
            else    //Enfin si l'extension ne convient pas..
            {
                QMessageBox::warning(this, "Erreur d'extension", "Le fichier choisis ne semble pas avoir la bonne extension...", QMessageBox::Ok);
            }
        }

        //On supprime la barre de chargement ensuite
        this->statusBar()->removeWidget(pBarreChargement);
        delete pBarreChargement;
    }
}

/**
 * Interprete le fichier XML
 * @brief f_MainWindow::ParserLeFichier
 * @param FichierOrganigramme
 * @param pBarreChargement
 */
void f_MainWindow::ParserLeFichier(QFile& FichierOrganigramme, QProgressBar* pBarreChargement)
{
    QXmlStreamReader Parseur(&FichierOrganigramme);          //On le donne au parseur

    //Déclaration
    ModuleManager *     ModuleCourant       (0);
    Routine *           RoutineCourante     (0);
    Instruction *       InstructionCourante (0);
    Inst_Boucle *       BouclePrecedente    (0);
    QStringRef          NomBalise ;
    QByteArray          ContenuConfig;
    bool                bAttribut           (true) ;
    bool                bDocXmlValide       (false) ;
    bool                bPremierTour        (true);
    int                 AvancementChargement(0);
    int                 TotalChargement     (0);



    while(!Parseur.atEnd())                                  //Tant qu'on est pas au bout du fichier
    {

        switch(Parseur.readNext())                           //On lit la prochaine balise
        {;
        case QXmlStreamReader::StartElement :               //Si c'est une balise ouvrante

            NomBalise   = Parseur.name() ;                   //On récupère son nom

            if(bPremierTour && NomBalise == "Projet")       //Vérification que c'est bien un fichier XML généré par OpenOrganigram
            {
                bDocXmlValide = true;
                bPremierTour = false;
            }

            if(bDocXmlValide)                               //Si c'est le cas, on commence le traitement
            {
                bAttribut = true ;

                if(NomBalise == "Resume")                   //Avec le résumé on calcul la taille totale de la barre de progression
                {
                    QXmlStreamAttributes    Attr            (Parseur.attributes()) ;
                    QStringRef              nNbreModule     (Attr.value("nNbreModule")) ;
                    QStringRef              nNbreRoutine    (Attr.value("nNbreRoutine"));
                    QStringRef              nNbreInstructions(Attr.value("nNbreInstructions"));

                    TotalChargement += nNbreModule.toInt() + nNbreRoutine.toInt() + nNbreInstructions.toInt() ;

                    bAttribut = false;
                }

                if(NomBalise == "Projet")                   //Avec la balise projet, on initialise la gestion de projet
                {
                    this->InitialiserGestionProjet();

                    QFileInfo NomProjet(FichierOrganigramme);
                    QString  sNomProjet(NomProjet.fileName());
                    this->pStIt_Projet->setText(sNomProjet.replace(".oorg", ""));

                    bAttribut = false;
                }

                if(NomBalise == "Config")
                {
                    bAttribut = false;
                }

                if(NomBalise == "Module")                   //Avec la balise module on initialise un nouveau module (qui devient le module courant)
                {
                    QStringRef  NomModule   (Parseur.attributes().value("sNomModule"));

                    ModuleCourant = new ModuleManager(NomModule.toString(), this->pArduino) ;
                    this->Lst_pManagers.append(ModuleCourant) ;

                    connect(ModuleCourant, SIGNAL(EtatExec(int)), this, SLOT(slot_EtatExecution(int)));

                    //Ajouter tout les modules à la liste
                    QStandardItem *     pStIt_NouveauModule (new QStandardItem(NomModule.toString()));
                    this->pStIt_ListeModules->appendRow(pStIt_NouveauModule) ;

                    bAttribut = false;
                    AvancementChargement++ ;
                }

                if(NomBalise == "ActionArduino")                   //Avec la balise ActionArduino on initialise une nouvelle action
                {
                    if(InstructionCourante == 0)
                    {
                        QStringRef      sNomAction  (Parseur.attributes().value("sNomAction"));
                        QStringRef      sCommande   (Parseur.attributes().value("sCommande"));
                        QStringRef      bActive     (Parseur.attributes().value("bActive"));
                        ActionArduino   NouvelleAction;

                        NouvelleAction.sNomAction   = sNomAction.toString();
                        NouvelleAction.sCommande    = sCommande.toString();

                        if(bActive == "true")
                        {
                            NouvelleAction.bActive = true;
                        }
                        else
                        {
                            NouvelleAction.bActive = false;
                        }

                        ModuleCourant->AjouterAction(NouvelleAction);

                        bAttribut = false;
                    }
                }

                if(NomBalise == "TestArduino")                   //Avec la balise ActionArduino on initialise un nouveau test
                {
                    if(InstructionCourante == 0)
                    {
                        QStringRef      sNomTest    (Parseur.attributes().value("sNomTest"));
                        QStringRef      sCommande   (Parseur.attributes().value("sCommande"));
                        QStringRef      bActive     (Parseur.attributes().value("bActive"));
                        TestArduino     NouveauTest;

                        NouveauTest.sNomTest     = sNomTest.toString();
                        NouveauTest.sCommande    = sCommande.toString();

                        if(bActive == "true")
                        {
                            NouveauTest.bActive = true;
                        }
                        else
                        {
                            NouveauTest.bActive = false;
                        }

                        ModuleCourant->AjouterTest(NouveauTest);

                        bAttribut = false;
                    }
                }

                if(NomBalise == "ARU")                   //Avec la balise ActionArduino on initialise un nouveau test
                {
                    QStringRef      ARU    (Parseur.attributes().value("valeur"));

                    ModuleCourant->AjouterARU(ARU.toString());

                    bAttribut = false;
                }

                if(NomBalise == "Routine")                  //Avec la balise routine, on initialise une nouvelle routine (qui devient le routine courante) appartenant au module courant
                {
                    QXmlStreamAttributes    Attr        (Parseur.attributes()) ;
                    QStringRef              IdRoutine   (Attr.value("nId"));
                    QStringRef              NomRoutine  (Attr.value("sNom"));

                    RoutineCourante = new Routine(IdRoutine.toInt(), NomRoutine.toString(), ModuleCourant, true) ;

                    ModuleCourant->AjouterRoutine(RoutineCourante);

                    bAttribut = false;
                    AvancementChargement++ ;
                }

                if(NomBalise == "Instruction")              //Avec la balise instruction, on initialise une instruction (qui devient l'instruction courante) appartenant à la routine courante
                {
                    QXmlStreamAttributes    Attr    (Parseur.attributes()) ;
                    QStringRef              IdInst  (Attr.value("nId"));
                    QStringRef              sType   (Attr.value("Type"));
                    QVariant                vType   (sType.toString()) ;
                    int                     nType   (vType.toInt());
                    TypeCommande            Type    (static_cast<TypeCommande>(nType));

                    InstructionCourante = Instruction::NouvelleInst(Type, IdInst.toInt(), RoutineCourante) ;
                    RoutineCourante->AjouterInstruction(InstructionCourante) ;

                    if(Type == BOUCLE)    //Si c'est un boucle, il faut initialiser la parité avec une autre instruction boucle
                    {
                        if(BouclePrecedente != 0)
                        {
                            if(BouclePrecedente->getInstPaire() == 0)
                            {
                                BouclePrecedente->setInstPaire(static_cast<Inst_Boucle *>(InstructionCourante));
                                static_cast<Inst_Boucle *>(InstructionCourante)->setInstPaire(BouclePrecedente);
                            }
                            else
                            {
                                BouclePrecedente = static_cast<Inst_Boucle *>(InstructionCourante);
                            }
                        }
                        else
                        {
                            BouclePrecedente = static_cast<Inst_Boucle *>(InstructionCourante);
                        }
                    }

                    bAttribut = false;
                    AvancementChargement++ ;
                }

                if(bAttribut)   //Si c'est une autre balise, c'est que c'est un attribut, on passe la balise entière à l'instruction courante qui se débrouille à initialiser ses paramètre avec
                {
                    InstructionCourante->setAttr(NomBalise.toString(), Parseur.attributes().value("valeur"));
                    AvancementChargement++ ;
                }
            }
            break;

        case QXmlStreamReader::Characters :

            if(NomBalise == "Config")
            {
                ContenuConfig += Parseur.text().toString();
                this->ConfigurationArduinoCourante = ContenuConfig;
            }
            break;

        case QXmlStreamReader::EndElement :     //Si c'est une balise fermante
            NomBalise   = Parseur.name() ;

            if(NomBalise == "Config")
            {
                QFile TempFile("TempConfigArduino.ini");

                if(TempFile.open(QFile::WriteOnly))
                {
                    TempFile.write(ContenuConfig);
                    TempFile.close();

                    InterpreteurFichierIni* ParseurIni(new InterpreteurFichierIni("TempConfigArduino.ini", this->pArduino));
                    this->connect(ParseurIni, SIGNAL(FinConfigMaquette(InterpreteurFichierIni*,bool)), this, SLOT(slot_FinInterpretationIniOuvrirProjet(InterpreteurFichierIni*,bool)));
                    ParseurIni->Interpreter();
                }
                else
                {
                    qDebug() << "Erreur d'ouverture";
                }


            }

            if(NomBalise == "Instruction")      //On remet à 0 l'instruction courante
            {
                InstructionCourante = 0;
            }

            if(NomBalise == "Routine")          //On remet à 0 la routine courante
            {
                RoutineCourante = 0;
            }

            if(NomBalise == "Module")           //On remet à 0 le module courant
            {
                ModuleCourant->RafraichirVues();
                ModuleCourant = 0;
            }

            break;

        default:    //Tout autre type d'élément du document est ignoré (normalement il ne doit jamais passé par là sauf pour le DOCTYPE)
            break;
        }

        if(TotalChargement != 0)    //Si le total de la barre est initialisé
        {
            pBarreChargement->setValue(AvancementChargement/TotalChargement * 100); //On calcul l'avancement en temps réel
        }
    }

    if(Parseur.hasError() || !bDocXmlValide) //S'il y a eu une erreur de lecture (en gros si c'est un fichier binaire plutôt que texte)
    {
        QMessageBox::warning(this, "Erreur", "Le fichier n'est pas un fichier OpenOrganigram valide", QMessageBox::Ok);
    }
    else
    {
        this->EtatProjetenCours.Etat.ModuleCharge = 0;
        this->EtatProjetenCours.Etat.ProjetEnregistre = 1;
        this->EtatProjetenCours.Etat.ProjetOuvert = 1;

        this->ActiverActions(true);
    }
}

/**
 * Créer un nouveau projet à partir du fichier ini fourni en parametre
 * @brief f_MainWindow::CreerNouveauProjet
 * @param CheminIni
 */
void f_MainWindow::CreerNouveauProjet(QString CheminIni)
{
    //===== Mise en place de l'arbre de gestion de projet

    this->InitialiserGestionProjet();

    //===== Mise en place du manager de programme

    //====== TEST =======
    if(CheminIni.isEmpty())
    {
        //Création d'un manager de test
        ModuleManager *   NouveauManager  (new ModuleManager("Module test", this->pArduino)) ;
        NouveauManager->AjouterRoutine("Principale") ;
        Lst_pManagers.append(NouveauManager) ;

        connect(NouveauManager, SIGNAL(EtatExec(int)), this, SLOT(slot_EtatExecution(int)));

        //Ajouter tout les modules à la liste
        QStandardItem *     pStIt_NouveauModule (new QStandardItem("Module test"));
        this->pStIt_ListeModules->appendRow(pStIt_NouveauModule) ;
    }
    else //======== FIN TEST =======
    {
        //On copie la config courante
        QFile FichierACopier(CheminIni);

        if(FichierACopier.open(QFile::ReadOnly))
        {
            QByteArray Contenu  (FichierACopier.readAll());
            this->ConfigurationArduinoCourante = Contenu;
        }
        FichierACopier.close();

        //Récupération des différent modules
        QSettings FichierIni(CheminIni, QSettings::IniFormat);

        //Définir le nom de projet dans le treeView
        FichierIni.beginGroup("IDENTIFICATION");
        this->pStIt_Projet->setText(FichierIni.value("Nom","Projet sans nom").toString());
        FichierIni.endGroup();

        FichierIni.beginGroup("MODULE");
        QStringList ListeNomModules (FichierIni.childKeys());
        qDebug() << ListeNomModules;

        for(register int i = 0; i < ListeNomModules.length(); i++)
        {
            ModuleManager *   NouveauManager  (new ModuleManager(FichierIni.value(ListeNomModules[i]).toString(), this->pArduino)) ;
            NouveauManager->AjouterRoutine("Principale") ;
            Lst_pManagers.append(NouveauManager) ;

            connect(NouveauManager, SIGNAL(EtatExec(int)), this, SLOT(slot_EtatExecution(int)));
        }

        FichierIni.endGroup();

        //Récuperation des connexion
        QStringList ListeConnexions (FichierIni.childGroups());

        //Pour chaque connexion on ajoute les ARU, les actions et tests possibles
        for(register int i = 0; i < ListeConnexions.length(); i++)
        {
            if(ListeConnexions[i].left(4) == "EASY" || ListeConnexions[i].left(7) == "ARDUINO")
            {
                FichierIni.beginGroup(ListeConnexions[i]);
                QStringList ListeAttributs(FichierIni.childKeys());
                FichierIni.endGroup();

                QString ARU;
                QString NomModule;
                QList<TestArduino>      TestPossible;
                QList<ActionArduino>    ActionPossible;

                for(register int j = 0; j < ListeAttributs.length(); j++)
                {
                    if(ListeAttributs[j] == "ARU")
                    {
                        ARU = FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString();
                    }

                    if(ListeAttributs[j].left(6) == "Action")
                    {
                        if(ListeAttributs[j].right(4) == "Code")
                        {
                            ActionArduino   NouvelAction;
                            QVariant        ValeurBrute (FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]));
                            QString         Commande;

                            if(ValeurBrute.type() == QVariant::StringList)
                            {
                                Commande = ValeurBrute.toStringList().join(',');
                            }
                            else
                            {
                                Commande = ValeurBrute.toString();
                            }

                            NouvelAction.sCommande = Commande;
                            ActionPossible.append(NouvelAction);
                        }

                        if(ListeAttributs[j].right(6) == "Enable")
                        {
                            if(FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString() == "true")
                            {
                                ActionPossible.last().bActive = true;
                            }
                            else
                            {
                                ActionPossible.last().bActive = false;
                            }

                        }

                        if(ListeAttributs[j].right(3) == "Nom")
                        {
                            ActionPossible.last().sNomAction = FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString();
                        }
                    }

                    if(ListeAttributs[j] == "Module")
                    {
                        NomModule = FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString();
                    }

                    if(ListeAttributs[j].left(4) == "Test")
                    {
                        if(ListeAttributs[j].right(4) == "Code")
                        {
                            TestArduino NouveauTest;
                            NouveauTest.sCommande = FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString();
                            TestPossible.append(NouveauTest);
                        }

                        if(ListeAttributs[j].right(6) == "Enable")
                        {
                            if(FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString() == "true")
                            {
                                TestPossible.last().bActive = true;
                            }
                            else
                            {
                                TestPossible.last().bActive = false;
                            }

                        }

                        if(ListeAttributs[j].right(3) == "Nom")
                        {
                            TestPossible.last().sNomTest = FichierIni.value(ListeConnexions[i] + "/" + ListeAttributs[j]).toString();
                        }
                    }
                }

                for(register int j = 0; j < this->Lst_pManagers.length(); j++)
                {
                    if(this->Lst_pManagers[j]->getNomModule() == NomModule)
                    {
                        this->Lst_pManagers[j]->AjouterARU(ARU);
                        this->Lst_pManagers[j]->AjouterAction(ActionPossible);
                        this->Lst_pManagers[j]->AjouterTest(TestPossible);
                    }
                }

            }
        }

        //Ajouter tous les modules à la liste
        for(register int i = 0; i < this->Lst_pManagers.length(); i++)
        {
            QStandardItem *     pStIt_NouveauModule (new QStandardItem(Lst_pManagers[i]->getNomModule()));
            this->pStIt_ListeModules->appendRow(pStIt_NouveauModule) ;
        }

        //qobject_cast<f_Supervision*>(this->ui->DockSV->widget())->OuvrirFichierINI(CheminIni);

    }

    //Création du fichier de plan de cablage dans le bon dossier de projet

    QString NomProjet = this->RecupererNomProjet("TempConfigArduino.ini");
    QString CheminRepertoireProjetCourant("");
    QDir RepertoireProjetCourant(QDir::currentPath());

    this->CreerPlanCablage(this->CreerArborescence(NomProjet), NomProjet);

    CheminRepertoireProjetCourant = QApplication::applicationDirPath();

    RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);




    //===== Mise à jour des informations concernant le projet

    this->EtatProjetenCours.Etat.ProjetOuvert = 1;
    this->EtatProjetenCours.Etat.ProjetEnregistre = 0;
    this->EtatProjetenCours.Etat.ModuleCharge = 0;
    this->EtatProjetenCours.sCheminVersProjet.clear() ;

    this->ActiverBt_ItemDock(true) ;
    this->ActiverActions(true);
}


/**
 * Vérifie si le projet et bien sauvegardé, propose une sauvegarde dans
 * le cas contraire.
 *
 * @brief   f_MainWindow::ProjetSauve()
 * @return  renvois un booléen : vrai si sauvegardé ou si la demande est refusée, faux si le message est annulé
 * @see     EtatProjet
 */
bool f_MainWindow::ProjetSauve()
{
    bool bRetour     (true) ;

    //Si il y a un projet d'ouvert et de pas enregistré
    if(this->EtatProjetenCours.Etat.ProjetOuvert == 1 && this->EtatProjetenCours.Etat.ProjetEnregistre == 0)
    {
        //Initialisation de la boite de dialogue
        QMessageBox DemandeEnregistrement   (this) ;

        DemandeEnregistrement.setWindowTitle("Avertissement") ;
        DemandeEnregistrement.setText("Projet non enregistré") ;
        DemandeEnregistrement.setInformativeText("Un projet est ouvert mais n'est pas enregistré! Voulez-vous le sauvegarder?") ;
        DemandeEnregistrement.setIcon(QMessageBox::Question) ;

        QPushButton *   pBt_Sauver       (0) ;
      //QPushButton *   pBt_NePasSauver  (0) ;
        QPushButton *   pBt_Annuler      (0) ;

        pBt_Sauver       =      DemandeEnregistrement.addButton("Sauver", QMessageBox::AcceptRole) ;
      /*pBt_NePasSauver  = */   DemandeEnregistrement.addButton("Ne pas sauver", QMessageBox::AcceptRole) ;
        pBt_Annuler      =      DemandeEnregistrement.addButton("Annuler", QMessageBox::RejectRole) ;
        DemandeEnregistrement.setDefaultButton(pBt_Sauver);

        DemandeEnregistrement.exec() ;

        //Traitement de la réponse
        QAbstractButton *   pReponse (0) ;
        pReponse = DemandeEnregistrement.clickedButton() ;

        if(pReponse == pBt_Sauver)
        {
            this->Sauver() ;
        }
        else
        {
            if(pReponse == pBt_Annuler)
            {
                bRetour = false ;
            }
        }
    }

    return bRetour;
}

/**
 * Ouvre une boite de dialogue pour sélectionner un emplacement
 * où sauvegarder le projet
 *
 * @brief   f_MainWindow::ObtenirEmplacementProjet()
 * @see     EtatProjet
 */
void f_MainWindow::ObtenirEmplacementProjet(bool bOuvrir)
{
    QString sChemin;

    if(bOuvrir)
    {
        sChemin = QFileDialog::getOpenFileName(this, "Ouvrir...", this->CheminRepertoirePojets, "Fichier OpenOrganigram (*.oorg)") ;
        QString CheminRepertoireProjetCourant("");
        QDir RepertoireProjetCourant(QDir::currentPath());
        QString sCheminCopie("");

        sCheminCopie = this->CreerArborescence(sChemin);
        sCheminCopie += "/"+sChemin;
        qDebug() << "nom copie oorg" << sCheminCopie;
        QFile::copy(sChemin, sCheminCopie);
        CheminRepertoireProjetCourant = QApplication::applicationDirPath();
        RepertoireProjetCourant.setCurrent(CheminRepertoireProjetCourant);
        RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);
    }
    else
    {
        QFileDialog fdSauvegarde;
        fdSauvegarde.setDefaultSuffix(pStIt_Projet->text()+".oorg") ;
        sChemin = fdSauvegarde.getSaveFileName(this, "Enregistrer sous...", this->CheminRepertoirePojets, "Fichier OpenOrganigram (*.oorg)") ;
    }

    this->EtatProjetenCours.sCheminVersProjet = sChemin ;
}


/** Création de la fenêtre de configuration et ouverture
 *
 * @brief   f_MainWindow::OuvrirFenetreConfig()
 * @see     f_Configuration
*/
void f_MainWindow::OuvrirFenetreConfig()
{
    f_Configuration   f_Config  (&(this->serveurWeb), this) ;
    QWidget::connect(&f_Config, SIGNAL(EnvoieEtatServeur(bool)),
                     this, SLOT(on_EnvoieEtatServeur(bool)));
    f_Config.exec() ;
}


/** Création de la fenêtre de configuration et ouverture
 *
 * @brief   f_MainWindow::OuvrirFenetreProfil()
 * @see     f_Configuration
*/
void f_MainWindow::OuvrirFenetreNouveauProfil()
{
    f_CreerProfil   f_Profil  (this) ;
    f_Profil.exec() ;
}


/** Création de la fenêtre de choix de profil et ouverture
*
* @brief    f_MainWindow::OuvrirFenetreChoixProfil()
* @see      f_ChoixProfil
*/
void f_MainWindow::OuvrirFenetreChoisirProfil()
{
    f_ChoixProfil    f_ChoisirProfil  (this) ;
    QWidget::connect(&f_ChoisirProfil, SIGNAL(EnvoieProfil(QString)),
                     this, SLOT(on_envoieProfil(QString)));

    f_ChoisirProfil.exec() ;
}


/** Création de la fenêtre de suppression de profil et affichage
*
* @brief    f_MainWindow::OuvrirFenetreSupprimerProfil()
* @see      f_SupprimerProfil
*/
void f_MainWindow::OuvrirFenetreSupprimerProfil()
{
    f_SupprimerProfil    f_SupprimerLeProfil  (this) ;
    f_SupprimerLeProfil.exec() ;
}


/** Création de la fenêtre de modification de profil et affichage
*
* @brief    f_MainWindow::OuvrirFenetreModifierProfil()
* @see      f_ModifierProfil
*/
void f_MainWindow::OuvrirFenetreModifierProfil()
{ 
        f_ModifierProfil   f_ModifierLeProfil  (this) ;
        f_ModifierLeProfil.exec() ;
}

/** Création de la fenêtre à propos
*
* @brief    f_MainWindow::OuvrirFenetreAPropos()
* @see      f_APropos
*/

void f_MainWindow::OuvrirFenetreAPropos()
{
    f_APropos    f_AProp  (this) ;
    f_AProp.exec() ;
}


/**
 * Slot correspondant à l'action de nouveau projet
 *
 * @brief   f_MainWindow::on_actionNouveau_triggered()
 * @see     Routine
 */
void f_MainWindow::on_actionNouveau_triggered()
{
    //Vérification que le projet ouvert est bien sauvegardé
    if(this->ProjetSauve())
    {
        //si le projet est ouvert, on le ferme
        if(this->EtatProjetenCours.Etat.ProjetOuvert == 1)
        {
            this->Fermer();
            this->ActiverBt_ItemDock(false);

            this->ActiverActions(false);

            this->EtatProjetenCours.Etat.ModuleCharge = 0;
            this->EtatProjetenCours.Etat.ProjetEnregistre = 0;
            this->EtatProjetenCours.Etat.ProjetOuvert = 0;
        }
        ui->actionArreterServeurWeb->setEnabled(false) ; // Le bouton arreter serveur se grise

        ui->actionDemarrerServeurWeb->setEnabled(false);  // Le bouton démarrer serveur se dégrise


        AssistantConfiguration Wizard;

        //Si la configuration est acceptée
        if(Wizard.LancerAssistant())
        {
            this->CreerNouveauProjet("TempConfigArduino.ini");
        }
    }
}

/**
 * Slot correspondant à l'action Enregistrer
 *
 * @brief   f_MainWindow::on_actionEnregistrer_triggered()
 * @see     f_MainWindow::Sauver()
 */
void f_MainWindow::on_actionEnregistrer_triggered()
{
    this->Sauver() ;
}

/**
 * Slot Correspondant à l'action enregistrer sous. Il demande l'emplacement du projet avant de le sauvegarder
 * @brief f_MainWindow::on_actionEnregistrer_sous_triggered()
 */
void f_MainWindow::on_actionEnregistrer_sous_triggered()
{
    this->Sauver() ;
}

/**
 * Slot correspondant à l'action de fermeture du projet. Vérifie si tout est enregistré et ferme le projet
 * @brief   f_MainWindow::on_actionFermer_triggered()
 * @see     f_MainWindow::Fermer()
 */
void f_MainWindow::on_actionFermer_triggered()
{
    if(this->ProjetSauve())
    {
        this->Fermer() ;
        this->ActiverBt_ItemDock(false) ;
    }
}

/**
 * Slot correspondant à l'action de fermeture de l'application. Déclenche un closeEvent
 * @brief   f_MainWindow::on_actionQuitter_triggered()
 * @see     f_MainWindow::Fermer()
 */
void f_MainWindow::on_actionQuitter_triggered()
{
    this->close() ;
}

/** Méthode éxécutée lors de l'appuis sur le bouton "Configuration" dans le menu "Options" de la fenêtre principale
*
* @brief    f_MainWindow::on_actionConfiguration_triggered()
* @see      OuvrirFenetreConfig()
*/

void f_MainWindow::on_actionConfiguration_Application_triggered()
{
    this->OuvrirFenetreConfig();
}

/** Méthode éxécutée lors de l'appuis sur le bouton "Nouveau Profil" dans le menu "Options" de la fenêtre principale
*
* @brief    f_MainWindow::on_actionNouveauProfil_triggered()
* @see      OuvrirFenetreProfil()
*/
void f_MainWindow::on_actionCreer_profil_triggered()
{
    this->OuvrirFenetreNouveauProfil();
}

/**
 * Ouvre une fenetre pour choisir le profil utilisateur
 *
 * @brief f_MainWindow::on_actionChoisirProfil_triggered
 */
void f_MainWindow::on_actionChanger_profil_triggered()
{
    this->OuvrirFenetreChoisirProfil() ;
}

/**
 * Ouvre une fenetre pour supprimer un profil
 *
 * @brief f_MainWindow::on_actionSupprimerProfil_triggered
 */
void f_MainWindow::on_actionSupprimer_profil_triggered()
{
    this->OuvrirFenetreSupprimerProfil() ;
}

/**
 * Ouvre une fenetre pour modifier le profil
 *
 * @brief f_MainWindow::on_actionModifierProfil_triggered
 */
void f_MainWindow::on_actionModifier_profil_triggered()
{
    this->OuvrirFenetreModifierProfil() ;
}

/** Méthode éxécutée lors du double clic sur un élément de la gestion de projet
*
* @brief    f_MainWindow::on_treeView_doubleClicked()
* @see      ChargerModule(QString sNomModule)
*/
void f_MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QStandardItemModel *    Model       (qobject_cast<QStandardItemModel*>(this->ui->treeView->model())) ;
    QStandardItem *         ItemSelect  (Model->itemFromIndex(index)) ;
    QStandardItem *         ItemParent  (ItemSelect->parent()) ;
    QString                 Texte       (ItemSelect->text()) ;
    QString                 TexteParent (ItemParent->text()) ;

    if(Texte == "Plan de câblage")
    {
        QMessageBox::information(this, "Plan de câblage", "ouverture du plan") ;
        QString NomProjetCourant("TempConfigArduino.ini");
        QFile ConfigCourante(NomProjetCourant);

        if(ConfigCourante.open(QFile::ReadWrite))
        {
            ConfigCourante.resize(0);
            ConfigCourante.write(ConfigurationArduinoCourante);
            ConfigCourante.close();

            AssistantConfiguration Wizard(NomProjetCourant);

            if(Wizard.LancerAssistant())
            {
                this->RechargerConfig(NomProjetCourant);
            }
        }
    }
    else
    {
        if(TexteParent == "Liste des modules")
        {
            this->ChargerModule(Texte) ;
        }
    }
}

/** Charge un module à partir de son nom : Le passe en tant que module courant et l'affiche.
*
* @brief    f_MainWindow::ChargerModule(QString sNomModule)
* @param    sNomModule  Nom du module devant être chargé
* @see      ModuleManager
*/
void f_MainWindow::ChargerModule(QString sNomModule)
{
    for(register int i = 0; i < this->Lst_pManagers.length(); i++)
    {
        if(this->Lst_pManagers[i]->getNomModule() == sNomModule)
        {
            this->IndiceModuleCourant = i;
        }
    }

    QTabWidget *    AffichageModule (0);

    AffichageModule = Lst_pManagers[this->IndiceModuleCourant]->getTabWidget();

    this->centralWidget()->setParent(0);
    this->setCentralWidget(AffichageModule);

    this->EtatProjetenCours.Etat.ModuleCharge = 1;
    this->ActiverActions(true);
    this->ActiverBt_ItemDock(true);
}

void f_MainWindow::RechargerConfig(QString ConfigActuelle)
{
    InterpreteurFichierIni* ParseurIni(new InterpreteurFichierIni(ConfigActuelle, this->pArduino));
    this->connect(ParseurIni, SIGNAL(FinConfigMaquette(InterpreteurFichierIni*,bool)), this, SLOT(slot_FinInterpretationIniOuvrirProjet(InterpreteurFichierIni*,bool)));
    ParseurIni->Interpreter();
}

/**
 * Zoom l'organigramme de 10%
 *
 * @brief f_MainWindow::on_actionAgrandir_triggered
 */
void f_MainWindow::on_actionAgrandir_triggered()
{
    QTabWidget *    Central (qobject_cast<QTabWidget *>(this->centralWidget())) ;

    QGraphicsView*  Vue     (qobject_cast<QGraphicsView *>(Central->currentWidget())) ;

    Vue->scale(1.1, 1.1);
    ui->actionVueGlobale->setEnabled(true);
}

/**
 * Dezoom l'organigramme de 10%
 *
 * @brief f_MainWindow::on_actionRetrecir_triggered
 */
void f_MainWindow::on_actionRetrecir_triggered()
{
    QTabWidget *    Central (qobject_cast<QTabWidget *>(this->centralWidget())) ;

    QGraphicsView*  Vue     (qobject_cast<QGraphicsView *>(Central->currentWidget())) ;

    Vue->scale(100.0/110.0, 100.0/110.0);
    ui->actionVueGlobale->setEnabled(true);
}

/**
 * Dezoom l'organigramme pour vue globale
 *
 * @brief f_MainWindow::on_actionVueGlobale_triggered
 */
void f_MainWindow::on_actionVueGlobale_triggered()
{
    QTabWidget *    Central (qobject_cast<QTabWidget *>(this->centralWidget())) ;

    QGraphicsView*  Vue     (qobject_cast<QGraphicsView *>(Central->currentWidget())) ;
    QList<QGraphicsItem *> ListeItems(Vue->items());

    int NombreItems = ListeItems.size();

    Vue->scale((10.0/NombreItems)/(1.0+(1.0/NombreItems)), (10.0/NombreItems)/(1.0+(1.0/NombreItems)));
    ui->actionVueGlobale->setEnabled(false);
}


/**
 * Appel de l'interpreteur de commande pour shell Mega Arduino
 *
 * @brief f_MainWindow::on_actionInterpreteur_triggered
 */
void f_MainWindow::on_actionInterpreteur_triggered()
{
    f_InterpreteurCommandes InterpreteurCommandes(this);

    connect(this->pArduino, SIGNAL(Signal_Temps(QTime)), &InterpreteurCommandes, SLOT(Signal_TempsL(QTime)) );
    connect(this->pArduino, SIGNAL(ArduinoConnect(int,QString)), &InterpreteurCommandes, SLOT(ArduinoConnect(int,QString)));
    connect(this->pArduino, SIGNAL(RetourCommandeGenerale(QByteArray)), &InterpreteurCommandes, SLOT(RecevoirDonneesL(QByteArray)));
    connect(&InterpreteurCommandes, SIGNAL(EnvoyerDonneesL(QString,EmetteurCommande)), this->pArduino, SLOT(EnvoyerDonnees(QString,EmetteurCommande)));

    this->pArduino->DemanderEtat();

    InterpreteurCommandes.exec();

    disconnect(this->pArduino, SIGNAL(Signal_Temps(QTime)), &InterpreteurCommandes, SLOT(Signal_TempsL(QTime)) );
    disconnect(this->pArduino, SIGNAL(ArduinoConnect(int,QString)), &InterpreteurCommandes, SLOT(ArduinoConnect(int,QString)));
    disconnect(this->pArduino, SIGNAL(RetourCommandeGenerale(QByteArray)), &InterpreteurCommandes, SLOT(RecevoirDonneesL(QByteArray)));
    disconnect(&InterpreteurCommandes, SIGNAL(EnvoyerDonneesL(QString,EmetteurCommande)), this->pArduino, SLOT(EnvoyerDonnees(QString,EmetteurCommande)));
}

/**
 * Modifie l'affichage de l'état de la connexion avec Arduino
 *
 * @brief f_MainWindow::slot_EtatConnexion
 * @param Etat
 * @param COM
 */
void f_MainWindow::slot_EtatConnexion(int Etat, QString COM)
{
    switch(Etat)
    {
    case 0:
        this->pEtatConnexion->setText("Maquette connectée et fonctionnelle (" + COM + ")");
        this->ui->actionRedemarrer_la_maquette->setEnabled(true);
        break;

    case 1:
        this->pEtatConnexion->setText("Maquette non connectée");
        this->ui->actionRedemarrer_la_maquette->setEnabled(false);
        break;

    case 2:
        this->pEtatConnexion->setText("Maquette connectée mais non fonctionnelle... (" + COM + ")");
        this->ui->actionRedemarrer_la_maquette->setEnabled(false);
        break;
    }
}

/**
 * Demande le démarrage de l'exécution
 * @brief f_MainWindow::on_actionExecuter_triggered
 */
void f_MainWindow::on_actionExecuter_triggered()
{
    this->Lst_pManagers[this->IndiceModuleCourant]->InitExecution();

    //S'il y a le mode pas à pas
    if(this->ui->actionDebug->isChecked())
    {
        this->on_actionJump_triggered();
    }
    else //Sinon départ normal
    {
        this->Lst_pManagers[this->IndiceModuleCourant]->LancerExecution();
    }
}

/**
 * Demande d'arrêt d'exécution
 * @brief f_MainWindow::on_actionArreter_triggered
 */
void f_MainWindow::on_actionArreter_triggered()
{
    this->Lst_pManagers[this->IndiceModuleCourant]->StopperExecution();
}

/**
 * Slot modifiant les action en fonction de l'etat d'exécution
 * @brief f_MainWindow::slot_EtatExecution
 * @param nEtat
 */
void f_MainWindow::slot_EtatExecution(int nEtat)
{
    switch(nEtat)
    {
    case PAUSE:
        this->ui->actionJump->setEnabled(true);
    case EN_EXEC:
        this->ui->actionDebug->setEnabled(false);
        this->ui->actionExecuter->setEnabled(false);
        this->ui->actionArreter->setEnabled(true);
        break;

    case ARRETE:
        this->ui->actionDebug->setEnabled(true);
        this->ui->actionExecuter->setEnabled(true);
        this->ui->actionArreter->setEnabled(false);
        this->ui->actionJump->setEnabled(false);
        break;
    }
}

/**
 * Demande de saut à l'instruction suivante
 * @brief f_MainWindow::on_actionJump_triggered
 */
void f_MainWindow::on_actionJump_triggered()
{
    this->Lst_pManagers[this->IndiceModuleCourant]->PasserInstSuiv();
}

/**
 * Demande d'ouverture d'un projet
 * @brief f_MainWindow::on_actionOuvrir_triggered
 */
void f_MainWindow::on_actionOuvrir_triggered()
{
    this->Ouvrir();
}

/**
 * Demande de compilation
 * @brief f_MainWindow::on_actionConvert_triggered
 */
void f_MainWindow::on_actionConvert_triggered()
{
    f_Compilation Compil(this->pArduino, this->Lst_pManagers, this);
    Compil.exec();
}

/**
 * Ouverture de la gestion de mémoire
 * @brief f_MainWindow::on_actionGestionMem_triggered
 */
void f_MainWindow::on_actionGestionMem_triggered()
{
    f_GestionMem Gestion(pArduino, this);
    Gestion.exec();
}

/**
 * Demande d'import depuis un plan de câblage existant
 * @brief f_MainWindow::on_actionImporter_triggered
 */
void f_MainWindow::on_actionImporter_triggered()
{
    //Vérification que le projet ouvert est bien sauvegardé
    if(this->ProjetSauve())
    {
        //Récuperation du fichier ini
        QString Chemin  (QFileDialog::getOpenFileName(this, "Importer un plan de câblage", QDir::homePath(), "Fichier ini (*.ini)"));

        if(Chemin != "")
        {
            if(this->EtatProjetenCours.Etat.ProjetOuvert == 1)
            {
                this->Fermer();
                this->ActiverBt_ItemDock(false);

                this->ActiverActions(false);

                this->EtatProjetenCours.Etat.ModuleCharge = 0;
                this->EtatProjetenCours.Etat.ProjetEnregistre = 0;
                this->EtatProjetenCours.Etat.ProjetOuvert = 0;
            }



            //S'il existe, on l'interprete
            if(!Chemin.isEmpty())
            {
                InterpreteurFichierIni* Interpreteur = new InterpreteurFichierIni(Chemin, pArduino, this);
                connect(Interpreteur, SIGNAL(FinConfigMaquette(InterpreteurFichierIni*, bool)), this, SLOT(slot_FinInterpretationIniImportConfig(InterpreteurFichierIni*, bool)));
                Interpreteur->Interpreter();
            }
        }

    }
}

/**
 * Slot de fin d'interpretation pour l'import
 * @brief f_MainWindow::slot_FinInterpretationIniImportConfig
 * @param Interpreteur
 * @param Reussi
 */
void f_MainWindow::slot_FinInterpretationIniImportConfig(InterpreteurFichierIni* Interpreteur, bool Reussi)
{
    //Récupération du chemin du fichier
    QString Chemin  (Interpreteur->getCheminFichierIni());

    //Destruction de l'interpreteur
    disconnect(Interpreteur, SIGNAL(FinConfigMaquette(InterpreteurFichierIni*, bool)), this, SLOT(slot_FinInterpretationIniImportConfig(InterpreteurFichierIni*, bool)));
    delete Interpreteur;

    //Si tout a fonctionné
    if(Reussi)
    {
        //On crée le nouveau projet
        this->CreerNouveauProjet(Chemin);
    }
    else //Sinon erreur
    {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors du chargement du plan de câblage... peut être qu'aucune maquette n'est connectée...");
    }
}

/**
 * Slot de fin d'interpretation en ouverture de fichier
 * @brief f_MainWindow::slot_FinInterpretationIniOuvrirProjet
 * @param Interpreteur
 * @param Reussi
 */
void f_MainWindow::slot_FinInterpretationIniOuvrirProjet(InterpreteurFichierIni* Interpreteur, bool Reussi)
{
    //Récuperation du chemin
    QString Chemin  (Interpreteur->getCheminFichierIni());

    //Destruction de l'interpreteur
    disconnect(Interpreteur, SIGNAL(FinConfigMaquette(InterpreteurFichierIni*, bool)), this, SLOT(slot_FinInterpretationIniImportConfig(InterpreteurFichierIni*, bool)));
    delete Interpreteur;

    //Si tout a réussi
    if(Reussi)
    {
        //On envois le fichier ini à la supervision
        //qobject_cast<f_Supervision*>(this->ui->DockSV->widget())->OuvrirFichierINI(Chemin);
    }
    else //Sinon erreur
    {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors du chargement du plan de câblage... peut être qu'aucune maquette n'est connectée...");
    }
}

/**
 * Slot de redémarrage de la maquette
 * @brief f_MainWindow::on_actionRedemarrer_la_maquette_triggered
 */
void f_MainWindow::on_actionRedemarrer_la_maquette_triggered()
{
    this->pArduino->EnvoyerDonnees(QString("Z"), GEN);
}

/**
 * Slot de gestion des composants I2C
 * @brief f_MainWindow::on_actionGestion_des_composants_I2C_triggered
 */
void f_MainWindow::on_actionGestion_des_composants_I2C_triggered()
{
    f_ConfigI2C ConfigI2C(this->pArduino, this);
    ConfigI2C.exec();
}

/**
 * Slot d'envoi de profil pour la paramètrage de l'application
 * @brief f_MainWindow::on_envoieProfil
 * @param ProfilActif
 */
void f_MainWindow::on_envoieProfil(QString ProfilActif)
{
    this->ProfilActif = ProfilActif ;
    this->show() ;
    if(this->ProfilActif == "Eleve")
    {
        ui->actionInterpreteur->setEnabled(false) ;
        ui->actionGestionMem->setEnabled(false) ;
        ui->actionGestion_des_composants_I2C->setEnabled(false) ;
        ui->actionRedemarrer_la_maquette->setEnabled(false) ;
        ui->actionCreer_profil->setEnabled(false) ;
        ui->actionModifier_profil->setEnabled(false) ;
        ui->actionSupprimer_profil->setEnabled(false) ;
        ui->actionConfiguration_Application->setEnabled(false) ;
    }
    if(this->ProfilActif == "Professeur")
    {
        ui->actionInterpreteur->setEnabled(true) ;
        ui->actionGestionMem->setEnabled(true) ;
        ui->actionGestion_des_composants_I2C->setEnabled(true) ;
        ui->actionRedemarrer_la_maquette->setEnabled(true) ;
        ui->actionCreer_profil->setEnabled(true) ;
        ui->actionModifier_profil->setEnabled(true) ;
        ui->actionSupprimer_profil->setEnabled(true) ;
        ui->actionConfiguration_Application->setEnabled(true) ;
    }
}


/**
 * Slot de demarrage du Serveur Web
 * @brief f_MainWindow::on_actionDemarrerServeurWeb_triggered
 */
void f_MainWindow::on_actionDemarrerServeurWeb_triggered()
{
    qDebug() << "Bouton masqué";
    this->ui->actionArreterServeurWeb->setEnabled(true) ; // Le bouton arreter se dégrise
    qDebug() << "Bouton visible";
    this->ui->actionDemarrerServeurWeb->setEnabled(false) ; // Le bouton démarrer se grise

    qDebug() << "Lancement du serveur ...";
    serveurWeb.lancerServeur(); // Lance le serveur Web
    qDebug() << "Serveur lancé";
    this->pTimerWeb = new QTimer;
    this->pTimerRafraichissement = new QTimer;

    DonneesWeb->Timer();

    DonneesWeb->Get_pTimer()->start(); // Affiche les données de la maquette dans la page web "Supervision.html"
    //qDebug() << "Timer Ok";
    bEtatTimer == true;
    DonneesWeb->on_EcrireDonneesDansPageHTML();
}


/**
 * Slot d'arret du Serveur Web
 * @brief f_MainWindow::on_actionArreterServeurWeb_triggered
 */
void f_MainWindow::on_actionArreterServeurWeb_triggered()
{
    this->DonneesWeb->Get_pTimer()->stop();
    this->pTimerWeb->stop();
    delete this->pTimerWeb;
    bEtatTimer == false;
    //this->DonneesWeb->pTimerRafraichissement->stop();
    this->ui->actionArreterServeurWeb->setEnabled(false) ; // Le bouton arreter serveur se grise
    this->ui->actionDemarrerServeurWeb->setEnabled(true);  // Le bouton démarrer serveur se dégrise
    serveurWeb.stopperServeur(); // Le serveur se stop

}

void f_MainWindow::on_EnvoieEtatServeur(bool EtatServeur)
{
    if(EtatServeur ==  true)
    {
        this->ui->actionArreterServeurWeb->setEnabled(true) ; // Le bouton arreter se dégrise
        this->ui->actionDemarrerServeurWeb->setEnabled(false) ; // Le bouton démarrer se grise
    }
    else
    {
        this->ui->actionArreterServeurWeb->setEnabled(false) ; // Le bouton arreter se dégrise
        this->ui->actionDemarrerServeurWeb->setEnabled(true) ; // Le bouton démarrer se grise
    }
}

/**
 * Slot d'ouverture de la fenêtre A propos
 * @brief f_MainWindow::on_actionA_propos_triggered
 */
void f_MainWindow::on_actionA_propos_triggered()
{
   this->OuvrirFenetreAPropos(); ; // Ouvre la fenêtre "A propos" qui donne des infos sur l'application.
}

/**
 * Méthode de récupération du nom de projet en cours
 * @brief f_MainWindow::RecupererNomProjet
 * @return retourne un QString: le nom du projet en courant
 */
QString f_MainWindow::RecupererNomProjet(QString sChemin)
{
    QSettings FichierINI(sChemin, QSettings::IniFormat);
    QString NomProjet = FichierINI.value("IDENTIFICATION/Nom", "Sans Nom").toString();

    return NomProjet;
}

/**
 * Méthode de création de l'arborescence du dossier des projets
 * @brief f_MainWindow::CreerArborescence
 * @param NomProjet
 * @return retourne un QString: le chemin du repertoire de  projet courant
 */
QString f_MainWindow::CreerArborescence(QString NomProjet)
{
    QDir RepertoireProjetCourant(QDir::currentPath());
    QString CheminRepertoireProjetCourant ("");

    CheminRepertoireProjetCourant = RepertoireProjetCourant.absolutePath()+"/Projets";
    if(!QDir(CheminRepertoireProjetCourant).exists())
    {
        if(!RepertoireProjetCourant.mkdir(CheminRepertoireProjetCourant))
        {
            QMessageBox test (this);
            test.setText("dossier ("+CheminRepertoireProjetCourant+") non créé!");
            test.exec();
        }
        qDebug() << "if" << CheminRepertoireProjetCourant;
        RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);

        CheminRepertoireProjetCourant = RepertoireProjetCourant.absolutePath()+"/"+NomProjet;
        if(!QDir(CheminRepertoireProjetCourant).exists())
        {
            if(!RepertoireProjetCourant.mkdir(CheminRepertoireProjetCourant))
            {
                QMessageBox test (this);
                test.setText("dossier Projets ("+NomProjet+") non créé!");
                test.exec();
            }
            qDebug() << "if if" <<CheminRepertoireProjetCourant;
            RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);
        }
        return RepertoireProjetCourant.absolutePath();
    }
    else
    {
        CheminRepertoireProjetCourant = RepertoireProjetCourant.absolutePath()+"/Projets/"+NomProjet;
        if(!QDir(CheminRepertoireProjetCourant).exists())
        {
            if(!RepertoireProjetCourant.mkdir(CheminRepertoireProjetCourant))
            {
                QMessageBox test (this);
                test.setText("dossier Projets ("+NomProjet+") non créé!");
                test.exec();
            }
            qDebug() << "else" << CheminRepertoireProjetCourant;
            RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);
        }
        else
        {
            CheminRepertoireProjetCourant = RepertoireProjetCourant.absolutePath()+"/Projets/"+NomProjet;
            qDebug() << "else else" << CheminRepertoireProjetCourant;
            RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);
        }
    }
    return RepertoireProjetCourant.absolutePath();
}

/**
 * Méthode de création de l'arborescence du dossier des projets
 * @brief f_MainWindow::CreerArborescence
 * @param NomProjet
 * @return retourne un booléen
 */
bool f_MainWindow::CreerPlanCablage(QString Chemin, QString NomProjet)
{
    QString CheminRepertoireProjetCourant("");
    QDir RepertoireProjetCourant(QDir::currentPath());

    CheminRepertoireProjetCourant = QApplication::applicationDirPath();
    RepertoireProjetCourant.setPath(CheminRepertoireProjetCourant);

    QString NomPlanDeCablage("");
    NomPlanDeCablage = NomProjet + "[Plandecablage].ini";
    QFile FichierCopier("TempConfigArduino.ini");

    FichierCopier.open(QFile::ReadOnly);
    QByteArray Contenu = FichierCopier.readAll();

    Chemin += "/"+NomProjet+".ini";
    RepertoireProjetCourant.setPath(Chemin);

    QFile PlanDeCablage(RepertoireProjetCourant.absolutePath());
    PlanDeCablage.open(QFile::ReadWrite);
    PlanDeCablage.write(Contenu);
    PlanDeCablage.close();

    if(PlanDeCablage.exists())
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool f_MainWindow::get_EtatTimer()
{
    return bEtatTimer;
}
