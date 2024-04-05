#include "Explosion.h"

Explosion::Explosion(int xpos, int ypos) {
    x = xpos;
    y = ypos;
    timer = 20;
}

void Explosion::avancerTemps() {
    if(timer > 0)
        timer -= 1;
}

int Explosion::getPosX() {
    return x;
}

int Explosion::getPosY() {
    return y;
}

bool Explosion::estActif() {
    return (timer > 0);
}