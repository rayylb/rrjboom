#include "JeuGraphique.h"
#include <iostream>

void JeuGraphique::jeuRectangle() {
    affichage.initFenetre(800, 600);
    SDL_Event event;
    bool running = true;
    int recX = 100;
    int recY = 100;
    int movX = 0;
    int movY = 0;
    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT : running = false; break;
                case SDL_KEYDOWN :
                    switch (event.key.keysym.sym) {
                        case SDLK_UP : movY = -1; break;
                        case SDLK_DOWN : movY = +1; break;
                        case SDLK_LEFT : movX = -1; break;
                        case SDLK_RIGHT : movX = +1; break;
                    }
                    break;
                case SDL_KEYUP :
                    switch (event.key.keysym.sym) {
                        case SDLK_UP : if(movY<0) movY = 0; break;
                        case SDLK_DOWN : if(movY>0) movY = 0; break;
                        case SDLK_LEFT : if(movX<0) movX = 0; break;
                        case SDLK_RIGHT : if(movX>0) movX = 0; break;
                    }
                    break;
                }
        }
        recX += (movX);
        recY += (movY);
        affichage.afficherRectangle(recX, recY);
        SDL_Delay(16);
    }
    affichage.detruireFenetre();
}

void JeuGraphique::jeuSprite() {
    Grille grille = jeu.getGrille();
    grille.initGrille();
    affichage.initFenetre(800, 600);
    SDL_Event event;
    bool running = true;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        for(int i = 0; i < grille.getDimX(); i++) {
            for(int j = 0; j < grille.getDimY(); j++) {
                int type_bloc = grille.infoCase(i, j).getType();
                affichage.afficherSprite((i*100), (j*100), type_bloc);
            }
        }
    }
    affichage.detruireFenetre();
}