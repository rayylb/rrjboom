#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "AffichageGraphique.h"

int main(int argc,char *argv[]) {
  AffichageGraphique aff;
  aff.initFenetre(800, 600);
  aff.afficherFenetre();
  //SDL_Delay(9000); 
  aff.detruireFenetre();
  return 0;
}
