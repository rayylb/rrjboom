#ifndef _GRILLE_H
#define _GRILLE_H

#include "Bloc.h"

/// constantes GRILLE_DIMX et GRILLE_DIMY
const int GRILLE_DIMX = 9;
const int GRILLE_DIMY = 5;

/**
 * 
 * @class Grille
 * @brief Classe représentant le plateau de jeu.
 * 
 * La grille est composée de cases, qui peuvent être vides, contenir un mur (destructible ou non), une bombe
 * ou un bonus. Elle est utilisée pour déterminer les déplacements des joueurs, les
 * explosions des bombes et les effets des bonus.
 */
class Grille {
private:
    Bloc terrain[GRILLE_DIMX][GRILLE_DIMY]; ///<  Tableau de cases représentant le plateau de jeu

public:
    /*
    * @brief Fonction qui retourne la largeur de la grille
    * @return L'entier GRILLE_DIMX qui est la largeur de la grille
    */
    int getDimX();

    /*
    * @brief Fonction qui retourne la hauteur de la grille
    * @return L'entier GRILLE_DIMY qui est la hauteur de la grille
    */
    int getDimY();

    /*
    * @brief Fonction qui initialise la grille avec des murs et des cases vides
    */
    void initGrille();

    /*
    * @brief Fonction qui affiche la grille dans le terminal
    */
    void affichTerminal();

    /*
    * @brief Copie la case demandée dans la case copie passée en référence
    * @param x Coordonnée horizontale de la case à copier
    * @param y Coordonnée verticale de la case à copier
    * @param copie Référence vers la case qui contiendra les informations copiées
    */
    void infoCase(int x, int y, Bloc& copie);

    /*
    * @brief Renvoie une référence vers la case demandée
    * @param x Coordonnée horizontale de la case
    * @param y Coordonnée verticale de la case
    * @return Référence vers la case demandée
    */
    Bloc& infoCase(int x, int y);

    /*
    * @brief Fonction qui détruit la case demandée, rendant la case marchable pour les joueurs
    * @param x Coordonnée horizontale de la case
    * @param y Coordonnée verticale de la case
    */
    void detruireCase(int x, int  y);

    /*
    * @brief Fonction qui retire le bonus de la case demandée
    * @param x Coordonnée horizontale de la case
    * @param y Coordonnée verticale de la case
    */
    BonusType recupererBonus(int x, int y);
};

#endif