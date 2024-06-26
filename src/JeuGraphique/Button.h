#ifndef _BUTTON_H
#define _BUTTON_H

#include <SDL2/SDL.h>
#include <iostream>

/**
 * @struct Button
 * @brief Structure représentant un bouton sur la fenêtre
*/

struct Button {
    SDL_Rect rect;
    std::string text;
    SDL_Color textColor;
    SDL_Color backColor;
    SDL_Color rectColor;
};

#endif