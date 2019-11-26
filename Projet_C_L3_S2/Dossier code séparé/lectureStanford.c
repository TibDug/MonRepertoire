#include "lectureStanford.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<err.h>

struct individu * voisinsStanford(struct individu * population, struct parametres * p){
    int origine, extremite;
    char c;
    rewind(p -> inputStanford);
    do {
        c = fgetc(p -> inputStanford);
        if(c == '#')
            while(c != '\n'){
                c = fgetc(p -> inputStanford);
            }
        else if (c != ' ' && c != '\n' && c != EOF){
            ungetc(c, p -> inputStanford);
            fscanf(p -> inputStanford, "%d", &origine);
            c = fgetc(p -> inputStanford); // prendre l'espace
            fscanf(p -> inputStanford, "%d", &extremite);
            population[origine].voisins = ajout(population[origine].voisins, &population[extremite]);
            population[extremite].voisins = ajout(population[extremite].voisins, &population[origine]);
        }
    }while(c != EOF);
    for(int id = 0; id < p -> nbIndividus; id ++){
        population[id].nbVoisins = longueurChaine(population[id].voisins);
    }
    fclose(p -> inputStanford);
    return population;
}


int lectureStanford(struct parametres * p){
    int sommet, nmax = 0;
    char c;
    do {
        c = fgetc(p -> inputStanford);
        if(c == '#')
            while(c != '\n'){
                c = fgetc(p -> inputStanford);
            }
        else if (c != ' ' && c != '\n' && c != EOF){
            ungetc(c, p -> inputStanford);
            fscanf(p -> inputStanford, "%d", &sommet);
            if (sommet > nmax)
                nmax = sommet;
        }
    }while(c != EOF);
    return nmax;
}

struct individu * initialiserStanford(struct parametres * p){
    p -> nbIndividus = lectureStanford(p);
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
    population = voisinsStanford(population, p);
    return population;
}