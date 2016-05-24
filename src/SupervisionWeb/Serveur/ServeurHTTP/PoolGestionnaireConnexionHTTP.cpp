/**
  @file
  @author Florian Philippeau
*/


//Includes QT
#include <QDir>

//Includes Perso
#include "PoolGestionnaireConnexionHTTP.h"

PoolGestionnaireConnexionHTTP::PoolGestionnaireConnexionHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete)
    : QObject()
{
    Q_ASSERT(parametres!=0);
    this->parametres=parametres;
    this->gestionnaireRequete=gestionnaireRequete;

    minuteurNettoyage.start(parametres->value("nettoyerInterval",1000).toInt());
    connect(&minuteurNettoyage, SIGNAL(timeout()), SLOT(nettoyer()));
}


PoolGestionnaireConnexionHTTP::~PoolGestionnaireConnexionHTTP()
{
    // delete all connection gestionnaires and wait until their threads are closed
    foreach(GestionnaireConnexionHTTP* gestionnaire, pool)
    {
       delete gestionnaire;
    }
    qDebug("PoolGestionnaireConnexionHTTP (%p): detruit", this);
}


GestionnaireConnexionHTTP* PoolGestionnaireConnexionHTTP::getGestionnaireConnexion()
{
    GestionnaireConnexionHTTP* gestionnaireDroits=0;
    mutex.lock();
    // find a free gestionnaire in pool
    foreach(GestionnaireConnexionHTTP* gestionnaire, pool)
    {
        if (!gestionnaire->estOccupe())
        {
            gestionnaireDroits=gestionnaire;
            gestionnaireDroits->setOccupe();
            break;
        }
    }
    // create a new gestionnaire, if necessary
    if (!gestionnaireDroits)
    {
        int gestionnaireConnexionMax=parametres->value("maxThreads",100).toInt();
        if (pool.count()<gestionnaireConnexionMax)
        {
            gestionnaireDroits=new GestionnaireConnexionHTTP(parametres,gestionnaireRequete);
            gestionnaireDroits->setOccupe();
            pool.append(gestionnaireDroits);
        }
    }
    mutex.unlock();
    return gestionnaireDroits;
}


void PoolGestionnaireConnexionHTTP::nettoyer()
{
    int gestionnaireInactiviteMax =parametres->value("minThreads",1).toInt();
    int compteurIinactivite=0;
    mutex.lock();
    foreach(GestionnaireConnexionHTTP* gestionnaire, pool)
    {
        if (!gestionnaire->estOccupe())
        {
            if (++compteurIinactivite > gestionnaireInactiviteMax )
            {
                delete gestionnaire;
                pool.removeOne(gestionnaire);
                qDebug("PoolGestionnaireConnexionHTTP: Suppression GestionnaireConnexion (%p), pool size is now %i",gestionnaire,pool.size());
                break; // remove only one gestionnaire in each interval
            }
        }
    }
    mutex.unlock();
}

