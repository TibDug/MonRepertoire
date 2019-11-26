#include "affichage.h"
#include <stdio.h>
#include <stdlib.h>


void affichageRegles() {
      printf("REGLES DU BARCA \n \n Le Barca est un jeu à deux joueur. Il existe trois types de pieces ayant des deplacements strictes et representes par divers symboles tel que : \n - la souris : \n \t - deplacements : verticaux et horizontaux, \n \t - symbole : s, \n - le lion : \n \t - deplacements : diagonaux, \n \t - symbole : l, \n - l'elephant : \n \t - deplacements : verticaux, horizontaux, diagonaux, \n \t - symbole : e. \n \n L'objectif du jeu est qu'un joueur ai trois de ses pieces positionnees sur des points d'eau, representes par des * sur le plateau. \n Les cases vides sont representees par des . . \n Le joueur 1 dirige les pieces noires, representees en majuscules. Le joueur 2 dirige les pieces blanches, representees en minuscule. \n");
}
  
  
  void afficherPlateau(struct plateau *plat) {
	for (int i = 0; i < plat -> hauteur; i++) {
		printf("     ");
		for (int j = 0; j < plat -> largeur; j++){
			printf("-----");
		}
		printf("\n");
		printf("  %d", inverserHauteur(i, plat -> hauteur));
        	int nbCaracteres = nbChiffres(inverserHauteur(i, plat -> hauteur));
        	while (nbCaracteres < 3) {
            		printf(" ");
            		nbCaracteres++;
        	}
		for (int j = 0; j < plat -> largeur; j++){
			if(plat -> contenu[i][j].pointEau == 1) {	
	  			switch (plat -> contenu[i][j].type) {
		      		case VIDE:
					printf("|( )|");
		          		break;
		      		case ELEPHANT:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("|(e)|");
		          		else printf("|(E)|");
		          		break;
		      		case LION:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("|(l)|");
		          		else printf("|(L)|");
		          		break;
		      		case SOURIS:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("|(s)|");
		          		else printf("|(S)|");
		          		break;
		      		}
			}
			else {
				switch (plat -> contenu[i][j].type) {
		      		case VIDE:
					printf("|   |");
		          		break;
		      		case ELEPHANT:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("| e |");
		          		else printf("| E |");
		          		break;
		      		case LION:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("| l |");
		          		else printf("| L |");
		          		break;
		      		case SOURIS:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("| s |");
		          		else printf("| S |");
		          		break;
		      		}
			}
		}
		printf("\n");
		printf("     ");
		for (int j = 0; j < plat -> largeur; j++){
			printf("-----");
		}
		printf("\n");
	}
	printf("     ");
	for (int j = 0; j < plat -> largeur; j++){
			printf("  %d", j);
			int nbCaracteres = nbChiffres(j);
        	while (nbCaracteres < 3) {
            		printf(" ");
            		nbCaracteres++;
          }
	}
	printf("\n\n");
  }
  
          void sontEffrayees(struct plateau *plat, struct joueur joue){
      for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
              if (plat -> contenu[i][j].effraye == 1 && plat -> contenu[i][j].couleur == joue.couleur){
                  printf("La piece : (%d;%d) est effrayee \n", j, inverserHauteur(i, plat -> hauteur));
              }
          }
      }
  }
  
   void felicitations(int joueur) {
      printf("Feliciations joueur %d ! Vous avez gagne ! \n\n", joueur);
  }