#include "JeuGraphique.h"

void JeuGraphique::jeuRectangle() {
    AffichageGraphique aff;
    aff.initFenetre(800, 600);
    aff.afficherFenetre();
    //SDL_Delay(9000); 
    bool running = true;
    while(running) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT){
                running = false;
            }
        }
    }
    aff.detruireFenetre();
}

void JeuGraphique::jeuSprite() {

}