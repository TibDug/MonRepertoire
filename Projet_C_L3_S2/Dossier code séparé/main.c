#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(NULL));
    if (argc <= 1 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-h") == 0){
        aide();
    }
    else
        ligneCommande(argc, argv);
    return 0;
}