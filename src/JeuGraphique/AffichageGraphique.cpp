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
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    SDL_RenderClear(rendu);
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.h = 100;
    rect.w = 100;
    SDL_SetRenderDrawColor(rendu, 50, 100, 0, 255);
    SDL_RenderDrawRect(rendu, &rect);
    SDL_RenderPresent(rendu);
}

void AffichageGraphique::afficherSprite(int posX, int posY, int type_bloc) {
    // Vérifie si le rendu a été initialisé
    if (rendu == nullptr) {
        std::cout << "Erreur : Le rendu n'a pas été initialisé." << std::endl;
        return;
    }

    // Initialise la texture à nullptr
    SDL_Texture* texture = nullptr;

    // Charge la texture en fonction du type de bloc
    SDL_Surface* surface = nullptr;
    switch (type_bloc) {
        case 0:
            surface = IMG_Load("../data/bloc_indestructible.png");
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

    // Vérifie si le chargement de la surface a réussi
    if (surface == nullptr) {
        std::cout << "Erreur : Chargement de l'image impossible." << std::endl;
        return;
    }

    // Crée la texture à partir de la surface chargée
    texture = SDL_CreateTextureFromSurface(rendu, surface);
    SDL_FreeSurface(surface); // Libère la surface après avoir créé la texture

    // Vérifie si la création de la texture a réussi
    if (texture == nullptr) {
        std::cout << "Erreur : Création de la texture impossible." << std::endl;
        return;
    }

    // Définit le rectangle source (copie l'intégralité de la texture)
    SDL_Rect srcRect = {0, 0, 32, 32};

    // Définit le rectangle destination (position et taille d'affichage)
    SDL_Rect destRect = {posX, posY, 100, 100};

    // Copie la texture chargée sur le rendu en utilisant les rectangles source et destination
    SDL_RenderCopy(rendu, texture, &srcRect, &destRect);

    // Détruit la texture après utilisation
    SDL_DestroyTexture(texture);

    // Affiche le rendu à l'écran
    SDL_RenderPresent(rendu);
}
