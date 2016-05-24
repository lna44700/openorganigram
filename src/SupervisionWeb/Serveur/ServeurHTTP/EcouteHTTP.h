/**
  @file
  @author Florian Philippeau
*/

#ifndef ECOUTEHTTP_H
#define ECOUTEHTTP_H

/** Includes QT */
#include <QTcpServer>
#include <QSettings>
#include <QBasicTimer>

/** Includes perso */
#include "GlobalHTTP.h"
#include "GestionnaireConnexionHTTP.h"
#include "PoolGestionnaireConnexionHTTP.h"
#include "GestionnaireRequeteHTTP.h"

/**
    Écoute les connexions TCP entrantes et passe toutes les requêtes HTTP entrantes à mon
    implémentation de Gestionnaire Requete HTTP, qui traite la demande et génére la réponse
    (généralement un document HTML).

  Exemple pour les paramètres requis dans le fichier de configuration (voir fichier Web.ini):

    ;host=192.168.0.100
    port=8080
    minThreads=1
    maxThreads=10
    cleanupInterval=1000
    readTimeout=60000
    maxRequestSize=16000
    maxMultiPartSize=1000000

    Le paramètre hôte optionnel lie l'auditeur à une interface réseau.
    L'écouteur gère toutes les interfaces réseau si aucun hôte est configuré.
    Le numéro de port spécifie le port TCP entrant que cet interlocuteur écoute.

    @see f_[Pool]GestionnaireConnexionHTTP pour la description des paramètres de
    configuration minThreads, maxThreads, CleanupInterval de cet
    interlocuteur d'écoute.
    @see f_GestionnaireConnexionHTTP pour la description de ReadTimeout
    @see f_RequeteHTTP pour la description des paramètres de configuration MaxRequestSize
    et max MultiPartSize
*/

class DECLSPEC EcouteHTTP : public QTcpServer {
    Q_OBJECT
    Q_DISABLE_COPY(EcouteHTTP)
public:

    /**
      Constructeur.
      Crée un pool de connexion et commence l'écoute sur l'hôte et le port configuré.
      @param parametres Les paramètres de configuration pour le serveur HTTP. Ne doit pas être 0.
      @param gestionnaireRequete Processus reçu par chaque requête HTTP, généralement par l'envoi
             au contrôleur des classes.
      @param parent Objet parent.
      @warning Je dois m'assurer de fermer ou de supprimer l'écouteur avant de supprimer le gestionnaire de requêtes.
    */
    EcouteHTTP();
    EcouteHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete, QObject* parent = NULL);

    /** Destructeur */
    virtual ~EcouteHTTP();

    /**
      Redémarrez l'écoute après la fermeture().
    */
    void listen();

    /**
    Ferme l'écouteur, attend jusqu'à ce que toutes les demandes en attente sont traitées,
    puis ferme le pool de connexion.
    */
    void close();

protected:

    /** Sert de nouvelles demandes de connexion entrantes */
    void incomingConnection(tSocketDescriptor socketDescriptor);

private:

    /** Les paramètres de configuration pour le serveur HTTP */
    QSettings* parametres;

    /** Pointe sur le gestionnaire de requêtes qui traite toutes les requêtes HTTP */
    GestionnaireRequeteHTTP* gestionnaireRequete;

    /** Pool de handles de connexion */
    PoolGestionnaireConnexionHTTP* pool;

signals:

    /**
      Envoyés au gestionnaire de connexion pour traiter une nouvelle connexion entrante.
      @param socketDescriptor références de la connexion acceptée.
    */

    void gestionConnexion(tSocketDescriptor socketDescriptor);

};

#endif // ECOUTEHTTP_H
