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
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);
}

void AffichageGraphique::detruireFenetre() {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
}

void AffichageGraphique::afficherRectangle(int posX, int posY, int height, int widht) {
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.h = height;
    rect.w = widht;
    SDL_SetRenderDrawColor(rendu, 100, 100, 200, 255);
    SDL_RenderDrawRect(rendu, &rect);
    SDL_RenderPresent(rendu);
}

void AffichageGraphique::afficherSprite(int posX, int posY, int type_bloc, int taille_bloc) {
    if (rendu == nullptr) {
        std::cout << "Erreur : Le rendu n'a pas été initialisé." << std::endl;
        return;
    }
    texture = nullptr;
    surface = nullptr;
    switch (type_bloc) {
        case 0:
            surface = IMG_Load("../data/bloc_sol.png");
            break;
        case 1:
            surface = IMG_Load("../data/bloc_destructible.png");
            break;
        case 2:
            surface = IMG_Load("../data/bloc_indestructible.png");
            break;
        default:
            std::cout << "Erreur : Type de bloc non pris en charge." << std::endl;
            return;
    }
    if (surface == nullptr) {
        std::cout << "Erreur : Chargement de l'image impossible." << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(rendu, surface);
    SDL_FreeSurface(surface);
    if (texture == nullptr) {
        std::cout << "Erreur : Création de la texture impossible." << std::endl;
        return;
    }
    SDL_Rect destRect = {posX*taille_bloc, posY*taille_bloc, taille_bloc, taille_bloc};
    SDL_RenderCopy(rendu, texture, NULL, &destRect);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(rendu);
}
