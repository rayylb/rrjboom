#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../Core/Grille.h"

const int AFFICHAGE_NB_TEXTURES = 8; //Nombre de textures en mémoire

class AffichageGraphique {
    private:
        int dimX, dimY;
        SDL_Window* fenetre;
        SDL_Renderer* rendu;
        SDL_Surface* surface;
        SDL_Texture* textures[AFFICHAGE_NB_TEXTURES];

    public:
        void initFenetre(int width, int height);
        void detruireFenetre();
        void clearRendu();
        void afficherRendu();

        void afficherRectangle(int posX, int posY, int width, int height);
        void afficherSprite(float posX, float posY, int type_bloc, int taille_bloc);
};

#endif
