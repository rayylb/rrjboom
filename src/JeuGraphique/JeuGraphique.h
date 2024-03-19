#ifndef _JEUGRAPHIQUE_H_
#define _JEUGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include "../Core/Partie.h"
#include "AffichageGraphique.h"

class JeuGraphique {
    private:
        Partie jeu;
        AffichageGraphique affichage;

    public:
        void jeuRectangle();
        void jeuSprite();

        void boucleJeu();
        void nouvellePartie();
        void afficherPartie();
        void tourDeJeu();
};

#endif