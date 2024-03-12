#include "AffichageGraphique.h"
#include <iostream>

void AffichageGraphique::initFenetre() {
    if(SDL_Init(SDL_INIT_VIDEO)<0) {
        std::cout<<"Erreur lors de l'initialisation de la SDL : "<<SDL_GetError()<<std::endl;
        SDL_Quit();
    }
    fenetre = SDL_CreateWindow("Rrjboom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DimX, DimY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    /*  
     SDL_Surface *surfaceFond=IMG_Load("data/il faut choisir un fond.png");
     textureFond = SDL_CreateTextureFromSurface(rendu,surfaceFond);
    */
}

void AffichageGraphique::detruireFenetre() {
    //SDL_DestroyTexture(textureFond);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}

SDL_Renderer* AffichageGraphique::getRenderer() {
    return rendu;
}
