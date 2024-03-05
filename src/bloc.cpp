#include "bloc.h"
#include <assert.h> 

Bloc::Bloc()
{
    destructible = false;
    bonusPresent = false;
    peutMarcher = true;
    bombeActive = false;
    joueurQuiAPoseLaBombe = 0;
}
Bloc::Bloc(bool isDestructible, bool hasBonus, bool marcher)
{
    destructible = isDestructible;
    bonusPresent = hasBonus;
    peutMarcher = marcher;
    bombeActive = false;
    joueurQuiAPoseLaBombe = 0;
}



bool Bloc::estDestructible() {
    return destructible;
}
bool Bloc::onPeutMarcher() {
    return peutMarcher;
}
bool Bloc::aBonus(){
    return bonusPresent;
}
void Bloc::retirerBonus() {
    bonusPresent = false;
}
void Bloc::poserBombe(int joueur) {
    bombeActive = true;
    joueurQuiAPoseLaBombe = joueur;
}
void Bloc::detruire(){
    assert(destructible);
    peutMarcher = true;
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