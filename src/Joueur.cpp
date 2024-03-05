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

int Joueur::getPositionX() const {
    return x;
}
int Joueur::getPositionY() const {
    return y;
}
int Joueur::getNbBombesMax() const {
    return nbBombesMax;
}
int Joueur::getPorteeBombe() const {
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