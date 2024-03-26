#include "Bloc.h"

Bloc::Bloc() {
    destructible = false;
    bonusPresent = false;
    peutMarcher = true;
}

Bloc::Bloc(bool isDestructible, bool hasBonus, bool canWalk) {
    destructible = isDestructible;
    bonusPresent = hasBonus;
    peutMarcher = canWalk;
}

bool Bloc::estDestructible() {
    return destructible;
}

bool Bloc::onPeutMarcher() {
    return peutMarcher;
}

bool Bloc::aBonus() {
    return bonusPresent;
}

void Bloc::retirerBonus() {
    bonusPresent = false;
    typeBonus = BonusType::Rien;
}

void Bloc::detruire() {
    if (destructible) {
        peutMarcher = true;
        destructible = false;
    }
}

void Bloc::blocSol() {
    destructible = false;
    bonusPresent = false;
    peutMarcher = true;
}

void Bloc::blocMur() {
    destructible = false;
    bonusPresent = false;
    peutMarcher = false;
}

void Bloc::blocDes(bool bonus) {
    destructible = true;
    bonusPresent = bonus;
    peutMarcher = false;
}

int Bloc::getType() {
    if (onPeutMarcher() && aBonus())
        return 6;
    else if (onPeutMarcher())
        return 0;
    else if (estDestructible() == true)
        return 1;
    else if (estDestructible() == false)
        return 2;
    else
        return 3;
}

BonusType Bloc::getBonusType() {
    return typeBonus;
}
