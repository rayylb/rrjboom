#include "Grille.h"
#include <stdlib.h>

void Grille::initGrille() {
    for (int i = 0; i < GRILLE_DIMX; i++)
        for (int j = 0; j < GRILLE_DIMY; j++) {
            if ((i + 1)%2 == 0 && (j + 1)%2 == 0)
                terrain[i][j].blocMur();
            else if ((i+j) < 3 || (i+j) > (GRILLE_DIMX+GRILLE_DIMY - 5))
                terrain[i][j].blocSol();
            else if (rand()%2 == 0)
                terrain[i][j].blocDes();
            else
                terrain[i][j].blocSol();
        }
            
}