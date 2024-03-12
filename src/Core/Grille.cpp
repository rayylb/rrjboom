#include "Grille.h"
#include <stdlib.h>
#include <iostream>

int Grille::getDimX() {
    return GRILLE_DIMX;
}

int Grille::getDimY() {
    return GRILLE_DIMY;
}

void Grille::initGrille() {
    for (int j = 0; j < GRILLE_DIMY; j++)
        for (int i = 0; i < GRILLE_DIMX; i++) {
            if ((i + 1)%2 == 0 && (j + 1)%2 == 0)
                terrain[i][j].blocMur();
            else if ((i+j) < 3 || (i+j) > (GRILLE_DIMX+GRILLE_DIMY - 5))
                terrain[i][j].blocSol();
            else if (rand()%3 < 2)
                terrain[i][j].blocDes(false);
            else
                terrain[i][j].blocSol();
        }
}

void Grille::affichTerminal() {
    for (int j = 0; j < GRILLE_DIMY; j++) {
        for (int i = 0; i < GRILLE_DIMX; i++) {
            if (terrain[i][j].onPeutMarcher() == true)
                std::cout<<" ";
            else if (terrain[i][j].estDestructible() == true)
                std::cout<<"=";
            else if (terrain[i][j].estDestructible() == false)
                std::cout<<"X";
            else
                std::cout<<"?";
        }
        std::cout<<std::endl;
    }
}

void Grille::infoCase(int x, int y, Bloc& copie) {
    if (terrain[x][y].onPeutMarcher() == true)
        copie.blocSol();
    else if (terrain[x][y].estDestructible() == true)
        copie.blocDes(terrain[x][y].aBonus());
    else
        copie.blocMur();
}

Bloc& Grille::infoCase(int x, int y) {
    return terrain[x][y];
}

void Grille::detruireCase(int x, int y) {
    terrain[x][y].detruire();
}

void Grille::recupererBonus(int x, int y) {
    terrain[x][y].retirerBonus();
}