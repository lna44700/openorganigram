/**
  @file
  @author Florian Philippeau
*/

#ifndef REQUETEHTTP_H
#define REQUETEHTTP_H


/** Includes QT */
#include <QByteArray>
#include <QHostAddress>
#include <QTcpSocket>
#include <QMap>
#include <QMultiMap>
#include <QSettings>
#include <QTemporaryFile>
#include <QUuid>

/** Includes perso */
#include "GlobalHTTP.h"

/**
    Cet objet représente une seule requête HTTP.
    Il lit la demande à partir d'un socket TCP et fournit des getters
    pour les différentes parties de la demande.

    MaxRequestSize est la taille maximale d'une requête HTTP.
    En cas de demandes multipart / form-data (également connu sous le
    nom de téléchargement de fichier), la taille maximale du corps ne
    doit pas dépasser max MultiPart Taille. Le corps est toujours un
    peu plus grand que le fichier lui-même.
*/

class DECLSPEC RequeteHTTP {
    Q_DISABLE_COPY(RequeteHTTP)
    friend class StockageSessionHTTP;

public:

    /** Les valeurs pour getStatus () */
    enum StatusRequete {waitForRequest, waitForHeader, waitForBody, complete, abort};

    /**
      Constructeur.
      @parametres parametres
    */
    RequeteHTTP(QSettings* parametres);

    /**
      Destructeur.
    */
    virtual ~RequeteHTTP();

    /**
    Lire la requête HTTP à partir d'une prise de courant.
    Cette méthode est appelée par le gestionnaire de connexion à
    plusieurs reprises jusqu'à ce que le statut est Demande Statut ::
    complète ou Request Status :: avorté.
      @param socket Source de données
    */
    void lireDansSocket(QTcpSocket* socket);

    /**
      Obtenir le statut de cette requête.
      @see RequestStatus
    */
    StatusRequete getStatus() const;

    /** Obtenir la méthode de la requête HTTP  (e.g. "GET") */
    QByteArray getMethode() const;

    /** Obtenir le chemin décodé de la requête HTTP (e.g. "/index.html") */
    QByteArray getChemin() const;

    /** Obtenir le chemin brut de la requête HTTP (e.g. "/file%20with%20spaces.html") */
    const QByteArray& getCheminBrut() const;

    /** Obtenir la version de la requête HTTP (e.g. "HTTP/1.1") */
    QByteArray getVersion() const;

    /**
      Obtenir la valeur d'un en-tête de requête HTTP.
      @param nom nom de l'header
      @return Si l'en-tête se produit plusieurs fois, seul le dernier est retourné.
    */
    QByteArray getHeader(const QByteArray& nom) const;

    /**
      Obtenir les valeurs d'un en-tête de requête HTTP.
      @param nom  nom de l'header
    */
    QList<QByteArray> getHeaders(const QByteArray& nom) const;

    /** Obtenir toute les en-têtes de requête HTTP */
    QMultiMap<QByteArray,QByteArray> getHeaderMap() const;

    /**
      Obtenir la valeur d'un paramètre de requête HTTP.
      @param nom nom du parametre
      @return Si le paramètre se produit plusieurs fois, seul le dernier est retourné.
    */
    QByteArray getParametre(const QByteArray& nom) const;

    /**
      Obtenir les valeurs d'un paramètre de requête HTTP.
      @param nom nom du parametre
    */
    QList<QByteArray> getParametres(const QByteArray& nom) const;

    /** Obtenir tous les paramètres de la requête HTTP. */
    QMultiMap<QByteArray,QByteArray> getParametreMap() const;

    /** Obtenez le corps de la requête HTTP.  */
    QByteArray getBody() const;

    /**

    */
    static QByteArray urlDecode(const QByteArray source);

    /**
Obtenir un fichier téléchargé. Le fichier est déjà ouvert. Il sera fermé et supprimé par le destructeur de cet objet HTTP Requete (après traitement de la demande).
Pour les fichiers téléchargés, les getParameters méthode () renvoie le nom d'origine tel que fourni par le navigateur Web appelant.
    */
    QTemporaryFile* getFichierEnvoye(const QByteArray nomDomaine) const;

    /**
Obtenez l'adresse du client connecté.
Notez que plusieurs clients peuvent avoir la même adresse IP, si elles partagent une connexion Internet (ce qui est très fréquent).
     */
    QHostAddress getPeerAddress() const;

private:

    /** Requete headers */
    QMultiMap<QByteArray,QByteArray> headers;

    /** Parametres de la requete */
    QMultiMap<QByteArray,QByteArray> parametres;

    /** Les fichiers téléchargés de la demande, la clé est le nom de domaine. */
    QMap<QByteArray,QTemporaryFile*> fichiersEnvoyes;

    /** Stockage des données du corps brut */
    QByteArray bodyData;

    /** Requete methode */
    QByteArray method;

    /** Demande chemin (en format brut codé) */
    QByteArray path;

    /** Version Demande de protocole */
    QByteArray version;

    /**
      Statut de cette demande.
      @see StatusRequete
    */
    StatusRequete status;

    /** Adresse du pair connecté. */
    QHostAddress peerAddress;

    /** La taille maximale des requêtes en octets. */
    int tailleMax;

    /** La taille maximale autorisée de formes multipart en octets. */
    int maxMultiPartTaille;

    /** La taille actuelle*/
    int tailleActuelle;

    /** La taille attendue du corps */
    int tailleBody;

    /** nom de l'en-tête en cours, ou vide si aucun en-tête est en cours de traitement*/
    QByteArray headerActuelle;

    /** Limite du corps multipart / form-data. Vide s'il n'y a pas de têter */
    QByteArray frontieres;

    /** fichier Temp, qui est utilisé pour stocker le / corps form-data multipart */
    QTemporaryFile fichierTempo;

    /** Parset he multipart body, that has been stored in the temp file. */
    void analyserFichierMultiPart();

    /** Sub-procedure of readFromSocket(), read the first line of a request. */
    void lireRequete(QTcpSocket* socket);

    /** Sub-procedure of readFromSocket(), read header lines. */
    void lireHeader(QTcpSocket* socket);

    /** Sub-procedure of readFromSocket(), read the request body. */
    void lireBody(QTcpSocket* socket);

    /** Sub-procedure of readFromSocket(), extract and decode request parametres. */
    void decodeParametresRequete();

    /** Buffer for collecting characters of request and header lines */
    QByteArray lineBuffer;

};

#endif // REQUETEHTTP_H
