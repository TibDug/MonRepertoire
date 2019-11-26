#ifndef VERIFICATIONS_H
#define VERIFICATION_H

#include "joueurs.h"

int dansPlateau(struct plateau *, int, int);
int caseVide(struct plateau *, int, int);
int memeCouleur(struct plateau *, struct joueur, int, int);
int deplacementLineaire(int, int, int, int);
int deplacementDiagonal(int, int, int, int);
int estEffrayee(struct plateau*, int, int, int, int);
int aDeplacer(struct plateau *, struct joueur, int, int);
int deplacementPossible(struct plateau *, struct joueur, int, int, int, int);
int deplacementPossibleSansTexte(struct plateau *, struct joueur, int, int, int, int);

#endif