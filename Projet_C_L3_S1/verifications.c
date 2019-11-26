#include "verifications.h"
#include <stdio.h>
#include <stdlib.h>

int dansPlateau(struct plateau * plat, int hauteurArr, int largeurArr) {
    if ((hauteurArr <= plat -> hauteur) && (largeurArr <= plat -> largeur) && (hauteurArr >= 0) && (largeurArr >= 0))
        return 1;
    return 0;
}
int caseVide(struct plateau * plat, int hauteur, int largeur) {
    if (plat -> contenu[hauteur][largeur].type == VIDE)
        return 1;
    return 0;
}
int memeCouleur(struct plateau * plat, struct joueur j, int hauteur, int largeur) {
    if (j.couleur == plat -> contenu[hauteur][largeur].couleur)
        return 1;
    return 0;
}
int deplacementLineaire(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
    if ((hauteurDep == hauteurArr && largeurDep != largeurArr) || (hauteurDep != hauteurArr && largeurDep == largeurArr))
        return 1;
    return 0;
}
int deplacementDiagonal(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
    if (fabs(hauteurDep - hauteurArr) == fabs(largeurDep - largeurArr))
        return 1;
    return 0;
}

int estEffrayee(struct plateau * plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
    for (int i = hauteurArr - 1; i <= hauteurArr + 1; i++) {
        for (int j = largeurArr - 1; j <= largeurArr + 1; j++) {
            if ( i >= 0 && i < plat -> hauteur && j >= 0 && j < plat -> largeur) {
                if (plat -> contenu[hauteurDep][largeurDep].couleur != plat -> contenu[i][j].couleur){
                    if (((plat -> contenu[hauteurDep][largeurDep].type == ELEPHANT) && (plat -> contenu[i][j].type == SOURIS)) ||
                        ((plat -> contenu[hauteurDep][largeurDep].type == SOURIS) && (plat -> contenu[i][j].type == LION)) ||
                        ((plat -> contenu[hauteurDep][largeurDep].type == LION) && (plat -> contenu[i][j].type == ELEPHANT))){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
  

  

  
int aDeplacer(struct plateau * plat, struct joueur joue, int hauteurDep, int largeurDep) {
    if (plat -> contenu[hauteurDep][largeurDep].effraye == 1)
        return 1;
    for (int i = 0; i < plat -> hauteur; i++) {
        for (int j = 0; j < plat -> largeur; j++) {
            if ((plat -> contenu[i][j].effraye == 1) && (plat -> contenu[i][j].couleur == joue.couleur))
                return 0;
        }
    }
    return 1;
}
  
int deplacementPossible(struct plateau * plat, struct joueur j, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
    if (dansPlateau(plat, hauteurDep, largeurDep)) {
        if (dansPlateau(plat, hauteurArr, largeurArr)) {
            if (!caseVide(plat, hauteurDep, largeurDep)) {
                if (caseVide(plat, hauteurArr, largeurArr)) {
                    if (memeCouleur(plat, j, hauteurDep, largeurDep)) {
                        if ((plat -> contenu[hauteurDep][largeurDep].type == SOURIS && deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                            (plat -> contenu[hauteurDep][largeurDep].type == LION && deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                            (plat -> contenu[hauteurDep][largeurDep].type == ELEPHANT && (deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr) ||
                                                                                          deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)))) {
                            if (estEffrayee(plat, hauteurDep, largeurDep, hauteurArr, largeurArr)) {
                                if (aDeplacer(plat, j, hauteurDep, largeurDep)) {
                                    return 1;
                                }
                                printf("ERREUR : Vous devez bouger une piece effrayee. \n");
                                return 0;
                            }
                            printf("ERREUR : La piece est effrayee par une autre piece. \n");
                            return 0;
                        }
                        printf("ERREUR : Le deplacement ne correspondont pas au type de la piece. \n");
                        return 0;
                    }
                    printf("ERREUR : Cette piece ne vous appartient pas. \n");
                    return 0;
                }
                printf("ERREUR : La case d'arrivee n'est pas disponible. \n");
                return 0;
            }
            printf("ERREUR : La case de depart ne correspond pas à une piece. \n");
            return 0;
        }
        printf("ERREUR : La position d'arrivee n'est pas dans les dimensions du plateau. \n");
        return 0;
    }
    printf("ERREUR : La position de départ n'est pas dans les dimensions du plateau. \n");
    return 0;
}
  
int deplacementPossibleSansTexte(struct plateau * plat, struct joueur j, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
    if (dansPlateau(plat, hauteurDep, largeurDep)) {
        if (dansPlateau(plat, hauteurArr, largeurArr)) {
            if (!caseVide(plat, hauteurDep, largeurDep)) {
                if (caseVide(plat, hauteurArr, largeurArr)) {
                    if (memeCouleur(plat, j, hauteurDep, largeurDep)) {
                        if ((plat -> contenu[hauteurDep][largeurDep].type == SOURIS && deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                            (plat -> contenu[hauteurDep][largeurDep].type == LION && deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                            (plat -> contenu[hauteurDep][largeurDep].type == ELEPHANT && (deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr) ||
                                                                                          deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)))) {
                            if (estEffrayee(plat, hauteurDep, largeurDep, hauteurArr, largeurArr)) {
                                if (aDeplacer(plat, j, hauteurDep, largeurDep)) {
                                    return 1;
                                }
                                return 0;
                            }
                            return 0;
                        }
                        return 0;
                    }
                    return 0;
                }
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
  
