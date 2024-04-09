#include "AffichageGraphique.h"

AffichageGraphique::AffichageGraphique() {
    dimX = 100;
    dimY = 100;
    fenetre = nullptr;
    rendu = nullptr;
    surface = nullptr;
    for (int i = 0; i < AFFICHAGE_NB_TEXTURES; i++)
        textures[i] = nullptr;
    font = nullptr;
}

void AffichageGraphique::initFenetre(int width, int height) {
    dimX = width;
    dimY = height;
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
    TTF_Init();
    if(!TTF_WasInit()) {
        std::cout << "TTF_Init failed " << TTF_GetError() << std::endl;
        return;
    }
    font = TTF_OpenFont("../data/font.ttf", 24);
    if (!font) {
        std::cout << "Erreur lors du chargement de la police : " << TTF_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    for(int i = 0; i < AFFICHAGE_NB_TEXTURES; i++) {
        switch(i) {
            case 0: surface = IMG_Load("../data/bloc_sol.png"); break;
            case 1: surface = IMG_Load("../data/bloc_destructible.png"); break;
            case 2: surface = IMG_Load("../data/bloc_indestructible.png"); break;
            case 3: surface = IMG_Load("../data/bombe.png"); break;
            case 4: surface = IMG_Load("../data/bombe_rouge.png"); break;
            case 5: surface = IMG_Load("../data/explosion.png"); break;
            case 6: surface = IMG_Load("../data/joueur_bas.png"); break;
            case 7: surface = IMG_Load("../data/joueur_haut.png"); break;
            case 8: surface = IMG_Load("../data/joueur_gauche.png"); break;
            case 9: surface = IMG_Load("../data/joueur_droite.png"); break;
            case 10: surface = IMG_Load("../data/bonus.png"); break;
            case 11: surface = IMG_Load("../data/bonus_bombe.png"); break;
            case 12: surface = IMG_Load("../data/bonus_flame.png"); break;
            case 13: surface = IMG_Load("../data/bonus_vitesse.png"); break;
            case 14: surface = IMG_Load("../data/titre_bomberman.png"); break;
            default: std::cout << "Erreur : Type de bloc non pris en charge." << std::endl; return;
        }
        if (surface == nullptr) {
            std::cout << "Erreur : Chargement de l'image impossible." << std::endl;
            return;
        }
        textures[i] = SDL_CreateTextureFromSurface(rendu, surface);
        if (textures[i] == nullptr) {
            std::cout << "Erreur : Création de la texture impossible." << std::endl;
            return;
        }
    }
}

void AffichageGraphique::detruireFenetre() {
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    SDL_FreeSurface(surface);
    for (int i = 0; i < AFFICHAGE_NB_TEXTURES; i++)
        SDL_DestroyTexture(textures[i]);
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void AffichageGraphique::clearRendu(SDL_Color color) {
    SDL_SetRenderDrawColor(rendu, color.r, color.g, color.b, color.a);
    SDL_RenderClear(rendu);
}

void AffichageGraphique::afficherRendu() {
    SDL_RenderPresent(rendu);
}

void AffichageGraphique::afficherRectangle(int posX, int posY, int width, int height, SDL_Color color) {
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.h = height;
    rect.w = width;
    SDL_SetRenderDrawColor(rendu, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(rendu, &rect);
}

void AffichageGraphique::afficherRectangle(SDL_Rect rect, SDL_Color color) {
    afficherRectangle(rect.x, rect.y, rect.w, rect.h, color);
}

void AffichageGraphique::afficherSprite(float posX, float posY, int type_bloc, int taille_bloc) {
    SDL_Rect destRect = {(int) (posX*taille_bloc), (int) (posY*taille_bloc), taille_bloc, taille_bloc};
    if(type_bloc >= 6 && type_bloc <= 9) {
        destRect.h = destRect.w*3/2;
        destRect.x -= taille_bloc/2;
        destRect.y -= taille_bloc;
    }
    if(type_bloc == 3) {
        destRect.h = destRect.w*19/15;
        destRect.y -= taille_bloc*19/15;
        destRect.y += taille_bloc;
        destRect.h = destRect.h*0.8;
        destRect.w = destRect.w*0.8;
        destRect.x += taille_bloc*0.1;
        destRect.y += taille_bloc*0.3;
    }
    SDL_RenderCopy(rendu, textures[type_bloc], NULL, &destRect);
}

void AffichageGraphique::afficherTexte(Button bouton) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, bouton.text.c_str(), bouton.textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(rendu, textSurface);
    if (!textTexture) {
        std::cout << "Erreur lors de la création des textures de texte : " << SDL_GetError() << std::endl;
        return;
    }
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
    SDL_Rect textRect = {bouton.rect.w / 2, bouton.rect.h / 2, textWidth, textHeight};
    SDL_RenderCopy(rendu, textTexture, NULL, &bouton.rect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

int AffichageGraphique::getDimX() {
    return dimX;
}

int AffichageGraphique::getDimY() {
    return dimY;
}