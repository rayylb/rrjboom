#include "Explosion.h"

Explosion::Explosion(int xpos, int ypos) {
    x = xpos;
    y = ypos;
    timer = 3;
}

int Explosion::getPosX() {
    return x;
}

int Explosion::getPosY() {
    return y;
}

void Explosion::avancerTemps() {
    if(timer > 0)
        timer -= 1;
}

bool Explosion::estActif() {
    return (timer > 0);
}