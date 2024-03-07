#include "Joueur.h"

void Joueur::spawn(bool num, int xg, int yg){
    numero = num;
    nbBombesMax = 9;
    nbBombes = 0;
    porteeBombe = 2;
    x  = xg;
    y = yg;
    vivant = true;
}

int Joueur::getPositionX() {
    return x;
}

int Joueur::getPositionY() {
    return y;
}

int Joueur::getNbBombes() {
    return nbBombes;
}

int Joueur::getNbBombesMax() {
    return nbBombesMax;
}

int Joueur::getPorteeBombe() {
    return porteeBombe;
}

bool Joueur::estVivant() {
    return vivant;
}

void Joueur::deplacementD() {
    x++;
}

void Joueur::deplacementG() {
    x--;
}

void Joueur::deplacementH() {
    y--;
}

void Joueur::deplacementB() {
    y++;
}

void Joueur::poserBombe() {
    nbBombes++;
}

void Joueur::exploser() {
    vivant= false;
}