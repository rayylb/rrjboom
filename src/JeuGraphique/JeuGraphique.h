#ifndef _JEUGRAPHIQUE_H_
#define _JEUGRAPHIQUE_H_

#include <SDL2/SDL.h>
#include "../Core/Partie.h"
#include "AffichageGraphique.h"

/**
 * @class JeuGraphique
 * @brief Classe permettant de jouer au jeu sur une fenêtre. Elle contient une partie pour gérer le jeu et une classe d'affichage pour gérer la SDL.
*/

class JeuGraphique {
    private:
        Partie jeu; //La partie du jeu
        AffichageGraphique affichage; //L'affichage du jeu
        int joueur1movX; //La vitesse horizontale du joueur 1
        int joueur1movY; //La vitesse verticale du joueur 1
        int joueur2movX; //La vitesse horizontale du joueur 2
        int joueur2movY; //La vitesse verticale du joueur 2

    public:
        JeuGraphique();
        
        /**
         * @brief Boucle principal du jeu
        */
        void boucleJeuMain();

        /**
         * @brief Boucle du menu
         * @param mainQuit Indique si l'excécution doit être arrêtée
         * @return Indique si une partie doit commencer
        */
        bool boucleMenu(bool& mainQuit);

        /**
         * @brief Commence une nouvelle partie
         * @param taille_bloc Taille en pixel avec laquelle seront affichés les cases du terrain
        */
        void nouvellePartie(int taille_bloc);
        
        /**
         * @brief Récupère les action des joueur et fait avancer la partie d'une frame
         * @param stillRunning Indique si la partie est finie
        */
        void tourDeJeu(bool& stillRunning);

        /**
         * @brief Convertis les inputs du joueur en commandes compréhensibles par la partie
         * @param joueurMovX La vitesse horizontale du joueur
         * @param joueurMovY La vitesse verticale du joueur
         * @param mov Caractère qui sera interprété par la partie
        */
        void convertirTouches(int joueurMovX, int joueurMovY, char& mov);

        /**
         * @brief Affiche le menu sur la fenêtre
         * @param buttons Boutons présents sur le menu
        */
        void afficherMenu(Button buttons[2]);

        /**
         * @brief Affiche la partie sur la fenêtre
         * @param taille_bloc Taille en pixel avec laquelle seront affichés les cases du terrain
        */
        void afficherPartie(int taille_bloc);

        /**
         * @brief Demo de mouvement d'un personnage dans la fenêtre
        */
        void jeuRectangle();

        /**
         * @brief Demo d'affichage du terrain de jeu
        */
        void jeuSprite();
};

#endif