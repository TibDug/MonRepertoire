#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "joueurs.h"
#include "fonctionsUsuelles.h"

void affichageRegles();
void afficherPlateau(struct plateau *);
void sontEffrayees(struct plateau *, struct joueur);
void felicitations(int);

#endif