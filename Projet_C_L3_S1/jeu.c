#include "jeu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void effraie(struct plateau * plat, int hauteurArr, int largeurArr) {
    for (int i = hauteurArr - 1; i <= hauteurArr + 1; i++) {
        for (int j = largeurArr - 1; j <= largeurArr + 1; j++) {
            if ( i >= 0 && i < plat -> hauteur && j >= 0 && j < plat -> largeur) {
                if (plat -> contenu[hauteurArr][largeurArr].couleur != plat -> contenu[i][j].couleur){
                    if (((plat -> contenu[hauteurArr][largeurArr].type == SOURIS) && (plat -> contenu[i][j].type == ELEPHANT)) ||
                        ((plat -> contenu[hauteurArr][largeurArr].type == LION) && (plat -> contenu[i][j].type == SOURIS)) ||
                        ((plat -> contenu[hauteurArr][largeurArr].type == ELEPHANT) && (plat -> contenu[i][j].type == LION))){
                        plat -> contenu[i][j].effraye = 1;
                    }
                }
            }
        }
    }
}

void deplacement(struct plateau *plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
    plat -> contenu[hauteurArr][largeurArr].type = plat -> contenu[hauteurDep][largeurDep].type;
    plat -> contenu[hauteurArr][largeurArr].couleur = plat -> contenu[hauteurDep][largeurDep].couleur;
    plat -> contenu[hauteurArr][largeurArr].effraye = 0;

    plat -> contenu[hauteurDep][largeurDep].type = VIDE;
    plat -> contenu[hauteurDep][largeurDep].effraye = 0;

    effraie(plat, hauteurArr, largeurArr);
}


void coordonneesOrdi(struct plateau *plat, struct joueur joue){
    int tabHaut[6], tabLarg[6], flag = 0, cpt = 0, indiceAleatoire,  hauteurDep, largeurDep, hauteurArr, largeurArr;
    
    for (int i = 0; i < plat -> hauteur; i++) {
        for (int j = 0; j < plat -> largeur; j++) {
            if (plat -> contenu[i][j].type != VIDE && plat -> contenu[i][j].couleur == joue.couleur && plat -> contenu[i][j].effraye == 1){
                hauteurDep = i;
                largeurDep = j;
                flag = 1;
            }
        }
    }
    if (flag == 0) {
        for (int i = 0; i < plat -> hauteur; i++) {
            for (int j = 0; j < plat -> largeur; j++) {
                if (plat -> contenu[i][j].type != VIDE && plat -> contenu[i][j].couleur == joue.couleur){
                    tabHaut[cpt] = i; 
                    tabLarg[cpt] = j; 
                    cpt++;
                }
            }
        }
        indiceAleatoire = rand() % 6;
        hauteurDep = tabHaut[indiceAleatoire];
        largeurDep = tabLarg[indiceAleatoire];
    }
    do{
        hauteurArr = rand() % plat -> hauteur;
        largeurArr = rand() % plat -> largeur;
    }while (deplacementPossibleSansTexte(plat, joue, hauteurDep, largeurDep, hauteurArr, largeurArr) == 0);
	    
    deplacement(plat, hauteurDep, largeurDep, hauteurArr, largeurArr);
	    
}

void coordonneesHumain(struct plateau *plat, struct joueur j){
    int hauteurDep, largeurDep, hauteurArr, largeurArr;
    do {
        printf("Quelle piece voulez vous deplacer ? (x y)\n");
        scanf("%d", & largeurDep);
        scanf("%d", & hauteurDep);
        hauteurDep = inverserHauteur(hauteurDep, plat -> hauteur);
            
        printf("Ou voulez vous la placer ? (x y) \n");
        scanf("%d", & largeurArr);
        scanf("%d", & hauteurArr);
        hauteurArr = inverserHauteur(hauteurArr, plat -> hauteur);

    } while (deplacementPossible(plat, j, hauteurDep, largeurDep, hauteurArr, largeurArr) == 0);

    deplacement(plat, hauteurDep, largeurDep, hauteurArr, largeurArr);
}


int partieTerminee(struct joueur j1, struct joueur j2) {
    if (j1.nbPointEau >= 3 || j2.nbPointEau >= 3)
        return 1;
    return 0;
}

int gagnant(struct joueur j1, struct joueur j2) {
    if (j1.nbPointEau == 3)
        return j1.identifiant;
    else
        return j2.identifiant;
}

void partie(struct plateau * plat) {
    int nbJoue;
    struct joueur joueurNoir;
    struct joueur joueurBlanc;
    struct joueur joueurActuel;
      
    do{
        printf("Partie a 1 ou deux joueurs ?\n");
        scanf("%d", &nbJoue);
        if (nbJoue != 1 && nbJoue != 2) {
            printf("Le nombre de joueurs doit être 1 ou 2 ! \n"); 
        }
    } while (nbJoue != 1 && nbJoue != 2);
      
    if (nbJoue == 1) {
        joueurNoir = initialiserJoueur(1, NOIR, 0, 1);
    }
    else {
        joueurNoir = initialiserJoueur(1, NOIR, 0, 0);
    }
        
    joueurBlanc = initialiserJoueur(2, BLANC, 1, 0);
      
    afficherPlateau(plat);

    do {
        joueurActuel = tourDe(joueurNoir, joueurBlanc);
        sontEffrayees(plat, joueurActuel);
        if (joueurActuel.ordi == 0)
            coordonneesHumain(plat, joueurActuel);
        else
            coordonneesOrdi(plat, joueurActuel);
            
        afficherPlateau(plat);
        joueurNoir = changementTour(joueurNoir);
        joueurBlanc = changementTour(joueurBlanc);
        joueurNoir = calculPointEau(plat, joueurNoir);
        joueurBlanc = calculPointEau(plat, joueurBlanc);
    } while (!partieTerminee(joueurNoir, joueurBlanc));

    felicitations(gagnant(joueurNoir, joueurBlanc));
}


