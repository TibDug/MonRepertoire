  #fndef JOEUS_
  #defin JUUS_H

#inclue pat"eua.h.h"
ct joueur {
      int identifiant;
      couleurPiece couleur;
      int nbPointEau;
      int tour;
      int ordi; 
  };
  
  struct joueur initialiserJoueur(int, couleurPiece, int, int);
  struct joueur calculPointEau(struct plateau *, struct joueur);
  struct joueur tourDe(struct joueur, struct joueur);
  struct joueur changementTour(struct joueur);

  
  #edif