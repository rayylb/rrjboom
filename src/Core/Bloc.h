#ifndef _BLOC_H
#define _BLOC_H

#include "Bonus.h"

/**
 * @class Bloc
 *
 * @brief La classe Bloc représente un bloc de la grille. Cette classe permet de créer et manipuler des bloc. 
 * La classe est constituée de booléens représentant si elle est destructible, si elle est détruite, si un bonus est présent sur la casee, et lequel.
 */

class Bloc {
private:
    bool destructible; //Indique si le bloc est destructible ou indestructible
    bool bonusPresent; //Indique si un bonus est présent dans ce bloc
    bool peutMarcher; //Indique si le bloc est détruit ou pas
    BonusType typeBonus; //Bonus présent sur la case

public:

    Bloc();
    Bloc(bool isDestructible, bool hasBonus, bool canWalk);

    /**
    * @brief Fonction qui retourne un booléen indiquant si le bloc est destructible
    *
    * @return Le paramêtre booléen 'destructible' du bloc.
    */
    bool estDestructible();

    /**
    * @brief Fonction qui retourne un booléen indiquant si les joueurs peuvent marcher sur le bloc
    *
    * @return Le paramêtre booléen 'peutMarcher' du bloc.
    */
    bool onPeutMarcher();

    /**
    * @brief Fonction qui retourne un booléen indiquant si une case possède un bonus
    *
    * @return Le paramêtre booléen 'bonusPresent' du bloc.
    */
    bool aBonus();

    /**
    * @brief Retire le bonus de la case en modifier la valeur du paramètre booléen 'BonusPresent' en false.
    */
    void retirerBonus();

    /**
    * @brief Detruit un bloc dans le jeu, en affectant au paramètre booléen "peutMarcher" la valeur True
    * @note Si la case n'est pas destructible, un message d'erreur est affiché.
    */
    void detruire();

    /**
    * @brief Transforme un bloc en "bloc sol" en affectant destructible = false, bonusPresent = false et peutMarcher = true
    * @param joueur Le joueur qui a posé la bombe
    */
    void blocSol();

    /**
    * @brief Transforme un bloc en "bloc destructible" en affectant destructible = true, bonusPresent = bonus et peutMarcher = false
    */
    void blocDes(BonusType bonus);

    /**
    * @brief Transforme un bloc en "bloc mur" en affectant destructible = false, bonusPresent = false et peutMarcher = false
    */
    void blocMur();

    int getType();

    BonusType getBonusType();
};


#endif 