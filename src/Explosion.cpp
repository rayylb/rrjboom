#include "Explosion.h"

void Explosion::avancerTemps() {
    if(timer > 0)
        timer -= 1;
}

bool Explosion::estActif() {
    return (timer > 0);
}