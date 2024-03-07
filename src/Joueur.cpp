#include "Joueur.h"

void Joueur::spawn(bool num, int xg, int yg){
    numero = num;
    nbBombesMax = 10;
    porteeBombe = 4;
    if(num){
        x = 0;
        y = 0;
    }
    else {
        x  = xg;
        y = yg;
    }
    vivant = true;
}

int Joueur::getPositionX() {
    return x;
}

int Joueur::getPositionY() {
    return y;
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