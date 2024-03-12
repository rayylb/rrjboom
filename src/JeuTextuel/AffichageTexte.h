#ifndef _AFFICHAGETEXTE_H
#define _AFFICHAGETEXTE_H

#include "../Core/Partie.h"

class AffichageTexte {
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