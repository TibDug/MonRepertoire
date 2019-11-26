  #include <stdio.h> 
  #include <stdlib.h> 
  #include <math.h>
  #include <time.h>

      //////////TO DO LIST
      ///// coder le second joueur 
      
      ///// Decouper le code 
      ///// rearranger les fonctions, rendre le code plus propre 
      ///// indentation / mise en page emacs
      
      ///////Inscription projet 

  typedef enum {
    SOURIS,
    LION,
    ELEPHANT,
    VIDE
  } typeCase;

  typedef enum {
      NOIR,
      BLANC
  } couleurPiece;

  struct position {
      int x;
      int y;
  };

  struct Case {
      typeCase type;
      couleurPiece couleur;
      int pointEau;
      int effraye;
  };

  struct plateau {
      int hauteur;
      int largeur;
      struct Case ** contenu;
  };

  struct joueur {
      int identifiant;
      couleurPiece couleur;
      int nbPointEau;
      int tour;
      int ordi; 
  };
  
  // REGLES DU JEUX AFFICHEES
    void affichageRegles() {
      printf("REGLES DU BARCA \n \n Le Barca est un jeu à deux joueur. Il existe trois types de pieces ayant des deplacements strictes et representes par divers symboles tel que : \n - la souris : \n \t - deplacements : verticaux et horizontaux, \n \t - symbole : s, \n - le lion : \n \t - deplacements : diagonaux, \n \t - symbole : l, \n - l'elephant : \n \t - deplacements : verticaux, horizontaux, diagonaux, \n \t - symbole : e. \n \n L'objectif du jeu est qu'un joueur ai trois de ses pieces positionnees sur des points d'eau, representes par des * sur le plateau. \n Les cases vides sont representees par des . . \n Le joueur 1 dirige les pieces noires, representees en majuscules. Le joueur 2 dirige les pieces blanches, representees en minuscule. \n");
  }
  
  // INITIALISATION DU PLATEAU 
  
 struct plateau * allouerPlateau(int largeur, int hauteur) {
      struct plateau * plat;
      struct Case case1;
      int i;

      plat = malloc(sizeof(struct plateau));
      plat -> largeur = largeur;
      plat -> hauteur = hauteur;

      plat -> contenu = malloc(hauteur * sizeof(int * ));

      for (i = 0; i < hauteur; i++)
          plat -> contenu[i] = malloc(largeur * sizeof(case1));

      return plat;
  }
  
    struct plateau * initialiserTaille() {
      struct plateau * plat;
      int largeur, hauteur;

      do {
          printf("Choisissez une largeur paire et superieure ou egale a  8 pour le plateau : ");
          scanf("%d", & largeur);
          printf("\n");
          if (largeur % 2 != 0)
              printf("ERREUR : la largeur doit etre paire ! \n");
          if (largeur < 8)
              printf("ERREUR : la largeur doit superieure ou egale a  8 ! \n");
      } while (largeur % 2 != 0 && largeur < 8);

      do {
          printf("Choisissez une hauteur paire et superieure ou egale a  8 pour le plateau : ");
          scanf("%d", & hauteur);
          printf("\n");
          if (hauteur % 2 != 0)
              printf("ERREUR : la hauteur doit etre paire ! \n");
          if (hauteur < 8)
              printf("ERREUR : la hauteur doit superieure ou egale a  8 ! \n");
      } while (hauteur % 2 != 0 && hauteur < 8);

      plat = allouerPlateau(largeur, hauteur);

      return plat;
  }
  
  struct plateau * initialiserPlateau() { 
      struct plateau * plat = initialiserTaille();

      for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
              plat -> contenu[i][j].type = VIDE;
              plat -> contenu[i][j].effraye = 0;
              
              if (((i == (plat -> hauteur / 2) - 2) && (j == (plat -> largeur / 2) - 2)) || 
              ((i == (plat -> hauteur / 2) - 2) && (j == (plat -> largeur / 2) + 1)) || 
              ((i == (plat -> hauteur / 2) + 1) && (j == (plat -> largeur / 2) - 2)) || 
              ((i == (plat -> hauteur / 2) + 1) && (j == (plat -> largeur / 2) + 1)))
                  plat -> contenu[i][j].pointEau = 1;
              else
                  plat -> contenu[i][j].pointEau = 0;
          }
      }
      return plat;
  }
  
  
  // INITIALISER LES PIECES
  
    struct plateau * initialiserCasePlateau(struct plateau *plat, typeCase ty, couleurPiece co, int hauteurDepart, int largeurDepart) {
      plat -> contenu[hauteurDepart][largeurDepart].type = ty;
      plat -> contenu[hauteurDepart][largeurDepart].couleur = co;
      return plat;
  }
  
  struct plateau * initialiserPieces(struct plateau * plat) {  
      // souris noire 1
      initialiserCasePlateau(plat, SOURIS, NOIR, 1, (plat -> largeur / 2) - 1);

      // souris noire 2
      initialiserCasePlateau(plat, SOURIS, NOIR, 1, (plat -> largeur / 2));

      // lion noir 1
      initialiserCasePlateau(plat, LION, NOIR, 0, (plat -> largeur / 2) - 2);

      // lion noir 2
      initialiserCasePlateau(plat, LION, NOIR, 0, (plat -> largeur / 2) + 1);

      // elephant noir 1
      initialiserCasePlateau(plat, ELEPHANT, NOIR, 0, (plat -> largeur / 2) - 1);

      // elephant noir 2
      initialiserCasePlateau(plat, ELEPHANT, NOIR, 0, (plat -> largeur / 2));

      // souris blanche 1
      initialiserCasePlateau(plat, SOURIS, BLANC, plat -> hauteur - 2, (plat -> largeur / 2) - 1);

      // souris blanche 2
      initialiserCasePlateau(plat, SOURIS, BLANC, plat -> hauteur - 2, (plat -> largeur / 2));

      // lion blanc 1
      initialiserCasePlateau(plat, LION, BLANC, plat -> hauteur - 1, (plat -> largeur / 2) - 2);

      // lion blanc 2
      initialiserCasePlateau(plat, LION, BLANC, plat -> hauteur - 1, (plat -> largeur / 2) + 1);

      // elephant blanc 1
      initialiserCasePlateau(plat, ELEPHANT, BLANC, plat -> hauteur - 1, (plat -> largeur / 2) - 1);

      // elephant blanc 2
      initialiserCasePlateau(plat, ELEPHANT, BLANC, plat -> hauteur - 1, (plat -> largeur / 2));

      return plat;
  }
  
  // AFFICHAGE DU PLATEAU 
  
  int nbChiffres(int n) {

    int cpt = 0;

    if (n == 0)
	cpt++;

    while (n != 0) {
	cpt++;
	n = n / 10;
    }

    return cpt;
  }

  int inverserHauteur(int hauteur, int hauteurPlateau) {
	  return hauteurPlateau - hauteur - 1;
  }

  void afficherPlateau(struct plateau *plat) {
	for (int i = 0; i < plat -> hauteur; i++) {
		printf("     ");
		for (int j = 0; j < plat -> largeur; j++){
			printf("-----");
		}
		printf("\n");
		printf("  %d", inverserHauteur(i, plat -> hauteur));
        	int nbCaracteres = nbChiffres(inverserHauteur(i, plat -> hauteur));
        	while (nbCaracteres < 3) {
            		printf(" ");
            		nbCaracteres++;
        	}
		for (int j = 0; j < plat -> largeur; j++){
			if(plat -> contenu[i][j].pointEau == 1) {	
	  			switch (plat -> contenu[i][j].type) {
		      		case VIDE:
					printf("|( )|");
		          		break;
		      		case ELEPHANT:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("|(e)|");
		          		else printf("|(E)|");
		          		break;
		      		case LION:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("|(l)|");
		          		else printf("|(L)|");
		          		break;
		      		case SOURIS:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("|(s)|");
		          		else printf("|(S)|");
		          		break;
		      		}
			}
			else {
				switch (plat -> contenu[i][j].type) {
		      		case VIDE:
					printf("|   |");
		          		break;
		      		case ELEPHANT:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("| e |");
		          		else printf("| E |");
		          		break;
		      		case LION:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("| l |");
		          		else printf("| L |");
		          		break;
		      		case SOURIS:
		          		if (plat -> contenu[i][j].couleur == BLANC) printf("| s |");
		          		else printf("| S |");
		          		break;
		      		}
			}
		}
		printf("\n");
		printf("     ");
		for (int j = 0; j < plat -> largeur; j++){
			printf("-----");
		}
		printf("\n");
	}
	printf("     ");
	for (int j = 0; j < plat -> largeur; j++){
			printf("  %d", j);
			int nbCaracteres = nbChiffres(j);
        	while (nbCaracteres < 3) {
            		printf(" ");
            		nbCaracteres++;
          }
	}
	printf("\n");
  }

  // PROGRAMMATION DE LA PARTIE 

  // INITIALISATION DES JOUEURS 
    struct joueur initialiserJoueur(int id, couleurPiece cj, int tr, int ordinateur) {
      struct joueur j;

      //j.nom = nj;
      j.identifiant = id;
      j.couleur = cj;
      j.nbPointEau = 0;
      j.tour = tr;
      j.ordi = ordinateur;

      return j;
  }
  
  
  // PARAMETRAGE DES DEPLACEMENTS
  
    int dansPlateau(struct plateau * plat, int hauteurArr, int largeurArr) {
      if ((hauteurArr <= plat -> hauteur) && (largeurArr <= plat -> largeur) && (hauteurArr >= 0) && (largeurArr >= 0))
          return 1;
      return 0;
  }
    int caseVide(struct plateau * plat, int hauteur, int largeur) {
      if (plat -> contenu[hauteur][largeur].type == VIDE)
          return 1;
      return 0;
  }
    int memeCouleur(struct plateau * plat, struct joueur j, int hauteur, int largeur) {
      if (j.couleur == plat -> contenu[hauteur][largeur].couleur)
          return 1;
      return 0;
  }
    int deplacementLineaire(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      if ((hauteurDep == hauteurArr && largeurDep != largeurArr) || (hauteurDep != hauteurArr && largeurDep == largeurArr))
          return 1;
      return 0;
  }
  int deplacementDiagonal(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      if (fabs(hauteurDep - hauteurArr) == fabs(largeurDep - largeurArr))
          return 1;
      return 0;
  }

  int estEffrayee(struct plateau * plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      for (int i = hauteurArr - 1; i <= hauteurArr + 1; i++) {
          for (int j = largeurArr - 1; j <= largeurArr + 1; j++) {
              if ( i >= 0 && i < plat -> hauteur && j >= 0 && j < plat -> largeur) {
                  if (plat -> contenu[hauteurDep][largeurDep].couleur != plat -> contenu[i][j].couleur){
                      if (((plat -> contenu[hauteurDep][largeurDep].type == ELEPHANT) && (plat -> contenu[i][j].type == SOURIS)) ||
                      ((plat -> contenu[hauteurDep][largeurDep].type == SOURIS) && (plat -> contenu[i][j].type == LION)) ||
                      ((plat -> contenu[hauteurDep][largeurDep].type == LION) && (plat -> contenu[i][j].type == ELEPHANT))){
                          return 0;
                      }
                  }
              }
          }
      }
      return 1;
  }
  
        void effraie(struct plateau * plat, int hauteurArr, int largeurArr) {
      for (int i = hauteurArr - 1; i <= hauteurArr + 1; i++) {
          for (int j = largeurArr - 1; j <= largeurArr + 1; j++) {
              if ( i >= 0 && i < plat -> hauteur && j >= 0 && j < plat -> largeur) {
                 if (plat -> contenu[hauteurArr][largeurArr].couleur != plat -> contenu[i][j].couleur){
                  if (((plat -> contenu[hauteurArr][largeurArr].type == SOURIS) && (plat -> contenu[i][j].type == ELEPHANT)) ||
                      ((plat -> contenu[hauteurArr][largeurArr].type == LION) && (plat -> contenu[i][j].type == SOURIS)) ||
                      ((plat -> contenu[hauteurArr][largeurArr].type == ELEPHANT) && (plat -> contenu[i][j].type == LION))){
                      plat -> contenu[i][j].effraye = 1;
                      }
                  }
              }
          }
      }
  }
  
        void sontEffrayees(struct plateau *plat, struct joueur joue){
      for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
              if (plat -> contenu[i][j].effraye == 1 && plat -> contenu[i][j].couleur == joue.couleur){
                  printf("La piece : (%d;%d) est effrayee \n", j, inverserHauteur(i, plat -> hauteur));
              }
          }
      }
  }
  
    int aDeplacer(struct plateau * plat, struct joueur joue, int hauteurDep, int largeurDep) {
      if (plat -> contenu[hauteurDep][largeurDep].effraye == 1)
          return 1;
      for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
              if ((plat -> contenu[i][j].effraye == 1) && (plat -> contenu[i][j].couleur == joue.couleur))
                  return 0;
          }
      }
      return 1;
  }
  
  int deplacementPossible(struct plateau * plat, struct joueur j, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      if (dansPlateau(plat, hauteurDep, largeurDep)) {
          if (dansPlateau(plat, hauteurArr, largeurArr)) {
              if (!caseVide(plat, hauteurDep, largeurDep)) {
                  if (caseVide(plat, hauteurArr, largeurArr)) {
                      if (memeCouleur(plat, j, hauteurDep, largeurDep)) {
                          if ((plat -> contenu[hauteurDep][largeurDep].type == SOURIS && deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                              (plat -> contenu[hauteurDep][largeurDep].type == LION && deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                              (plat -> contenu[hauteurDep][largeurDep].type == ELEPHANT && (deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr) ||
                                  deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)))) {
                              if (estEffrayee(plat, hauteurDep, largeurDep, hauteurArr, largeurArr)) {
                                  if (aDeplacer(plat, j, hauteurDep, largeurDep)) {
                                      return 1;
                                  }
                                  printf("ERREUR : Vous devez bouger une piece effrayee. \n");
                                  return 0;
                              }
                              printf("ERREUR : La piece est effrayee par une autre piece. \n");
                              return 0;
                          }
                          printf("ERREUR : Le deplacement ne correspondont pas au type de la piece. \n");
                          return 0;
                      }
                      printf("ERREUR : Cette piece ne vous appartient pas. \n");
                      return 0;
                  }
                  printf("ERREUR : La case d'arrivee n'est pas disponible. \n");
                  return 0;
              }
              printf("ERREUR : La case de depart ne correspond pas à une piece. \n");
              return 0;
          }
          printf("ERREUR : La position d'arrivee n'est pas dans les dimensions du plateau. \n");
          return 0;
      }
      printf("ERREUR : La position de départ n'est pas dans les dimensions du plateau. \n");
      return 0;
  }
  
  int deplacementPossibleSansTexte(struct plateau * plat, struct joueur j, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      if (dansPlateau(plat, hauteurDep, largeurDep)) {
          if (dansPlateau(plat, hauteurArr, largeurArr)) {
              if (!caseVide(plat, hauteurDep, largeurDep)) {
                  if (caseVide(plat, hauteurArr, largeurArr)) {
                      if (memeCouleur(plat, j, hauteurDep, largeurDep)) {
                          if ((plat -> contenu[hauteurDep][largeurDep].type == SOURIS && deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                              (plat -> contenu[hauteurDep][largeurDep].type == LION && deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
                              (plat -> contenu[hauteurDep][largeurDep].type == ELEPHANT && (deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr) ||
                                  deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)))) {
                              if (estEffrayee(plat, hauteurDep, largeurDep, hauteurArr, largeurArr)) {
                                  if (aDeplacer(plat, j, hauteurDep, largeurDep)) {
                                      return 1;
                                  }
                                  return 0;
                              }
                              return 0;
                          }
                          return 0;
                      }
                      return 0;
                  }
                  return 0;
              }
              return 0;
          }
          return 0;
      }
      return 0;
  }
  
    void deplacement(struct plateau *plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      plat -> contenu[hauteurArr][largeurArr].type = plat -> contenu[hauteurDep][largeurDep].type;
      plat -> contenu[hauteurArr][largeurArr].couleur = plat -> contenu[hauteurDep][largeurDep].couleur;
      plat -> contenu[hauteurArr][largeurArr].effraye = 0;

      plat -> contenu[hauteurDep][largeurDep].type = VIDE;
      plat -> contenu[hauteurDep][largeurDep].effraye = 0;
          
      effraie(plat, hauteurArr, largeurArr);
  }
  
  
     void coordonneesOrdi(struct plateau *plat, struct joueur joue){
	  int tabHaut[6], tabLarg[6], flag = 0, cpt = 0, indiceAleatoire,  hauteurDep, largeurDep, hauteurArr, largeurArr;
	  
	  for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
			      if (plat -> contenu[i][j].type != VIDE && plat -> contenu[i][j].couleur == joue.couleur && plat -> contenu[i][j].effraye == 1){
			          hauteurDep = i;
			          largeurDep = j;
			          flag = 1;
			          printf("Je suis passé par là ! \n");
			      }
			    }
	    }
	    if (flag == 0) {
	    
	      for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
			      if (plat -> contenu[i][j].type != VIDE && plat -> contenu[i][j].couleur == joue.couleur){
			          tabHaut[cpt] = i; printf("%d\n \n", tabHaut[cpt]);
			          tabLarg[cpt] = j; printf("%d\n \n", tabLarg[cpt]);
			          cpt++;
			          printf("la compteur : %d \n\n", cpt);
			      }
			    }
	      }
	      indiceAleatoire = rand() % 6;
	      hauteurDep = tabHaut[indiceAleatoire];
	      printf("HauteurDep : %d \n \n ", hauteurDep);
	      largeurDep = tabLarg[indiceAleatoire];
	      printf("largeurDep : %d \n \n ", largeurDep);
	    }
	    do{
	    hauteurArr = rand() % plat -> hauteur;
	          printf("HauteurArr: %d \n \n ", hauteurDep);
	    largeurArr = rand() % plat -> largeur;
	    	      printf("largeurArr : %d \n \n ", largeurDep);
	    
	    
	    }while (deplacementPossibleSansTexte(plat, joue, hauteurDep, largeurDep, hauteurArr, largeurArr) == 0);
	    
	    deplacement(plat, hauteurDep, largeurDep, hauteurArr, largeurArr);
	    
	    }
  
void coordonneesHumain(struct plateau *plat, struct joueur j){
  int hauteurDep, largeurDep, hauteurArr, largeurArr;
      do {
          printf("Quelle piece voulez vous deplacer ? (x y)\n");
          scanf("%d", & largeurDep);
          scanf("%d", & hauteurDep);
          hauteurDep = inverserHauteur(hauteurDep, plat -> hauteur);

          printf("Ou voulez vous la placer ? (x y) \n");
          scanf("%d", & largeurArr);
          scanf("%d", & hauteurArr);
          hauteurArr = inverserHauteur(hauteurArr, plat -> hauteur);
          
      } while (deplacementPossible(plat, j, hauteurDep, largeurDep, hauteurArr, largeurArr) == 0);
      deplacement(plat, hauteurDep, largeurDep, hauteurArr, largeurArr);
      
}


  // FIN DE LA PARTIE 
  
  struct joueur calculPointEau(struct plateau *plat, struct joueur joue) {
      joue.nbPointEau = 0;
      for (int i = 0; i < plat -> hauteur; i++) {
          for (int j = 0; j < plat -> largeur; j++) {
              if (plat -> contenu[i][j].pointEau == 1 && plat -> contenu[i][j].type != VIDE && plat -> contenu[i][j].couleur == joue.couleur)
                  joue.nbPointEau++;
          }
      }
      return joue;
  }
  

  int partieTerminee(struct joueur j1, struct joueur j2) {
      if (j1.nbPointEau >= 3 || j2.nbPointEau >= 3)
          return 1;
      return 0;
  }

  int gagnant(struct joueur j1, struct joueur j2) {
      if (j1.nbPointEau == 3)
          return j1.identifiant;
      else
          return j2.identifiant;
  }

  void felicitations(int joueur) {
      printf("Feliciations joueur %d ! Vous avez gagne ! \n\n", joueur);
  }

  /*
  int nomJoueur(char couleur){
   printf("Quel est le nom du joueur %c ? \n");
   scanf("%c", &nom);
   return nom;
  }
  */
  
  // PARAMETRAGE DE LA PARTIE ET DES TOURS 
  
  struct joueur tourDe(struct joueur j1, struct joueur j2) {
      if (j1.tour == 1) {
          printf("Au tour du joueur %d, qui controle les pieces noires (majuscule) \n\n", j1.identifiant);
          return j1;
      } else {
          printf("Au tour du joueur %d, qui controle les pieces blanches (miniscules) \n\n", j2.identifiant);
          return j2;
      }
  }

  struct joueur changementTour(struct joueur j) {
      if (j.tour == 1)
          j.tour = 0;
      else
          j.tour = 1;
      return j;
  }
  
  

  void partie(struct plateau * plat) {
      int nbJoue;
      struct joueur joueurNoir;
      struct joueur joueurBlanc;
      struct joueur joueurActuel;
      
      do{
        printf("Partie a 1 ou deux joueurs ?\n");
        scanf("%d", &nbJoue);
        if (nbJoue != 1 && nbJoue != 2) {
          printf("Le nombre de joueurs doit être 1 ou 2 ! \n"); 
        }
      } while (nbJoue != 1 && nbJoue != 2);
      
      if (nbJoue == 1) {
        joueurNoir = initialiserJoueur(1, NOIR, 0, 1);
      }
      else {
        joueurNoir = initialiserJoueur(1, NOIR, 0, 0);
      }
        
      joueurBlanc = initialiserJoueur(2, BLANC, 1, 0);
      
      afficherPlateau(plat);

      do {
          joueurActuel = tourDe(joueurNoir, joueurBlanc);
          sontEffrayees(plat, joueurActuel);
          if (joueurActuel.ordi == 0)
            coordonneesHumain(plat, joueurActuel);
          else
            coordonneesOrdi(plat, joueurActuel);
            
          afficherPlateau(plat);
          joueurNoir = changementTour(joueurNoir);
          joueurBlanc = changementTour(joueurBlanc);
          joueurNoir = calculPointEau(plat, joueurNoir);
          joueurBlanc = calculPointEau(plat, joueurBlanc);
      } while (!partieTerminee(joueurNoir, joueurBlanc));

      felicitations(gagnant(joueurNoir, joueurBlanc));
  }

  void libererPlateau(struct plateau * plat) {
      int i;
      for (i = 0; i < plat -> hauteur; i++)
          free(plat -> contenu[i]);
      free(plat -> contenu[i]);
      free(plat);
  }
  

  int main() {
      srand(time(NULL));
      affichageRegles();
      struct plateau * plat = initialiserPlateau();
      initialiserPieces(plat);
      partie(plat);
      libererPlateau(plat);
      return 0;
  }
