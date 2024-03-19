#include "AffichageGraphique.h"
#include <iostream>

void AffichageGraphique::initFenetre(int width, int height) {
    if(SDL_Init(SDL_INIT_VIDEO)<0) {
        std::cout<<"Erreur lors de l'initialisation de la SDL : "<<SDL_GetError()<<std::endl;
        SDL_Quit();
    }
    dimX = width;
    dimY = height;
    fenetre = SDL_CreateWindow("Rrjboom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimX, dimY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
}

void AffichageGraphique::afficherFenetre() {
    SDL_RenderClear(rendu);
    SDL_RenderPresent(rendu);
}

void AffichageGraphique::detruireFenetre() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}

void AffichageGraphique::afficherRectangle(int posX, int posY) {

}

void AffichageGraphique::afficherSprite(int posX, int posY) {
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);
    texture = IMG_LoadTexture(rendu, "bloc destructible.png");
    SDL_RenderCopy(rendu, texture, NULL, NULL);
    SDL_RenderPresent(rendu);
}