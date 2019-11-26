#ifndef GESTIONPARAMETRES_H
#define GESTIONPARAMETRES_H

#include "structures.h"
#include "simulation.h"

int * infectesAuHasard(struct parametres *, int);
int erreursLigneCommande(struct parametres *);
struct parametres initialiserParametres();
void ligneCommande(int, char **);
void aide();

#endif