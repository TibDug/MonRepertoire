#include "smallWorld.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<err.h>


struct individu * voisinsSmallWorld(struct individu * population, struct parametres * p) {
    float probabilite;
    struct voisinage * listeIndiv = NULL, * tmp, * cellCourante, * cellCourante2, * cellCourante3;
    int tailleListeIndiv;
    int individuHasard;
    int idVoisin;
    for(int id = 0; id < p -> nbIndividus; id ++){
        for(int i = 1; i <= p -> rebranchement; i++){ // id + k pour la limite de voisin // modulo pour avoir un cercle
            int idVoisins = (id + i) % p -> nbIndividus;
            population[id].voisins = ajout(population[id].voisins, &population[idVoisins]);
            population[idVoisins].voisins = ajout(population[idVoisins].voisins, &population[id]);
        }
    }
    int compteur = 0;
    for(int k = 0; k < p -> rebranchement; k++) {
        for(int id = 0; id < p -> nbIndividus; id ++){
            if (population[id].voisins == NULL)
                break;
            cellCourante = population[id].voisins;
            int nombreVoisins = longueurChaine(population[id].voisins);
            for (int nbVoisinsRebranches = 0; nbVoisinsRebranches < nombreVoisins; nbVoisinsRebranches++){
                probabilite = (float)rand() / (float)RAND_MAX;
                if (probabilite < p -> proba){
                    tmp = cellCourante;
                    cellCourante = cellCourante -> voisinSuivant;
                    idVoisin = tmp -> individuActuel -> id;
                  	population[id].voisins = suppression(population[id].voisins, idVoisin);
                    population[idVoisin].voisins = suppression(population[idVoisin].voisins, id);
                    for (int i = 0; i < p -> nbIndividus; i++) {
                        if(id != i)
                            listeIndiv = ajout(listeIndiv, &population[i]);
                    }
                    cellCourante2 = population[id].voisins;
                    while (cellCourante2 != NULL) {
                        listeIndiv = suppression(listeIndiv, cellCourante2 -> individuActuel -> id);
                        cellCourante2 = cellCourante2 -> voisinSuivant;
                    }
                    tailleListeIndiv = longueurChaine(listeIndiv);
                    individuHasard = rand() % tailleListeIndiv;
                    cellCourante3 = listeIndiv;
                    int cpt = 0;
                    while (cellCourante3 != NULL) {
                        if (cpt == individuHasard) {
                            population[id].voisins = ajout(population[id].voisins, cellCourante3 -> individuActuel);
                            population[cellCourante3 -> individuActuel -> id].voisins = ajout(population[cellCourante3 -> individuActuel -> id].voisins, &population[id]);
                            break;
                        }
                        cpt++;
                        cellCourante3 = cellCourante3 -> voisinSuivant;
                    }
                    listeIndiv = NULL;
                    compteur++;
                }
                else {
                    cellCourante = cellCourante -> voisinSuivant;
                }
            }
        }
    }
    for(int id = 0; id < p -> nbIndividus; id ++)
        population[id].nbVoisins = longueurChaine(population[id].voisins);
    return population;
}