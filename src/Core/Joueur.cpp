#include "Joueur.h"
#include "Bloc.h"

void Joueur::spawn(bool num, int xg, int yg){
    numero = num;
    nbBombesMax = 9;
    nbBombes = 0;
    porteeBombe = 2;
    x  = xg;
    y = yg;
    vivant = true;
    bonus = BonusType::Rien;
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

void Joueur::appliquerBonus(BonusType typeBonus) {
    // Appliquer les effets du bonus au joueur en fonction de son type
    switch(typeBonus) {
        case BonusType::Speed : speed += 1;
          
            break;
        default:
         
            break;
    }
}

