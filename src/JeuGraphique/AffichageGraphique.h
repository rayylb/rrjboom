#ifndef _AFFICHAGEGRAPHIQUE_H_
#define _AFFICHAGEGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "../Core/Grille.h"
#include "Button.h"

const int AFFICHAGE_NB_TEXTURES = 15; //Nombre de textures en mémoire

/**
 * @class AffichageGraphique
 * @brief Classe intermédiaire permettant l'utilisation de la SDL à travers des fonction simples comme afficherRectangle ou afficherSprite.
*/

class AffichageGraphique {
    private:
        int dimX; //Largeur de la fenêtre
        int dimY; //Hauteur de la fenêtre
        SDL_Window* fenetre; //La fenêtre actuellement utilisée
        SDL_Renderer* rendu; //Objet Renderer de la SDL
        SDL_Surface* surface; //Objet Surface de la SDL
        SDL_Texture* textures[AFFICHAGE_NB_TEXTURES]; //Tableau des textures chargées en mémoire
        TTF_Font* font; //Police utilisée pour les textes chargée en mémoire

    public:
        AffichageGraphique();

        /**
         * @brief Initialise la SDL, charge les images et la police en mémoire, et ouvre une nouvelle fenêtre
         * @param width Largeur de la fenêtre
         * @param height Hauteur de la fenêtre
        */
        void initFenetre(int width, int height);

        /**
         * @brief Quitte la SDL proprement
        */
        void detruireFenetre();

        /**
         * @brief Efface tout ce qu'il y a dans la fenêtre
         * @param color Couleur par laquelle sera remplacée l'écran
        */
        void clearRendu(SDL_Color color = {255, 255, 255, 255});

        /**
         * @brief Mets à jour l'affichage de la fenêtre
        */
        void afficherRendu();
        
        /**
         * @brief Dessine un rectangle sur la fenêtre
         * @param posX Position horizontale du coin haut gauche du rectangle
         * @param posY Position verticale du coin haut gauche du rectangle
         * @param width Largeur du rectangle
         * @param height Hauteur du rectangle
         * @param color Couleur du rectangle
        */
        void afficherRectangle(int posX, int posY, int width, int height, SDL_Color color = {255, 255, 255, 255});

        /**
         * @brief Dessine un rectangle sur la fenêtre
         * @param rect Objet rectangle de la SDL
         * @param color Couleur du rectangle
        */
        void afficherRectangle(SDL_Rect rect, SDL_Color color = {255, 255, 255, 255});

        /**
         * @brief Dessine un sprite déjà chargée en mémoire sur la fenêtre
         * @param posX Position horizontale du coin haut gauche du sprite
         * @param posY Position verticale du coin haut gauche du sprite
         * @param type_bloc Le numéro de l'image chargée en mémoire
         * @param taille_bloc Taille avec laquelle le sprite sera affiché
        */
        void afficherSprite(float posX, float posY, int type_bloc, int taille_bloc);

        /**
         * @brief Affiche du texte sur la fenêtre
         * @param bouton Une structure contenant toutes les informations sur un texte à afficher sur la fenêtre
        */
        void afficherTexte(Button bouton);

        /**
         * @brief Retourne la largeur de la fenêtre
         * @return Largeur de la fenêtre, en pixels
        */
        int getDimX();

        /**
         * @brief Retourne la hauteur de la fenêtre
         * @return Hauteur de la fenêtre, en pixels
        */
        int getDimY();
};

#endif
