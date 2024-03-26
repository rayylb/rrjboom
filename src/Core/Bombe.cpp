#include "Bombe.h"

Bombe::Bombe(int xpos, int ypos, int flamerange, int joueurpose) {
    x = xpos;
    y = ypos;
    range = flamerange;
    timer = 60;
    joueur = joueurpose;
}

int Bombe::getPosX() {
    return x;
}

int Bombe::getPosY() {
    return y;
}

int Bombe::getRange() {
    return range;
}

int Bombe::getJoueur() {
    return joueur;
}

void Bombe::avancerTemps() {
    if(timer > 0)
        timer -= 1;
}

void Bombe::exploser() {
    timer = 0;
}

bool Bombe::estExplosee() {
    return (timer == 0);
}