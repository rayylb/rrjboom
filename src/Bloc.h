#ifndef _BLOC_H
#define _BLOC_H

/**
 * @class Bloc
 *
 * @brief La classe Bloc représente un bloc de la grille. Cette classe permet de créer et manipuler des bloc. 
 * La classe est notamment constituée de booléens permettant de gérer les propriétés de la case: si elle est destructible, si elle est détruite, si une bombe a été
 * posée dessus, si un bonus est présent sur la case... L'entier jouerQuiAPoséLaBombe permet de connaître le joueur qui a posé une bombe, si une bombe a été posée.
 */
class Bloc {
private:
    bool destructible; // Indique si le bloc est destructible ou indestructible
    bool bonusPresent; // Indique si un bonus est présent dans ce bloc
    bool peutMarcher; // Indique si le bloc est détruit ou pas
    bool bombeActive; //Indique si une bombe est posée sur le plateau
    int joueurQuiAPoseLaBombe; // Peut être 0 pour aucun joueur ou 1/2 pour les joueurs respectifs

    // Vous pouvez ajouter d'autres propriétés en fonction de vos besoins

public:

    Bloc();
    Bloc(bool isDestructible, bool hasBonus, bool marcher);

    // Méthodes pour accéder et modifier les propriétés

    /**
    * @brief Fonction qui retourne un booléen indiquant si le bloc est destructible
    *
    * @return Le paramêtre booléen 'destructible' du bloc.
    *
    */
    bool estDestructible();

    /**
    * @brief Fonction qui retourne un booléen indiquant si les joueurs peuvent marcher sur le bloc
    *
    * @return Le paramêtre booléen 'peutMarcher' du bloc.
    *
    */
    bool onPeutMarcher();

    /**
    * @brief Fonction qui retourne un booléen indiquant si une case possède un bonus
    *
    * @return Le paramêtre booléen 'bonusPresent' du bloc.
    *
    */
    bool aBonus();

    /**
    * @brief Retire le bonus de la case en modifier la valeur du paramètre booléen 'BonusPresent' en false.
    */
    void retirerBonus();

    /**
    * @brief Efface l'image en remplissant toute sa surface avec une 
    * couleur spécifiée. La couleur précédente est donc effacée.
    *
    * @param couleur La couleur à utiliser pour effacer l'image
    * @note si les dimensions de l'image sont nulles ou négatives, un message
    * d'erreur est affiché
    */    
    void poserBombe(int joueur);

    void detruire();
    void blocSol();
    void blocDes(bool bonus);
    void blocMur();
};


#endif 