#include "Partie.h"

void Partie::initJeu(Grille* grille_jeu) {
    grille = grille_jeu;
}

void Partie::nouvellePartie() {
    int dimx, dimy;
    grille->getDim(dimx, dimy);
    grille->initGrille();
    joueur1.spawn(true, 0, 0);
    joueur2.spawn(false, dimx-1, dimy-1);
    while(joueur1.estVivant() && joueur2.estVivant()) {
        actionsJoueursTerminal();
        avancerPartie();
        afficherTerminal();
    }
}