/**
  @file
  @author Florian Philippeau
*/

#ifndef GESTIONNAIREREQUETEHTTP_H
#define GESTIONNAIREREQUETEHTTP_H

/** Includes Perso */
#include "GlobalHTTP.h"
#include "RequeteHTTP.h"
#include "ReponseHTTP.h"

/**
    Le gestionnaire de requêtes génère une réponse à chaque requête HTTP.
    Applications Web ont généralement un gestionnaire de requêtes central
    qui mappe les demandes entrantes à plusieurs contrôleurs (servlets)
    basé sur le chemin d'accès demandé.

    Vous devez redéfinir la méthode de service () ou vous obtiendrez toujours une erreur HTTP 501.

    @warning L'instance principale du gestionnaire de requêtes doit être créée
    sur le tas et qu'il est utilisé par plusieurs threads simultanément.
    @see ControleurFichierStatique qui fournit des fichiers locaux statiques.
*/

class DECLSPEC GestionnaireRequeteHTTP : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(GestionnaireRequeteHTTP)
public:

    /**
     * Constructeur.
     * @param parent Objet parent.
     */
    GestionnaireRequeteHTTP(QObject* parent=NULL);

    /** Destructeur */
    virtual ~GestionnaireRequeteHTTP();

    /**
      Générer une réponse à une requête HTTP entrante.
      @param requete La requête HTTP reçue
      @param reponse Doit être utilisé pour retourner la réponse
      @warning Cette méthode doit être thread-safe
    */
    virtual void service(RequeteHTTP& requete, HttpReponse& reponse);

};

#endif // GESTIONNAIREREQUETEHTTP_H
