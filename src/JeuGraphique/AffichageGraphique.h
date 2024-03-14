#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>

class AffichageGraphique {
    private:
        int dimX, dimY;
        SDL_Window* fenetre;
        SDL_Renderer* rendu;
        SDL_Texture* texture;

    public:
        void initFenetre(int width, int height);
        void afficherFenetre();
        void detruireFenetre();
};

#endif
