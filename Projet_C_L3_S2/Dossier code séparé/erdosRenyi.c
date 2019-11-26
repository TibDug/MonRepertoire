#include "erdosRenyi.h"

struct individu * voisinsErdosRenyi(struct individu * population, struct parametres * p){
    float probabilite;
    for(int id = 0; id < p -> nbIndividus; id ++){
        for(int idVoisins = id; idVoisins < p -> nbIndividus; idVoisins ++){
            if(id != idVoisins){
                probabilite = (float)rand() / (float)RAND_MAX;;
                if (probabilite < p -> proba){
                    population[id].voisins = ajout(population[id].voisins, &population[idVoisins]);
                    population[idVoisins].voisins = ajout(population[idVoisins].voisins, &population[id]);
                }
            }
        }
        population[id].nbVoisins = longueurChaine(population[id].voisins);
    }
    return population;
}
