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
<<<<<<< HEAD
=======

        void boucleJeuMain();
        void nouvellePartie(int taille_bloc);
        void afficherPartie(int taille_bloc);
        void tourDeJeu(bool& stillRunning);

        void convertirTouches(float& joueurX, float& joueurY, char& mov);
>>>>>>> 83d8ddea33519c5330d729c2e102b9cee8e4bc5b
};

#endif