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

struct case {
    typeCase type;
    couleurPiece couleur;
    caracterePiece caractere;
    int pointEau;
    int effraye;
};

struct plateau {
    int hauteur;
    int largeur;
    struct case contenu[hauteur][largeur];
}

struct piece initialiserPieces2(case p, typeCase ty, couleurPiece co, caracterePiece cp){
    p->type = ty;
    p->couleur = co;
    p->caractere = cp;

    return p;
}

struct plateau initialiserCasePlateau(struct plateau plat, typeCase ty, couleurPiece co, caracterePiece cp, int hauteurDepart, int largeurDepart){
   plat->contenu[hauteurDepart][largeurDepart]->type = ty;
   plat->contenu[hauteurDepart][largeurDepart]->couleur = co;
   plat->contenu[hauteurDepart][largeurDepart]->caractere = cp;
   
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
}

struct plateau initialiserTaille() {
    struct plateau plat;
    int hauteur, largeur;

    do {
    printf("Choisissez une hauteur paire et supérieure ou égale à 8 pour le plateau : "); 
    scanf("%d", &hauteur);
    printf("\n");
    if (hauteur % 2 != 0)
	  printf("ERREUR : la hauteur doit être paire ! \n");
    if (hauteur >= 8)
	  printf("ERREUR : la hauteur doit être supérieure ou égale à 8 ! \n");
    } while(hauteur % 2 != 0 && hauteur >= 8);
	
    do {
    printf("Choisissez une largeur paire et supérieure ou égale à 8 pour le plateau : "); 
    scanf("%d", &largeur);
    printf("\n");
    if (largeur % 2 != 0)
	printf("ERREUR : la largeur doit être paire ! \n");
    if (largeur >= 8)
	printf("ERREUR : la largeur doit être supérieure ou égale à 8 ! \n");
    } while(largeur % 2 != 0 && largeur >= 8);

    plat->hauteur = hauteur;
    plat->largeur = largeur;

    return plat;
}

void initialiserPlateau(struct plateau plat) {
    for(int i = 0; i < plat->hauteur; i++) {
	     for(int j = 0; j < plat->largeur; j++) {
	        plat->contenu[i][j]->type = VIDE;
	        plat->contenu[i][j]->couleur = NULL;
	        plat->contenu[i][j]->caractere = NULL;
	        plat->contenu[i][j]->effraye = 0;
	        if(((i == hauteur / 2 - 1) && (j== largeur / 2) - 1)) || ((i == hauteur / 2 - 1) && (j == largeur / 2 + 2)) || ((i == (hauteur / 2 + 2) && (j == largeur / 2 - 1)) || ((i == hauteur / 2 + 2) && (j == largeur / 2 + 2)))
	          plat->contenu[i][j]->pointEau = 1;
	        else
            plat->contenu[i][j]->pointEau = 0;
	        
	     }
    }
}

void placerPiece(struct plateau plat){
  
}

void effraye(struct plateau plat, int x, int y){
  for (int i = x - 1; i <= x + 1; i ++){
    for (int j = y - 1; j <= y + 1; j ++){
      if (plat->contenu[x][y]->typeCase == ELEPHANT && plat->contenu[i][j]->typeCase == ELEPHANT)
        plat->contenu[x][y]->effraye = 1;
      if (plat->contenu[x][y]->typeCase == SOURIS && plat->contenu[i][j]->typeCase == LION)
       plat->contenu[x][y]->effraye = 1;
      if (plat->contenu[x][y]->typeCase == LION && plat->contenu[i][j]->typeCase == ELEPHANT)
        plat->contenu[x][y]->effraye = 1;
    }
  }
}



int dansPlateau(struct plateau plat, position posArrivee) {
    if ((posArrivee->x <= plat->hauteur) && (posArrivee->y <= plat->largeur) && (posArrivee->x >= 0) && (posArrivee->y >= 0))
	return 1;
    return 0;
}

int deplacementLineaire(struct piece p, struct position posArrivee){
    if ((p->posCourante->x == posArrivee->x && p->posCourante->y != posArrivee->y) || (p->posCourante->x != posArrivee->x && p->posCourante->y == posArrivee->y))
	return 1;
    return 0;
}

int deplacementDiagonal(struct piece p, struct position posArrivee){
    if ((fabs(p->posCourante->x - posArrivee->x) == fabs(p->posCourante->y - posArrivee->y))
	return 1;
    return 0;
}
    
int deplacementPossible(struct plateau plat, struct piece p, struct position posArrivee) {
    if (dansPlateau(plat, posArrivee)){
	    if (p->type == SOURIS && deplacementLineaire(p, posArrivee) ||
		p->type == LION && deplacementDiagonal(p, posArrivee) ||
		p->type == ELEPHANT && (deplacementLineaire(p, posArrivee) || deplacementDiagonal(p, posArrivee)))
		return 1;
    }
    return 0;
}

int main(){
    initialiserPieces();
    initialiserTaille();
    
    return 0;
}



..........
..........
...*..*...
..........
..........
...*..*...
..........
..........