#include "Grille.h"
#include <stdlib.h>
#include <iostream>

Grille::Grille() {
    initGrille(GRILLE_DIMX_MAX, GRILLE_DIMY_MAX);
}

void Grille::initGrille(int largeur, int hauteur) {
    dimX = largeur;
    dimY = hauteur;
    for (int j = 0; j < dimY; j++)
        for (int i = 0; i < dimX; i++) {
            if ((i + 1)%2 == 0 && (j + 1)%2 == 0)
                terrain[i][j].blocMur();
            else if ((i+j) < 3 || (i+j) > (dimX+dimY - 5))
                terrain[i][j].blocSol();
            else if (rand()%3 < 2)
                terrain[i][j].blocDes(nouveauBonus());
            else
                terrain[i][j].blocSol();
        }
}

void Grille::detruireCase(int x, int y) {
    terrain[x][y].detruire();
}

BonusType Grille::recupererBonus(int x, int y) {
    BonusType bonusSurCase = terrain[x][y].getBonusType();
    terrain[x][y].retirerBonus();
    return bonusSurCase;
}

void Grille::affichTerminal() {
    for (int j = 0; j < dimY; j++) {
        for (int i = 0; i < dimX; i++) {
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

int Grille::getDimX() {
    return dimX;
}

int Grille::getDimY() {
    return dimY;
}

void Grille::infoCase(int x, int y, Bloc& copie) {
    if (terrain[x][y].onPeutMarcher() == true)
        copie.blocSol();
    else if (terrain[x][y].estDestructible() == true)
        copie.blocDes(terrain[x][y].getBonusType());
    else
        copie.blocMur();
}

Bloc& Grille::infoCase(int x, int y) {
    if(x < 0 || x > dimX-1 || y < 0 || y > dimY-1) 
        return terrain[1][1];
    else
        return terrain[x][y];
}

BonusType Grille::nouveauBonus() {
    if(rand()%10 > 10)
        return BonusType::Rien;
    else switch (rand()%5) {
        case 0 : return BonusType::BombUp;
        case 1 : return BonusType::BombUp;
        case 2 : return BonusType::FlameUp;
        case 3 : return BonusType::FlameUp;
        case 4 : return BonusType::SpeedUp;
        default : return BonusType::Rien;
    }
}