  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  
  
  //////////TO DO LIST
  ///// coder le second joueur 
  ///// coder la fin de la partie 
  ///// vérifier si 3 points d'eau sont non vides par une meme couleur 
  ///// vérifier si la hauteurDep et largeurDep == non vide 
  ///// vérifier si la hauteurDep et largeurDep == piece de la couleur du joueur 
  ///// fonction : tel joueur a acces a telle piece 
  
  typedef enum {SOURIS, LION, ELEPHANT, VIDE} typeCase;
  
  typedef enum {NOIR, BLANC} couleurPiece;
  
  typedef enum {S, L, E, s, l, e} caracterePiece;
  
  struct position {
      int x;
      int y;
  };
  
  struct Case {
      typeCase type;
      couleurPiece couleur;
      caracterePiece caractere;
      int pointEau;
      int effraye;
  };
  
  struct plateau {
      int hauteur;
      int largeur;
      struct Case **contenu;
  };
  
  struct plateau *initialiserCasePlateau(struct plateau *plat, typeCase ty, couleurPiece co, caracterePiece cp, int hauteurDepart, int largeurDepart){
      plat->contenu[hauteurDepart][largeurDepart].type = ty;
      plat->contenu[hauteurDepart][largeurDepart].couleur = co;
      plat->contenu[hauteurDepart][largeurDepart].caractere = cp;
     
      return plat;
  }
  
  void afficherPlateau (struct plateau *plat){
      for (int i = 0; i < plat-> hauteur; i++){
        for (int j = 0; j < plat-> largeur; j++){
          if(plat->contenu[i][j].type == VIDE)
            printf(".");
          if(plat->contenu[i][j].type == LION)
            printf("l");
          if(plat->contenu[i][j].type == ELEPHANT)
            printf("e");
          if(plat->contenu[i][j].type == SOURIS)
            printf("s");
        
        
        
        /*
    	    switch (plat->contenu[i][j].type) {
    	    
    	    case VIDE : printf("."); break;
    	    case ELEPHANT : if (plat->contenu[i][j].couleur == BLANC) printf("e"); else printf("E"); break;
    	    case LION : if (plat->contenu[i][j].couleur == BLANC) printf("l"); else printf("L"); break;
    	    case SOURIS : if (plat->contenu[i][j].couleur == BLANC) printf("s"); else printf("S"); break;
    	    default : printf("."); break;
    	    
    	    */ 
    	    //}
  	   }
    	printf("\n");
     }
  }
  
  struct plateau *initialiserPieces(struct plateau *plat) { // j'ai modifie la fonction en rajoutant un return plat pour correspondre 
      // souris noire 1
      initialiserCasePlateau(plat, SOURIS, NOIR, S, 1, (plat->largeur / 2));
      afficherPlateau (plat);
      printf("\n");
      
      // souris noire 2
      initialiserCasePlateau(plat, SOURIS, NOIR, S, 1, (plat->largeur / 2) + 1);
      afficherPlateau (plat);
      printf("\n");
      
      // lion noir 1
      initialiserCasePlateau(plat, LION, NOIR, L, 0, (plat->largeur / 2) - 1);
      afficherPlateau (plat);
      printf("\n");
      
      // lion noir 2
      initialiserCasePlateau(plat, LION, NOIR, L, 0, (plat->largeur / 2) + 2);
      afficherPlateau (plat);
      printf("\n");
      
      // elephant noir 1
      initialiserCasePlateau(plat, ELEPHANT, NOIR, E, 0, (plat->largeur / 2));
      afficherPlateau (plat);
      printf("\n");
      
      // elephant noir 2
      initialiserCasePlateau(plat, ELEPHANT, NOIR, E, 0, (plat->largeur / 2) + 1);
      afficherPlateau (plat);
      printf("\n");
      
      
      // souris blanche 1
      initialiserCasePlateau(plat, SOURIS, BLANC, S, plat->hauteur - 2, (plat->largeur / 2));
      afficherPlateau (plat);
      printf("\n");
      
      // souris blanche 2
      initialiserCasePlateau(plat, SOURIS, BLANC, S, plat->hauteur - 2, (plat->largeur / 2) + 1);
      afficherPlateau (plat);
      printf("\n");
      
      // lion blanc 1
      initialiserCasePlateau(plat, LION, BLANC, L, plat->hauteur -  1, (plat->largeur / 2) - 1);
      afficherPlateau (plat);
      printf("\n");
      
      // lion blanc 2
      initialiserCasePlateau(plat, LION, BLANC, L, plat->hauteur - 1, (plat->largeur / 2) + 2);
      afficherPlateau (plat);
      printf("\n");
      
      // elephant blanc 1
      initialiserCasePlateau(plat, ELEPHANT, BLANC, E, plat->hauteur - 1, (plat->largeur / 2));
      afficherPlateau (plat);
      printf("\n");
      
      // elephant blanc 2
      initialiserCasePlateau(plat, ELEPHANT, BLANC, E, plat->hauteur - 1, (plat->largeur / 2) + 1);
      afficherPlateau (plat);
      printf("\n");
      
      return plat;
  }
  
  struct plateau *allouerPlateau(int largeur, int hauteur) {
      struct plateau *plat;
      int i;
  
      plat = malloc (sizeof(struct plateau));
      plat->largeur = largeur;
      plat->hauteur = hauteur;
      
      plat->contenu = malloc(hauteur * sizeof(int *));
  
      for (i = 0; i < hauteur; i++)
  	    plat->contenu[i] = malloc(largeur * sizeof(int));
  
      return plat;
  }
  
  struct plateau *initialiserTaille() {
      struct plateau *plat;
      int largeur, hauteur;
  	
      do {
  	printf("Choisissez une largeur paire et supÃ©rieure ou Ã©gale Ã  8 pour le plateau : "); 
  	scanf("%d", &largeur);
  	printf("\n");
  	if (largeur % 2 != 0)
  	    printf("ERREUR : la largeur doit Ãªtre paire ! \n");
  	if (largeur < 8)
  	    printf("ERREUR : la largeur doit Ãªtre supÃ©rieure ou Ã©gale Ã  8 ! \n");
      } while(largeur % 2 != 0 && largeur < 8);
  
      do {
  	printf("Choisissez une hauteur paire et supÃ©rieure ou Ã©gale Ã  8 pour le plateau : "); 
  	scanf("%d", &hauteur);
  	printf("\n");
  	if (hauteur % 2 != 0)
  	    printf("ERREUR : la hauteur doit Ãªtre paire ! \n");
  	if (hauteur < 8)
  	    printf("ERREUR : la hauteur doit Ãªtre supÃ©rieure ou Ã©gale Ã  8 ! \n");
      } while(hauteur % 2 != 0 && hauteur < 8);
  
      plat = allouerPlateau(largeur, hauteur);
  
      return plat;
  }
  
  struct plateau *initialiserPlateau() { //// La fonction est passee en void /// ou alors faut return le plat jsp...
      struct plateau *plat = initialiserTaille();
      
      for(int i = 0; i < plat->hauteur; i++) {
  	    for(int j = 0; j < plat->largeur; j++) {
  	       plat->contenu[i][j].type = VIDE;
  	       plat->contenu[i][j].effraye = 0;
  	       /*if((((i == plat->hauteur / 2 - 1) && (j == plat->largeur / 2) - 1)) ||
  	          ((i == plat->hauteur / 2 - 1) && (j == plat->largeur / 2 + 2)) ||
  	          ((i == (plat->hauteur / 2 + 2) && (j == plat->largeur / 2 - 1)) ||
  	        	((i == plat->hauteur / 2 + 2) && (j == plat->largeur / 2 + 2))))
  		        plat->contenu[i][j].pointEau = 1;
  	      else
  		        plat->contenu[i][j].pointEau = 0; */
  	    }
      }
      afficherPlateau (plat);
      printf("\n");
      
      return plat;
  }
  
  int nonEffrayee(struct plateau *plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){ // J'i modifie la logique de la fonction pour retourner les pieces non effrayees (plus pratique dans deplacementPossible)
      for (int i = hauteurArr - 1; i <= hauteurArr + 1; i ++){
  	for (int j = largeurArr - 1; j <= largeurArr + 1; j ++){
  	    if ((plat->contenu[hauteurDep][largeurDep].type == ELEPHANT && plat->contenu[i][j].type != SOURIS) ||
  		(plat->contenu[hauteurDep][largeurDep].type == SOURIS && plat->contenu[i][j].type != LION) ||
  		(plat->contenu[hauteurDep][largeurDep].type == LION && plat->contenu[i][j].type != ELEPHANT))
  		return 1;
  	}
      }
      return 0;
  }
  
  int effraie(struct plateau *plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
      for (int i = hauteurArr - 1; i <= hauteurArr + 1; i ++){
  	for (int j = largeurArr - 1; j <= largeurArr + 1; j ++){
  	    if ((plat->contenu[hauteurDep][largeurDep].type == SOURIS && plat->contenu[i][j].type == ELEPHANT) ||
  		(plat->contenu[hauteurDep][largeurDep].type == LION && plat->contenu[i][j].type == SOURIS) ||
  		(plat->contenu[hauteurDep][largeurDep].type == ELEPHANT && plat->contenu[i][j].type == LION))
  		plat->contenu[i][j].effraye = 1;
  	}
      }
      return 0;
      /// Il faut pouvoir retourner les positions des pieces effrayes pour ne pas avoir a lire tout le plateau 
      /// 
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////////
  // FAIRE FONCTION QUI PERMET DE PARCOURIR LE PLATEAU ET QUI RENVOIT LES PIECES EFFRAYEES //
  ///////////////////////////////////////////////////////////////////////////////////////////
  
  
  int caseDisponible(struct plateau *plat, int hauteurArr, int largeurArr){
      if (plat->contenu[hauteurArr][largeurArr].type == VIDE)
  	return 1;
      return 0;
  }
  
  /*
    int verificationEffraiement(struct plateau *plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
    if (estEffrayee(plat, hauteurDep, largeurDep, hauteurArr, largeurArr)){
    printf("Vous ne pouvez pas poser ce pion, il est effraye ! \n");
    return 1;
    }
    return 0;
    }
  */
  
  int dansPlateau(struct plateau *plat, int hauteurArr, int largeurArr) {
      if ((hauteurArr <= plat->hauteur) && (largeurArr <= plat->largeur) && (hauteurArr >= 0) && (largeurArr >= 0))
  	return 1;
      return 0;
  }
  
  int deplacementLineaire(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
      if ((hauteurDep == hauteurArr && largeurDep != largeurArr) || (hauteurDep != hauteurArr && largeurDep == largeurArr))
  	return 1;
      return 0;
  }
  
  int deplacementDiagonal(int hauteurDep, int largeurDep, int hauteurArr, int largeurArr){
      if (fabs(hauteurDep - hauteurArr) == fabs(largeurDep - largeurArr))
  	return 1;
      return 0;
  }
  
  int deplacementPossible(struct plateau *plat, int hauteurDep, int largeurDep, int hauteurArr, int largeurArr) {
      if (dansPlateau(plat, hauteurArr, largeurArr)){
  	if ((plat->contenu[hauteurArr][largeurArr].type == SOURIS && deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
  	    (plat->contenu[hauteurArr][largeurArr].type == LION && deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)) ||
  	    (plat->contenu[hauteurArr][largeurArr].type == ELEPHANT && (deplacementLineaire(hauteurDep, largeurDep, hauteurArr, largeurArr) || deplacementDiagonal(hauteurDep, largeurDep, hauteurArr, largeurArr)))){
  	    if(caseDisponible(plat, hauteurArr, largeurArr)){
  		if(nonEffrayee(plat, hauteurDep, largeurDep, hauteurArr, largeurArr)){
  		    return 1;
  		}
  		printf("La piece est effrayee par une autre piece. \n");
  		return 0;
  	    }
  	    printf("La case n'est pas disponible. \n");
  	    return 0;
  	}
  	printf("Le deplacement ne correspondont pas au type de la piece. \n");
  	return 0;
      }
      printf("La position d'arrivee n'est pas dans les dimensions du plateau. \n");
      return 0;
  }
  
  void deplacement (struct plateau *plat){
      int hauteurDep, largeurDep, hauteurArr, largeurArr, i=0;
      printf("Quelle piece voulez vous deplacer ? (x y)\n");
      scanf("%d", &hauteurDep);
      scanf("%d", &largeurDep);
      printf("Ou voulez vous la placer ? (x y) \n");
      scanf("%d", &hauteurArr);
      scanf("%d", &largeurArr);
  
  	do{
    deplacementPossible(plat, hauteurDep, largeurDep, hauteurArr, largeurArr);
    printf("Ou voulez vous la placer ? (x y) \n");
      scanf("%d", &hauteurArr);
      scanf("%d", &largeurArr);
    i++; // J’ai rajoute la condition du i pour que la personne ne joue pas trop longtemps mais jsp comment ca sera gerre
  
  	} while (deplacementPossible(plat, hauteurDep, largeurDep, hauteurArr, largeurArr) == 0 && i <= 10);
  	
    plat->contenu[hauteurArr][largeurArr].type = plat->contenu[hauteurDep][largeurDep].type;
  	plat->contenu[hauteurArr][largeurArr].couleur = plat->contenu[hauteurDep][largeurDep].couleur;
    plat->contenu[hauteurArr][largeurArr].caractere = plat->contenu[hauteurDep][largeurDep].caractere;
  	plat->contenu[hauteurArr][largeurArr].effraye = 0;
  	
  }

  
  
  void libererPlateau(struct plateau *plat) {
      int i;
      for(i = 0; i < plat->hauteur; i++)
  	free(plat->contenu[i]);
      free(plat->contenu[i]);
      free(plat);
  }
      
  
  int main(){
      struct plateau *plat = initialiserPlateau();
      initialiserPieces(plat);
      afficherPlateau (plat);
      //deplacement(plat); 
      libererPlateau(plat);
      return 0;
  }
  
  

