#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Bloc.h"
#include "Grille.h"

int main() {
    srand(time(NULL));
    Grille test;
    test.initGrille();
    test.affichTerminal();
    return 0;
}