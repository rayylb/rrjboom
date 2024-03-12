#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class AffichageGraphique {
    private:
        int DimX,DimY;
        SDL_Window * fenetre;
        SDL_Renderer * rendu;
        SDL_Texture *textureFond;

    public:
        void initFenetre();
        void detruireFenetre();
        SDL_Renderer* getRenderer();
};

#endif