#ifndef _BLOC_H
#define _BLOC_H

/**
 * @class Bloc
 *
 * @brief La classe Image représente un bloc de la grille. Cette classe permet de créer et manipuler des bloc. 
 * La classe est notamment constituée de booléens permettant de gérer les propriétés de la case: si elle est destructible, si elle est détruite, si une bombe a été
 * posée dessus, si un bonus est présent sur la case... L'entier jouerQuiAPosé
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
    Bloc(bool isDestructible, bool hasBonus, bool marcher);

    // Méthodes pour accéder et modifier les propriétés
    bool estDestructible();
    bool onPeutMarcher();
    bool aBonus();
    void retirerBonus();
    void poserBombe(int joueur);
    void detruire();
};


#endif 