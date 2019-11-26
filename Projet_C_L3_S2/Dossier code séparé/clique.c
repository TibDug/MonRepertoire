#include "clique.h"

struct individu * voisinsClique(struct individu * population, struct parametres * p) {
    for(int id = 0; id < p -> nbIndividus; id ++){
        population[id].nbVoisins = p -> nbIndividus - 1;
        for(int i = 0; i < p -> nbIndividus; i ++){
            if (id != i){
                population[id].voisins = ajout(population[id].voisins, &population[i]);
            }
        }
        population[id].nbVoisins = longueurChaine(population[id].voisins);
    }
    return population;
}