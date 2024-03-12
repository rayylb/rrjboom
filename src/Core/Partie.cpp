#include "Partie.h"
#include <iostream>

void Partie::initPartie() {
    grille.initGrille();
    joueur1.spawn(true, 0, 0);
    joueur2.spawn(false, grille.getDimX()-1, grille.getDimY()-1);
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

void Partie::actionsJoueurs(char movJ1, char bombJ1, char movJ2, char bombJ2) {
    int jx, jy;

    //////////JOUEUR1
    jx = joueur1.getPositionX();
    jy = joueur1.getPositionY();
    switch(movJ1) {
        case('U') : {
            if(jy > 0 && grille.infoCase(jx, jy-1).onPeutMarcher() && (!caseEstMinee(jx, jy-1)))
                {joueur1.deplacementH(); jy--;} break;}
        case('L') : {
            if(jx > 0 && grille.infoCase(jx-1, jy).onPeutMarcher() && (!caseEstMinee(jx-1, jy)))
                {joueur1.deplacementG(); jx--;} break;}
        case('D') : {
            if(jy < grille.getDimY()-1 && grille.infoCase(jx, jy+1).onPeutMarcher() && (!caseEstMinee(jx, jy+1)))
                {joueur1.deplacementB(); jy++;} break;}
        case('R') : {
            if(jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy).onPeutMarcher() && (!caseEstMinee(jx+1, jy)))
                {joueur1.deplacementD(); jx++;} break;}
        default: break;
    }
    if (bombJ1 == 'X' && joueur1.getNbBombes() < joueur1.getNbBombesMax()) {
        Bombe newbombe(jx, jy, joueur1.getPorteeBombe());
        bombes.push_back(newbombe);
        joueur1.poserBombe();
    }

    //////////JOUEUR2
    jx = joueur2.getPositionX();
    jy = joueur2.getPositionY();
    switch(movJ2) {
        case('U') : {
            if(jy > 0 && grille.infoCase(jx, jy-1).onPeutMarcher() && (!caseEstMinee(jx, jy-1)))
                {joueur2.deplacementH(); jy--;} break;}
        case('L') : {
            if(jx > 0 && grille.infoCase(jx-1, jy).onPeutMarcher() && (!caseEstMinee(jx-1, jy)))
                {joueur2.deplacementG(); jx--;} break;}
        case('D') : {
            if(jy < grille.getDimY()-1 && grille.infoCase(jx, jy+1).onPeutMarcher() && (!caseEstMinee(jx, jy+1)))
                {joueur2.deplacementB(); jy++;} break;}
        case('R') : {
            if(jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy).onPeutMarcher() && (!caseEstMinee(jx+1, jy)))
                {joueur2.deplacementD(); jx++;} break;}
        default: break;
    }
    if (bombJ2 == 'X' && joueur2.getNbBombes() < joueur2.getNbBombesMax()) {
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