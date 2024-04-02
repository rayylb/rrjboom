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
    if (rendu == nullptr) {
        std::cout << "Erreur : Le rendu n'a pas été initialisé." << std::endl;
        return;
    }
    IMG_Init(IMG_INIT_PNG);
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);
    for (int i = 0; i < AFFICHAGE_NB_TEXTURES; i++) {
        textures[i] = nullptr;
        surface = nullptr;
        switch (i) {
            case 0: surface = IMG_Load("../data/bloc_sol.png"); break;
            case 1: surface = IMG_Load("../data/bloc_destructible.png"); break;
            case 2: surface = IMG_Load("../data/bloc_indestructible.png"); break;
            case 3: surface = IMG_Load("../data/joueur1.png"); break;
            case 4: surface = IMG_Load("../data/joueur2.png"); break;
            case 5: surface = IMG_Load("../data/bombe.png"); break;
            case 6: surface = IMG_Load("../data/explosion.png"); break;
            case 7: surface = IMG_Load("../data/bonus.png"); break;
            case 8: surface = IMG_Load("../data/bonus_vitesse.png"); break;
            default: std::cout << "Erreur : Type de bloc non pris en charge." << std::endl; return;
        }
        if (surface == nullptr) {
            std::cout << "Erreur : Chargement de l'image impossible." << std::endl;
            return;
        }
        textures[i] = SDL_CreateTextureFromSurface(rendu, surface);
        SDL_FreeSurface(surface);
        if (textures[i] == nullptr) {
            std::cout << "Erreur : Création de la texture impossible." << std::endl;
            return;
        }
    }
}

void AffichageGraphique::detruireFenetre() {
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    for (int i = 0; i < AFFICHAGE_NB_TEXTURES; i++)
        SDL_DestroyTexture(textures[i]);
    SDL_Quit();
}

void AffichageGraphique::clearRendu() {
    SDL_RenderClear(rendu);
}

void AffichageGraphique::afficherRendu() {
    SDL_RenderPresent(rendu);
}

void AffichageGraphique::afficherRectangle(int posX, int posY, int height, int widht) {
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.h = height;
    rect.w = widht;
    SDL_SetRenderDrawColor(rendu, 100, 100, 200, 255);
    SDL_RenderDrawRect(rendu, &rect);
}

void AffichageGraphique::afficherSprite(float posX, float posY, int type_bloc, int taille_bloc) {
    SDL_Rect destRect = {(int) (posX*taille_bloc), (int) (posY*taille_bloc), taille_bloc, taille_bloc};
    if(type_bloc == 3 || type_bloc == 4) {
        destRect.h = destRect.w*3/2;
        destRect.x -= taille_bloc/2;
        destRect.y -= taille_bloc;
    }
    if(type_bloc == 5) {
        destRect.h = destRect.w*19/15;
        destRect.y -= taille_bloc*19/15;
        destRect.y += taille_bloc;
    }
    SDL_RenderCopy(rendu, textures[type_bloc], NULL, &destRect);
}
