/**
  @file
  @author Florian Philippeau
*/

//Includes Perso
#include "GestionnaireRequeteHTTP.h"

GestionnaireRequeteHTTP::GestionnaireRequeteHTTP(QObject* parent)
    : QObject(parent)
{

}

GestionnaireRequeteHTTP::~GestionnaireRequeteHTTP()
{

}

void GestionnaireRequeteHTTP::service(RequeteHTTP& requete, HttpReponse& reponse)
{
    qCritical("GestionnaireRequeteHTTP: vous devez remplacer la fonction de service");
    qDebug("GestionnaireRequeteHTTP: requete=%s %s %s",requete.getMethode().data(),requete.getChemin().data(),requete.getVersion().data());
    reponse.setStatus(501,"pas mis en oeuvre");
    reponse.ecrire("501 pas mis en oeuvre",true);
}
