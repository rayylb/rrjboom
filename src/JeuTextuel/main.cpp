#include <time.h>
#include <stdlib.h>

#include "Affichage.h"

int main() {
    srand(time(NULL));
    Affichage jeuText;
    jeuText.boucleJeu();
    return 0;
}