#include "Partie.h"
#include <iostream>

void Partie::initJeu(Grille* grille_jeu) {
    grille = grille_jeu;
}

void Partie::nouvellePartie() {
    grille->initGrille();
    joueur1.spawn(true, 0, 0);
    joueur2.spawn(false, grille->getDimX()-1, grille->getDimY()-1);
    afficherTerminal();
    while(joueur1.estVivant() && joueur2.estVivant()) {
        actionsJoueursTerminal();
        avancerPartie();
        afficherTerminal();
    }
}

void Partie::actionsJoueursTerminal() {
    char touche;
    int jx, jy;

    ///////JOUEUR1
    std::cout<<"Joueur1 mouvement: ZQSD"<<std::endl;
    std::cin>>touche;
    jx = joueur1.getPositionX();
    jy = joueur1.getPositionY();
    switch(touche) {
        case('Z') : {
            if(jx > 0 && grille->infoCase(jx, jy-1).onPeutMarcher()) joueur1.deplacementH(); break;}
        case('Q') : {
            if(jy > 0 && grille->infoCase(jx-1, jy).onPeutMarcher()) joueur1.deplacementG(); break;}
        case('S') : {
            if(jx < grille->getDimX()-1 && grille->infoCase(jx, jy+1).onPeutMarcher()) joueur1.deplacementB(); break;}
        case('D') : {
            if(jy < grille->getDimY()-1 && grille->infoCase(jx+1, jy).onPeutMarcher()) joueur1.deplacementD(); break;}
    }
    std::cout<<"Joueur1 poser bombe: X"<<std::endl;
    std::cin>>touche;
    if (touche == 'X' && joueur1.getNbBombes() < joueur1.getNbBombesMax()) {
        Bombe newbombe(jx, jy, joueur1.getPorteeBombe());
        bombes.push(newbombe);
        joueur1.poserBombe();
    }

    ///////JOUEUR2
    std::cout<<"Joueur2 mouvement: IJKL"<<std::endl;
    std::cin>>touche;
    jx = joueur2.getPositionX();
    jy = joueur2.getPositionY();
    switch(touche) {
        case('I') : {
            if(jx > 0 && grille->infoCase(jx, jy-1).onPeutMarcher()) joueur2.deplacementH(); break;}
        case('J') : {
            if(jy > 0 && grille->infoCase(jx-1, jy).onPeutMarcher()) joueur2.deplacementG(); break;}
        case('K') : {
            if(jx < grille->getDimX()-1 && grille->infoCase(jx, jy+1).onPeutMarcher()) joueur2.deplacementB(); break;}
        case('L') : {
            if(jy < grille->getDimY()-1 && grille->infoCase(jx+1, jy).onPeutMarcher()) joueur2.deplacementD(); break;}
    }
    std::cout<<"Joueur1 poser bombe: P"<<std::endl;
    std::cin>>touche;
    if (touche == 'P' && joueur2.getNbBombes() < joueur2.getNbBombesMax()) {
        Bombe newbombe(jx, jy, joueur2.getPorteeBombe());
        bombes.push(newbombe);
        joueur2.poserBombe();
    }
}