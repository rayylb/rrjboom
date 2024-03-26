#ifndef _JOUEUR_H
#define _JOUEUR_H

#include "Bonus.h"

class Joueur {
private:
    bool numero; ///<  Numéro du joueur (True pour le joueur 1, False pour le joueur 2)
    int x; ///<  Position en X du joueur sur la grille
    int y; ///<  Position en Y du joueur sur la grille
    float xExact; ///<  Position en X exacte (flottante) du joueur sur la grille
    float yExact; ///<  Position en Y exacte (flottante) du joueur sur la grille
    int nbBombes; ///<  Nombre de bombes posées par le joueur
    int nbBombesMax; ///<  Nombre maximum de bombes que le joueur peut poser
    int porteeBombe; ///<  Portée de l'explosion de la bombe du joueur
    int speed;
    bool vivant; ///<  Indique si le joueur est vivant ou non
    float hitboxUP;
    float hitboxDOWN;
    float hitboxLEFT;
    float hitboxRIGHT;
    
public:
    void spawn(bool num, int xg, int yg);

    /**
    * @brief Fonction qui retourne la position horizontale du joueur
    * @return L'entier joueur.x qui est la position horizontale du joueur
    */
    int getPositionX();

    /**
    * @brief Fonction qui retourne la position verticale du joueur
    * @return L'entier joueur.y qui est la position verticale du joueur
    */
    int getPositionY();

    /**
    * @brief Fonction qui retourne le nombre de bombes que le joueur a posé
    * @return L'entier joueur.nbBombes qui est le nombre de bombes posées par le joueur
    */
    int getNbBombes();

    /**
    * @brief Fonction qui retourne la position horizontale exacte du joueur
    * @return Le flottant joueur.xExact qui est la position horizontale exacte du joueur
    */
    float getExactX();

    /**
    * @brief Fonction qui retourne la position verticale exacte du joueur
    * @return Le flottant joueur.yExact qui est la position verticale exacte du joueur
    */
    float getExactY();

    /**
    * @brief Fonction qui retourne le nombre maximum de bombes que le joueur peut poser
    * @return L'entier joueur.nbBombesMax qui est le nombre maximum de bombes que le joueur peut poser
    */
    int getNbBombesMax();

    /**
    * @brief Fonction qui retourne la portée de l'explosion de la bombe du joueur
    * @return L'entier joueur.porteeBombe qui est la portée de l'explosion de la bombe du joueur
    */
    int getPorteeBombe();

    /**
    * @brief Fonction qui retourne un booléen indiquant si le joueur est vivant
    */
    bool estVivant();

    /**
    * @brief Fonction qui déplace le joueur vers la droite
    */
    void moveR(bool canSkip);

    /**
    * @brief Fonction qui déplace le joueur vers la gauche
    */
    void moveL(bool canSkip);

    /**
    * @brief Fonction qui déplace le joueur vers le haut
    */
    void moveU(bool canSkip);

    /**
    * @brief Fonction qui déplace le joueur vers le bas
    */
    void moveD(bool canSkip);

    /**
    * @brief Fonction qui fait poser une bombe au joueur
    */
    void poserBombe();

    /**
    * @brief Fonction qui fait exploser le joueur
    */
    void exploser();

    //ajouter un getbonus
    int GetBonus();

    void appliquerBonus(BonusType typeBonus);
};

#endif