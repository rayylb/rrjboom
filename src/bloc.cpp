#include "bloc.h"

Bloc::Bloc(bool isDestructible, bool hasBonus, bool marcher)
{
    destructible = isDestructible;
    bonusPresent = hasBonus;
    peutMarcher = marcher;
    bombeActive = false;
    joueurQuiAPoseLaBombe = 0;
}

    // Méthodes pour accéder et modifier les propriétés
bool estDestructible();
bool onPeutMarcher();
bool aBonus();
void retirerBonus();
void poserBombe(int joueur);
void detruire();