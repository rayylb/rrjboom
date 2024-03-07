#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "Partie.h"
#include "Grille.h"

int main(int argc, char** argv) {
    /*
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
    }
    fenetre = SDL_CreateWindow("rrjboom", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 640 , 480 , SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer (window , -1 , 0);
    SDL_SetRenderDrawColor (renderer, 0,0,0);
    */
    srand(time(NULL));
    Partie testjeu;
    Grille grillejeu;
    testjeu.initJeu(grillejeu);
    testjeu.nouvellePartie();
    return 0;
}