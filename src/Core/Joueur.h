#ifndef _JOUEUR_H
#define _JOUEUR_H

#include <iostream>
#include "Bonus.h"

const int JOUEUR_MAX_BOMBES = 9; //Nombre maximum de bombe pouvant être posées à la fois par un joueur
const int JOUEUR_MAX_FLAMES = 9; //Portée maximum des bombes d'un joueur
const int JOUEUR_MAX_SPEED = 20; //Vitesse maximale d'un joueur

/**
 * @class Joueur
 * @brief Classe représentant un joueur. Elle stocke sa position, ses bonus, le nombre de bombes posées, ainsi que les hitboxes du joueur.
*/

class Joueur {
private:
    int x; //Position en X du joueur sur la grille
    int y; //Position en Y du joueur sur la grille
    float xExact; //Position en X exacte (flottante) du joueur sur la grille
    float yExact; //Position en Y exacte (flottante) du joueur sur la grille
    bool vivant; //Indique si le joueur est vivant ou non

    int nbBombesPosee; //Nombre de bombes posées par le joueur
    int nbBombesPoseeMax; //Nombre maximum de bombes que le joueur peut poser
    int porteeBombe; //Portée de l'explosion de la bombe du joueur
    int speed; //Vitesse du joueur
    
    float hitboxUP; //Hitbox haute du joueur
    float hitboxDOWN; //Hitbox basse du joueur
    float hitboxLEFT; //Hitbox gauche du joueur
    float hitboxRIGHT; //Hitbox droite du joueur
    
public:
    Joueur();

    void spawn(bool num, int xg, int yg);

    /**
    * @brief Fonction qui déplace le joueur vers la droite
    */
    void moveR(bool canSkip, bool canSkipUp, bool canSkipDown);

    /**
    * @brief Fonction qui déplace le joueur vers la gauche
    */
    void moveL(bool canSkip, bool canSkipUp, bool canSkipDown);

    /**
    * @brief Fonction qui déplace le joueur vers le haut
    */
    void moveU(bool canSkip, bool canSkipLeft, bool canSkipRight);

    /**
    * @brief Fonction qui déplace le joueur vers le bas
    */
    void moveD(bool canSkip, bool canSkipLeft, bool canSkipRight);

    /**
    * @brief Fonction qui fait poser une bombe au joueur
    */
    void poserBombe();

    /**
    * @brief Fonction qui fait récupérer une bombe au joueur
    */
    void recupererBombe();

    /**
    * @brief Fonction qui fait exploser le joueur
    */
    void exploser();

    /**
    * @brief Fonction qui donne un bonus au joueur
    * @param typeBonus Le bonus qui est donné au joueur
    */
    void appliquerBonus(BonusType typeBonus);

    /*
    * @brief Fonction qui retourne la position horizontale du joueur
    * @return L'entier joueur.x qui est la position horizontale du joueur
    */
    int getPositionX();

    /*
    * @brief Fonction qui retourne la position verticale du joueur
    * @return L'entier joueur.y qui est la position verticale du joueur
    */
    int getPositionY();

    /*
    * @brief Fonction qui retourne la position horizontale exacte du joueur
    * @return Le flottant joueur.xExact qui est la position horizontale exacte du joueur
    */
    float getExactX();

    /*
    * @brief Fonction qui retourne la position verticale exacte du joueur
    * @return Le flottant joueur.yExact qui est la position verticale exacte du joueur
    */
    float getExactY();

    /*
    * @brief Fonction qui retourne un booléen indiquant si le joueur est vivant
    */
    bool estVivant();

    /*
    * @brief Fonction qui retourne le nombre de bombes que le joueur a posé
    * @return L'entier joueur.nbBombes qui est le nombre de bombes posées par le joueur
    */
    int getNbBombes();

    /*
    * @brief Fonction qui retourne le nombre maximum de bombes que le joueur peut poser
    * @return L'entier joueur.nbBombesMax qui est le nombre maximum de bombes que le joueur peut poser
    */
    int getNbBombesMax();

    /*
    * @brief Fonction qui retourne la portée de l'explosion de la bombe du joueur
    * @return L'entier joueur.porteeBombe qui est la portée de l'explosion de la bombe du joueur
    */
    int getPorteeBombe();
};

#endif