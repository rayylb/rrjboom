#ifndef _PARTIE_H
#define _PARTIE_H

#include "Grille.h"
#include "Joueur.h"
#include "Bombe.h"
#include "Bonus.h"
#include "Explosion.h"
#include <vector>

const int PARTIE_MAX_BOMBES = 9;
const int PARTIE_MAX_FLAMES = 9;

/*
* @class Partie
* @brief Classe représentant une partie de jeu
* Elle contient une grille, deux joueurs, des bombes et des explosions
*
*/

class Partie {
    private:
        Grille grille; ///< La grille de jeu
        Joueur joueur1; ///< Le joueur 1
        Joueur joueur2; ///< Le joueur 2
        std::vector<Bombe> bombes; ///< La liste des bombes posées sur la grille
        std::vector<Explosion> explosions; ///< La liste des explosions sur la grille

    public:

        /**
         * @brief Fonction qui initialise une partie de jeu
         */
        void initPartie();

        Grille& getGrille();
        Joueur& getJoueur1();
        Joueur& getJoueur2();
        std::vector<Bombe>& getBombes();
        std::vector<Explosion>& getExplosions();

        void actionsJoueurs(char movJ1, char bombJ1, char movJ2, char bombJ2);
        void avancerPartie();

        void creerExplosions(Bombe source);
        bool caseEstExplosee(int posX, int posY);
        bool caseEstMinee(int posX, int posY);
};

#endif