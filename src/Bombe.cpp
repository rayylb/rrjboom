#include "Bombe.h"

Bombe::Bombe(int xpos, int ypos, int flamerange) {
    x = xpos;
    y = ypos;
    range = flamerange;
    timer = 4;
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

void Bombe::avancerTemps() {
    if(timer > 0)
        timer -= 1;
}

bool Bombe::estExplosee() {
    return (timer == 0);
}