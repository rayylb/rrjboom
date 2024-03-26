#ifndef _BOMBE_H
#define _BOMBE_H

/**
 * 
 * @class Bombe
 * @brief Classe représentant une bombe.
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

        /*
        * @brief Fonction qui retourne la position horizontale de la bombe
        * @return L'entier bombe.x qui est la position horizontale de la bombe
        */
        int getPosX();

        /* 
        * @brief Fonction qui retourne la position verticale de la bombe
        * @return L'entier bombe.y qui est la position verticale de la bombe
        */
        int getPosY();

        /*
        * @brief Fonction qui retourne la portée de la bombe
        * @return L'entier bombe.range qui est la portée de la bombe
        */
        int getRange();
        
        int getJoueur();
        
        /**
         * @brief Avance d'une unité de temps, jusqu'à l'explosion.
        */
        void avancerTemps();

        /**
         * @brief Fonction qui retourne un booléen indiquant si la bombe a explosé
        */
        bool estExplosee();
};

#endif