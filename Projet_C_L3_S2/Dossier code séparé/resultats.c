#include "resultats.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<err.h>

void resultatsFichierSortie(struct individu * population, struct parametres * p, int tempsSimu){
    fprintf(p -> fichierResultats, "Tour %d : ", tempsSimu);
    for(int i = 0; i < p->nbIndividus; i ++){
        if (population[i].etat == S)
            fprintf(p -> fichierResultats,"%dS ", i);
        else if (population[i].etat == I)
            fprintf(p -> fichierResultats, "%dI ", i);
        else
            fprintf(p -> fichierResultats, "%dR ", i);
    }
    fprintf(p -> fichierResultats,"\n");
}

void ecritureStanford(struct individu * population, struct parametres * p){
    for (int id = 0; id < p -> nbIndividus; id ++){
        struct voisinage * cellCourante = population[id].voisins;
        while(cellCourante != NULL) {
            fprintf(p -> outputStanford, "%d %d\n", id, cellCourante -> individuActuel -> id);
            cellCourante = cellCourante -> voisinSuivant;
        }
    }
    fclose(p -> outputStanford);
}

void afficheResultats(struct individu * population, struct parametres * p, int nbContamination){
    int rcpt = 0, scpt = 0, icpt = 0;
    float nbTotalVoisins = 0.0;
    for (int id = 0; id < p -> nbIndividus; id ++){
        if (population[id].etat == R){
            rcpt ++;
        }
        else if (population[id].etat == S){
            scpt ++;
        }
        else if (population[id].etat == I){
            icpt ++;
        }
        nbTotalVoisins = nbTotalVoisins + population[id].nbVoisins;
    }
    float nbVoisinsMoyen = nbTotalVoisins / p -> nbIndividus;
    printf("Nombre de tours effectues : %d\nNombre d'individus infectes : %d\nNombre d'individus sains : %d\nNombre d'individus résistants :%d\nNombre d'individus total : %d\nNombre de contamination : %d\nTaux de maladie : %.2lf %% \nNombre moyen de voisins : %.2lf\n", p -> dureeMax, icpt, scpt, rcpt, p -> nbIndividus, nbContamination, ((icpt * 100.0) / p -> nbIndividus), nbVoisinsMoyen);
}