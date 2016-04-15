/**
  @file
  @author Florian Philippeau
*/

#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "GestionnaireRequeteHTTP.h"

/**
La demande mappeur distribue les requêtes HTTP entrantes au contrôleur des classes
   en fonction du trajet demandé.
*/

class RequeteMapper : public GestionnaireRequeteHTTP {
    Q_OBJECT
    Q_DISABLE_COPY(RequeteMapper)
public:

    /**
      Constructeur.
      @param parent Objet parent
    */
    RequeteMapper(QObject* parent=0);

    /**
      Destructeur.
    */
    ~RequeteMapper();

    /**
La demande mappeur distribue les requêtes HTTP entrantes au contrôleur des classes
   en fonction du trajet demandé.
      @param requete La requête HTTP reçue
      @param response Doit être utilisé pour retourner la réponse
    */
    void service(RequeteHTTP& requete, HttpReponse& response);

};

#endif // REQUESTMAPPER_H
