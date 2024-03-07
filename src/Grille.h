#ifndef _GRILLE_H
#define _GRILLE_H

#include "Bloc.h"

/// constantes GRILLE_DIMX et GRILLE_DIMY
const int GRILLE_DIMX = 7;
const int GRILLE_DIMY = 5;

class Grille {
private:
    Bloc terrain[GRILLE_DIMX][GRILLE_DIMY];

public:
    Grille();
    ~Grille();

    void getDim(int x, int y);
    void initGrille();
    void affichTerminal();

    void infoCase(int x, int y, Bloc& copie);
    Bloc& infoCase(int x, int y);

    void detruireCase(int x, int  y);
    void recupererBonus(int x, int y);
};

#endif