#include "prairieAleatoire.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<err.h>

struct individu * voisinsPrairie(struct individu * population, struct parametres * p){
    int rmin = p->paramPrairie.rayonPrairieMin;
    int rmax = p->paramPrairie.rayonPrairieMax;
    for(int id = 0; id < p->nbIndividus; id ++){
        population[id].arguPrairie = (struct prairie *)malloc(sizeof(struct prairie));
        population[id].arguPrairie->posAbscisse = rand() % p->paramPrairie.dimPrairie;
        population[id].arguPrairie->posOrdonnee = rand() % p->paramPrairie.dimPrairie;
        population[id].arguPrairie->rayon = (rand() % (rmax - rmin)) + rmin;
    }
    for(int id = 0; id < p->nbIndividus; id ++){
        for(int idVoisins = id; idVoisins < p->nbIndividus; idVoisins ++){
            if(id != idVoisins){
                float distanceIndiv = sqrt(pow((population[id].arguPrairie->posAbscisse - population[idVoisins].arguPrairie->posAbscisse),2) + pow((population[id].arguPrairie->posOrdonnee - population[idVoisins].arguPrairie->posOrdonnee),2));
                float distanceContact = population[id].arguPrairie->rayon + population[idVoisins].arguPrairie->rayon;
                if (distanceIndiv <= distanceContact) {
                    population[id].voisins = ajout(population[id].voisins, &population[idVoisins]);
                    population[idVoisins].voisins = ajout(population[idVoisins].voisins, &population[id]);
                }
            }
        }
        population[id].nbVoisins = longueurChaine(population[id].voisins);
    }
    return population;
}