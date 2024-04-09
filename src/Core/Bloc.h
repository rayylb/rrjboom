#ifndef _BLOC_H
#define _BLOC_H

#include "Bonus.h"

/**
 * @class Bloc
 * @brief Classe représentant un bloc de la grille. Cette classe permet de créer et manipuler des bloc. 
 * La classe est constituée de booléens représentant si elle est destructible, si elle est détruite, si un bonus est présent sur la case, et lequel.
 */

class Bloc {
private:
    bool destructible; //Indique si le bloc est destructible ou indestructible
    bool bonusPresent; //Indique si un bonus est présent dans ce bloc
    bool peutMarcher; //Indique si le bloc est détruit ou pas
    BonusType typeBonus; //Bonus présent sur la case

public:
    Bloc() : destructible(false), bonusPresent(false), peutMarcher(true), typeBonus(BonusType::Rien) {};

    Bloc(bool isDestructible, bool hasBonus, bool canWalk);

    /**
    * @brief Transforme un bloc en "bloc sol" en affectant destructible = false, bonusPresent = false et peutMarcher = true
    */
    void blocSol();

    /**
    * @brief Transforme un bloc en "bloc destructible" en affectant destructible = true, bonusPresent = bonus et peutMarcher = false
    * @param bonus Le bonus présent dans le bloc
    */
    void blocDes(BonusType bonus);

    /**
    * @brief Transforme un bloc en "bloc mur" en affectant destructible = false, bonusPresent = false et peutMarcher = false
    */
    void blocMur();

    /**
    * @brief Retire le bonus de la case
    */
    void retirerBonus();

    /**
    * @brief Essaie de détruire le bloc, si il n'est pas destructible rien ne se passera
    */
    void detruire();

    /**
     * @brief Retourne le type de bloc
     * @return L'entier retourné correspond à l'image chargée en mémoire
    */
    int typeBloc();

    /**
    * @brief Fonction qui retourne un booléen indiquant si le bloc est destructible
    * @return Le paramêtre booléen 'destructible' du bloc
    */
    bool estDestructible();

    /**
    * @brief Fonction qui retourne un booléen indiquant si les joueurs peuvent marcher sur le bloc
    * @return Le paramêtre booléen 'peutMarcher' du bloc
    */
    bool onPeutMarcher();

    /**
    * @brief Fonction qui retourne un booléen indiquant si une case possède un bonus
    * @return Le paramêtre booléen 'bonusPresent' du bloc
    */
    bool aBonus();

    /**
    * @brief Fonction qui retourne le bonus présent sur la case
    * @return Le paramêtre 'typeBonus' du bloc
    */
    BonusType getBonusType();
};

#endif 