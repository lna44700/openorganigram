/**
  @file
  @author Florian Philippeau
*/

//Includes QT
#include <QCoreApplication>

//Includes Perso
#include "f_RequeteMapper.h"
#include "f_ControleurFichierStatique.h"


/** Controller for static files */
extern ControleurFichierStatique* controleurFichierStatique;

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
