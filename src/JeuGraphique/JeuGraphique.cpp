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
        if (recX + movX >= 0 && recX + movX <= 800-100) {
            recX += (2*movX);
        }
        if (recY + movY >= 0 && recY + movY <= 600-100) {
            recY += (2*movY);
        }
        affichage.afficherRectangle(recX, recY);
        SDL_Delay(16);
    }
    affichage.detruireFenetre();
}

void JeuGraphique::jeuSprite() {
    jeu.initPartie();
    int dimX = jeu.getGrille().getDimX();
    int dimY = jeu.getGrille().getDimY();
    affichage.initFenetre(800, 600);
    SDL_Event event;
    bool running = true;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        for(int i = 0; i < dimX; i++) {
            for(int j = 0; j < dimY; j++) {
                int type_bloc = jeu.getGrille().infoCase(i, j).getType();
                affichage.afficherSprite(i, j, type_bloc, 64);
            }
        }
        SDL_Delay(16);
    }
    affichage.detruireFenetre();
}

void JeuGraphique::boucleJeuMain() {
    nouvellePartie(64);
}

void JeuGraphique::nouvellePartie(int taille_bloc) {
    joueur1X = 0.5;
    joueur1Y = 0.5;
    joueur2X = 0.5;
    joueur2Y = 0.5;
    joueur1movX = 0;
    joueur1movY = 0;
    joueur2movX = 0;
    joueur2movY = 0;
    jeu.initPartie();
    affichage.initFenetre(jeu.getGrille().getDimX()*taille_bloc, jeu.getGrille().getDimY()*taille_bloc);
    afficherPartie();
    bool running = true;
    while(running) {
        tourDeJeu(running);
        afficherPartie();
        SDL_Delay(16);
    }
}

void JeuGraphique::afficherPartie() {
    int dimX = jeu.getGrille().getDimX();
    int dimY = jeu.getGrille().getDimY();
    for(int i = 0; i < dimX; i++) {
        for(int j = 0; j < dimY; j++) {
            int type_bloc = jeu.getGrille().infoCase(i, j).getType();
            affichage.afficherSprite(i, j, type_bloc, 64);
        }
    }
}

void JeuGraphique::tourDeJeu(bool& stillRunning) {
    SDL_Event event;
    int recX = 100;
    int recY = 100;
    int movX = 0;
    int movY = 0;
    while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT : stillRunning = false; break;
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
    if ((!jeu.getJoueur1().estVivant()) || (!jeu.getJoueur2().estVivant()))
        stillRunning = false;
}