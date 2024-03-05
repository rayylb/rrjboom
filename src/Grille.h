#ifndef _GRILLE_H
#define _GRILLE_H

#include "Bloc.h"

const int GRILLE_DIMX = 7;
const int GRILLE_DIMY = 5;

class Grille {
private:
    Bloc terrain[GRILLE_DIMX][GRILLE_DIMY];

public:
    void initGrille();
    void affichTerminal();

    void infoCase(int x, int y, Bloc& copie);

    void detruireCase(int x, int  y);
    void recupererBonus(int x, int y);
};

#endif