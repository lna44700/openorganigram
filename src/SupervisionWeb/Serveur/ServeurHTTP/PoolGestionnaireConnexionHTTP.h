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

    Pour le support SSL, j'ai besoin d'un fichier de certificat OpenSSL et d'un fichier de clé.
    Les deux peuvent être créés avec la commande suivante :

    openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout my.key -out my.cert

    Visitez http://slproweb.com/products/Win32OpenSSL.html pour télécharger
    la version Light de OpenSSL pour Windows.

    Attention ! Un écouteur avec paramêtres SSL ne peut gérer le protocole HTTPS.
    Pour prendre en charge les protocoles HTTP et HTTPS simultanément, je dois
    commencer à deux auditeurs sur des ports différents - une avec ALL et un sans SSL.

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

    /** La configuration de SSL (certificat, clé et autres paramètres) */
    QSslConfiguration* sslConfiguration;

    /** Charger configuration SSL */
    void chargerSslConfig();

private slots:

    /** Reçu de la minuterie de nettoyage.  */
    void nettoyer();

};

#endif // POOLGESTIONNAIRECONNEXIONHTTP_H
