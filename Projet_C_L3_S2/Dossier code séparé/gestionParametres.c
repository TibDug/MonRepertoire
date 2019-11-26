#include "gestionParametres.h"

int * infectesAuHasard(struct parametres * p, int nbInfectesReels){
    int indice, tmp, nbi = p -> nbIndividus;
    int * tabIndividus = malloc (sizeof(int) * nbi);
    int flagInfectePresent = 0;
    for (int j = 0; j < p -> nbIndividus; j++){
        tabIndividus[j] = j;
    }
    while(nbInfectesReels < p -> nbInfectes){
        indice = rand() % nbi; // nbIndividus sert d'indice pour le tableau
        if(nbInfectesReels == 0) {
            p -> tabInfectes[nbInfectesReels] = tabIndividus[indice];
            nbInfectesReels++;
        }
        else {
            for(int i = 0; i < nbInfectesReels; i++) {
                if (tabIndividus[indice] == p -> tabInfectes[i]) {
                    flagInfectePresent = 1;
                }
            }
            if (flagInfectePresent == 0
                ) {
                p -> tabInfectes[nbInfectesReels] = tabIndividus[indice];
                nbInfectesReels++;
            }
        }
        tmp = tabIndividus[indice];
        tabIndividus[indice] = tabIndividus[nbi - 1];
        tabIndividus[nbi - 1] = tmp;
        nbi --;
    }
    return p -> tabInfectes;
}

int erreursLigneCommande(struct parametres * p){
    if(p -> topologie > 6 || p -> topologie < 1){
        printf("ERR : Topologie incorrecte ou manquante. \n");
        return 1;
    }
    if(p -> nbInfectes < 0 || p -> dureeMax < 1 || p -> tempsGuerison < 1 || p -> tempsDesimmunisation < 1 || p -> probaInfection < 0 || p -> probaInfection > 1){
        printf("ERR : paramètre général. \n");
        return 1;
    }
    if(p -> topologie == 3 &&  (p -> proba < 0 || p -> proba > 1)){
        printf("ERR : probabilité du modèle. \n");
        return 1;
    }
    if(p -> topologie == 5 && (p -> proba < 0 || p -> proba > 1 || p -> paramPrairie.dimPrairie < 1 || p -> paramPrairie.rayonPrairieMax < 1 || p -> paramPrairie.rayonPrairieMin < 1 )){
        printf("ERR : argument manquant pour le modèle prairie aléatoire. \n");
        return 1;
    }
    if(p -> topologie == 6 && (p -> proba < 0 || p -> proba > 1 || p -> rebranchement < 0 || p -> rebranchement > (p -> nbIndividus / 2))){
        printf("ERR : argument manquant pour le modèle prairie aléatoire. \n");
        return 1;
    }
    return 0;
}

struct parametres initialiserParametres(){
    struct parametres p;
    p.topologie = -1;
    p.dureeMax = -1;
    p.tempsGuerison = -1;
    p.tempsDesimmunisation = -1;
    p.nbInfectes = -1;
    p.nbIndividus = -1;
    p.probaInfection = -1;
    p.proba = -1;
    p.paramPrairie.dimPrairie = -1;
    p.paramPrairie.rayonPrairieMin = -1;
    p.paramPrairie.rayonPrairieMax = -1;
    p.rebranchement = -1;
    return p;
};

void ligneCommande(int argc, char **argv){
    int indiceTabInfectes = 0;
    struct parametres p = initialiserParametres();
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"-nbi") == 0){
            i++;
            p.nbInfectes = atoi(argv[i]);
        }
    }
    p.tabInfectes = malloc(sizeof(int) * p.nbInfectes);
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"-nb") == 0){
            i++;
            p.nbIndividus = atoi(argv[i]);
        }
        if (strcmp(argv[i],"-topo") == 0){
            i++;
            p.topologie = atoi(argv[i]);
        }
        if (strcmp(argv[i],"-i") == 0){
            i++;
            int numInfecte = atoi(argv[i]);
            p.tabInfectes[indiceTabInfectes] = numInfecte;
            indiceTabInfectes++;
        }
        if (strcmp(argv[i],"-tg") == 0){
            i++;
            p. tempsGuerison = atoi(argv[i]);
        }
        if (strcmp(argv[i],"-td") == 0){
            i++;
            p.tempsDesimmunisation = atoi(argv[i]);
        }
        if (strcmp(argv[i],"-dm") == 0){
            i++;
            p.dureeMax = atoi(argv[i]);
        }
        if (strcmp(argv[i],"-p") == 0){
            i++;
            p.proba = atof(argv[i]);
        }
        if (strcmp(argv[i], "-fe") == 0){
            i++;
            FILE * inputStanford = fopen(argv[i], "r");
            if (inputStanford == NULL){
                err(1,"ERR : fopen %s", argv[i]);
                return;
            }
            p.inputStanford = inputStanford;
        }
        if (strcmp(argv[i], "-fs") == 0){
            //SEULEMENT DANS LE CAS DES MODELES ALEATOIRES
            i++;
            FILE * outputStanford = fopen(argv[i], "w");
            if (outputStanford == NULL){
                err(1,"ERR : fopen %s", argv[i]);
                return;
            }
            p.outputStanford = outputStanford;
        }
        if (strcmp(argv[i], "-fr") == 0){
            i++;
            FILE * fichierResultats = fopen(argv[i], "w");
            if (fichierResultats == NULL){
                err(1,"ERR : fopen %s", argv[i]);
                return;
            }
            p.fichierResultats = fichierResultats;
        }
        if (strcmp(argv[i], "-c") == 0){
            i++;
            p.paramPrairie.dimPrairie = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-rmax") == 0){
            i++;
            p.paramPrairie.rayonPrairieMax = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-rmin") == 0){
            i++;
            p.paramPrairie.rayonPrairieMin = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-k") == 0){
            i++;
            p.rebranchement = atoi(argv[i]);
        }
        if (strcmp(argv[i], "-probaI") == 0){
            i++;
            p.probaInfection = atof(argv[i]);
        }
    }
    if(erreursLigneCommande(&p) == 1){
        return;
    }
    struct individu * population;
    if (p.topologie == 4){
        population = initialiserStanford(&p);
    }
    else{
        population = initialiser(&p);
    }
    if(indiceTabInfectes < p.nbInfectes){
        p.tabInfectes = infectesAuHasard(&p, indiceTabInfectes);
    }
    simulation(population, &p);
}

void aide(){
    printf("Aide : \n"
           "-t\t le type de topologie : \n"
           "\t\t 1 clique \n"
           "\t\t 2 anneaux \n"
           "\t\t 3 Erdos-Renyi \n"
           "\t\t 4 Lecture de fichier Stanford \n"
           "\t\t 5 Prairie \n"
           "\t\t 6 Small World \n"
           "-dm\t la durée de la simulation \n"
           "-tg\t le nombre de tour avant guérison \n"
           "-td\t le nombre de tour avant désimmunisation \n"
           "-nbi\t le nombre d'individus infectes \n"
           "-nb\t le nombre d'individus total \n"
           "-i\t les identifiants des individus infectés (aléatoire si non précisé) \n"
           "-probaI\t la probabilité d'un individu d'être infecte \n"
           "-fr\t fichier de résultats détaillé\n"
           "-proba\t la probabilité de créer une arrête (modèles Erdos-Renyi, Prairie, Small Word)\n"
           "-fs\t fihcier stanford de sortie (modèle Erdos-Renyi, Prairie, Small Word)\n"
           "-fe\t fichier standford à lire (modèle Stanford)\n"
           "-c\t la dimention de la prairie (modèle Prairie)\n"
           "-rmax\t le rayon maximum d'un individu (modèle Prairie)\n"
           "-rmin\t le rayon minimum d'un individu (modèle Prairie)\n"
           "-k\t le nombre de rebramchements (modèle Small World)\n"
           );
}