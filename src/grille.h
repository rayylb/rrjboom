#include <vector>
#include "bloc.h"
#ifndef _GRILLE_H
#define _GRILLE_H

class Grille {
private:
    int largeur; // Largeur de la grille
    int hauteur; // Hauteur de la grille
    std::vector<std::vector<Bloc>> grille; // Grille représentant les blocs du jeu

public:
    Grille(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
        // Initialisation de la grille avec des blocs vides
        grille.resize(hauteur, std::vector<Bloc>(largeur, Bloc(false, false)));
    }

    // Méthodes pour accéder et modifier les blocs de la grille
    Bloc& getBloc(int x, int y) { return grille[y][x]; }
    const Bloc& getBloc(int x, int y) const { return grille[y][x]; }

    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }
};

#endif