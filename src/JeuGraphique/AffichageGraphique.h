#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../Core/Grille.h"

class AffichageGraphique {
    private:
        int dimX, dimY;
        SDL_Window* fenetre;
        SDL_Renderer* rendu;
        SDL_Texture* texture;
        SDL_Surface* surface;

    public:
        void initFenetre(int width, int height);
        void detruireFenetre();

        void afficherRectangle(int posX, int posY);
        void afficherSprite(int posX, int posY, int type_bloc, int taille_bloc);
};

#endif
