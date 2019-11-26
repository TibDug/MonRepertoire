#include "simulation.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<err.h>


struct individu * contamination(struct individu * population, int id){
    population[id].etat = I;
    population[id].tempsEtat = 0;
    population[id].contamine = 0;
    return population;
}

struct individu * guerison(struct individu * population, int id){
    population[id].etat = R;
    population[id].tempsEtat = 0;
    return population;
}

struct individu * desimmunisation(struct individu * population, int id){
    population[id].etat = S;
    population[id].tempsEtat = 0;
    return population;
}

struct voisinage * transmission(struct voisinage * teteVoisins, struct parametres * p) {
    float probabilite;
    struct voisinage * voisinCourant = teteVoisins;
    while (voisinCourant != NULL){
        probabilite = (float)rand() / (float)RAND_MAX;
        if(voisinCourant -> individuActuel -> etat == S && probabilite < p -> probaInfection){
            voisinCourant -> individuActuel -> contamine = 1;
        }
        voisinCourant = voisinCourant -> voisinSuivant;
    }
    return teteVoisins;
}

struct individu * initialiser(struct parametres * p){
    struct individu * population = (struct individu *)malloc(sizeof(struct individu) * p -> nbIndividus);
    for (int i = 0; i < p -> nbIndividus; i ++){
        population[i].id = i;
        population[i].contamine = 0;
        population = desimmunisation(population, i);
        for (int j = 0; j < p -> nbInfectes; j ++){
            if (population[i].id == p -> tabInfectes[j]){
                population = contamination(population, i);
            }
        }
    }
    if (p -> topologie == 1) { // clique
        population = voisinsClique(population, p);
    }
    if (p -> topologie == 2){ // anneau
        population = voisinsAnneau(population, p);
    }
    if (p -> topologie == 3){ // Erdos-Renyi
        population = voisinsErdosRenyi(population, p);
    }
    if (p -> topologie == 5){ // prairie aléatoire
        population =  voisinsPrairie(population, p);
    }
    if (p -> topologie == 6){ // small world
        population =  voisinsSmallWorld(population, p);
    }
    return population;
}

void liberer(struct individu * population, struct parametres * p){
    for (int i = 0; i < p->nbIndividus; i ++) {
        if (population[i].arguPrairie != NULL)
            free(population[i].arguPrairie);
        if (population[i].voisins != NULL)
            libererListe(population[i].voisins);
    }
    free(population);
    free(p -> tabInfectes);
}


struct individu * simulation(struct individu * population, struct parametres * p){
    int tempsSimu, nbContamination = 0;
    for (tempsSimu = 0; tempsSimu < p->dureeMax; tempsSimu ++){
        resultatsFichierSortie(population, p, tempsSimu);
        for(int id = 0; id < p->nbIndividus; id ++){
            if(population[id].contamine == 1){
                population = contamination(population, id);
                nbContamination ++;
            }
        }
        for(int id = 0; id < p->nbIndividus; id ++){
            population[id].tempsEtat ++; // On peut faire des stats sur le temps avec l'etat S d'un individu
            if(population[id].etat == R && population[id].tempsEtat >= p->tempsDesimmunisation){
                population[id].etat = S;
            }
            if(population[id].etat == I && population[id].tempsEtat >= p->tempsGuerison){
                population[id].etat = R;
            }
            if(population[id].etat == I){
                transmission(population[id].voisins, p);
            }
        }
    }
    resultatsFichierSortie(population, p, tempsSimu);
    afficheResultats(population, p, nbContamination);
    ecritureStanford(population, p);
    fclose(p -> fichierResultats);
    liberer(population, p);
    return population;
}