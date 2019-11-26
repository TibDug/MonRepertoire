#ifndef simulation_H
#define simulation_H

#include "resultats.h"
#include "clique.h"
#include "anneau.h"
#include "erdosRenyi.h"
#include "lectureStanford.h"
#include "prairieAleatoire.h"
#include "smallWorld.h"
#include "gestionListes.h"
#include "structures.h"

struct individu * contamination(struct individu * population, int id);

struct individu * guerison(struct individu * population, int id);

struct individu * desimmunisation(struct individu * population, int id);

struct voisinage * transmission(struct voisinage * teteVoisins, struct parametres * p);

struct individu * initialiser(struct parametres * p);

void liberer(struct individu * population, struct parametres * p);


struct individu * simulation(struct individu * population, struct parametres * p);

#endif