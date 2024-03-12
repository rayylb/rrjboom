#ifndef _PARTIE_H
#define _PARTIE_H

#include "Grille.h"
#include "Joueur.h"
#include "Bombe.h"
#include "Explosion.h"

#include <vector>

const int PARTIE_MAX_BOMBES = 9;
const int PARTIE_MAX_FLAMES = 9;

class Partie {
    private:
        Grille grille;
        Joueur joueur1;
        Joueur joueur2;
        std::vector<Bombe> bombes;
        std::vector<Explosion> explosions;

    public:
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