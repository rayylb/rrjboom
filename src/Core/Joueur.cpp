#include "Joueur.h"

void Joueur::spawn(bool num, int xg, int yg){
    x = xg;
    y = yg;
    xExact = xg+0.5;
    yExact = yg+0.5;
    vivant = true;
    
    nbBombesMax = 1;
    nbBombes = 0;
    porteeBombe = 1;
    speed = 2;
    
    hitboxUP = 0.1;
    hitboxDOWN = 0.4;
    hitboxLEFT = 0.4;
    hitboxRIGHT = 0.4;
}

void Joueur::moveR(bool canSkip) {
    xExact += (float) speed/20;
    if((int)xExact > x)
        if(canSkip)
            x++;
        else
            xExact = x + 0.9;
}

void Joueur::moveL(bool canSkip) {
    xExact -= (float) speed/20;
    if((int)xExact < x)
        if(canSkip)
            x--;
        else
            xExact = x;
}

void Joueur::moveU(bool canSkip) {
    yExact -= (float) speed/20;
    if((int)yExact < y)
        if(canSkip)
            y--;
        else
            yExact = y;
}

void Joueur::moveD(bool canSkip) {
    yExact += (float) speed/20;
    if((int)yExact > y)
        if(canSkip)
            y++;
        else
            yExact = y + 0.9;
}

void Joueur::poserBombe() {
    nbBombes++;
}

void Joueur::recupererBombe() {
    nbBombes--;
}

void Joueur::exploser() {
    vivant = false;
}

void Joueur::appliquerBonus(BonusType typeBonus) {
    switch(typeBonus) {
        case BonusType::Rien : break;
        case BonusType::BombUp : nbBombesMax += 1; break;
        case BonusType::FlameUp : porteeBombe += 1; break;
        case BonusType::SpeedUp : speed += 1; break;
        default: break;
    }
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

bool Joueur::estVivant() {
    return vivant;
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