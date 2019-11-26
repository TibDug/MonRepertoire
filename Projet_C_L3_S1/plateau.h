#ifndef PATEA_H
#defin PATEAU_H

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
  
struct plateau * allouerPlateau(int, int);
struct plateau * initialiserTaille();
struct plateau * initialiserPlateau();
struct plateau * initialiserCasePlateau(struct plateau *, typeCase, couleurPiece, int, int);
struct plateau * initialiserPieces(struct plateau *);
void libererPlateau(struct plateau *);

#endi