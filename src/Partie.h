#ifndef _PARTIE_H
#define _PARTIE_H

#include "Grille.h"
#include "Bombe.h"
#include "Joueur.h"

const int PARTIE_NB_JOUEURS = 2;
const int PARTIE_MAX_BOMBES = 9;
const int PARTIE_MAX_FLAMES = 9;

class Partie {
    private:
        Grille* grille;
        Joueur* j1;
        Joueur* j2;
        Bombe bombes[PARTIE_NB_JOUEURS*PARTIE_MAX_BOMBES];

    public:
        void initJeu(Grille* grille_jeu, Joueur* joueur1, Joueur* joueur2);
        void nouvellePartie();
        void actionsJoueurs();
        void avancerPartie();
};

#endif