#include "Bloc.h"

Bloc::Bloc(){
    destructible = false;
    bonusPresent = false;
    peutMarcher = true;
}

Bloc::Bloc(bool isDestructible, bool hasBonus, bool marcher){
    destructible = isDestructible;
    bonusPresent = hasBonus;
    peutMarcher = marcher;
}

bool Bloc::estDestructible(){
    return destructible;
}

bool Bloc::onPeutMarcher(){
    return peutMarcher;
}

bool Bloc::aBonus(){
    return bonusPresent;
}

void Bloc::retirerBonus(){
    bonusPresent = false;
}

void Bloc::detruire(){
    if (destructible) {
        peutMarcher = true;
        destructible = false;
    }
}

void Bloc::blocSol(){
    destructible = false;
    bonusPresent = false;
    peutMarcher = true;
}

void Bloc::blocMur(){
    destructible = false;
    bonusPresent = false;
    peutMarcher = false;
}

void Bloc::blocDes(bool bonus){
    destructible = true;
    bonusPresent = bonus;
    peutMarcher = false;
}
