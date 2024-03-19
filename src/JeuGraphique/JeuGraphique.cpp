#include "JeuGraphique.h"

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

}