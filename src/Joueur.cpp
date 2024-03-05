#include "Joueur.h"

Joueur::Joueur(bool num, int xg, int yg){
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

void Joueur::deplacementD() {
    x++;
}

void Joueur::deplacementG() {
    x--;
}

void Joueur::deplacementH(){
    y--;
}

void Joueur::deplacementB(){
    y++;
}