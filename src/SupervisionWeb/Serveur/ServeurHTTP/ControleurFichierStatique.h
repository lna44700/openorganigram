/**
  @file
  @author Florian Philippeau
*/

#ifndef CONTROLEURFICHIERSTATIQUE_H
#define CONTROLEURFICHIERSTATIQUE_H

/** Includes QT */
#include <QCache>
#include <QMutex>

/** Includes Perso */
#include "GlobalHTTP.h"
#include "RequeteHTTP.h"
#include "ReponseHTTP.h"
#include "GestionnaireRequeteHTTP.h"

/**
    Rend les fichiers statiques.
    Il est généralement appelé par principal gestionnaire de requete de l'application lorsque
    l'appelant demande un chemin qui est mappé à des fichiers statiques.

    Les paramètres suivants sont requis dans le fichier de configuration (voir Web.ini):

    path=../www
    codage=UTF-8
    maxAge=60000
    cacheTime=60000
    cacheSize=100     // Attention, ne pas mettre un valeur plus élevé sinon les valeurs reçus par la
                       maquette ne seront pas visibles instantanément dans les pages web du serveur !
    maxCachedFileSize=65536

    Le chemin est relatif au répertoire du fichier de configuration.
    En cas de fenêtres, si les paramètres sont dans le registre,
    le chemin est relatif au répertoire de travail courant.

    Le codage est envoyé au navigateur Web dans le cas de fichiers texte et html.

    Le cache améliore les performances des petits fichiers lorsqu'il est chargé à partir
    d'un lecteur réseau. Les fichiers volumineux ne sont pas mis en cache.
    Les fichiers sont mis en cache aussi longtemps que possible, lorsque cacheTime = 0.
    La valeur max Age (en msec!) Contrôle le cache de navigateurs à distance.

    Ne pas instancier cette classe dans chaque requete, car cela rendrait le cache de fichiers inutiles.
    Mieux vaut créer une instance au cours du démarrage et de l'appeler lorsque l'application a reçu une
    requête HTTP associée.
*/

class DECLSPEC ControleurFichierStatique : public GestionnaireRequeteHTTP  {
    Q_OBJECT
    Q_DISABLE_COPY(ControleurFichierStatique)
public:

    /** Constructeur */
    ControleurFichierStatique(QSettings* parametres, QObject* parent = NULL);

    /** Génère la réponse */
    void service(RequeteHTTP& requete, HttpReponse& reponse);

private:

    /** codage des fichiers textes */
    QString codage;

    /** Le répertoire racine des documents */
    QString www;

    /** L'âge maximum de fichiers dans le cache du navigateur */
    int maxAge;

    struct CacheEntry {
        QByteArray document;
        qint64 created;
        QByteArray filename;
    };

    /** Délai d'expiration pour chaque fichier mis en cache */
    int cacheDelaiExpiration;

    /** La taille maximale des fichiers en cache, les fichiers volumineux ne sont pas mis en cache */
    int tailleFichierCacheMax;

    /** Le stockage du cache*/
    QCache<QString,CacheEntry> cache;

    /** Utilisé pour synchroniser l'accès de cache pour les discussions(threads) */
    QMutex mutex;

    /** Définir un en-tête de type de contenu dans la réponse en fonction de la fin du nom de fichier */
    void setTypeContenu(QString fichier, HttpReponse& reponse) const;
};

#endif // CONTROLEURFICHIERSTATIQUE_H
