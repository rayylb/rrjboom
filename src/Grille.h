#ifndef _GRILLE_H
#define _GRILLE_H

#include "bloc.h"

const int GRILLE_DIMX = 7;
const int GRILLE_DIMY = 5;

class Grille {
private:
    Bloc terrain[GRILLE_DIMX][GRILLE_DIMY];

public:
    Grille();
    ~Grille();

    void initGrille();
    void affichTerminal();

    Bloc& infoCase(int x, int y);

    void detruireCase(int x, int  y);
    void recupererBonus(int x, int y);
};

#endif