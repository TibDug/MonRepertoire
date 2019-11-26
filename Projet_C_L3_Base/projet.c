#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>

int presentUn(double tabNotes[], int n) {

    int cpt = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotes[i] >= 0) {
            cpt++;
        }
    }

    return cpt;
}

int presentDeux(double tabNotes1[], double tabNotes2[], int n) {

    int cpt = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotes1[i] >= 0 && tabNotes2[i] >= 0) {
            cpt++;
        }
    }

    return cpt;
}

double moyPresentUn(double tabNotes[], int n) {

    double somme = 0;
    int presents = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotes[i] >= 0) {
            somme += tabNotes[i];
            presents++;
        }
    }

    return somme / presents;
}

double moyPresentDeux(double tabNotePourMoyenne[], double tabComparaison[], int n) {

    double somme = 0;
    int presents = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotePourMoyenne[i] >= 0 && tabComparaison[i] >= 0) {
            somme += tabNotePourMoyenne[i];
            presents++;
        }
    }

    return somme / presents;
}

void triSelection(double tab[], int n) {
    int min = 0;
    double tmp = 0;

    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[min])
                min = j;
        }
        if (min != i) {
            tmp = tab[min];
            tab[min] = tab[i];
            tab[i] = tmp;
        }
    }
}

double mediane(double tabNotePourMediane[], double tabComparaison[], int n, int etuAssidus) {

    double tabNotePourMedianeTrie[etuAssidus];
    double mediane = 0;
    int indiceMediane = 0;
    int compteur = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotePourMediane[i] >= 0 && tabComparaison[i] >= 0) {
            tabNotePourMedianeTrie[compteur] = tabNotePourMediane[i];
            compteur++;
            if (compteur == (etuAssidus / 2))
                indiceMediane = i;
        }
    }

    triSelection(tabNotePourMedianeTrie, etuAssidus);

    mediane = tabNotePourMedianeTrie[indiceMediane];

    return mediane;
}

double pearson(double tabNotes1[], double tabNotes2[], int n, double moyTab1, double moyTab2) {

    double varianceTab1 = 0;
    double varianceTab2 = 0;
    int etuPresents = 0;
    double ecartTypeTab1 = 0;
    double ecartTypeTab2 = 0;
    double covariance = 0;
    double coeffCor = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotes1[i] >= 0 && tabNotes2[i] >= 0) {
            varianceTab1 += (tabNotes1[i] - moyTab1) * (tabNotes1[i] - moyTab1);
            varianceTab2 += (tabNotes2[i] - moyTab2) * (tabNotes2[i] - moyTab2);
            covariance += (tabNotes1[i] - moyTab1) * (tabNotes2[i] - moyTab2);
            etuPresents++;
        }
    }

    varianceTab1 = varianceTab1 / etuPresents;
    printf("La variance obtenue pour le premier controle est egale a %.2lf .\n", varianceTab1);
    varianceTab2 = varianceTab2 / etuPresents;
    printf("La variance obtenue pour le deuxieme controle est egale a %.2lf .\n", varianceTab2);
    printf("\n");

    ecartTypeTab1 = sqrt(varianceTab1);
    printf("L'ecart type du premier controle est egal a %.2lf .\n", ecartTypeTab1);
    ecartTypeTab2 = sqrt(varianceTab2);
    printf("L'ecart type du deuxieme controle est egal a %.2lf .\n", ecartTypeTab2);
    printf("\n");

    covariance = covariance / etuPresents;
    printf("La covariance du premier et du deuxieme controle est egale a %.2lf .\n", covariance);
    printf("\n");

    coeffCor = covariance / (ecartTypeTab1 * ecartTypeTab2);

    return coeffCor;
}

int quintile(double tabNotePourQuintile[], double tabComparaison[], int n, int borneInf, int borneSup) {

    int nbEtu = 0;

    for (int i = 0; i < n; i++) {
        if (tabNotePourQuintile[i] >= 0 && tabComparaison[i] >= 0 && tabNotePourQuintile[i] >= borneInf && tabNotePourQuintile[i] < borneSup) {
            nbEtu++;
        }
    }

    return nbEtu;
}

int maxQuintile(int quintile1, int quintile2, int quintile3, int quintile4, int quintile5) {

    int tabQuintiles[5] = {
        quintile1,
        quintile2,
        quintile3,
        quintile4,
        quintile5
    };
    int max = tabQuintiles[0];

    for (int i = 1; i < 5; i++) {
        if (tabQuintiles[i] > max) {
            max = tabQuintiles[i];
        }
    }

    return max;
}

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

void histogramme(int valeur1, int valeur2, int valeur3, int valeur4, int valeur5, int valeurMax) {

    int tailleHisto = valeurMax;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

    for (int i = 0; i <= tailleHisto + 1; i++) {

        int nbEspaces = nbChiffres(tailleHisto - i);
        while (nbEspaces <= nbChiffres(tailleHisto)) {
            printf(" ");
            nbEspaces++;
        }

        if (i == tailleHisto + 1) {
            printf("  0         4         8         12        16      20");
        } else if (i == tailleHisto) {

            printf("%d", tailleHisto - i);
            printf("|");

            if (i == (tailleHisto - valeur1)) {
                printf("====Q1====");
                flag1 = 1;
            } else if (flag1 == 1)
                printf("|________|");
            else
                printf("__________");

            if (i == (tailleHisto - valeur2)) {
                printf("====Q2====");
                flag2 = 1;
            } else if (flag2 == 1)
                printf("|________|");
            else
                printf("__________");

            if (i == (tailleHisto - valeur3)) {
                printf("====Q3====");
                flag3 = 1;
            } else if (flag3 == 1)
                printf("|________|");
            else
                printf("__________");

            if (i == (tailleHisto - valeur4)) {
                printf("====Q4====");
                flag4 = 1;
            } else if (flag4 == 1)
                printf("|________|");
            else
                printf("__________");

            if (i == (tailleHisto - valeur5)) {
                printf("====Q5====");
                flag5 = 1;
            } else if (flag5 == 1)
                printf("|________|");
            else
                printf("__________");

            printf("|\n");

        } else {

            printf("%d", tailleHisto - i);
            printf("|");

            if (i == (tailleHisto - valeur1)) {
                printf("====Q1====");
                flag1 = 1;
            } else if (flag1 == 1)
                printf("|        |");
            else
                printf("          ");

            if (i == (tailleHisto - valeur2)) {
                printf("====Q2====");
                flag2 = 1;
            } else if (flag2 == 1)
                printf("|        |");
            else
                printf("          ");

            if (i == (tailleHisto - valeur3)) {
                printf("====Q3====");
                flag3 = 1;
            } else if (flag3 == 1)
                printf("|        |");
            else
                printf("          ");

            if (i == (tailleHisto - valeur4)) {
                printf("====Q4====");
                flag4 = 1;
            } else if (flag4 == 1)
                printf("|        |");
            else
                printf("          ");

            if (i == (tailleHisto - valeur5)) {
                printf("====Q5====");
                flag5 = 1;
            } else if (flag5 == 1)
                printf("|        |");
            else
                printf("          ");

            printf("|\n");

        }
    }
}

void histogrammePourcentage(double valeur1, double valeur2, double valeur3, double valeur4, double valeur5, double effectif) {

    double pourcentage1 = 0, pourcentage2 = 0, pourcentage3 = 0, pourcentage4 = 0, pourcentage5 = 0;

    pourcentage1 = (valeur1 / effectif) * 100;
    pourcentage2 = (valeur2 / effectif) * 100;
    pourcentage3 = (valeur3 / effectif) * 100;
    pourcentage4 = (valeur4 / effectif) * 100;
    pourcentage5 = (valeur5 / effectif) * 100;

    histogramme(pourcentage1, pourcentage2, pourcentage3, pourcentage4, pourcentage5, 100);

}

int main() {

    int n = 0, rc = 0;
    char nom[512], prenom[512];
    double note1 = 0, note2 = 0;
    int nbEtu1 = 0, nbEtu2 = 0, nbEtu12 = 0;
    double moy1 = 0, moy2 = 0, moy1Assidu = 0, moy2Assidu = 0;
    double mediane1 = 0, mediane2 = 0;
    double coeffCor = 0;
    int premierQuintileNote1 = 0, deuxiemeQuintileNote1 = 0, troisiemeQuintileNote1 = 0, quatriemeQuintileNote1 = 0, cinquiemeQuintileNote1 = 0;
    int premierQuintileNote2 = 0, deuxiemeQuintileNote2 = 0, troisiemeQuintileNote2 = 0, quatriemeQuintileNote2 = 0, cinquiemeQuintileNote2 = 0;

    rc = scanf("%d\n", & n);
    if (rc != 1) {
        fprintf(stderr, "Impossible de lire le nombre de notes.\n");
        exit(1);
    }

    if (n < 0 || n > 5000) {
        fprintf(stderr, "Eek!\n");
        exit(1);
    }

    double tabNote1[n];
    double tabNote2[n];

    for (int i = 0; i < n; i++) {
        rc = scanf(" %511[^,;\n] , %511[^,;\n] , %lf , %lf", nom, prenom, & note1, & note2);
        if (rc != 4) {
            fprintf(stderr, "Impossible de lire le relevé.\n");
            exit(1);
        }

        tabNote1[i] = note1;
        tabNote2[i] = note2;

        printf("L'étudiant %s %s a eu %.2lf et %.2lf.\n", prenom, nom, note1, note2);
    }

    printf("Ok.\n\n\n");

    ///////////////////////////////////////////////////////////////////

    printf("----- CALCUL DU NOMBRE D'ETUDIANTS PRESENTS -----\n\n\n");

    nbEtu1 = presentUn(tabNote1, n);
    nbEtu2 = presentUn(tabNote2, n);
    nbEtu12 = presentDeux(tabNote1, tabNote2, n);

    printf("%d etudiants etaient presents au premier controle.\n", nbEtu1);
    printf("%d etudiants etaient presents au deuxieme controle.\n", nbEtu2);
    printf("%d etudiants etaient presents au premier et au deuxieme controle.\n", nbEtu12);

    printf("\n\n\n");

    ///////////////////////////////////////////////////////////////////

    printf("----- CALCUL DES MOYENNES -----\n\n\n");

    moy1 = moyPresentUn(tabNote1, n);
    moy2 = moyPresentUn(tabNote2, n);
    moy1Assidu = moyPresentDeux(tabNote1, tabNote2, n);
    moy2Assidu = moyPresentDeux(tabNote2, tabNote1, n);

    printf("La moyenne obtenue par le premier correcteur est egale a %.2lf .\n", moy1);
    printf("La moyenne obtenue par le deuxieme correcteur est egale a %.2lf .\n", moy2);
    printf("La moyenne obtenue par le premier correcteur pour les etudiants presents aux deux controles est egale a %.2lf .\n", moy1Assidu);
    printf("La moyenne obtenue par le premier correcteur pour les etudiants presents aux deux controles est egale a %.2lf .\n", moy2Assidu);

    printf("\n\n\n");

    ///////////////////////////////////////////////////////////////////

    printf("----- CALCUL DE LA MEDIANE -----\n\n\n");

    mediane1 = mediane(tabNote1, tabNote2, n, nbEtu12);
    mediane2 = mediane(tabNote2, tabNote1, n, nbEtu12);

    printf("La mediane obtenue au premier controle pour les etudiants ayant assistes aux deux controles est de %.2lf .\n", mediane1);
    printf("La mediane obtenue au deuxieme controle pour les etudiants ayant assistes aux deux controles est de %.2lf .\n", mediane2);

    printf("\n\n\n");

    ///////////////////////////////////////////////////////////////////

    printf("----- CALCUL DU COEFFICIENT DE CORRELATION DE PEARSON -----\n\n\n");

    coeffCor = pearson(tabNote1, tabNote2, n, moy1Assidu, moy2Assidu);

    printf("Le coefficient de correlation entre les notes de chacun des correcteurs est egal a %lf .\n", coeffCor);

    printf("\n");

    if (coeffCor > 0.5 || coeffCor < -0.5)
        printf("Les notes des deux controles sont fortement correlees.\n");
    else
        printf("Les notes des deux controles ont une correlation faible.\n");

    printf("\n\n\n");

    ///////////////////////////////////////////////////////////////////

    printf("----- CALCUL DES QUINTILES -----\n\n\n");

    premierQuintileNote1 = quintile(tabNote1, tabNote2, n, 0, 4);
    deuxiemeQuintileNote1 = quintile(tabNote1, tabNote2, n, 4, 8);
    troisiemeQuintileNote1 = quintile(tabNote1, tabNote2, n, 8, 12);
    quatriemeQuintileNote1 = quintile(tabNote1, tabNote2, n, 12, 16);
    cinquiemeQuintileNote1 = quintile(tabNote1, tabNote2, n, 16, 21); // 21 pour que 20 soit inclus

    premierQuintileNote2 = quintile(tabNote2, tabNote1, n, 0, 4);
    deuxiemeQuintileNote2 = quintile(tabNote2, tabNote1, n, 4, 8);
    troisiemeQuintileNote2 = quintile(tabNote2, tabNote1, n, 8, 12);
    quatriemeQuintileNote2 = quintile(tabNote2, tabNote1, n, 12, 16);
    cinquiemeQuintileNote2 = quintile(tabNote2, tabNote1, n, 16, 21); // 21 pour que 20 soit inclus

    printf("Au premier controle, %d etudiants ont obtenu entre 0 et 4.\n", premierQuintileNote1);
    printf("Au premier controle, %d etudiants ont obtenu entre 4 et 8.\n", deuxiemeQuintileNote1);
    printf("Au premier controle, %d etudiants ont obtenu entre 8 et 12.\n", troisiemeQuintileNote1);
    printf("Au premier controle, %d etudiants ont obtenu entre 12 et 16.\n", quatriemeQuintileNote1);
    printf("Au premier controle, %d etudiants ont obtenu entre 16 et 20.\n", cinquiemeQuintileNote1);

    printf("\n");

    printf("Au second controle, %d etudiants ont obtenu entre 0 et 4.\n", premierQuintileNote2);
    printf("Au second controle, %d etudiants ont obtenu entre 4 et 8.\n", deuxiemeQuintileNote2);
    printf("Au second controle, %d etudiants ont obtenu entre 8 et 12.\n", troisiemeQuintileNote2);
    printf("Au second controle, %d etudiants ont obtenu entre 12 et 16.\n", quatriemeQuintileNote2);
    printf("Au second controle, %d etudiants ont obtenu entre 16 et 20.\n", cinquiemeQuintileNote2);

    printf("\n\n\n");

    ///////////////////////////////////////////////////////////////////

    printf("----- REPRESENTATION GRAPHIQUE DES QUINTILES -----\n\n\n");

    histogramme(premierQuintileNote1, deuxiemeQuintileNote1, troisiemeQuintileNote1, quatriemeQuintileNote1, cinquiemeQuintileNote1,
        maxQuintile(premierQuintileNote1, deuxiemeQuintileNote1, troisiemeQuintileNote1, quatriemeQuintileNote1, cinquiemeQuintileNote1) + 5);

    printf("\n");

    printf("Histogramme de la repartition des notes en quintiles pour le premier controle.");

    printf("\n\n\n");

    histogramme(premierQuintileNote2, deuxiemeQuintileNote2, troisiemeQuintileNote2, quatriemeQuintileNote2, cinquiemeQuintileNote2,
        maxQuintile(premierQuintileNote2, deuxiemeQuintileNote2, troisiemeQuintileNote2, quatriemeQuintileNote2, cinquiemeQuintileNote2) + 5);

    printf("\n");

    printf("Histogramme de la repartition des notes en quintiles pour le deuxieme controle.");

    printf("\n\n\n");

    histogrammePourcentage(premierQuintileNote1, deuxiemeQuintileNote1, troisiemeQuintileNote1, quatriemeQuintileNote1, cinquiemeQuintileNote1, nbEtu12);

    printf("\n");

    printf("Histogramme de la repartition des notes en quintiles pour le premier controle, en pourcentages.");

    printf("\n\n\n");

    histogrammePourcentage(premierQuintileNote2, deuxiemeQuintileNote2, troisiemeQuintileNote2, quatriemeQuintileNote2, cinquiemeQuintileNote2, nbEtu12);

    printf("\n");

    printf("Histogramme de la repartition des notes en quintiles pour le deuxieme controle, en pourcentages.");

    printf("\n\n\n\n");

    return 0;
}
