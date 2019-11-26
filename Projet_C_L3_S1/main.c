#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
        
int main() {
    srand(time(NULL));
    affichageRegles();
    struct plateau * plat = initialiserPlateau();
    initialiserPieces(plat);
    partie(plat);
    libererPlateau(plat);
    return 0;
}