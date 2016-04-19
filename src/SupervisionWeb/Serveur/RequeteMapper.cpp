/**
  @file
  @author Florian Philippeau
*/

//Includes QT
#include <QCoreApplication>

//Includes Perso
#include "RequeteMapper.h"
#include "ControleurFichierStatique.h"


/** Contrôleur pour les fichiers statiques */
ControleurFichierStatique* controleurFichierStatique;

RequeteMapper::RequeteMapper(QObject* parent)
    :GestionnaireRequeteHTTP(parent)
{
    qDebug("RequeteMapper : cree");
}


RequeteMapper::~RequeteMapper()
{
    qDebug("RequeteMapper : supprime");
}


void RequeteMapper::service(RequeteHTTP& requete, HttpReponse& response)
{
    QByteArray path=requete.getChemin();
    qDebug("RequeteMapper : path=%s",path.data());


    controleurFichierStatique->service(requete, response);


    qDebug("RequeteMapper : Requete Terminee");

}
