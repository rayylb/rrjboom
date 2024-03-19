#include "JeuGraphique.h"
#include <iostream>

void JeuGraphique::jeuRectangle() {
    affichage.initFenetre(800, 600);
    SDL_Event event;
    bool running = true;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
        affichage.afficherRectangle(100, 100);
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