#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef enum {VIDE, SOURIS, LION, ELEPHANT} typeContenu;

typedef enum {NOIR, BLANC} couleurPiece;

typedef enum {S, L, E, s, l, e} caracterePiece;

struct position {
    int x;
    int y;
};

struct Case {
    typeContenu type;
    couleurPiece couleur;
    int pointEau;
    //caracterePiece caractere;
    //struct position posCourante;
};

struct plateau {
    int largeur;
    int hauteur;
    Case **contenu;
};
	
struct piece initialiserPieces2(struct piece p, typePiece ty, couleurPiece co, caracterePiece cp, int x, int y){
    p.type = ty;
    p.couleur = co;
    p.caractere = cp;

    return p;
}

void initialiserPieces() {
    struct piece sourisNoir1;
    initialiserPieces2(sourisNoir1, SOURIS, NOIR, S, 1, 1);

    struct piece sourisNoir2;
    initialiserPieces2(sourisNoir2, SOURIS, NOIR, S, 2, 1);
   
}

/*void initialiserPieces(){
  piece sourisNoir1;
  sourisNoir1.nom = SOURIS;
  sourisNoir1.caractere = S;
  piece sourisNoir2;
  sourisNoir2.nom = SOURIS;
  sourisNoir2.caractere = S;

  piece lionNoir1;
  lionNoir1.nom = LION;
  lionNoir1.caractere = L;
  piece lionNoir2;
  lionNoir2.nom = LION;
  lionNoir2.caractere = L;

  piece elephantNoir1;
  elephantNoir1.nom = ELEPHANT;
  elephantNoir1.caractere = E;
  piece elephantNoir2;
  elephantNoir2.nom = ELEPHANT;
  elephantNoir2.caractere = E;

  piece sourisBlanc1;
  sourisBlanc1.nom = SOURIS;
  sourisBlanc1.caractere = s;
  piece sourisBlanc2;
  sourisBlanc2.nom = SOURIS;
  sourisBlanc2.caractere = s;

  piece lionBlanc1;
  lionBlanc1.nom = LION;
  lionBlanc1.caractere = l;
  piece lionBlanc2;
  lionBlanc2.nom = LION;
  lionBlanc2.caractere = l;

  piece elephantBlanc1;
  elephantBlanc1.nom = ELEPHANT;
  elephantBlanc1.caractere = e;
  piece elephantBlanc2;
  elephantBlanc2.nom = ELEPHANT;
  elephantBlanc2.caractere = e;
  }*/

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
	    plat->contenu[i][j] = VIDE;
	}
    }

    return plat;
}

int dansPlateau(struct plateau plat, struct position posArrivee) {
    if ((posArrivee.x <= plat.hauteur) && (posArrivee.y <= plat.largeur) && (posArrivee.x >= 0) && (posArrivee.y >= 0))
	return 1;
    return 0;
}

int deplacementLineaire(struct piece p, struct position posArrivee){
    if ((p.posCourante.x == posArrivee.x && p.posCourante.y != posArrivee.y) || (p.posCourante.x != posArrivee.x && p.posCourante.y == posArrivee.y))
	return 1;
    return 0;
}

int deplacementDiagonal(struct piece p, struct position posArrivee){
    if (fabs(p.posCourante.x - posArrivee.x) == fabs(p.posCourante.y - posArrivee.y))
	return 1;
    return 0;
}
    
int deplacementPossible(struct plateau plat, struct piece p, struct position posArrivee) {
    if (dansPlateau(plat, posArrivee)){
	if (((p.type == SOURIS) && (deplacementLineaire(p, posArrivee))) ||
	    ((p.type == LION) && (deplacementDiagonal(p, posArrivee))) ||
	    ((p.type == ELEPHANT) && (deplacementLineaire(p, posArrivee) || deplacementDiagonal(p, posArrivee))))
	    return 1;
    }
    return 0;
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
