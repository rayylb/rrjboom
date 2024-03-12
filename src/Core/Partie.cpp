#include "Partie.h"
#include <iostream>

void Partie::initPartie() {
    grille.initGrille();
    joueur1.spawn(true, 0, 0);
    joueur2.spawn(false, grille.getDimX()-1, grille.getDimY()-1);
    afficherTerminal();
    while(joueur1.estVivant() && joueur2.estVivant()) { ///BOUCLE DE JEU
        actionsJoueursTerminal();
        avancerPartie();
        afficherTerminal();
    }
    if(joueur1.estVivant())
        std::cout<<"Victoire du joueur 1!"<<std::endl;
    else if(joueur2.estVivant())
        std::cout<<"Victoire du joueur 2!"<<std::endl;
    else
        std::cout<<"Personne a gagné..."<<std::endl;
}

Grille& Partie::getGrille() {
    return grille;
}

Joueur& Partie::getJoueur1() {
    return joueur1;
}

Joueur& Partie::getJoueur2() {
    return joueur2;
}

std::vector<Bombe>& Partie::getBombes() {
    return bombes;
}

std::vector<Explosion>& Partie::getExplosions() {
    return explosions;
}

void Partie::actionsJoueursTerminal() {
    char touche;
    int jx, jy;

    //////////JOUEUR1
    std::cout<<"Joueur1 mouvement: ZQSD"<<std::endl;
    std::cin>>touche;
    jx = joueur1.getPositionX();
    jy = joueur1.getPositionY();
    switch(touche) {
        case('Z') : {
            if(jy > 0 && grille.infoCase(jx, jy-1).onPeutMarcher() && (!caseEstMinee(jx, jy-1)))
                {joueur1.deplacementH(); jy--;} break;}
        case('Q') : {
            if(jx > 0 && grille.infoCase(jx-1, jy).onPeutMarcher() && (!caseEstMinee(jx-1, jy)))
                {joueur1.deplacementG(); jx--;} break;}
        case('S') : {
            if(jy < grille.getDimY()-1 && grille.infoCase(jx, jy+1).onPeutMarcher() && (!caseEstMinee(jx, jy+1)))
                {joueur1.deplacementB(); jy++;} break;}
        case('D') : {
            if(jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy).onPeutMarcher() && (!caseEstMinee(jx+1, jy)))
                {joueur1.deplacementD(); jx++;} break;}
        default: break;
    }
    std::cout<<"Joueur1 poser bombe: X"<<std::endl;
    std::cin>>touche;
    if (touche == 'X' && joueur1.getNbBombes() < joueur1.getNbBombesMax()) {
        Bombe newbombe(jx, jy, joueur1.getPorteeBombe());
        bombes.push_back(newbombe);
        joueur1.poserBombe();
    }

    //////////JOUEUR2
    std::cout<<"Joueur2 mouvement: IJKL"<<std::endl;
    std::cin>>touche;
    jx = joueur2.getPositionX();
    jy = joueur2.getPositionY();
    switch(touche) {
        case('I') : {
            if(jy > 0 && grille.infoCase(jx, jy-1).onPeutMarcher() && (!caseEstMinee(jx, jy-1)))
                {joueur2.deplacementH(); jy--;} break;}
        case('J') : {
            if(jx > 0 && grille.infoCase(jx-1, jy).onPeutMarcher() && (!caseEstMinee(jx-1, jy)))
                {joueur2.deplacementG(); jx--;} break;}
        case('K') : {
            if(jy < grille.getDimY()-1 && grille.infoCase(jx, jy+1).onPeutMarcher() && (!caseEstMinee(jx, jy+1)))
                {joueur2.deplacementB(); jy++;} break;}
        case('L') : {
            if(jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy).onPeutMarcher() && (!caseEstMinee(jx+1, jy)))
                {joueur2.deplacementD(); jx++;} break;}
        default: break;
    }
    std::cout<<"Joueur1 poser bombe: P"<<std::endl;
    std::cin>>touche;
    if (touche == 'P' && joueur2.getNbBombes() < joueur2.getNbBombesMax()) {
        Bombe newbombe(jx, jy, joueur2.getPorteeBombe());
        bombes.push_back(newbombe);
        joueur2.poserBombe();
    }
}

void Partie::avancerPartie() {
    if (!bombes.empty()) { ///AVANCE TIMER BOMBES
        for (int i = bombes.size()-1; i >= 0; i--) {
            bombes.at(i).avancerTemps();
            if (bombes.at(i).estExplosee()) {
                creerExplosions(bombes.at(i)); ///EXPLOSIONS DES BOMBES
                bombes.erase(bombes.begin()+i);
            }
        }
    }
    if (!explosions.empty()) { ///AVANCE TIMER EXPLOSIONS
        for (int i = explosions.size()-1; i >= 0; i--) {
            if (explosions.at(i).getPosX() == joueur1.getPositionX() && explosions.at(i).getPosY() == joueur1.getPositionY()) ///CHECK MORT J1
                joueur1.exploser();
            if (explosions.at(i).getPosX() == joueur2.getPositionX() && explosions.at(i).getPosY() == joueur2.getPositionY()) ///CHECK MORT J2
                joueur2.exploser();
            explosions.at(i).avancerTemps();
            if (!explosions.at(i).estActif()) {
                explosions.erase(explosions.begin()+i); ///DISPARITION DES EXPLOSIONS
            }
        }
    }
}

void Partie::afficherTerminal() {
    std::cout<<std::endl;
    for(int j = 0; j < grille.getDimY(); j++) {
        for(int i = 0; i < grille.getDimX(); i++) { ///AFFICHAGE DES CASES AVEC ORDRE DE PRIORITE
            if(grille.infoCase(i, j).onPeutMarcher() == false && grille.infoCase(i, j).estDestructible() == false)
                std::cout<<"X";
            else if(caseEstExplosee(i, j))
                std::cout<<"#";
            else if(i == joueur1.getPositionX() && j == joueur1.getPositionY())
                std::cout<<"1";
            else if(i == joueur2.getPositionX() && j == joueur2.getPositionY())
                std::cout<<"2";
            else if(caseEstMinee(i, j))
                std::cout<<"B";
            else if(grille.infoCase(i, j).estDestructible() == true)
                std::cout<<"=";
            else if(grille.infoCase(i, j).aBonus() == true)
                std::cout<<"S";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

void Partie::creerExplosions(Bombe source) {
    int bx = source.getPosX();
    int by = source.getPosY();
    int brange = source.getRange();
    int i, j;
    Explosion newexp(bx, by); //EXPLOSION CENTRE
    explosions.push_back(newexp);
    i = bx+1;
    while (i <= bx+brange && i < grille.getDimX()) { ///EXPLOSION BAS
        Explosion newexp(i, by);
        explosions.push_back(newexp);
        grille.detruireCase(i, by);
        if((!grille.infoCase(i, by).onPeutMarcher()) || grille.infoCase(i, by).aBonus())
            i = grille.getDimX();
        else
            i++;
    }
    i = bx-1;
    while (i >= bx-brange && i >= 0) { ///EXPLOSION HAUT
        Explosion newexp(i, by);
        explosions.push_back(newexp);
        grille.detruireCase(i, by);
        if((!grille.infoCase(i, by).onPeutMarcher()) || grille.infoCase(i, by).aBonus())
            i = -1;
        else
            i--;
    }
    j = by+1;
    while (j <= by+brange && j < grille.getDimY()) { ///EXPLOSION DROITE
        Explosion newexp(bx, j);
        explosions.push_back(newexp);
        grille.detruireCase(bx, j);
        if((!grille.infoCase(bx, j).onPeutMarcher()) || grille.infoCase(bx, j).aBonus())
            j = grille.getDimY();
        else
            j++;
    }
    j = by-1;
    while (j >= by-brange && j >= 0) { ///EXPLOSION GAUCHE
        Explosion newexp(bx, j);
        explosions.push_back(newexp);
        grille.detruireCase(bx, j);
        if((!grille.infoCase(bx, j).onPeutMarcher()) || grille.infoCase(bx, j).aBonus())
            j = -1;
        else
            j--;
    }
}

bool Partie::caseEstExplosee(int posX, int posY) {
    if (!explosions.empty()) {
        for (int i=0; i<explosions.size(); i++) {
            if (explosions.at(i).getPosX() == posX && explosions.at(i).getPosY() == posY)
                return true;
        }
    }
    return false;
}

bool Partie::caseEstMinee(int posX, int posY) {
    if (!bombes.empty()) {
        for (int i=0; i<bombes.size(); i++) {
            if (bombes.at(i).getPosX() == posX && bombes.at(i).getPosY() == posY)
                return true;
        }
    }
    return false;
}