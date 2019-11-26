#include "anneau.h"

struct individu * voisinsAnneau(struct individu * population, struct parametres * p){
    for(int id = 0; id < p -> nbIndividus; id ++){
        int idInfectePrecedent = (id - 1 + p -> nbIndividus) % p -> nbIndividus;
        int idInfecteSuivant = (id + 1) % p -> nbIndividus;
        population[id].voisins = ajout(population[id].voisins, &population[idInfectePrecedent]);
        population[id].voisins = ajout(population[id].voisins, &population[idInfecteSuivant]);
        population[id].nbVoisins = longueurChaine(population[id].voisins);
    }
    return population;
}