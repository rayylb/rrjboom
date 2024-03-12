#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "Partie.h"
#include "Grille.h"

int main()
{
    srand(time(NULL));
    Partie testjeu;
    Grille grillejeu;
    testjeu.initJeu(grillejeu);
    testjeu.nouvellePartie();
    return 0;
}