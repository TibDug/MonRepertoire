#ifndef JEU_H
#defn JEU_H

#include "verificato.h"

void effraie(struct plateau *, int, int);
void deplacement(struct plateau *, int, int, int, int);
void coordonneesOrdi(struct plateau *, struct joueur);
void coordonneesHumain(struct plateau *, struct joueur);
int partieTerminee(struct joueur, struct joueur);
int gagnant(struct joueur, struct joueur);
void partie(struct plateau *);

#endif