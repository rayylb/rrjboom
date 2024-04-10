#include "Partie.h"
#include <assert.h>

int main(void){
    // Test régression Bloc.h
    Grille grille;
    Partie partie;
    Bloc bloc;
    bloc.blocSol();
    assert(bloc.onPeutMarcher() == true);
    assert(bloc.estDestructible() == false);
    assert(bloc.aBonus() == false);
    bloc.blocMur();
    assert(bloc.onPeutMarcher() == false);
    assert(bloc.estDestructible() == false);
    assert(bloc.aBonus() == false);
    bloc.blocDes(BonusType::Rien);
    assert(bloc.onPeutMarcher() == false);
    assert(bloc.estDestructible() == true);
    assert(bloc.aBonus() == true);
    bloc.blocDes(BonusType::Rien);
    assert(bloc.onPeutMarcher() == false);
    assert(bloc.estDestructible() == true);
    assert(bloc.aBonus() == false);
    bloc.detruire();
    assert(bloc.onPeutMarcher() == true);
    assert(bloc.estDestructible() == false);
    assert(bloc.aBonus() == false);

    // Test régression Grille.h
    grille.initGrille(GRILLE_DIMX_MAX, GRILLE_DIMY_MAX);
    assert(grille.getDimX() == GRILLE_DIMX_MAX);
    assert(grille.getDimY() == GRILLE_DIMY_MAX);
    grille.affichTerminal();
    Bloc bloc2;
    grille.infoCase(0, 0, bloc2);
    assert(bloc2.onPeutMarcher() == true);
    assert(bloc2.estDestructible() == false);
    assert(bloc2.aBonus() == false);
    grille.detruireCase(0, 0);
    grille.infoCase(0, 0, bloc2);
    assert(bloc2.onPeutMarcher() == true);
    assert(bloc2.estDestructible() == false);
    assert(bloc2.aBonus() == false);
    grille.recupererBonus(0, 0);
    grille.infoCase(0, 0, bloc2);
    assert(bloc2.onPeutMarcher() == true);
    assert(bloc2.estDestructible() == false);
    assert(bloc2.aBonus() == false);

    // Test régression Joueur.h
    Joueur joueur;
    assert(joueur.getPositionX() == 0);
    assert(joueur.getPositionY() == 0);
    assert(joueur.getNbBombes() == 0);
    assert(joueur.getNbBombesMax() == 9);
    return 0;
}