/**
  @file
  @author Florian Philippeau
*/

#ifndef GESTIONNAIRECONNEXIONHTTP_H
#define GESTIONNAIRECONNEXIONHTTP_H

#ifndef QT_NO_OPENSSL
   #include <QSslConfiguration>
#endif

/** Includes QT */
#include <QTcpSocket>
#include <QSettings>
#include <QTimer>
#include <QThread>

/** Includes perso */
#include "GlobalHTTP.h"
#include "RequeteHTTP.h"
#include "ReponseHTTP.h"
#include "GestionnaireRequeteHTTP.h"

/** Pour la compatibilité avec les différentes versions de Qt */
#if QT_VERSION >= 0x050000
    typedef qintptr tSocketDescriptor;
#else
    typedef int tSocketDescriptor;
#endif

/** Alias pour QSslConfiguration si OpenSSL n'est pas pris en charge */
#ifdef QT_NO_OPENSSL
  #define QSslConfiguration QObject
#endif

/**
    Le gestionnaire de connexion accepte les connexions entrantes et envoie les requêtes entrantes
    à une demande mapper. Depuis les clients HTTP peuvent envoyer plusieurs demandes avant d'attendre
    la réponse, les demandes entrantes sont mises en attente et traitées les unes après les autres.

    La valeur ReadTimeout définit le délai maximum d'attente pour une requête HTTP complète.
  @see RequeteHTTP pour la description des paramètres de configuration MaxRequestSize et max MultiPartSize.
*/
class DECLSPEC GestionnaireConnexionHTTP : public QThread {
    Q_OBJECT
    Q_DISABLE_COPY(GestionnaireConnexionHTTP)

public:

    /**
      Constructeur.
      @param settings Configuration settings of the HTTP webserver
      @param requestHandler Handler that will process each incoming HTTP request
    */
    GestionnaireConnexionHTTP(QSettings* parametres, GestionnaireRequeteHTTP* gestionnaireRequete);
    /** Destructeur */
    virtual ~GestionnaireConnexionHTTP();

    /** Retourne true, si ce gestionnaire est en cours d'utilisation. */
    bool estOccupe();

    /** Marquer ce gestionnaire comme occupé */
    void setOccupe();

private:

    /** Les paramètres de configuration */
    QSettings* parametres;

    /** socket TCP de la connexion courante  */
    QTcpSocket* socket;

    /** Temps pour la détection de lecture de temporisation */
    QTimer lireTimer;

    /** Stockage de la requête actuelle HTTP entrante */
    RequeteHTTP* requeteActuelle;

    /** Dispatches a reçu des demandes de services */
    GestionnaireRequeteHTTP* gestionnaireRequete;

    /** Cela montre l'état occupé à une époque très tôt */
    bool occupe;

    /** Exécute la propre boucle d'événements threads */
    void run();

    /**  Creer TCP socket */
    void creerSocket();

    void supprimerSocket();

public slots:

    /**
     Reçu de l'écouteur, lorsque le gestionnaire doit commencer à traiter une nouvelle connexion.
      @param socketDescriptor références de la connexion acceptée.
    */
    void gestionConnexion(tSocketDescriptor socketDescriptor);

private slots:

    /** Reçu dans le socket quand un délai lu est survenu */
    void readTimeout();

    /** Reçu dans le socket lorsque les données entrantes peuvent être lues */
    void read();

    /** Reçu dans le socket quand une connexion a été fermée */
    void disconnected();

};

#endif // GESTIONNAIRECONNEXIONHTTP
