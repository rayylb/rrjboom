#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "JeuGraphique.h"

int main(int argc,char *argv[]) {
    srand(time(NULL));
    JeuGraphique jeu;
    jeu.boucleJeuMain();
  return 0;
}
