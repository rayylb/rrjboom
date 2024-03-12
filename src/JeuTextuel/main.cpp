#include <time.h>
#include <stdlib.h>

#include "AffichageTexte.h"

int main() {
    srand(time(NULL));
    AffichageTexte jeuText;
    jeuText.boucleJeu();
    return 0;
}