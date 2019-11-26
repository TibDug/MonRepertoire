#ifndef GESTIONLISTES_H
#define GESTIONLISTES_H

struct voisinage * ajout(struct voisinage *, struct individu *);
struct voisinage * suppression(struct voisinage *, int);
int longueurChaine(struct voisinage *);
void libererListe(struct voisinage *);

#endif