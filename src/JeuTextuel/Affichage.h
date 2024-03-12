#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

#include "../Core/Partie.h"

class Affichage {
    private:
        Partie jeu;
        int menu;
    
    public:
        void boucleJeu();
        void nouvellePartie();
        void afficherPartie();
        void tourDeJeu();

        void convertirMove(char up, char left, char down, char right, char& mov);
};

#endif