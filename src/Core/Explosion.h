#ifndef _EXPLOSION_H
#define _EXPLOSION_H

/**
 * @class Explosion
 * @brief Classe représentant une explosion sur une case de la grille.
 * L'explosion est créée par une bombe après son explosion. Elle détruit les murs et tue les joueurs à proximité.
 */

class Explosion {
    private:
        int x; //Indique la position horizontale de l'explosion
        int y; //Indique la position verticale de l'explosion
        int timer; //Indique le temps restant avant la fin de l'explosion

    public:
        Explosion() : x(0), y(0), timer(3) {};

        Explosion(int xpos, int ypos);

        /**
        * @brief Fonction qui avance d'une unité de temps, jusqu'à la fin de l'explosion
        */
        void avancerTemps();

        /**
        * @brief Fonction qui retourne la position horizontale de l'explosion
        * @return L'entier x qui est la position horizontale de l'explosion
        */
        int getPosX();

        /**
        * @brief Fonction qui retourne la position verticale de l'explosion
        * @return L'entier y qui est la position verticale de l'explosion
        */
        int getPosY();

        /**
        * @brief Fonction qui retourne un booléen indiquant si l'explosion est terminée
        * @return True si l'explosion est encore présente
        */
        bool estActif();
};

#endif