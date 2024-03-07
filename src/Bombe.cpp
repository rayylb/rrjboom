#include "Bombe.h"

Bombe::Bombe() {
    x = 0;
    y = 0;
    range = 1;
    timer = 4; 
}

Bombe::Bombe(int xpos, int ypos, int flamerange) {
    x = xpos;
    y = ypos;
    range = flamerange;
    timer = 4;
}

void Bombe::avancerTemps() {
    if(timer > 0)
        timer -= 1;
}

bool Bombe::estExplosee() {
    return (timer == 0);
}