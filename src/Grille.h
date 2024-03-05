#ifndef _GRILLE_H
#define _GRILLE_H

#include "Bloc.h"

const int GRILLE_DIMX = 13;
const int GRILLE_DIMY = 7;

/**
 * @class Grille
 * 
 * @brief La classe Grille comporte l'ensemble des blocs qui forment le terrain de jeu. Elle ne comporte pas les joueurs ou les bombes.
*/

class Grille {
private:
    Bloc terrain[GRILLE_DIMX][GRILLE_DIMY];

public:
    /**
     * @brief Récupère la dimension de la grille.
     * 
     * @param x Largeur de la grille.
     * @param y Hauteur de la grille.
    */
    void getDim(int x, int y);

    /**
     * @brief Génère un terrain aléatoirement, prêt à être joué dessus.
    */
    void initGrille();
    /**
     * @brief Affiche la grille dans le terminal.
    */
    void affichTerminal();

    /**
     * @brief Récupère une case de la grille sans la modifier.
     * 
     * @param x Abscisse du bloc à récupérer.
     * @param y Ordonnée du bloc à récupérer.
     * @param copie Copie du bloc demandé.
    */
    void infoCase(int x, int y, Bloc& copie);

    /**
     * @brief Détruit le bloc sur une case de la grille, si elle est destructible.
     * 
     * @param x Abscisse du bloc qu'on essaie de détruire.
     * @param y Ordonnée du bloc qu'on essaie de détruire
    */
    void detruireCase(int x, int  y);
    /**
     * @brief Récupère un bonus sur une case de la grille, si elle en comporte un.
     * 
     * @param x Abscisse du bonus qu'on essaie de récupérer.
     * @param y Ordonnée du bonus qu'on essaie de récupérer.
    */
    void recupererBonus(int x, int y);
};

#endif