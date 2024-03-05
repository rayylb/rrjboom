#ifndef _JOUEUR_H
#define _JOUEUR_H

class Joueur {
private:
    bool numero; ///<  Numéro du joueur (True pour le joueur 1, False pour le joueur 2)
    int x; ///<  Position en X du joueur sur la grille
    int y; ///<  Position en Y du joueur sur la grille
    int nbBombesMax; ///<  Nombre maximum de bombes que le joueur peut poser
    int porteeBombe; ///<  Portée de l'explosion de la bombe du joueur
    
public:
    Joueur(bool num, int xg, int yg);
    int getPositionX() const;
    int getPositionY() const;
    int getNbBombesMax() const;
    int getPorteeBombe() const;
    void deplacementD();
    void deplacementG();
    void deplacementH();
    void deplacementB();
};

#endif