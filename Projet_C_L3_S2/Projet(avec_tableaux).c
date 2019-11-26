#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef enum {S, I, R} etat_t;

struct individu{
    int id;
    etat_t etat;
    int nbVoisins;
    int tempsEtat;
    int contamine;
      // ICI
    struct individu ** voisins;
};

struct parametres {
    int seuilContamination; // penser a le gerer
    int tempsGuerison;
    int tempsDesimmunisation;
    int dureeMax;
    int nbInfectes;
    int nbIndividus;
    int topologie;
    float probaER;
    int * tabInfectes;
};

struct cellER {
    int id;
    struct cellER * suivant;
};

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

int longueurChaine(struct cellER * cellCourante){
    if (cellCourante == NULL)
        return 0;
    return (1 + longueurChaine(cellCourante -> suivant));
}

struct cellER * allouerListe(int val, struct cellER * cellCourante){
    struct cellER * cellSuivante;
    if ( cellCourante == NULL){
      cellSuivante = malloc (sizeof (struct cellER));
        cellSuivante -> id = val;
        cellSuivante -> suivant = NULL;
        return cellSuivante;
    }
    cellCourante -> suivant = allouerListe(val, cellCourante -> suivant);
    return cellCourante; 
}

struct individu * tableauVoisinsErdosRenyi(struct individu * population, struct parametres p){
    float probabilite;
    //int longueurChaine = 0;
    int cpt = 0;
	printf("1\n");
    for(int id = 0; id < p.nbIndividus; id ++){
		printf("2\n");
        struct cellER * cellCourante = NULL;
		printf("3\n"); 
        for(int idVoisins = id; idVoisins < p.nbIndividus; idVoisins ++){
			printf("4\n");
            if(id != idVoisins){
				printf("5\n");
                probabilite = (float)rand() / (float)RAND_MAX;;
                printf("%lf, %lf", p.probaER, probabilite);
                if (probabilite > p.probaER){
					printf("6\n");
                    cellCourante = allouerListe(id, cellCourante);
                }
            }
        }
		printf("7\n");
        population[id].nbVoisins = longueurChaine(cellCourante);
        population[id].voisins = malloc(sizeof(struct individu *) * population[id].nbVoisins);
        while(cellCourante != NULL){
			printf("8\n");
            population[id].voisins[cpt] = &population[cellCourante -> id];
            cpt++;
            cellCourante = cellCourante -> suivant;
        }
    }
    return population;
}

struct individu * tableauVoisinsAnneau(struct individu * population, struct parametres p){
    for(int id = 0; id < p.nbIndividus; id ++){
        population[id].nbVoisins = 2;
        // ICI
        population[id].voisins = malloc(sizeof(struct individu *) * population[id].nbVoisins);
        int idInfectePrecedent = (id - 1 + p.nbIndividus) % p.nbIndividus;
        int idInfecteSuivant = (id + 1) % p.nbIndividus;
        population[id].voisins[0] = &population[idInfectePrecedent];
        population[id].voisins[1] = &population[idInfecteSuivant];
        printf("%d  ", id);
        printf("%d  ", idInfectePrecedent);
        printf("%d\n", idInfecteSuivant);
    }
    return population;
}

struct individu * tableauVoisinsClique(struct individu * population, struct parametres p) {
    for(int id = 0; id < p.nbIndividus; id ++){
        int indiceTab = 0;
        population[id].nbVoisins = p.nbIndividus - 1;
        // ICI
        population[id].voisins = malloc(sizeof(struct individu *) * population[id].nbVoisins);
        for(int i = 0; i < p.nbIndividus; i ++){
            if (id != i){
                population[id].voisins[indiceTab] = &population[i];
                indiceTab ++;
            }
        }
    }
    return population;
}

struct individu * initialiser(struct parametres p){
    struct individu * population = (struct individu *)malloc(sizeof(struct individu) * p.nbIndividus);
    for (int i = 0; i < p.nbIndividus; i ++){
        population[i].id = i;
        population[i].contamine = 0;
        population = desimmunisation(population, i);
        for (int j = 0; j < p.nbInfectes; j ++){
            if (population[i].id == p.tabInfectes[j]){
                population = contamination(population, i);
            }
        }
    }
    if (p.topologie == 1) { // dans le cadre de la clique
        population = tableauVoisinsClique(population, p);
    }
    if (p.topologie == 2){ // dans le cadre de l'anneau
        population = tableauVoisinsAnneau(population, p);
    }
    if (p.topologie == 3){ // dans le cadre de l'anneau
        population = tableauVoisinsErdosRenyi(population, p);
    }
    return population;
}

void affiche(struct individu * population, struct parametres p, int tempsSimu){
    printf("\n### ETAPE %d ###\n", tempsSimu);
    for(int i = 0; i < p.nbIndividus; i ++){
        printf("\nIdentifiant : %d \t", population[i].id);
        if (population[i].etat == S)
            printf("Etat : S \t");
        else if (population[i].etat == I)
            printf("Etat : I \t");
        else
            printf("Etat : R \t");
        printf("Nombre de voisins : %d \t", population[i].nbVoisins);
        printf("Temps etat : %d \t", population[i].tempsEtat);
        printf("Contamine : %d \t", population[i].contamine);
    }
}

void liberer(struct individu * population, struct parametres p){
    for (int i = 0; i < p.nbIndividus; i ++)
        // ICI
        free(population[i].voisins);
    free(population);
    free(p.tabInfectes);
}


struct individu * simulation(struct parametres p){
    struct individu * population = initialiser(p);
    int tempsSimu;
    for (tempsSimu = 0; tempsSimu < p.dureeMax; tempsSimu ++){
        affiche(population, p, tempsSimu);
        for(int id = 0; id < p.nbIndividus; id ++){
            if(population[id].contamine == 1){
                population = contamination(population, id);
            }
        }
        for(int id = 0; id < p.nbIndividus; id ++){
            population[id].tempsEtat ++; // On peut faire des stats sur le temps avec l'etat S d'un individu
            if(population[id].etat == R && population[id].tempsEtat >= p.tempsDesimmunisation){
                population[id].etat = S;
            }
            if(population[id].etat == I && population[id].tempsEtat >= p.tempsGuerison){
                population[id].etat = R;
            }
            if(population[id].etat == I){
                for(int j = 0; j < population[id].nbVoisins; j++){
                    // ICI
                    if (population[id].voisins[j]->etat == S){
                        population[id].voisins[j]->contamine = 1;
                    }
                }
            }
        }
    }
    //affiche(population, p, tempsSimu);
    return population;
}

void openFile(char * fileName){
    FILE * fichier;
    fichier = fopen("fileName", "r");
    // A COMPLETER A L'OCCASION
    // char * a;
    // sscanf (a, "%d %d", &x, &y);
    // double b
    // sscanf (argv[i], "%ls", %d)
}

int * infectesAuHasard(int * tabInfectes, int * tabIndividus, int nbInfectesMax, int nbInfectesReels, int nbIndividus){
    // probleme en cas d'initialisation a i = 0 ou alors lorsque le nbi = 2 et les i ne sont pas donnés
    int indice = rand() % nbIndividus;
    int tmp;
    if (nbInfectesReels == nbInfectesMax)
        return tabInfectes;
    for(int i = 0; i < nbInfectesReels; i++) { // fonctionne sans erreur en remplacant nbInfectesReels avec nbInfectesMax
        if (tabIndividus[indice] != tabInfectes[i]) {
            nbInfectesReels++;
            tabInfectes[nbInfectesReels] = tabIndividus[indice];
        }
        tmp = tabIndividus[indice];
        tabIndividus[indice] = tabIndividus[nbIndividus - 1];
        tabIndividus[nbIndividus - 1] = tmp;
        nbIndividus--;
        return infectesAuHasard(tabInfectes, tabIndividus, nbInfectesMax, nbInfectesReels, nbIndividus);
    }
}

// on regarde su l'individu est dans tabInfecté
// si non : on l'ajoute dans tabInfecté
//          On incrémente nbInfecté
//          On place cet infecté à la fin du tableau tabIndividu
//          On décrémente nbIndividus

void ligneCommande(int argc, char **argv){
    int indiceTabInfectes = 0;
    struct parametres p;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"-nbi") == 0){
            i++;
            p.nbInfectes = atoi(argv[i]);
            printf("le nb individus infectes a ete init %d \n", p.nbInfectes );
        }
    }
    p.tabInfectes = malloc(sizeof(int) * p.nbInfectes);
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i],"-nb") == 0){
            i++;
            p.nbIndividus = atoi(argv[i]);
            printf("le nb individus a ete init %d \n", p.nbIndividus);
        }
        if (strcmp(argv[i],"-topo") == 0){
            i++;
            p.topologie = atoi(argv[i]);
            printf("la topologie a ete init %d \n", p.topologie);
        }
        if (strcmp(argv[i],"-i") == 0){
            i++;
            int numInfecte = atoi(argv[i]);
            p.tabInfectes[indiceTabInfectes] = numInfecte;
            indiceTabInfectes++;
            printf("l'identifiant %d de l'infectes a ete init \n", numInfecte);
        }
        if (strcmp(argv[i],"-tg") == 0){
            i++;
            p.tempsGuerison = atoi(argv[i]);
            printf("le temps de guerison a ete init %d \n", p.tempsGuerison);
        }
        if (strcmp(argv[i],"-td") == 0){
            i++;
            p.tempsDesimmunisation = atoi(argv[i]);
            printf("le temps de desimmunisation a ete init %d \n",p.tempsDesimmunisation);
        }
        if (strcmp(argv[i],"-dm") == 0){
            i++;
            p.dureeMax = atoi(argv[i]);
            printf("la duree max a ete init %d \n", p.dureeMax);
        }
        if (strcmp(argv[i],"-sc") == 0){
            i++;
            p.seuilContamination = atoi(argv[i]);
            printf("le seuil de contamination a ete init a %d \n", p.seuilContamination);
        }
        if (strcmp(argv[i],"-pER") == 0){
            i++;
            p.probaER = atof(argv[i]);
            printf("la probabilite de voisinage pour le modele ER %lf \n", p.probaER);
        }
    }
    if(indiceTabInfectes < p.nbInfectes){
        int * tabIndividus = malloc (sizeof(int) * p.nbIndividus);
        for (int j = 0; j < p.nbIndividus; j++)
            tabIndividus[j] = j;
        p.tabInfectes = infectesAuHasard(p.tabInfectes, tabIndividus, p.nbInfectes, indiceTabInfectes, p.nbIndividus);
    }
    simulation(p);
}

void aide(){
    printf("Aide : \n");
    // -f pour rentrer un fichier qui contient la ligne de commande
    // -nb pour le nombre d'individus
    // -i pour les individus infectés
    // -t pour le type de topologie
    //  1 pour une clique
    //  2 pour les anneaux
    // attention a ne pas definir le nbIndividus infectes avant les individus infectes
}


int main(int argc, char **argv) {
    printf ("%d", -1 % 5);
    srand(time(NULL));
    if (argc <= 1 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-h") == 0){
        aide();
    }
    else if (strcmp(argv[1],"-f") == 0)
        openFile(argv[2]);
    else
        ligneCommande(argc, argv);
    return 0;
}

// Arguments en ligne de commande
//  nb d'individus
//  type de topologie
//  quel(s) individu(s) est(sont) malade(s)
//  optionnel : faire un help -h -help
// exemple de ligne de commande :
// ./a.out -nbi 1 -nb 4 -i 2 -topo 1 -tg 3 -td 3 -dm 10 -sc 0

