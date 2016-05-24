/**
  @file
  @author Florian Philippeau
*/

#ifndef POOLGESTIONNAIRECONNEXIONHTTP_H
#define POOLGESTIONNAIRECONNEXIONHTTP_H

/** Includes QT */
#include <QList>
#include <QTimer>
#include <QObject>
#include <QMutex>

/** Includes Perso */
#include "GlobalHTTP.h"
#include "GestionnaireConnexionHTTP.h"

/**
    Pool de gestionnaires de connexion http. La taille du pool se développe et
    rétrécit à la demande.

    Après le démarrage du serveur, la taille du pool de threads est toujours 0. Les threads
    sont lancés à la demande lorsque les demandes entrent en jeu. La minuterie de nettoyage réduit
    le nombre de threads inactifs lentement en fermant un thread dans chaque intervalle.
    Mais le nombre maximum configuré de thread sont tenus au cours d'exécution.

  @see f_GestionnaireConnexionHTTP pour la description de ReadTimeout
  @see f_RequeteHTTP pour la description de config paramètres MaxRequestSize et maxMultiPartSize
*/

class DECLSPEC PoolGestionnaireConnexionHTTP : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(PoolGestionnaireConnexionHTTP)
public:

    /**
      Constructeur.
      @param parametres Les paramètres de configuration pour le serveur HTTP. Ne doit pas être 0.
      @param gestionnaireRequete Le gestionnaire qui va traiter chaque requête HTTP reçu.
      @warning Le requeteMapper est supprimé par le destructeur de cette pool.
    */
    PoolGestionnaireConnexionHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete);

    /** Destructeur */
    virtual ~PoolGestionnaireConnexionHTTP();

    /** Obtenez un gestionnaire de connexion libre, ou 0 si non disponible. */
    GestionnaireConnexionHTTP* getGestionnaireConnexion();

private:

    /** paramètres pour cette pool */
    QSettings* parametres;

    /** Sera attribué à chaque GestionnaireConnexion lors de leur création*/
    GestionnaireRequeteHTTP* gestionnaireRequete;

    /** Pool de handles de connexion */
    QList<GestionnaireConnexionHTTP*> pool;

    /** Timer pour le nettoyage gestionnaire de connexion inutilisé */
    QTimer minuteurNettoyage;

    /** Utilisé pour synchroniser les threads */
    QMutex mutex;

private slots:

    /** Reçu de la minuterie de nettoyage.  */
    void nettoyer();

};

#endif // POOLGESTIONNAIRECONNEXIONHTTP_H
