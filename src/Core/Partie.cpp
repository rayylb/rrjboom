#include "Partie.h"
#include <iostream>

Partie::Partie() {
    initPartie(GRILLE_DIMX_MAX, GRILLE_DIMY_MAX);
}

void Partie::initPartie(int grilleX, int grilleY) {
    grille.initGrille(grilleX, grilleY);
    bombes.clear();
    explosions.clear();
    joueur1.spawn(true, 0, 0);
    joueur2.spawn(false, grille.getDimX()-1, grille.getDimY()-1);
}

void Partie::actionsJoueurs(char movJ1, char bombJ1, char movJ2, char bombJ2) {
    int jx, jy;
    BonusType bonus;
    bool caseDevant, caseAvant, caseApres;

    //////////JOUEUR1
    jx = joueur1.getPositionX();
    jy = joueur1.getPositionY();
    bonus = grille.recupererBonus(jx,jy);
    joueur1.appliquerBonus(bonus);
    switch(movJ1) {
        case('U') : caseDevant = jy > 0 && grille.infoCase(jx, jy-1).onPeutMarcher() && (!caseEstMinee(jx, jy-1));
            caseAvant = jy > 0 && grille.infoCase(jx-1, jy-1).onPeutMarcher() && (!caseEstMinee(jx-1, jy-1));
            caseApres = jy > 0 && grille.infoCase(jx+1, jy-1).onPeutMarcher() && (!caseEstMinee(jx+1, jy-1));
            joueur1.moveU(caseDevant, caseAvant, caseApres); break;
        case('L') : caseDevant = jx > 0 && grille.infoCase(jx-1, jy).onPeutMarcher() && (!caseEstMinee(jx-1, jy));
            caseAvant = jx > 0 && grille.infoCase(jx-1, jy-1).onPeutMarcher() && (!caseEstMinee(jx-1, jy-1));
            caseApres = jx > 0 && grille.infoCase(jx-1, jy+1).onPeutMarcher() && (!caseEstMinee(jx-1, jy+1));
            joueur1.moveL(caseDevant, caseAvant, caseApres); break;
        case('D') : caseDevant = jy < grille.getDimY()-1 && grille.infoCase(jx, jy+1).onPeutMarcher() && (!caseEstMinee(jx, jy+1));
            caseAvant = jy < grille.getDimY()-1 && grille.infoCase(jx-1, jy+1).onPeutMarcher() && (!caseEstMinee(jx-1, jy+1));
            caseApres = jy < grille.getDimY()-1 && grille.infoCase(jx+1, jy+1).onPeutMarcher() && (!caseEstMinee(jx+1, jy+1));
            joueur1.moveD(caseDevant, caseAvant, caseApres); break;
        case('R') : caseDevant = jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy).onPeutMarcher() && (!caseEstMinee(jx+1, jy));
            caseAvant = jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy-1).onPeutMarcher() && (!caseEstMinee(jx+1, jy-1));
            caseApres = jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy+1).onPeutMarcher() && (!caseEstMinee(jx+1, jy+1));
            joueur1.moveR(caseDevant, caseAvant, caseApres); break;
        default: break;
    }
    jx = joueur1.getPositionX();
    jy = joueur1.getPositionY();
    if (bombJ1 == 'X' && joueur1.getNbBombes() < joueur1.getNbBombesMax() && (!caseEstMinee(jx, jy))) {
        Bombe newbombe(jx, jy, joueur1.getPorteeBombe(), 1);
        bombes.push_back(newbombe);
        joueur1.poserBombe();
    }

    //////////JOUEUR2
    jx = joueur2.getPositionX();
    jy = joueur2.getPositionY();
    bonus = grille.recupererBonus(jx,jy);
    joueur2.appliquerBonus(bonus);
    switch(movJ2) {
        case('U') : caseDevant = jy > 0 && grille.infoCase(jx, jy-1).onPeutMarcher() && (!caseEstMinee(jx, jy-1));
            joueur2.moveU(caseDevant, caseDevant, caseDevant); break;
        case('L') : caseDevant = jx > 0 && grille.infoCase(jx-1, jy).onPeutMarcher() && (!caseEstMinee(jx-1, jy));
            joueur2.moveL(caseDevant, caseDevant, caseDevant); break;
        case('D') : caseDevant = jy < grille.getDimY()-1 && grille.infoCase(jx, jy+1).onPeutMarcher() && (!caseEstMinee(jx, jy+1));
            joueur2.moveD(caseDevant, caseDevant, caseDevant); break;
        case('R') : caseDevant = jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy).onPeutMarcher() && (!caseEstMinee(jx+1, jy));
            caseAvant = jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy-1).onPeutMarcher() && (!caseEstMinee(jx+1, jy-1));
            caseApres = jx < grille.getDimX()-1 && grille.infoCase(jx+1, jy+1).onPeutMarcher() && (!caseEstMinee(jx+1, jy+1));
            joueur2.moveR(caseDevant, caseAvant, caseApres); break;
        default: break;
    }
    jx = joueur2.getPositionX();
    jy = joueur2.getPositionY();
    if (bombJ2 == 'X' && joueur2.getNbBombes() < joueur2.getNbBombesMax() && (!caseEstMinee(jx, jy))) {
        Bombe newbombe(jx, jy, joueur2.getPorteeBombe(), 2);
        bombes.push_back(newbombe);
        joueur2.poserBombe();
    }
}

void Partie::avancerPartie() {
    for (int i = bombes.size()-1; i >= 0; i--) {
        bombes.at(i).avancerTemps();
        if (bombes.at(i).estExplosee()) {
            creerExplosions(bombes.at(i)); ///EXPLOSIONS DES BOMBES
            bombes.erase(bombes.begin()+i);
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
    if(source.getJoueur() == 1)
        joueur1.recupererBombe();
    else
        joueur2.recupererBombe();
    int bx = source.getPosX();
    int by = source.getPosY();
    int brange = source.getRange();
    int i, j;
    int step;
    pushExplosion(bx, by); //EXPLOSION CENTRE
    j = by-1;
    while (j >= by-brange && j >= 0) { ///EXPLOSION HAUT
        pushExplosion(bx, j);
        grille.detruireCase(bx, j);
        if((!grille.infoCase(bx, j).onPeutMarcher()) || grille.infoCase(bx, j).aBonus())
            step = -1;
        else
            step = j - 1;
        grille.detruireCase(bx, j);
        j = step;
    }
    i = bx-1;
    while (i >= bx-brange && i >= 0) { ///EXPLOSION GAUCHE
        pushExplosion(i, by);
        if((!grille.infoCase(i, by).onPeutMarcher()) || grille.infoCase(i, by).aBonus())
            step = -1;
        else
            step = i - 1;
        grille.detruireCase(i, by);
        i = step;
    }
    i = bx+1;
    while (i <= bx+brange && i < grille.getDimX()) { ///EXPLOSION DROITE
        pushExplosion(i, by);
        if((!grille.infoCase(i, by).onPeutMarcher()) || grille.infoCase(i, by).aBonus())
            step = grille.getDimX();
        else
            step = i + 1;
        grille.detruireCase(i, by);
        i = step;
    }
    j = by+1;
    while (j <= by+brange && j < grille.getDimY()) { ///EXPLOSION BAS
        pushExplosion(bx, j);
        if((!grille.infoCase(bx, j).onPeutMarcher()) || grille.infoCase(bx, j).aBonus())
            step = grille.getDimY();
        else
            step = j + 1;
        grille.detruireCase(bx, j);
        j = step;
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

void Partie::pushExplosion(int posX, int posY) {
    Explosion newexp(posX, posY);
    explosions.push_back(newexp);
    for (int i=0; i<bombes.size(); i++)
        if (bombes.at(i).getPosX() == posX && bombes.at(i).getPosY() == posY && (!bombes.at(i).estExplosee())) { ///EXPLOSIONS EN CHAINE
            bombes.at(i).exploser();
        }
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