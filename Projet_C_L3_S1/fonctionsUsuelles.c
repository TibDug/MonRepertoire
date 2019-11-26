#include "fonctionsUsuelles.h"
#include <stdio.h>
#include <stdlib.h>

int nbChiffres(int n) {

    int cpt = 0;

    if (n == 0)
	cpt++;

    while (n != 0) {
	cpt++;
	n = n / 10;
    }

    return cpt;
  }

  int inverserHauteur(int hauteur, int hauteurPlateau) {
	  return hauteurPlateau - hauteur - 1;
  }