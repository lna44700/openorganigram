#include "AfficherDonnees.h"
#include "Supervision/f_Supervision.h"
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QCoreApplication>
#include <QDir>
#include <ostream>
#include <fstream>
#include <QIODevice>

using namespace std;


/** Cherche le fichier de configuration */
QString searchCablageFileIni()
{
    //QString binDir=QCoreApplication::applicationDirPath();
    QString appName="TempConfigArduino";
    QString fileName(appName+".ini");

    /*QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir+"src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../../src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../"+appName+"src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../../"+appName+"src/SupervisionWeb/Web/etc");
    searchList.append(binDir+"/../../../"+appName+"src/SupervisionWeb/Web/etc/etc");
    searchList.append(binDir+"/../../../../"+appName+"src/SupervisionWeb/Web/etc/etc");
    searchList.append(binDir+"/../../../../../"+appName+"src/SupervisionWeb/Web/etc/etc");
    searchList.append(QDir::rootPath()+"src/SupervisionWeb/Web/etc/opt");
    searchList.append(QDir::rootPath()+"etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir+"/"+fileName);
        if (file.exists())
        {
            // found
            fileName=QDir(file.fileName()).canonicalPath();
            qDebug("Utiliser le fichier de configuration %s",qPrintable(fileName));
            return fileName;
        }
    }

    // not found
    foreach (QString dir, searchList)
    {
        qWarning("%s/%s pas trouve",qPrintable(dir),qPrintable(fileName));
    }
    qFatal("ne trouve pas le fichier de configuration %s",qPrintable(fileName));
    return 0; */
}

AfficherDonnees::AfficherDonnees()
{


}

AfficherDonnees::~AfficherDonnees()
{

}

AfficherDonnees::AfficherNomBroche()
{
    //Compteur(0),
    //bAttenteReponse(false)
    //pArduino->setSimulation(this);

     // Timer de l'arduino
    //this->CompteurSup.setInterval(200);                                                   //On définit un intervalle  pour le Timer
    //connect(&(this->CompteurSup),SIGNAL(timeout()),this, SLOT(on_TempsFinit()));              //Lorsque le temps est atteint, on lance Detection

    //this->connect(pArduino, SIGNAL(RetourCommandeSupervision(QByteArray)), this, SLOT(RetourCommande(QByteArray))); //On récupère le signal de retour de commande de supervsion au retour de commande de la classe






    // Cherche fichier de configuration
        //QString configFileName=searchCablageFileIni();
        QString appName="TempConfigArduino";
        QString configFileName(appName+".ini");

    // Ouverture du fichier INI
    QSettings fileSettingsNom(configFileName, QSettings::IniFormat);

    //QSettings FichierIni(sChemin,QSettings::IniFormat) ;
    QStringList ListeGroupe(fileSettingsNom.childGroups());
   // QStringList ListeValeurIocard(fileSettingsNom.allKeys());

    QString DebutFichier("<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"utf-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><meta name=\"description\" content=\"\"><meta name=\"author\" content=\"\"><link rel=\"icon\" href=\"logo.png\"><title>OpenOrganigram</title><!-- Bootstrap core CSS --><link href=\"bootstrap.min.css\" rel=\"stylesheet\"><!-- IE10 viewport hack for Surface/desktop Windows 8 bug --><link href=\"ie10-viewport-bug-workaround.css\" rel=\"stylesheet\"><!-- Custom styles for this template --><link href=\"starter-template.css\" rel=\"stylesheet\"><!-- Just for debugging purposes. Don\'t actually copy these 2 lines! --><!--[if lt IE 9]><script src=\"../../assets/js/ie8-responsive-file-warning.js\"></script><![endif]--><script src=\"../../assets/js/ie-emulation-modes-warning.js\"></script><!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries --><!--[if lt IE 9]><script src=\"https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js\"></script><script src=\"https://oss.maxcdn.com/respond/1.4.2/respond.min.js\"></script><![endif]--><meta http-equiv=\"Refresh\" content=\"1.5; url=Supervision.html\"></head><body><nav class=\"navbar navbar-inverse navbar-fixed-top\"><div class=\"container\"><div class=\"navbar-header\"><button type=\"button\" class=\"navbar-toggle collapsed\" data-toggle=\"collapse\" data-target=\"#navbar\" aria-expanded=\"false\" aria-controls=\"navbar\"><span class=\"sr-only\">Menu</span><span class=\"icon-bar\"></span><span class=\"icon-bar\"></span><span class=\"icon-bar\"></span></button><a class=\"navbar-brand\" href=\"index.html\">OpenOrganigram</a></div><div id=\"navbar\" class=\"collapse navbar-collapse\"><ul class=\"nav navbar-nav\"><li  class=\"active\"><a href=\"Supervision.html\">Supervision maquette</a></li><li><a href=\"Aide.html\">Aide</a></li></ul></div><!--/.nav-collapse --></div></nav><div class=\"container\"><br><br><div class=\"alert alert-warning\" role=\"alert\"><center><b>Attention !</b> Le programme ne renvoie actuellement pas les donn&#233es des capteurs/actionneurs, cela sera fait prochainement. </center></div><div class=\"alert alert-success\" role=\"alert\"><center><b>Nom du projet en cours : </b>");
    //On récupère le nom du projet
    QString NomProjet = fileSettingsNom.value("IDENTIFICATION/Nom", "").toString();
    //On écrit le nom du projet sur la page supervision
    QString NomProjetWeb = NomProjet;
    //On récupère le nom de la carte Arduino
    QString NomCarteArduino = fileSettingsNom.value("IDENTIFICATION/Board", "").toString();
    //On écrit le nom de la carte Arduino sur la page supervision
    QString NomCarteArduinoWeb = NomCarteArduino;
    QString DebutFichierBis(" - <b>Carte programm&#233e sur le serveur WEB: </b>");
    QString DebutFichier2("</center></div><div class=\"starter-template\"><div class=\"panel panel-default\"><div class=\"panel-heading\">&#201tat des capteurs/actionneurs connect&#233s &#224 la maquette.</div><table class=\"table table-bordered\"><thead><tr><th><center>Num&#233ro broche du Shield</center></th><th><center>Nom du capteur/actionneur</center></th><th><center>Visuel</center></th><th><center>Etat du capteur/actionneur</center></th></tr></thead><tbody>");
    QString DebutTab("");
    QString Broche;
    QString Nom;
    QString Visuel;
    QString Valeur = ("?");
    QString FinTab("</tr></table>");

    QFile f("www/Supervision.html");
    if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&f);

            out << DebutFichier;
            out << NomProjetWeb;
            out << DebutFichierBis;
            out << NomCarteArduinoWeb;
            out << DebutFichier2;
            out << DebutTab;
            f.close();
        }
    f.close();

    for(register int i = 0; i < ListeGroupe.length(); i++)
    {
        if(ListeGroupe[i].contains("BROCHE"))
        {
            qDebug() << ListeGroupe[i];

            fileSettingsNom.beginGroup(ListeGroupe[i]);

                Nom = fileSettingsNom.value("Iocard").toString();
                Broche = fileSettingsNom.value("Nom").toString();

                Visuel = "<img src=\"/IOCard/"+Nom+"/photo.png\" alt=\"photo\">";

                //QSettings   ConfigCarte("./IOCard/" +Nom+ "/config.ini", QSettings::IniFormat);
                //Valeur = ConfigCarte.value("SUP/TxtOn").toString();

                 //QFile f("www/TestSupervision.html");
                if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                {
                    QTextStream out(&f);
                    out <<"<tr><td><br>" <<Broche << "</td><td><br>" << Nom << "</td><td>" << Visuel << "</td><td><br>"<< Valeur << "</td></tr>";

                     f.close();
                }

                f.close();

            fileSettingsNom.endGroup();
        }
    }

    QString FinFichier ("</tbody></table><!-- /.container --></body></html>");




    if (f.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&f);

            out << FinTab;
            out << FinFichier;
            f.close();
        }
    f.close();
}

