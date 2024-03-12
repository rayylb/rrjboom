#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

#include "src/Core/Partie.h"

class Affichage {
    private:
        Partie jeu;
        int menu;
    
    public:
        void commencerJeu();
};

#endif