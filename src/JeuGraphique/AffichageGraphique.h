#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "../Core/Grille.h"

const int AFFICHAGE_NB_TEXTURES = 15; //Nombre de textures en mémoire

struct Button {
    int x, y;
    SDL_Rect rect;
    std::string text;
    SDL_Color textColor;
};

class AffichageGraphique {
    private:
        int dimX, dimY;
        SDL_Renderer* rendu;
        SDL_Window* fenetre;
        SDL_Surface* surface;
        SDL_Texture* textures[AFFICHAGE_NB_TEXTURES];
        TTF_Font* font;

    public:
        void initFenetre(int width, int height);
        void detruireFenetre();
        void clearRendu(SDL_Color color = {255, 255, 255, 255});
        void afficherRendu();
        
        int getDimX();
        int getDimY();
        SDL_Renderer* getRendu();

        void afficherRectangle(int posX, int posY, int width, int height, SDL_Color color = {255, 255, 255, 255});
        void afficherRectangle(SDL_Rect rect, SDL_Color color = {255, 255, 255, 255});
        void afficherSprite(float posX, float posY, int type_bloc, int taille_bloc);
        void afficherTexte(Button bouton);
};

#endif
