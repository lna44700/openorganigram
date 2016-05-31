/** @file       Donnees.cpp
* @brief        Données qui seront écrite dans la page Supervision.html.
*
* @author       PHILIPPEAU Florian
* @author       STS SNIR, Lycée Nicolas APPERT, ORVAULT (FRANCE)
* @since        11/04/2016
* @version      1.0
* @date         11/04/2016
*
* Fabrication   OpenOrganigram.pro
*
* @todo         Donnée de supervision.
*
* @bug          26/04/2016 - Non corrigé - le connect du constructeur par défaut plante le programme.
*/


//Includes perso
#include "Donnees.h"
#include "Supervision/f_Supervision.h"

//Includes de QT
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QCoreApplication>
#include <QDir>
#include <ostream>
#include <fstream>
#include <QIODevice>
#include <QDebug>
//#include <QThread>
#include <QSemaphore>
#include <QTimer>
//#include <QObject>
#include <unistd.h>

using namespace std;

/** Constructeur par défaut de la classe Donnees
* Ces données seront affichées dans la page Supervision.html
* @see     Donnees::Donnees()
*/
Donnees::Donnees()
{

}


/** Constructeur paramètré de la classe Donnees
* Ces données seront affichées dans la page Supervision.html
* @see     Donnees::Donnees()
*/
Donnees::Donnees(Arduino *pControleur, QObject * parent):
    QObject (parent),
    bAttenteReponse(false),
    pArduino(pControleur),
    Compteur(0)
{ 

}

/** Destructeur de la classe Donnees
* @see     Donnees::~Donnees()
*/
Donnees::~Donnees()
{
    this->pArduino=0;
    this->Compteur=0;
    this->bAttenteReponse=false;
    this->pTimerWeb->stop();
    delete this->pTimerWeb;
}

/** Permet l'écriture de la page Supervision.html
* Ces données seront affichées dans la page Supervision.html
* @see     Donnees::EcrireDonneesDansPageHTML()
*/
void Donnees::on_EcrireDonneesDansPageHTML()
{

    remove ("www/Supervision.html");

    qDebug() << "Supervision.html supprimé";

    // Cherche fichier de configuration
        QString sConfiguration="TempConfigArduino";
        QString sNomFichierConfiguration(sConfiguration+".ini");

    // Ouverture du fichier INI
    QSettings FichierConfiguration(sNomFichierConfiguration, QSettings::IniFormat);

    //QSettings FichierIni(sChemin,QSettings::IniFormat) ;
    QStringList ListeGroupe(FichierConfiguration.childGroups());
   // QStringList ListeValeurIocard(FichierConfiguration.allKeys());

    //Durée de rafraichissement de la supervision WEB
    // Cherche fichier de configuration
    QString sConfigurationServeur="ConfigurationServeurWeb";
    QString sNomFichierConfigurationServeur(sConfigurationServeur+".ini");
    // Ouverture du fichier INI
    QSettings FichierConfigurationServeur(sNomFichierConfigurationServeur, QSettings::IniFormat);
    QString sRafraichissementPage = FichierConfigurationServeur.value("www/dureeRafraichissement","ConfigurationServeurWeb").toString();



    //String comprenant le début du code de la page "Supervision.html"
    QString sDebutFichier("<!DOCTYPE html><html lang=\"fr\"><head><meta charset=\"utf-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><meta name=\"description\" content=\"\"><meta name=\"author\" content=\"\"><link rel=\"icon\" href=\"logo.png\"><title>OpenOrganigram</title><!-- Bootstrap core CSS --><link href=\"bootstrap.min.css\" rel=\"stylesheet\"><!-- IE10 viewport hack for Surface/desktop Windows 8 bug --><link href=\"ie10-viewport-bug-workaround.css\" rel=\"stylesheet\"><!-- Custom styles for this template --><link href=\"starter-template.css\" rel=\"stylesheet\"><!-- Just for debugging purposes. Don\'t actually copy these 2 lines! --><!--[if lt IE 9]><script src=\"../../assets/js/ie8-responsive-file-warning.js\"></script><![endif]--><script src=\"../../assets/js/ie-emulation-modes-warning.js\"></script><!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries --><!--[if lt IE 9]><script src=\"https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js\"></script><script src=\"https://oss.maxcdn.com/respond/1.4.2/respond.min.js\"></script><![endif]-->"
"<meta http-equiv=\"Refresh\" content=\""+sRafraichissementPage +"; url=Supervision.html\">"
                          "</head><body><nav class=\"navbar navbar-inverse navbar-fixed-top\"><div class=\"container\"><div class=\"navbar-header\"><button type=\"button\" class=\"navbar-toggle collapsed\" data-toggle=\"collapse\" data-target=\"#navbar\" aria-expanded=\"false\" aria-controls=\"navbar\"><span class=\"sr-only\">Menu</span><span class=\"icon-bar\"></span><span class=\"icon-bar\"></span><span class=\"icon-bar\"></span></button><a class=\"navbar-brand\" href=\"index.html\">OpenOrganigram</a></div><div id=\"navbar\" class=\"collapse navbar-collapse\"><ul class=\"nav navbar-nav\"><li  class=\"active\"><a href=\"Supervision.html\">Supervision maquette</a></li><li><a href=\"Aide.html\">Aide</a></li></ul></div><!--/.nav-collapse --></div></nav><div class=\"container\"><br><br><div class=\"alert alert-warning\" role=\"alert\"><center><b>Attention !</b> Tests du projet </center></div><div class=\"alert alert-success\" role=\"alert\"><center><b>Nom du projet en cours : </b>");

    this->pTimerRafraichissement->setInterval(sRafraichissementPage.toInt()*1000);

    //On récupère le nom du projet
    QString sNomProjet = FichierConfiguration.value("IDENTIFICATION/Nom", "").toString();
    //On écrit le nom du projet sur la page supervision
    QString sNomProjetWeb = sNomProjet;
    //On récupère le nom de la carte Arduino
    QString NomCarteArduino = FichierConfiguration.value("IDENTIFICATION/Board", "").toString();
    //On écrit le nom de la carte Arduino sur la page supervision
    QString sNomCarteArduinoWeb = NomCarteArduino;
    //On écrit le taut de rafraichissement de la page Web
    QString sRafraichissementEcrit = " - <b>Taux de rafraichissement de la page: </b> " + sRafraichissementPage + " sec";
    QString sDebutFichierBis(" - <b>Carte programm&#233e sur le serveur WEB: </b>");
    QString sDebutFichier2("</center></div><div class=\"starter-template\"><div class=\"panel panel-default\"><div class=\"panel-heading\">&#201tat des capteurs/actionneurs connect&#233s &#224 la maquette.</div><table class=\"table table-bordered\"><thead><tr><th><center>Num&#233ro broche du Shield</center></th><th><center>Nom du capteur/actionneur</center></th><th><center>Visuel</center></th><th><center>Etat du capteur/actionneur</center></th></tr></thead><tbody>");
    QString sDebutTab("");
    QString sBroche;
    QString sNom;
    QString sVisuel;
    QString sTypeCarte;
    QString sFinTab("</tr></table>");
    //String pour écriture de la fin code HTML
    QString sFinFichier ("</tbody></table><!-- /.container --></body></html>");

    QFile f("www/Supervision.html");
    if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&f);

            out << sDebutFichier; //écriture du début du fichier
            out << sNomProjetWeb; //écriture du nom du projet
            out << sDebutFichierBis; //écriture de la suite du fichier
            out << sNomCarteArduinoWeb; //écrite du nom de la carte
            out << sRafraichissementEcrit; // écriture du taux de rafraichissement
            out << sDebutFichier2; // écriture du fichier (suite)
            out << sDebutTab; // écriture des premières balises du tableau
            f.close();
        }

    for(register int i = 0; i < ListeGroupe.length(); i++)
    {
        if(ListeGroupe[i].contains("BROCHE"))
        {
            qDebug() << "Liste groupe[i]" << ListeGroupe[i];

            FichierConfiguration.beginGroup(ListeGroupe[i]);

                sNom = FichierConfiguration.value("Iocard").toString();
                sBroche = FichierConfiguration.value("Nom").toString();

                //Code pour afficher la photo du capteur/actionneur sur la page
                sVisuel = "<img src=\"/IOCard/"+sNom+"/photo.png\" alt=\"photo\">";



                sTypeCarte = FichierConfiguration.value("Type").toString();
                qDebug() << "Type carte" << sTypeCarte;

               QString sBrocheNumerique = FichierConfiguration.value("Broche_Numerique").toString();
               QString sBrocheAnalogique = FichierConfiguration.value("Broche_Analogique").toString();

               QString sCommande;


                //Type carte
                if(sTypeCarte=="NI" || sTypeCarte=="NO")
                {
                    sCommande = "R" + sBrocheNumerique;
                }
                if(sTypeCarte=="AI" || sTypeCarte=="AO")
                {
                    sCommande = "A" + sBrocheAnalogique;
                }


                 qDebug() << "Commande :" <<sCommande;

                int nRetour(0);
                QString sRetour;

             //Pour la récupération des valeurs!
             nRetour = this->pArduino->LireCapteur(sCommande);

                qDebug () << "Commande envoyée :" << sCommande ;
                qDebug () << "nRetour : " + nRetour;

                if(sNom == "LED jaune"||sNom == "LED rouge"||sNom == "LED verte")
                {
                    if(nRetour == 1)
                    {
                        sRetour = "LED allum&#233e" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "LED &#233teinte" ;
                    }
                }
                else if(sNom == "Bouton poussoir vert"||sNom == "Bouton poussoir blanc"||sNom == "Bouton poussoir noir"||sNom == "Bouton poussoir rouge")
                {
                    if(nRetour == 1)
                    {
                        sRetour = "Bouton relach&#233" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "Bouton enfonc&#233" ;
                    }
                }
                else if(sNom == "Potentiometre")
                {
                    sRetour = "Valeur : " + QString::number(nRetour);
                }
                else if(sNom == "Capteur fin de course" )
                {
                    if(nRetour == 1)
                    {
                        sRetour = "Inactif" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "Actif" ;
                    }
                }

                else if(sNom == "Barriere infrarouge" )
                {
                    if(nRetour == 1)
                    {
                        sRetour = "Aucun obstacle n'est d&#233tect&#233" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "Obstacle d&#233tect&#233" ;
                    }
                }
                else if(sNom == "Capteur de Luminosite")
                {
                    QSettings   Configuration("./IOCard/" + sNom + "/config.ini", QSettings::IniFormat);
                    Expression = Configuration.value("SUP/Expression").toString();
                    qDebug() << "Expression : " << Expression ;
                    QString Inconnue = Configuration.value("SUP/Inconnue").toString();
                    val = nRetour;
                    if(!Expression.isEmpty() && !Inconnue.isEmpty())
                    {
                        Parser.DefineVar(Inconnue.toStdString().c_str(), &val);
                        qDebug () << val;
                        Parser.SetExpr(Expression.toStdString().c_str());
                    }

                    double aff(0);

                    if(!Expression.isEmpty())
                    {
                        aff = Parser.Eval();
                    }
                    else
                    {
                        aff = val;
                    }

                    sRetour = "Luminosit&#233 : " + QString::number(aff) + " lux";
                }
                else if(sNom == "Capteur de Temperature CTN")
                {
                    QSettings   Configuration("./IOCard/" + sNom + "/config.ini", QSettings::IniFormat);
                    Expression = Configuration.value("SUP/Expression").toString();
                    qDebug() << "Expression : " << Expression ;
                    QString Inconnue = Configuration.value("SUP/Inconnue").toString();
                    val = nRetour;
                    if(!Expression.isEmpty() && !Inconnue.isEmpty())
                    {
                        Parser.DefineVar(Inconnue.toStdString().c_str(), &val);
                        qDebug () << val;
                        Parser.SetExpr(Expression.toStdString().c_str());
                    }

                    double aff(0);

                    if(!Expression.isEmpty())
                    {
                        aff = Parser.Eval();
                    }
                    else
                    {
                        aff = val;
                    }

                    sRetour = "Temp&#233rature : " + QString::number(aff) + " &#176C";
                }
                else if(sNom == "Detecteur de mouvement" )
                {
                    if(nRetour == 1)
                    {
                        sRetour = "Un mouvement est d&#233tect&#233" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "Aucun mouvement n'est d&#233tect&#233" ;
                    }
                }
                else if(sNom == "ILS" )
                {
                    if(nRetour == 1)
                    {
                        sRetour = "Aimant absent" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "Aimant présent" ;
                    }
                }
                else if(sNom == "Detecteur de ligne" )
                {
                    if(nRetour == 1)
                    {
                        sRetour = "Couleur non d&#233tect&#233e" ;
                    }
                    else if(nRetour == 0)
                    {
                        sRetour = "Couleur d&#233tect&#233e" ;
                    }
                }
                else if(sNom == "Telecommande InfraRouge" )
                {
                    sRetour = " Touche appuy&#233e : - " ;
                }
                else if(sNom == "Horloge temps reel DS1307" || sNom == "Commande Servo Moteur" || sNom == "Connexion directe d'un Moteur" || sNom == "Moteur broche DIR" || sNom == "Moteur broche PWM" || sNom == "Moteur MOT2 broche DIR" || sNom == "Moteur MOT2 broche PWM" || sNom == "Buzzer")
                {
                        sRetour = " - " ;
                }
                else
                {
                    sRetour = "Valeur : " + QString::number(nRetour);
                }

                if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream out(&f);
                    // Remplissage du tableau
                    out <<"<tr><td><br>" <<sBroche << "</td><td><br>" << sNom << "</td><td>" << sVisuel << "</td><td><br>"<< sRetour << "</td></tr>";
                     f.close();
                }


            FichierConfiguration.endGroup();
        }
    }
    if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {

            QTextStream out(&f);
            out << sFinTab; // écriture de la fin du tableau
            out << sFinFichier; // écriture de la fin du code HTML
            f.close();
        }
    qDebug() << "Données écrite";

    this->pTimerRafraichissement->start();

    this->pTimerWeb->stop();
}

QTimer * Donnees::Get_pTimer()
{
    return this->pTimerWeb;
}

void Donnees::Timer()
{
     this->pTimerWeb = new QTimer;
     this->pTimerRafraichissement = new QTimer;

     qDebug() << "Timer construit";
     connect(pTimerWeb,SIGNAL(timeout()),this,SLOT(on_EcrireDonneesDansPageHTML()));
     connect(pTimerRafraichissement,SIGNAL(timeout()),this,SLOT(on_EcrireDonneesDansPageHTML()));
     qDebug() << "Connect Timer Ok";
     this->pTimerWeb->start(700);
}

void Donnees::StoperTimer()
{
    this->pTimerWeb->stop();
    delete this->pTimerWeb;
}

bool Donnees::get_EtatTimer()
{
    return bEtatTimer;
}
