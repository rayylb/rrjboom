#ifndef _JEUGRAPHIQUE_H_
#define _JEUGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include "../Core/Partie.h"
#include "AffichageGraphique.h"

class JeuGraphique {
    private:
        Partie jeu;
        AffichageGraphique affichage;
        int joueur1movX;
        int joueur1movY;
        int joueur2movX;
        int joueur2movY;

    public:
        void jeuRectangle();
        void jeuSprite();

        void boucleJeuMain();
        void nouvellePartie(int taille_bloc);
        void afficherPartie(int taille_bloc);
        void tourDeJeu(bool& stillRunning);

        void convertirTouches(int joueurMovX, int joueurMovY, char& mov);
        void dessinerMenu();
        bool boucleMenu(SDL_Event& e, bool& quit);

};

#endif