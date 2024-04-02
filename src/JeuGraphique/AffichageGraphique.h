#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../Core/Grille.h"

const int AFFICHAGE_NB_TEXTURES = 8; //Nombre de textures en mémoire

struct Button {
    int x, y;
    SDL_Rect rect;
    //std::string text;
    //SDL_Color textColor;
    SDL_Texture* texture;
};

class AffichageGraphique {
    private:
        int dimX, dimY;
        SDL_Renderer* rendu;
        SDL_Window* fenetre;
        SDL_Surface* surface;
        SDL_Texture* textures[AFFICHAGE_NB_TEXTURES];
        SDL_Texture* textureFondMenu;

    public:
        void initFenetre(int width, int height);
        void detruireFenetre();
        void clearRendu();
        void afficherRendu();
        SDL_Renderer * getRendu() const;


        void afficherRectangle(int posX, int posY, int height, int width);
        void afficherSprite(float posX, float posY, int type_bloc, int taille_bloc);
        void dessinerMenu();
};

#endif
