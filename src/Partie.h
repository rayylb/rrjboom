#ifndef _PARTIE_H
#define _PARTIE_H

#include "Grille.h"
#include "Joueur.h"
#include "Bombe.h"
#include "Explosion.h"

const int PARTIE_NB_JOUEURS = 2;
const int PARTIE_MAX_BOMBES = 9;
const int PARTIE_MAX_FLAMES = 9;

class Partie {
    private:
        Grille* grille;
        Joueur joueur1;
        Joueur joueur2;
        Bombe bombes[PARTIE_NB_JOUEURS*PARTIE_MAX_BOMBES];
        Explosion explosions[PARTIE_NB_JOUEURS*PARTIE_MAX_BOMBES*PARTIE_MAX_FLAMES*4];

    public:
        void initJeu(Grille* grille_jeu);
        void nouvellePartie();
        void actionsJoueursTerminal();
        void avancerPartie();
        void afficherTerminal();
};

#endif