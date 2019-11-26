#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum {SOURIS, LION, ELEPHANT, VIDE} typeCase;

typedef enum {NOIR, BLANC} couleurPiece;

typedef enum {S, L, E, s, l, e} caracterePiece;

struct position {
    int x;
    int y;
};

struct Case {
    typeCase type;
    couleurPiece couleur;
    caracterePiece caractere;
    int pointEau;
    int effraye;
};

struct plateau {
    int hauteur;
    int largeur;
    struct Case **contenu;
}

struct plateau initialiserCasePlateau(struct plateau plat, typeCase ty, couleurPiece co, caracterePiece cp, int hauteurDepart, int largeurDepart){
   plat->contenu[hauteurDepart][largeurDepart].type = ty;
   plat->contenu[hauteurDepart][largeurDepart].couleur = co;
   plat->contenu[hauteurDepart][largeurDepart].caractere = cp;
   
   return plat;
}

struct plateau initialiserPieces(struct plateau plat) {
    // souris noire 1
    initialiserCasePlateau(plat, SOURIS, NOIR, S, 1, (plat->largeur / 2));
    
    // souris noire 2
    initialiserCasePlateau(plat, SOURIS, NOIR, S, 1, (plat->largeur / 2) + 1);
    
    // lion noir 1
    initialiserCasePlateau(plat, LION, NOIR, L, 0, (plat->largeur / 2) - 1);
    
    // lion noir 2
    initialiserCasePlateau(plat, LION, NOIR, L, 0, (plat->largeur / 2) + 2);
    
    // elephant noir 1
    initialiserCasePlateau(plat, ELEPHANT, NOIR, E, 0, (plat->largeur / 2));
    
    // elephant noir 2
    initialiserCasePlateau(plat, ELEPHANT, NOIR, E, 0, (plat->largeur / 2) + 1);
    
    
    // souris blanche 1
    initialiserCasePlateau(plat, SOURIS, BLANC, S, plat->hauteur - 2, (plat->largeur / 2));
    
    // souris blanche 2
    initialiserCasePlateau(plat, SOURIS, BLANC, S, plat->hauteur - 2, (plat->largeur / 2) + 1);
    
    // lion blanc 1
    initialiserCasePlateau(plat, LION, BLANC, L, plat->hauteur -  1, (plat->largeur / 2) - 1);
    
    // lion blanc 2
    initialiserCasePlateau(plat, LION, BLANC, L, plat->hauteur - 1, (plat->largeur / 2) + 2);
    
    // elephant blanc 1
    initialiserCasePlateau(plat, ELEPHANT, BLANC, E, plat->hauteur - 1, (plat->largeur / 2));
    
    // elephant blanc 2
    initialiserCasePlateau(plat, ELEPHANT, BLANC, E, plat->hauteur - 1, (plat->largeur / 2) + 1);
}

struct plateau *allouerPlateau(int largeur, int hauteur) {
    struct plateau *plat;
    int i;

    plat = malloc (sizeof(struct plateau));
    plat->largeur = largeur;
    plat->hauteur = hauteur;
    
    plat->contenu = malloc(hauteur * sizeof(int *));

    for (i = 0; i < hauteur; i++)
	plat->contenu[i] = malloc(largeur * sizeof(int));

    return plat;
}

struct plateau *initialiserTaille() {
    struct plateau *plat;
    int largeur, hauteur;
	
    do {
	printf("Choisissez une largeur paire et supérieure ou égale à 8 pour le plateau : "); 
	scanf("%d", &largeur);
	printf("\n");
	if (largeur % 2 != 0)
	    printf("ERREUR : la largeur doit être paire ! \n");
	if (largeur < 8)
	    printf("ERREUR : la largeur doit être supérieure ou égale à 8 ! \n");
    } while(largeur % 2 != 0 && largeur < 8);

    do {
	printf("Choisissez une hauteur paire et supérieure ou égale à 8 pour le plateau : "); 
	scanf("%d", &hauteur);
	printf("\n");
	if (hauteur % 2 != 0)
	    printf("ERREUR : la hauteur doit être paire ! \n");
	if (hauteur < 8)
	    printf("ERREUR : la hauteur doit être supérieure ou égale à 8 ! \n");
    } while(hauteur % 2 != 0 && hauteur < 8);

    plat = allouerPlateau(largeur, hauteur);

    return plat;
}

struct plateau *initialiserPlateau() {
    struct plateau *plat = initialiserTaille();
    
    for(int i = 0; i < plat->hauteur; i++) {
	     for(int j = 0; j < plat->largeur; j++) {
	        plat->contenu[i][j].type = VIDE;
	        plat->contenu[i][j].couleur = NULL;
	        plat->contenu[i][j].caractere = NULL;
	        plat->contenu[i][j].effraye = 0;
	        if(((i == hauteur / 2 - 1) && (j== largeur / 2) - 1)) || ((i == hauteur / 2 - 1) && (j == largeur / 2 + 2)) || ((i == (hauteur / 2 + 2) && (j == largeur / 2 - 1)) || ((i == hauteur / 2 + 2) && (j == largeur / 2 + 2)))
	          plat->contenu[i][j].pointEau = 1;
	        else
            plat->contenu[i][j].pointEau = 0;
	        
	     }
    }
}

int estEffraye(struct plateau plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
  for (int i = hauteurArr - 1; i <= hauteurArr + 1; i ++){
    for (int j = largeurArr - 1; j <= largeurArr + 1; j ++){
      if ((plat->contenu[hauteurDep][largeurDep]->typeCase == ELEPHANT && plat->contenu[i][j]->typeCase == SOURIS) || (plat->contenu[hauteurDep][largeurDep]->typeCase == SOURIS && plat->contenu[i][j]->typeCase == LION) || (plat->contenu[hauteurDep][largeurDep]->typeCase == LION && plat->contenu[i][j]->typeCase == ELEPHANT))
        return 1;
    }
  }
}

int effraie(struct plateau plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
  for (int i = hauteurArr - 1; i <= hauteurArr + 1; i ++){
    for (int j = largeurArr - 1; j <= largeurArr + 1; j ++){
      if ((plat->contenu[hauteurDep][largeurDep]->typeCase == SOURIS && plat->contenu[i][j]->typeCase == ELEPHANT) || (plat->contenu[hauteurDep][largeurDep]->typeCase == LION && plat->contenu[i][j]->typeCase == SOURIS) || (plat->contenu[hauteurDep][largeurDep]->typeCase == ELEPHANT && plat->contenu[i][j]->typeCase == LION))
        plat->contenu[i][j]->effraye == 1;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////
// FAIRE FONCTION QUI PERMET DE PARCOURIR LE PLATEAU ET QUI RENVOIT LES PIECES EFFRAYEES //
///////////////////////////////////////////////////////////////////////////////////////////


int caseOccupee(struct plateau plat, int hauteurArr, int largeurArr){
  if (plat->contenu[hauteurArr][largeurArr]->type != VIDE)
    return 1;
  return 0;
}

int verificationEffraiement(struct plateau plat, int x, int y){
  if (estEffraye(plat,x,y)){
    printf("Vous ne pouvez pas poser ce pion, il est effraye ! \n");
    return 1;
  }
  return 0;
}

int dansPlateau(struct plateau plat, int hauteurArr, int largeurArr) {
  if ((hauteurArr <= plat->hauteur) && (largeurArr <= plat->largeur) && (hauteurArr >= 0) && (largeurArr >= 0))
    return 1;
  return 0;
}

int deplacementLineaire(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
  if ((hauteurDep == hauteurArr && largeurDep != largeurArr) || (hauteurDep != hauteurArr && largeurDep == largeurArr))
    return 1;
  return 0;
}

int deplacementDiagonal(int hauteurDep, int largeurDep, in hauteurArr, int largeurArr){
  if ((fabs(hauteurDep - hauteurArr) == fabs(largeurDep - largeurArr))
    return 1;
  return 0;
}
    
int deplacementPossible(struct plateau plat, int hauteurArr, int largeurArr) {
  if (dansPlateau(plat, posArrivee)){
    if (p->type == SOURIS && deplacementLineaire(p, posArrivee) ||
    p->type == LION && deplacementDiagonal(p, posArrivee) ||
    p->type == ELEPHANT && (deplacementLineaire(p, posArrivee) || deplacementDiagonal(p, posArrivee)))
      return 1;
    }
      return 0;
////////////Appeler toutes les fonctions effraye esteffraye etc etc dans cette fonction 
}

void afficherPlateau (struct plateau *plat){
    for (int i = 0; i < plat-> hauteur; i++){
	for (int j = 0; j < plat-> largeur; j++){
	    switch (plat->contenu[i][j]) {
		//case VIDE : printf("."); break;
		//case  : printf("."); break;
		//case VIDE : printf("."); break;
	}
	printf("\n");
    }
    printf("\n");
}

void libererPlateau(struct plateau *plat) {
    int i;

    for(i = 0; i < plat->hauteur; i++)
	free(plat->contenu[i]);

    free(plat->contenu[i]);

    free(plat);
}
    

int main(){
    initialiserPieces();
    struct plateau *plat = initialiserPlateau();
    afficherPlateau (plat);
    libererPlateau(plat);
    return 0;
}
