#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Affichage.h"

int main(int argc,char *argv[])
{ 
    //fenetre noire
    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
    //personnage rectangle rouge
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = 200
    rect.h = 150;
        SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
        SDL_RenderFillRect(rendu, & rect);
        SDL_RenderClear(rendu);
    SDL_RenderPresent(rendu);
      SDL_Delay(9000); 
    affichage.detruireFenetre();
    return 0;
}
