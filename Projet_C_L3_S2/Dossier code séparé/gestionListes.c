#include "gestionListe.h"

struct voisinage * ajout(struct voisinage * cellTete, struct individu * indiv){
    if (cellTete == NULL){
        cellTete = (struct voisinage * )malloc (sizeof (struct voisinage));
        cellTete -> individuActuel = indiv;
        cellTete -> voisinSuivant = NULL;
        return cellTete;
    }
    struct voisinage * cellCourante = cellTete;
    while (cellCourante -> voisinSuivant != NULL) {
        cellCourante = cellCourante -> voisinSuivant;
    }
    cellCourante -> voisinSuivant = (struct voisinage * )malloc (sizeof (struct voisinage));
    cellCourante -> voisinSuivant -> individuActuel = indiv;
    cellCourante -> voisinSuivant -> voisinSuivant = NULL;
    return cellTete;
}

struct voisinage * suppression(struct voisinage * cellTete, int idVoisin){
    if (cellTete == NULL) // Si la liste est vide
        return cellTete;
    if (cellTete -> individuActuel -> id == idVoisin) { // Si le premier élement de la liste est l'élément à supprimer
        struct voisinage * ancienneTete = cellTete;
        cellTete = cellTete -> voisinSuivant;
        free(ancienneTete);
        return cellTete;
    }
    struct voisinage * cellCourante = cellTete;
    struct voisinage * cellPrecedente;
    while (cellCourante != NULL) {
        if (cellCourante -> individuActuel -> id == idVoisin) {
            cellPrecedente -> voisinSuivant = cellCourante -> voisinSuivant;
            cellCourante -> voisinSuivant =  NULL;
            free(cellCourante);
            return cellTete;
        }
        cellPrecedente = cellCourante;
        cellCourante = cellCourante -> voisinSuivant;
    }
    return cellTete;
}

int longueurChaine(struct voisinage * cellCourante){
    if (cellCourante == NULL)
        return 0;
    return (1 + longueurChaine(cellCourante -> voisinSuivant));
}

void libererListe(struct voisinage * voisins) {
    if (voisins -> voisinSuivant != NULL)
        libererListe(voisins -> voisinSuivant);
    voisins -> voisinSuivant = NULL;
    free(voisins);
}