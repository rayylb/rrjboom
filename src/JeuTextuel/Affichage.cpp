#include <iostream>
#include "Affichage.h"

void Affichage::commencerJeu() {
    Partie testjeu;
    Grille grillejeu;
    testjeu.initJeu(grillejeu);
    bool jeuFini = false;
    char reponse;
    std::cout<<"Bienvenue dans Bomberman !"<<std::endl;
    while(!jeuFini) {
        std::cout<<"Nouvelle partie ? (rentrer y/n)"<<std::endl;
        std::cin>>reponse;
        if (reponse == 'y')
            testjeu.nouvellePartie();
        else
            jeuFini = true;
    }
    std::cout<<"Aurevoir !"<<std::endl;
}