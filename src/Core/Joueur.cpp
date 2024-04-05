#include "Joueur.h"

Joueur::Joueur() {
    spawn(true, 0, 0);
}

void Joueur::spawn(bool num, int xg, int yg){
    x = xg;
    y = yg;
    xExact = xg+0.5;
    yExact = yg+0.5;
    vivant = true;
    
    nbBombesPosee = 0;
    nbBombesPoseeMax = 1;
    porteeBombe = 1;
    speed = 10;
    
    hitboxUP = 0;
    hitboxDOWN = 0.4;
    hitboxLEFT = 0.3;
    hitboxRIGHT = 0.3;
}

void Joueur::moveR(bool canSkip, bool canSkipUp, bool canSkipDown) {
    xExact += (float)(speed)/100;
    bool canMove = canSkip;
    if((int)(xExact + hitboxRIGHT) > x) {
        if(yExact-y-hitboxUP < 0) {
            if(!canSkipUp) canMove = false;
        }
        else if(yExact-y+hitboxDOWN > 1) {
            if(!canSkipDown) canMove = false;
        }
        if(canMove) {
            if((int)(xExact) > x)
                x++;
        }
        else {
            xExact = x + 1 - hitboxRIGHT;
        }
    }
}

void Joueur::moveL(bool canSkip, bool canSkipUp, bool canSkipDown) {
    xExact -= (float)(speed)/100;
    bool canMove = canSkip;
    if((xExact - hitboxLEFT) < 0)
        xExact = x + hitboxLEFT;
    else if((int)(xExact - hitboxLEFT) < x) {
        if(yExact-y-hitboxUP < 0) {
            if(!canSkipUp) canMove = false;
        }
        else if(yExact-y+hitboxDOWN > 1) {
            if(!canSkipDown) canMove = false;
        }
        if(canMove) {
            if((int)(xExact) < x)
                x--;
        }
        else {
            xExact = x + hitboxLEFT;
        }
    }
}

void Joueur::moveU(bool canSkip, bool canSkipLeft, bool canSkipRight) {
    yExact -= (float)(speed)/100;
    bool canMove = canSkip;
    if((yExact - hitboxUP) < 0)
        yExact = y + hitboxUP;
    else if((int)(yExact - hitboxUP) < y) {
        if(xExact-x-hitboxLEFT < 0) {
            if(!canSkipLeft) canMove = false;
        }
        else if(xExact-x+hitboxRIGHT > 1) {
            if(!canSkipRight) canMove = false;
        }
        if(canMove) {
            if((int)(yExact) < y)
                y--;
        }
        else {
            yExact = y + hitboxUP;
        }
    }
}

void Joueur::moveD(bool canSkip, bool canSkipLeft, bool canSkipRight) {
    yExact += (float)(speed)/100;
    bool canMove = canSkip;
    if((int)(yExact + hitboxDOWN) > y) {
        if(xExact-x-hitboxLEFT < 0) {
            if(!canSkipLeft) canMove = false;
        }
        else if(xExact-x+hitboxRIGHT > 1) {
            if(!canSkipRight) canMove = false;
        }
        if(canMove) {
            if((int)(yExact) > y)
                y++;
        }
        else {
            yExact = y + 1 - hitboxDOWN;
        }
    }
}

void Joueur::poserBombe() {
    nbBombesPosee++;
}

void Joueur::recupererBombe() {
    nbBombesPosee--;
}

void Joueur::exploser() {
    vivant = false;
}

void Joueur::appliquerBonus(BonusType typeBonus) {
    switch(typeBonus) {
        case BonusType::Rien : break;
        case BonusType::BombUp : if(nbBombesPoseeMax < JOUEUR_MAX_BOMBES) nbBombesPoseeMax += 1; break;
        case BonusType::FlameUp : if(porteeBombe < JOUEUR_MAX_FLAMES) porteeBombe += 1; break;
        case BonusType::SpeedUp : if(speed < JOUEUR_MAX_SPEED) speed += 2; break;
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
    return nbBombesPosee;
}

int Joueur::getNbBombesMax() {
    return nbBombesPoseeMax;
}

int Joueur::getPorteeBombe() {
    return porteeBombe;
}