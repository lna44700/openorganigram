/**
  @file
  @author Florian Philippeau
*/

#ifndef REPONSEHTTP_H
#define REPONSEHTTP_H

/** Includes QT */
#include <QMap>
#include <QString>
#include <QTcpSocket>

/** Includes Perso */
#include "GlobalHTTP.h"

/**
  Cet objet représente une réponse HTTP, utilisé pour retourner quelque chose au client Web.
*/

class DECLSPEC HttpReponse {
    Q_DISABLE_COPY(HttpReponse)
public:

    /**
      Constructeur.
      @param socket utilisé pour ecrire the reponse
    */
    HttpReponse(QTcpSocket* socket);

    /**
    Définir un en-tête de réponse HTTP.
    Je dois appeler cette méthode avant la première écriture.
      @param nom name du header
      @param valeur du header
    */
    void definirHeader(QByteArray nom, QByteArray valeur);

    /**
     Définir un en-tête de réponse HTTP.
     Je dois appeler cette méthode avant la première écriture.
      @param nom nom du header
      @param valeur valeur du header
    */
    void definirHeader(QByteArray nom, int valeur);

    /** j'obtiens la map des en-têtes de réponse HTTP */
    QMap<QByteArray,QByteArray>& getHeaders();


    /**
    Définir le code d'état et de la description. La valeur par défaut est 200, OK.
    Je dois appeler cette méthode avant la première écriture.
    */
    void setStatus(int codeStatus, QByteArray description=QByteArray());

    /** Retourne le code d'état. */
    int getCodeStatus() const;

    /**
      écrire les données du corps dans le socket.

      La ligne d'état HTTP, les en-têtes sont envoyés automatiquement avant que le corps.
      Si la réponse ne contient qu'un seul morceau (indiqué par dernierePartie = true),
      puis un en-tête Content-Length est réglé automatiquement.

      @param donnees octets de données du body
      @param dernierePartie Indique que ceci est le dernier bloc de données et vide le tampon de sortie.
    */
    void ecrire(QByteArray donnees, bool dernierePartie=false);

    /**
    indique si le body a été envoyé complètement (ecrire() a été appelé avec dernierePartie() = true).
    */
    bool aEnvoyeDernierePartie() const;


    /**
    Envoyer une réponse de redirection vers le navigateur.
    Ne peut être combiné avec ecrire ().
      @param url URL de destination
    */
    void redirect(const QByteArray& url);

    /**
    Vider la mémoire tampon de sortie.
    Pas besoin d'appeler cette méthode parce que flush est
    appelé automatiquement après GestionnaireRequeteHTTP :: service () retourne.
    **/
    void flush();

    /**
    Peut être utilisé pour vérifier si la connexion au client Web a été perdu.
    Cela peut être utile pour annuler la génération de réponses lentes.
     */
    bool isConnected() const;

private:

    /** Demander des headers */
    QMap<QByteArray,QByteArray> headers;

    /** Socket pour la sortie d'écriture */
    QTcpSocket* socket;

    /** HTTP status code*/
    int codeStatus;

    /** HTTP status code (description) */
    QByteArray statusText;

    /** Indique si les en-têtes ont été envoyés */
    bool headersEnvoye;

    /** Indique si le corps a été envoyé complètement */
    bool dernierePartieEnvoyee;

    /** Que la réponse est envoyée en mode chunked */
    bool modeChunked;

    /** ECRIRE données brutes à la socket.
     * Cette méthode bloque jusqu'à ce que tous les octets ont été transmis à la mémoire tampon TCP */
    bool ecrireDansSocket(QByteArray donnees);

    /**
    ECRIRE l'état de réponse HTTP et les en-têtes à la socket.
    L'appel de cette méthode est facultative, parce ecrire Body() appelle automatiquement en cas de besoin.
    */
    void ecrireHeaders();

};

#endif // REPONSEHTTP_H
