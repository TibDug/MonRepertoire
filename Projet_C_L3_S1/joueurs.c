#include "joueurs.h"
#include <stdio.h>
#include <stdlib.h>
 
struct joueur {
    int identifiant;
    couleurPiece couleur;
    int nbPointEau;
    int tour;
    int ordi; 
};
  
  
// INITIALISATION DES JOUEURS 
struct joueur initialiserJoueur(int id, couleurPiece cj, int tr, int ordinateur) {
    struct joueur j;

    //j.nom = nj;
    j.identifiant = id;
    j.couleur = cj;
    j.nbPointEau = 0;
    j.tour = tr;
    j.ordi = ordinateur;

    return j;
}
  
struct joueur calculPointEau(struct plateau *plat, struct joueur joue) {
    joue.nbPointEau = 0;
    for (int i = 0; i < plat -> hauteur; i++) {
        for (int j = 0; j < plat -> largeur; j++) {
            if (plat -> contenu[i][j].pointEau == 1 && plat -> contenu[i][j].type != VIDE && plat -> contenu[i][j].couleur == joue.couleur)
                joue.nbPointEau++;
        }
    }
    return joue;
}
  
struct joueur tourDe(struct joueur j1, struct joueur j2) {
    if (j1.tour == 1) {
        printf("Au tour du joueur %d, qui controle les pieces noires (majuscule) \n\n", j1.identifiant);
        return j1;
    } else {
        printf("Au tour du joueur %d, qui controle les pieces blanches (miniscules) \n\n", j2.identifiant);
        return j2;
    }
}

struct joueur changementTour(struct joueur j) {
    if (j.tour == 1)
        j.tour = 0;
    else
        j.tour = 1;
    return j;
}
  