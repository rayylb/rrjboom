#include "Joueur.h"

void Joueur::spawn(bool num, int xg, int yg){
    numero = num;
    nbBombesMax = 9;
    nbBombes = 0;
    porteeBombe = 2;
    speed = 2;
    x = xg;
    y = yg;
    xExact = xg+0.5;
    yExact = yg+0.5;
    vivant = true;
    hitboxUP = 0.1;
    hitboxDOWN = 0.4;
    hitboxLEFT = 0.4;
    hitboxRIGHT = 0.4;
}

int Joueur::getPositionX() {
    return x;
}

int Joueur::getPositionY() {
    return y;
}

float Joueur::getExactX() {
    return xExact;
}

float Joueur::getExactY() {
    return yExact;
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

void Joueur::moveR(bool canSkip) {
    xExact += (float) speed/10;
    if((int)xExact > x)
        if(canSkip)
            x++;
        else
            xExact = x + 0.9;
}

void Joueur::moveL(bool canSkip) {
    xExact -= (float) speed/10;
    if((int)xExact < x)
        if(canSkip)
            x--;
        else
            xExact = x;
}

void Joueur::moveU(bool canSkip) {
    yExact -= (float) speed/10;
    if((int)yExact < y)
        if(canSkip)
            y--;
        else
            yExact = y;
}

void Joueur::moveD(bool canSkip) {
    yExact += (float) speed/10;
    if((int)yExact > y)
        if(canSkip)
            y++;
        else
            yExact = y + 0.9;
}

void Joueur::poserBombe() {
    nbBombes++;
}

void Joueur::exploser() {
    vivant= false;
}