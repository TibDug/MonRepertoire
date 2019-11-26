#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>

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
  struct voisinage * voisinPrecedent;
};

struct parametrePrairie {
  int dimPrairie;
  int rayonPrairieMin;
  int rayonPrairieMax;
};

struct parametres {
  //int seuilContamination; // penser a le gerer
  int tempsGuerison;
  int tempsDesimmunisation;
  int dureeMax;
  int nbInfectes;
  int nbIndividus;
  int topologie;
  float probaInfection;
  FILE * fichier;
  float proba;
  struct parametrePrairie paramPrairie;
  int rebranchement;
  int * tabInfectes;
};

struct voisinage * ajout(struct voisinage * cellTete, struct individu * indiv){
  if (cellTete == NULL){
    cellTete = (struct voisinage * )malloc (sizeof (struct voisinage));
    cellTete -> individuActuel = indiv;
    cellTete -> voisinSuivant = NULL;
    cellTete -> voisinPrecedent = NULL;
    return cellTete;
  }
  struct voisinage * cellCourante = cellTete;
  while (cellCourante -> voisinSuivant != NULL) {
    cellCourante = cellCourante -> voisinSuivant;
  }
  cellCourante -> voisinSuivant = (struct voisinage * )malloc (sizeof (struct voisinage));
  cellCourante -> voisinSuivant -> individuActuel = indiv;
  cellCourante -> voisinSuivant -> voisinSuivant = NULL;
  cellCourante -> voisinSuivant -> voisinPrecedent = cellCourante;
  return cellTete;
}

/*struct voisinage * suppression(struct voisinage * cellTete, int idVoisin){
  struct voisinage * cellCourante = cellTete;
  while (cellCourante != NULL) {
    if (cellCourante -> individuActuel -> id == idVoisin) {
      if (cellCourante -> voisinPrecedent == NULL){
        newListe = cellCourante -> voisinSuivant
        newListe -> voisinPrecedent == NULL;
        free(cellCourante);
        return newListe;
      }
      if (cellCourante -> voisinSuivant == NULL) {
        free(cellCourante);
        
      }
  	  if (cellCourante -> voisinPrecedent != NULL){
        	cellCourante -> voisinPrecedent -> voisinSuivant = cellCourante -> voisinSuivant;
  		cellCourante -> voisinPrecedent = NULL;
  	  }
  	  if (cellCourante -> voisinSuivant != NULL){
        	cellCourante -> voisinSuivant -> voisinPrecedent = cellCourante -> voisinPrecedent;
        	cellCourante -> voisinSuivant = NULL;
  	  }
      free(cellCourante);
    }
    cellCourante = cellCourante -> voisinSuivant;
  }
  return cellTete;
}*/

struct voisinage * suppression(struct voisinage * cellTete, int idVoisin){
  // Si la liste est vide
  if (cellTete == NULL)
      return cellTete;
  // Si le premier élement de la liste est l'élément à supprimer
  if (cellTete -> individuActuel -> id) {
      struct voisinage ancienneTete = cellTete
      cellTete = cellTete -> suivant;
      free(ancienneTete);
      return cellTete;
  }
  struct voisinage * cellCourante = cellTete;
  struct voisinage * cellTmp;
  while (cellCourante != NULL) {
    if (cellCourante -> individuActuel -> id == idVoisin) {
      cellTmp = cellCourante;
      cellCourante = cellCourante -> voisinSuivant;
      cellCourante -> voisinPrecedent = cellTmp -> voisinPrecedent
      cellTmp = cellCourante
      
      
      if (cellCourante -> voisinPrecedent == NULL){
        newListe = newListe -> voisinSuivant
        newListe -> voisinPrecedent == NULL;
        free(cellTete);
        return newListe;
      }
      if (cellCourante -> voisinSuivant == NULL) {
        free(cellCourante);
        
      }
  	  if (cellCourante -> voisinPrecedent != NULL){
        	cellCourante -> voisinPrecedent -> voisinSuivant = cellCourante -> voisinSuivant;
  		cellCourante -> voisinPrecedent = NULL;
  	  }
  	  if (cellCourante -> voisinSuivant != NULL){
        	cellCourante -> voisinSuivant -> voisinPrecedent = cellCourante -> voisinPrecedent;
        	cellCourante -> voisinSuivant = NULL;
  	  }
      free(cellCourante);
    }
    cellTete = cellTete -> voisinSuivant;
  }
  return cellTete;
}

struct voisinage * affichageListe(struct voisinage * cellTete){
  struct voisinage * cellCourante = cellTete;
  while (cellCourante != NULL) {
    printf("%d    ", cellCourante -> individuActuel -> id);
	cellCourante = cellCourante -> voisinSuivant;
  }
  printf("\n");
  return cellTete;
}

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

int longueurChaine(struct voisinage * cellCourante){
  if (cellCourante == NULL)
    return 0;
  return (1 + longueurChaine(cellCourante -> voisinSuivant));
}

struct individu * voisinsSmallWorld(struct individu * population, struct parametres * p) {
// initialisation !!
  float probabilite;
  struct voisinage * listeIndiv, * cellCourante, * cellCourante2, * cellCourante3;
  int tailleListeIndiv;
  int individuHasard;
  int cpt = 0;
  for(int id = 0; id < p -> nbIndividus; id ++){
    for(int i = 1; i <= p -> rebranchement; i++){ // id + k pour la limite de voisin // modulo pour avoir un cercle
	int idVoisins = (id + i) % p -> nbIndividus;
      population[id].voisins = ajout(population[id].voisins, &population[idVoisins]);
      population[idVoisins].voisins = ajout(population[idVoisins].voisins, &population[id]);
    }
	affichageListe(population[id].voisins);
  }
printf("\n");
for(int id = 0; id < p -> nbIndividus; id ++){
affichageListe(population[id].voisins);
}
  for(int k = 0; k < p -> rebranchement; k++) {
      for(int id = 0; id < p -> nbIndividus; id ++){
          if (population[id].voisins == NULL)
              break;
          cellCourante = population[id].voisins;
          while (cellCourante != NULL) {
		affichageListe(population[id].voisins);
              probabilite = (float)rand() / (float)RAND_MAX;
              if (probabilite < p -> proba){
				  printf("1 \n");
                  population[id].voisins = suppression(population[id].voisins, cellCourante -> individuActuel -> id);
			affichageListe(population[id].voisins);
				  printf("2 \n");
                  for (int i = 0; i < p -> nbIndividus; i++) {
					 if(id != i)
                      	listeIndiv = ajout(listeIndiv, &population[i]);
                  }
				  affichageListe(listeIndiv);
				  affichageListe(population[id].voisins);
  				  printf("3 \n");
                  cellCourante2 = population[id].voisins;
                  while (cellCourante2 != NULL) {
                      listeIndiv = suppression(listeIndiv, cellCourante2 -> individuActuel -> id);
                      cellCourante2 = cellCourante2 -> voisinSuivant;  
                  }
				  affichageListe(listeIndiv);
				  printf("4 \n");
                  tailleListeIndiv = longueurChaine(listeIndiv);
                  individuHasard = rand() % tailleListeIndiv;
                  cellCourante3 = listeIndiv;
                  while (cellCourante3 != NULL) {
					  printf("5 \n");
                      if (cpt == individuHasard) {
						  printf("6 \n");
						  printf("%d \n",cellCourante3 -> individuActuel -> id);
						  printf("7 \n");
                          population[id].voisins = ajout(population[id].voisins, cellCourante3 -> individuActuel);
                      }
                      cpt++;
                      cellCourante3 = cellCourante3 -> voisinSuivant;  
                  }
              }
              cellCourante = cellCourante -> voisinSuivant;  
          }
    // for (j) qui parcours la liste de voisins
      // if : on regarde si la probabilité nous poussez à rebranche
        // on creer un liste qui contient tous les individus
        // on supprime de cette liste tous les voisins de cet individu sauf (j)
        // on calcule la taille de cette liste
        // on determine au hasard un indice dans cette liste
    }
  }
	return population;
}


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


struct individu * voisinsStanford(struct individu * population, struct parametres * p){
  int origine, extremite;
  char c;
  rewind(p -> fichier);
  do {
    c = fgetc(p -> fichier);
    if(c == '#')
      while(c != '\n'){
	c = fgetc(p -> fichier);
      }
    else if (c != ' ' && c != '\n' && c != EOF){
      ungetc(c, p -> fichier);
      fscanf(p -> fichier, "%d", &origine);
      c = fgetc(p -> fichier); // prendre l'espace
      fscanf(p -> fichier, "%d", &extremite);
      population[origine].voisins = ajout(population[origine].voisins, &population[extremite]);
      population[extremite].voisins = ajout(population[extremite].voisins, &population[origine]);
    }
  }while(c != EOF);
  for(int id = 0; id < p -> nbIndividus; id ++){
      population[id].nbVoisins = longueurChaine(population[id].voisins);
  }
  return population;
}


int lectureStanford(struct parametres * p){
  int sommet, nmax = 0;
  char c;
  do {
    c = fgetc(p -> fichier);
    if(c == '#')
      while(c != '\n'){
	c = fgetc(p -> fichier);
      }
    else if (c != ' ' && c != '\n' && c != EOF){
      ungetc(c, p -> fichier);
      fscanf(p -> fichier, "%d", &sommet);
      if (sommet > nmax)
	nmax = sommet;
    }
  }while(c != EOF);
  return nmax;
}

struct individu * initialiserStanford(struct parametres * p){
  p -> nbIndividus = lectureStanford(p);
  struct individu * population = (struct individu *)malloc(sizeof(struct individu) * p -> nbIndividus);
  printf("Le nombre d'individus est : %d\n", p -> nbIndividus);
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

struct individu * voisinsErdosRenyi(struct individu * population, struct parametres * p){
  float probabilite;
  //int longueurChaine = 0;
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

struct individu * voisinsAnneau(struct individu * population, struct parametres * p){
  for(int id = 0; id < p -> nbIndividus; id ++){
    int idInfectePrecedent = (id - 1 + p -> nbIndividus) % p -> nbIndividus;
    int idInfecteSuivant = (id + 1) % p -> nbIndividus;
    population[id].voisins = ajout(population[id].voisins, &population[idInfectePrecedent]);
    population[id].voisins = ajout(population[id].voisins, &population[idInfecteSuivant]);
    population[id].nbVoisins = longueurChaine(population[id].voisins);
  }
  return population;
}

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

/*
void resultatsFichierSortie(struct individu * population, struct parametres * p, int tempsSimu){
    FILE * fichier;
    fichier = fopen ("resultats.txt", "w")
    fprintf(fichier, "Tour %d : ", tempSimu);
    for(int i = 0; i < p->nbIndividus; i ++){
        if (population[i].etat == S)
            fprintf(fichier,"%dS ", i);
        else if (population[i].etat == I)
            fprintf(fichier, "%dI ", i);
        else
            fprintf(fichier, "%dR ", i);
    }
    printf("\n");
}
*/

void affiche(struct individu * population, struct parametres * p, int tempsSimu){
  printf("\n### ETAPE %d ###\n", tempsSimu);
  printf("Nb individus affiche : %d\n", p->nbIndividus);
  for(int i = 0; i < p->nbIndividus; i ++){
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
  printf("\n\n");
}

void libererListe(struct voisinage * voisins) {
  if (voisins -> voisinSuivant != NULL)
    libererListe(voisins -> voisinSuivant);
  voisins -> voisinSuivant = NULL;
  voisins -> voisinPrecedent = NULL;
  free(voisins);
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

struct individu * simulation(struct individu * population, struct parametres * p){
  int tempsSimu;
  for (tempsSimu = 0; tempsSimu < p->dureeMax; tempsSimu ++){
    affiche(population, p, tempsSimu);
    for(int id = 0; id < p->nbIndividus; id ++){
      if(population[id].contamine == 1){
	population = contamination(population, id);
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
  affiche(population, p, tempsSimu);
  liberer(population, p);
  return population;
}

/*
void openFile(char * fileName){
  FILE * fichier;
  fichier = fopen("fileName", "r");
  // A COMPLETER A L'OCCASION
  // char * a;
  // sscanf (a, "%d %d", &x, &y);
  // double b
  // sscanf (argv[i], "%ls", %d)
}*/

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
      p. tempsGuerison = atoi(argv[i]);
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
    /*if (strcmp(argv[i],"-sc") == 0){
      i++;
      p.seuilContamination = atoi(argv[i]);
      printf("le seuil de contamination a ete init a %d \n", p.seuilContamination);
    }*/
    if (strcmp(argv[i],"-p") == 0){
      i++;
      p.proba = atof(argv[i]);
      printf("la probabilite a été init %lf \n", p.proba);
    }
    if (strcmp(argv[i], "-f") == 0){
      i++;
      FILE * fichier = fopen(argv[i], "r");
      if (fichier == NULL)
        printf("Erreur ouverture fichier \n");
      p.fichier = fichier;
      printf("Le fichier de lecture a ete init \n");

    }
    if (strcmp(argv[i], "-c") == 0){
      i++;
      p.paramPrairie.dimPrairie = atoi(argv[i]);
      printf("la dimension de la prairie aleatoire a ete init %d \n", p.paramPrairie.dimPrairie);
    }
    if (strcmp(argv[i], "-rmax") == 0){
      i++;
      p.paramPrairie.rayonPrairieMax = atoi(argv[i]);
      printf("le rayon maximum de la prairie aleatoire a ete init %d \n", p.paramPrairie.rayonPrairieMax);
    }
    if (strcmp(argv[i], "-rmin") == 0){
      i++;
      p.paramPrairie.rayonPrairieMin = atoi(argv[i]);
      printf("le rayon minimum de la prairie aleatoire a ete init %d \n", p.paramPrairie.rayonPrairieMin);
    }
    if (strcmp(argv[i], "-k") == 0){
      i++;
      p.rebranchement = atoi(argv[i]);
      printf("le nombre de rebranchement a ete init %d \n", p.rebranchement);
    }
    if (strcmp(argv[i], "-probaI") == 0){
      i++;
      p.probaInfection = atof(argv[i]);
      printf("La proba d'infection a ete init %lf \n", p.probaInfection);
    }
  }
  struct individu * population;
  if (p.topologie == 4){
    FILE * fichier = fopen("facebook_combined.txt", "r");
    if (fichier == NULL)
      printf("Erreur ouverture fichier \n");
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
	 "\t -f pour rentrer un fichier qui contient la ligne de commande \n"
	 "\t -nb pour le nombre d'individus total \n"
	 "\t -nbi pour le nombre d'individus infectes \n"
	 "\t -i pour les individus infectés \n"
	 "\t -t pour le type de topologie \n"
	 "\t\t 1 clique \n"
	 "\t\t 2 anneaux \n"
	 "\t\t 3 Erdos-Renyis \n"
	 "\t\t 4 Lecture de fichier Stanford \n"
	 "\t\t 5 Prairie \n"
	 "\t attention a ne pas definir le nbIndividus infectes avant les individus infectes \n");
}


int main(int argc, char **argv) {
  srand(time(NULL));
  if (argc <= 1 || strcmp(argv[1],"-help") == 0 || strcmp(argv[1],"-h") == 0){
    aide();
  }
  /*else if (strcmp(argv[1],"-f") == 0)
    openFile(argv[2]);*/
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

// topologie 1 : clique
// topo 1, nb, nbi (i), dm, td, tg, sc, probaI

// topologie 2 : anneau 
// topo 2, nb, nbi (i), dm, td, tg, sc, probaI

// topologie 3 : Erdos-Renyi
// topo 3, nb, nbi (i), dm, td, tg, sc, probaI, proba

// topologie 4 : Chargement fichier, stanford
// topo 4, fichier, nbi (i), dm, td, tg, sc, probaI
// /!\ pas de nb a prendre en compte 

// topologie 5 : prairie aléatoire
//  topo 5, nb, nbi (i), dm, td, tg, sc, probaI, proba, c, rmax, rmin

// topologie 6 : small word / Watts-Strogatz 
//  topo 6, nb, nbi (i), dm, td, tg, sc, probaI, proba, k
