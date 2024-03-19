#ifndef _JEUGRAPHIQUE_H_
#define _JEUGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include "../Core/Partie.h"
#include "AffichageGraphique.h"

class JeuGraphique {
    private:
        Partie jeu;
        AffichageGraphique affichage;
        float joueur1X;
        float joueur1Y;
        float joueur2X;
        float joueur2Y;
        int joueur1movX;
        int joueur1movY;
        int joueur2movX;
        int joueur2movY;

    public:
        void jeuRectangle();
        void jeuSprite();

        void boucleJeuMain();
        void nouvellePartie(int taille_bloc);
        void afficherPartie();
        void tourDeJeu(bool& stillRunning);
};

#endif