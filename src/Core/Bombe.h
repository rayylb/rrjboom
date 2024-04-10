#ifndef _BOMBE_H
#define _BOMBE_H

/**
 * @class Bombe
 * @brief Classe représentant une bombe sur une case de la grille.
 * La bombe est placée par un joueur sur une case du plateau de jeu. Elle explose
 * après un certain temps, détruisant les murs et tuant les joueurs à proximité.
*/

class Bombe {
    private:
        int x; //Indique la position horizontale de la bombe
        int y; //Indique la position verticale de la bombe
        int range; //Indique la portée de la bombe
        int timer; //Indique le temps restant avant l'explosion
        int joueur; //Joueur qui a posé la bombe
    
    public:
        Bombe() : x(0), y(0), range(1), timer(3), joueur(1) {};

        Bombe(int xpos, int ypos, int flamerange, int joueurpose);

        /**
         * @brief Avance d'une unité de temps, jusqu'à l'explosion
        */
        void avancerTemps();

        /**
         * @brief Force l'explosion de la bombe
        */
        void exploser();

        /**
        * @brief Fonction qui retourne la position horizontale de la bombe
        * @return La position horizontale entière de la bombe sur la grille
        */
        int getPosX();

        /** 
        * @brief Fonction qui retourne la position verticale de la bombe
        * @return La position verticale entière de la bombe sur la grille
        */
        int getPosY();

        /**
        * @brief Fonction qui retourne la portée de la bombe
        * @return Le nombre de case dans chaque direction
        */
        int getRange();

        /**
         * @brief Fonction qui retourne un booléen indiquant si la bombe est proche d'exploser
        */
        bool estProcheExplosee();

        /**
         * @brief Fonction qui retourne un booléen indiquant si la bombe a explosé
        */
        bool estExplosee();

        /**
         * @brief Fonction qui renvoie le joueur ayant posé la bombe
         * @return Soit 1 ou 2 en fonction du joueur
        */
        int getJoueur();
};

#endif