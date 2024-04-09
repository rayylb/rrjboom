#ifndef _AFFICHAGETEXTE_H
#define _AFFICHAGETEXTE_H

#include "../Core/Partie.h"

/**
 * @class AffichageTexte
 * @brief Classe permettant de joueur au jeu dans le terminal. Elle contient seulement une partie et se sert de ses informations pour afficher la grille.
*/

class AffichageTexte {
    private:
        Partie jeu; //La partie du jeu
    
    public:
        AffichageTexte();

        /**
         * @brief Boucle principal du jeu, lance le menu
        */
        void boucleJeuMain();

        /**
         * @brief Boucle de jeu d'une partie
        */
        void nouvellePartie();

        /**
         * @brief Affiche la grille dans le terminal
        */
        void afficherPartie();

        /**
         * @brief Fais avancer le jeu d'un tour
        */
        void tourDeJeu();

        /**
         * @brief Convertis les inputs du joueur en commandes compréhensibles par la partie
         * @param up Caractère qui indique que le joueur va en haut
         * @param left Caractère qui indique que le joueur va à gauche
         * @param down Caractère qui indique que le joueur va en bas
         * @param right Caractère qui indique que le joueur va à droite
         * @param mov Caractère qui sera interprété par la partie
        */
        void convertirMove(char up, char left, char down, char right, char& mov);
};

#endif