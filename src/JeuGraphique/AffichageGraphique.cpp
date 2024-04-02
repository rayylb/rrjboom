#include "AffichageGraphique.h"
//#include <SDL/SDL_ttf.h>
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
            case 8: surface = IMG_Load("../data/bonus_bombe.png"); break;
            case 9: surface = IMG_Load("../data/bonus_flame.png"); break;
            case 10: surface = IMG_Load("../data/bonus_vitesse.png"); break;
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

int AffichageGraphique::getDimX() const{
    return dimX;
}

int AffichageGraphique::getDimY() const{
    return dimY;
}

SDL_Renderer* AffichageGraphique::getRendu() const{
    return rendu;
}

void AffichageGraphique::afficherRectangle(int posX, int posY, int height, int width) {
    SDL_Rect rect;
    rect.x = posX;
    rect.y = posY;
    rect.h = height;
    rect.w = width;
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
        destRect.h = destRect.h*0.8;
        destRect.w = destRect.w*0.8;
        destRect.x += taille_bloc*0.1;
        destRect.y += taille_bloc*0.3;
    }
    SDL_RenderCopy(rendu, textures[type_bloc], NULL, &destRect);
}

void AffichageGraphique::dessinerMenu() {
    SDL_SetRenderDrawColor(rendu, 200, 200, 0, 255); // Couleur de fond orange
    SDL_RenderClear(rendu);
    Button buttons[2];
    /* Initialisation des boutons
    buttons[0].text = "Play";
    buttons[0].textColor = {255, 255, 255, 255};
    buttons[1].text = "Quit";
    buttons[1].textColor = {255, 255, 255, 255};
    */
    // Coordonnées et dimensions des boutons
    SDL_Rect playRect = {
        static_cast<int>(static_cast<double>(dimX) / 2 - static_cast<double>(dimX) * 0.6 * 0.5),
        static_cast<int>(static_cast<double>(dimY) * 0.3 - static_cast<double>(dimY) * 0.1 * 0.5),
        static_cast<int>(dimX * 0.6),
        static_cast<int>(dimY * 0.1)
    };
    SDL_Rect quitRect = {
        static_cast<int>(static_cast<double>(dimX) / 2 - static_cast<double>(dimX) * 0.6 * 0.5),
        static_cast<int>(static_cast<double>(dimY) * 0.3 + static_cast<double>(dimY) * 0.1 * 0.5),
        static_cast<int>(dimX * 0.6),
        static_cast<int>(dimY * 0.1)
    };
    // Dessin des boutons
    SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255); // Couleur rouge pour les boutons (pour tester)     SDL_SetRenderDrawColor(rendu, 0, 0, 0, 0); // Couleur transparente
    SDL_RenderDrawRect(rendu, &playRect); // Dessine le rectangle du bouton "Play"
    SDL_RenderDrawRect(rendu, &quitRect); // Dessine le rectangle du bouton "Quit"
    // Met à jour l'affichage
    SDL_RenderPresent(rendu);

    /* POUR LE TEXTE (pas utile pour l'instant)
    
    Charger la police 
    TTF_Font* font = TTF_OpenFont("mygame.ttf", 24); // Adapter la taille de police au besoin

    // Vérifier si la police a été chargée avec succès
    if (!font) {
        std::cout << "Erreur lors du chargement de la police : " << TTF_GetError() << std::endl;
        return;
    } 

    // pour afficher le texte dans les boutons apres avoir charger la police
    SDL_Surface* playTextSurface = TTF_RenderText_Solid(font, buttons[0].text.c_str(), buttons[0].textColor);
    SDL_Surface* quitTextSurface = TTF_RenderText_Solid(font, buttons[1].text.c_str(), buttons[1].textColor);
    

    // Convertir les surfaces en textures (affiche les boutons)
    SDL_Texture* playTextTexture = SDL_CreateTextureFromSurface(rendu, playTextSurface);
    SDL_Texture* quitTextTexture = SDL_CreateTextureFromSurface(rendu, quitTextSurface);

    // Libérer les surfaces car elles ne sont plus nécessaires
    SDL_FreeSurface(playTextSurface);
    SDL_FreeSurface(quitTextSurface);

    // Vérifier si les textures ont été créées avec succès
    if (!playTextTexture || !quitTextTexture) {
        std::cerr << "Erreur lors de la création des textures de texte : " << SDL_GetError() << std::endl;
        TTF_CloseFont(font);
        return;
    }

    // Obtenir les dimensions des textures pour les positionner correctement
    int playTextWidth, playTextHeight, quitTextWidth, quitTextHeight;
    SDL_QueryTexture(playTextTexture, nullptr, nullptr, &playTextWidth, &playTextHeight);
    SDL_QueryTexture(quitTextTexture, nullptr, nullptr, &quitTextWidth, &quitTextHeight);

    // Positionner et afficher les textures des boutons
    SDL_Rect playTextRect = {playRect.x + 10, playRect.y + 10, playTextWidth, playTextHeight};
    SDL_Rect quitTextRect = {quitRect.x + 10, quitRect.y + 10, quitTextWidth, quitTextHeight};
    SDL_RenderCopy(rendu, playTextTexture, nullptr, &playTextRect);
    SDL_RenderCopy(rendu, quitTextTexture, nullptr, &quitTextRect);

    // Libérer la police
    TTF_CloseFont(font);
    
    */
}


