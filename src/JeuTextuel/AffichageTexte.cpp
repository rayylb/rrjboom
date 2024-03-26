#include <iostream>
#include "AffichageTexte.h"

void AffichageTexte::boucleJeu() {
    bool jeuFini = false;
    char reponse;
    std::cout<<"Bienvenue dans Bomberman !"<<std::endl;
    while(!jeuFini) {
        std::cout<<"Nouvelle partie ? (rentrer y/n)"<<std::endl;
        std::cin>>reponse;
        if (reponse == 'y')
            nouvellePartie();
        else
            jeuFini = true;
    }
    std::cout<<"Aurevoir !"<<std::endl;
}

void AffichageTexte::nouvellePartie() {
    jeu.initPartie();
    afficherPartie();
    while(jeu.getJoueur1().estVivant() && jeu.getJoueur2().estVivant()) {
        tourDeJeu();
        afficherPartie();
    }
    if(jeu.getJoueur1().estVivant())
        std::cout<<"Victoire du joueur 1!"<<std::endl;
    else if(jeu.getJoueur2().estVivant())
        std::cout<<"Victoire du joueur 2!"<<std::endl;
    else
        std::cout<<"Personne a gagné..."<<std::endl;
}

void AffichageTexte::afficherPartie() {
    std::cout<<std::endl;
    for(int j = 0; j < jeu.getGrille().getDimY(); j++) {
        for(int i = 0; i < jeu.getGrille().getDimX(); i++) {
            if(jeu.getGrille().infoCase(i, j).onPeutMarcher() == false && jeu.getGrille().infoCase(i, j).estDestructible() == false)
                std::cout<<"X";
            else if(jeu.caseEstExplosee(i, j))
                std::cout<<"#";
            else if(i == jeu.getJoueur1().getPositionX() && j == jeu.getJoueur1().getPositionY())
                std::cout<<"1";
            else if(i == jeu.getJoueur2().getPositionX() && j == jeu.getJoueur2().getPositionY())
                std::cout<<"2";
            else if(jeu.caseEstMinee(i, j))
                std::cout<<"B";
            else if(jeu.getGrille().infoCase(i, j).estDestructible() == true)
                std::cout<<"=";
            else if(jeu.getGrille().infoCase(i, j).getBonusType() != BonusType::Rien)
                std::cout<<"S";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void AffichageTexte::tourDeJeu() {
    char movJ1, bombJ1, movJ2, bombJ2;
    std::cout<<"Joueur1 mouvement: ZQSD"<<std::endl;
    std::cin>>movJ1;
    std::cout<<"Joueur1 poser bombe: X"<<std::endl;
    std::cin>>bombJ1;
    std::cout<<"Joueur2 mouvement: IJKL"<<std::endl;
    std::cin>>movJ2;
    std::cout<<"Joueur1 poser bombe: P"<<std::endl;
    std::cin>>bombJ2;
    if(bombJ1 == 'X' || bombJ1 == 'x')
        bombJ1 = 'X';
    if(bombJ2 == 'P' || bombJ1 == 'p')
        bombJ1 = 'X';
    convertirMove('Z', 'Q', 'S', 'D', movJ1);
    convertirMove('I', 'J', 'K', 'L', movJ2);
    std::cout<<movJ1<<" "<<bombJ1<<" "<<movJ2<<" "<<bombJ2<<std::endl;
    for(int i = 0; i < 5; i++)
        jeu.actionsJoueurs(movJ1, bombJ1, movJ2, bombJ2);
    for(int i = 0; i < 20; i++)
        jeu.avancerPartie();
}

void AffichageTexte::convertirMove(char up, char left, char down, char right, char& mov) {
    char diff = 'A'-'a';
    if(mov == up || mov == up-diff)
        mov = 'U';
    if(mov == left || mov == left-diff)
        mov = 'L';
    if(mov == down || mov == down-diff)
        mov = 'D';
    if(mov == right || mov == right-diff)
        mov = 'R';
}