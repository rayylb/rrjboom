#include "Bloc.h"

Bloc::Bloc(bool isDestructible, bool hasBonus, bool canWalk) {
    destructible = isDestructible;
    bonusPresent = hasBonus;
    peutMarcher = canWalk;
    typeBonus = BonusType::Rien;
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

void Bloc::blocDes(BonusType bonus) {
    destructible = true;
    bonusPresent = (bonus != BonusType::Rien);
    peutMarcher = false;
    typeBonus = bonus;
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
    else if (peutMarcher && bonusPresent)
        retirerBonus();
}

int Bloc::typeBloc() {
    if (onPeutMarcher() && aBonus() && (typeBonus != BonusType::Rien)) {
        if(typeBonus == BonusType::BombUp)
            return 11;
        else if (typeBonus == BonusType::FlameUp)
            return 12;
        else if(typeBonus == BonusType::SpeedUp)
            return 13;
        else
            return 10;
    }
    else if (onPeutMarcher())
        return 0;
    else if (estDestructible() == true)
        return 1;
    else if (estDestructible() == false)
        return 2;
    else
        return -1;
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

BonusType Bloc::getBonusType() {
    return typeBonus;
}
