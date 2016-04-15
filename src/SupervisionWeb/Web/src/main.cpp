/**
  @file
  @author Florian Philippeau
*/

//Includes QT
#include <QCoreApplication>
#include <QDir>

//Include Perso
#include "f_EcouteHTTP.h"
#include "f_ControleurFichierStatique.h"
#include "f_RequeteMapper.h"

/** Controller for static files */
ControleurFichierStatique* controleurFichierStatique;

/** Search the configuration file */
QString searchConfigFile()
{
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QString fileName(appName+".ini");

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir+"/etc");
    searchList.append(binDir+"/../etc");
    searchList.append(binDir+"/../../etc");
    searchList.append(binDir+"/../"+appName+"/etc");
    searchList.append(binDir+"/../../"+appName+"/etc");
    searchList.append(binDir+"/../../../"+appName+"/etc");
    searchList.append(binDir+"/../../../../"+appName+"/etc");
    searchList.append(binDir+"/../../../../../"+appName+"/etc");
    searchList.append(QDir::rootPath()+"etc/opt");
    searchList.append(QDir::rootPath()+"etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir+"/"+fileName);
        if (file.exists())
        {
            // found
            fileName=QDir(file.fileName()).canonicalPath();
            qDebug("Using config file %s",qPrintable(fileName));
            return fileName;
        }
    }

    // not found
    foreach (QString dir, searchList)
    {
        qWarning("%s/%s not found",qPrintable(dir),qPrintable(fileName));
    }
    qFatal("Cannot find config file %s",qPrintable(fileName));
    return 0;
}


/**
  Entry point of the program.
*/
int main(int argc, char *argv[])
{
    QCoreApplication app(argc,argv);

    app.setApplicationName("Web");

    // Find the configuration file
    QString configFileName=searchConfigFile();


    // Configure static file controller
    QSettings* fileSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    fileSettings->beginGroup("www");
    controleurFichierStatique=new ControleurFichierStatique(fileSettings,&app);

    // Configure and start the TCP listener
    QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,&app);
    listenerSettings->beginGroup("listener");
    new EcouteHTTP(listenerSettings,new RequeteMapper(&app),&app);

    qWarning("Application lancee");

    app.exec();

    qWarning("Application stoppee");
}
