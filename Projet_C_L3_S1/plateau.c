#include "plateau.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    SOURIS,
    LION,
    ELEPHANT,
    VIDE
} typeCase;

typedef enum {
    NOIR,
    BLANC
} couleurPiece;

struct Case {
    typeCase type;
    couleurPiece couleur;
    int pointEau;
    int effraye;
};

struct plateau {
    int hauteur;
    int largeur;
    struct Case ** contenu;
};
  
  
struct plateau * allouerPlateau(int largeur, int hauteur) {
    struct plateau * plat;
    struct Case case1;
    int i;

    plat = malloc(sizeof(struct plateau));
    plat -> largeur = largeur;
    plat -> hauteur = hauteur;

    plat -> contenu = malloc(hauteur * sizeof(int * ));

    for (i = 0; i < hauteur; i++)
        plat -> contenu[i] = malloc(largeur * sizeof(case1));

    return plat;
}
  
struct plateau * initialiserTaille() {
    struct plateau * plat;
    int largeur, hauteur;

    do {
        printf("Choisissez une largeur paire et superieure ou egale a  8 pour le plateau : ");
        scanf("%d", & largeur);
        printf("\n");
        if (largeur % 2 != 0)
            printf("ERREUR : la largeur doit etre paire ! \n");
        if (largeur < 8)
            printf("ERREUR : la largeur doit superieure ou egale a  8 ! \n");
    } while (largeur % 2 != 0 && largeur < 8);

    do {
        printf("Choisissez une hauteur paire et superieure ou egale a  8 pour le plateau : ");
        scanf("%d", & hauteur);
        printf("\n");
        if (hauteur % 2 != 0)
            printf("ERREUR : la hauteur doit etre paire ! \n");
        if (hauteur < 8)
            printf("ERREUR : la hauteur doit superieure ou egale a  8 ! \n");
    } while (hauteur % 2 != 0 && hauteur < 8);

    plat = allouerPlateau(largeur, hauteur);

    return plat;
}
  
struct plateau * initialiserPlateau() { 
    struct plateau * plat = initialiserTaille();

    for (int i = 0; i < plat -> hauteur; i++) {
        for (int j = 0; j < plat -> largeur; j++) {
            plat -> contenu[i][j].type = VIDE;
            plat -> contenu[i][j].effraye = 0;
              
            if (((i == (plat -> hauteur / 2) - 2) && (j == (plat -> largeur / 2) - 2)) || 
                ((i == (plat -> hauteur / 2) - 2) && (j == (plat -> largeur / 2) + 1)) || 
                ((i == (plat -> hauteur / 2) + 1) && (j == (plat -> largeur / 2) - 2)) || 
                ((i == (plat -> hauteur / 2) + 1) && (j == (plat -> largeur / 2) + 1)))
                plat -> contenu[i][j].pointEau = 1;
            else
                plat -> contenu[i][j].pointEau = 0;
        }
    }
    return plat;
}
  
  
  
struct plateau * initialiserCasePlateau(struct plateau *plat, typeCase ty, couleurPiece co, int hauteurDepart, int largeurDepart) {
    plat -> contenu[hauteurDepart][largeurDepart].type = ty;
    plat -> contenu[hauteurDepart][largeurDepart].couleur = co;
    return plat;
}
  
struct plateau * initialiserPieces(struct plateau * plat) {  
    // souris noire 1
    initialiserCasePlateau(plat, SOURIS, NOIR, 1, (plat -> largeur / 2) - 1);

    // souris noire 2
    initialiserCasePlateau(plat, SOURIS, NOIR, 1, (plat -> largeur / 2));

    // lion noir 1
    initialiserCasePlateau(plat, LION, NOIR, 0, (plat -> largeur / 2) - 2);

    // lion noir 2
    initialiserCasePlateau(plat, LION, NOIR, 0, (plat -> largeur / 2) + 1);

    // elephant noir 1
    initialiserCasePlateau(plat, ELEPHANT, NOIR, 0, (plat -> largeur / 2) - 1);

    // elephant noir 2
    initialiserCasePlateau(plat, ELEPHANT, NOIR, 0, (plat -> largeur / 2));

    // souris blanche 1
    initialiserCasePlateau(plat, SOURIS, BLANC, plat -> hauteur - 2, (plat -> largeur / 2) - 1);

    // souris blanche 2
    initialiserCasePlateau(plat, SOURIS, BLANC, plat -> hauteur - 2, (plat -> largeur / 2));

    // lion blanc 1
    initialiserCasePlateau(plat, LION, BLANC, plat -> hauteur - 1, (plat -> largeur / 2) - 2);

    // lion blanc 2
    initialiserCasePlateau(plat, LION, BLANC, plat -> hauteur - 1, (plat -> largeur / 2) + 1);

    // elephant blanc 1
    initialiserCasePlateau(plat, ELEPHANT, BLANC, plat -> hauteur - 1, (plat -> largeur / 2) - 1);

    // elephant blanc 2
    initialiserCasePlateau(plat, ELEPHANT, BLANC, plat -> hauteur - 1, (plat -> largeur / 2));

    return plat;
}
  
void libererPlateau(struct plateau * plat) {
    int i;
    for (i = 0; i < plat -> hauteur; i++)
        free(plat -> contenu[i]);
    free(plat -> contenu[i]);
    free(plat);
}
