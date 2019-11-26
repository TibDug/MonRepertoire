#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {S, I, R} etat_t;

struct individu{
    int id;
    etat_t etat;
    int nbVoisins;
    int tempsEtat;
    int contamine;
    struct prairie * arguPrairie;
    struct voisinage * voisins;
};

struct prairie{
    int posAbscisse;
    int posOrdonnee;
    float rayon;
};

struct voisinage {
    struct individu * individuActuel;
    struct voisinage * voisinSuivant;
};

struct parametrePrairie {
    int dimPrairie;
    int rayonPrairieMin;
    int rayonPrairieMax;
};

struct parametres {
    int topologie;
    int dureeMax;
    int tempsGuerison;
    int tempsDesimmunisation;
    int nbInfectes;
    int nbIndividus;
    float probaInfection;
    float proba;
    int rebranchement;
    int * tabInfectes;
    FILE * inputStanford;
    FILE * outputStanford;
    FILE * fichierResultats;
    struct parametrePrairie paramPrairie;
};
