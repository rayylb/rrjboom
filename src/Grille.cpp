#include "Grille.h"
#include <stdlib.h>
#include <iostream>

void Grille::initGrille() {
    for (int i = 0; i < GRILLE_DIMX; i++)
        for (int j = 0; j < GRILLE_DIMY; j++) {
            if ((i + 1)%2 == 0 && (j + 1)%2 == 0)
                terrain[i][j].blocMur();
            else if ((i+j) < 3 || (i+j) > (GRILLE_DIMX+GRILLE_DIMY - 5))
                terrain[i][j].blocSol();
            else if (rand()%2 == 0)
                terrain[i][j].blocDes(false);
            else
                terrain[i][j].blocSol();
        }
            
}

void Grille::affichTerminal() {
    for (int i = 0; i < GRILLE_DIMX; i++)
        for (int j = 0; j < GRILLE_DIMY; j++) {
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

Bloc& Grille::infoCase(int x, int y) {
    Bloc copie;
    if (terrain[x][y].onPeutMarcher() == true)
        copie.blocSol();
    else if (terrain[x][y].estDestructible() == true)
        copie.blocDes(terrain[x][y].aBonus());
    else
        copie.blocMur();
    return copie;
}

void Grille::detruireCase(int x, int y) {
    terrain[x][y].detruire();
}

void Grille::recupererBonus(int x, int y) {
    terrain[x][y].retirerBonus();
}