//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "../Tools/Tools.h"
#include "Sorting.h"

int const MIN= -1200;
int const MAX=  1200;

// WARNING :
// pow(X, NMax_echantillons) must not exceed 16384, else the program will crash due to recursions limits.
int const X=2; //The number pow NMax_echantillons = the size of the last tab that will be randomly generated.
int const NMax_echantillons=14;
int const MAX_DATA=100;


/**
 * Fonction qui prend des fonctions de tri à tester et la taille des tableaux à générer pour les tester.
 * @param fonction 
 * @param n 
 * @return 
 */
double testSortsAlgo(void (*fonction)(TElement*, int), int n) {
    TElement *tab = initTab(n); //Génération du tableau de taille n
    randomiseTab(tab, n, MIN, MAX); // Avec des valeurs aléatoires allant de 100 à 200

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    fonction(tab,n);

    clock_gettime(CLOCK_MONOTONIC, &end);
    free(tab);
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9; // Durée en secondes
}


/**
 * Fonction qui initialise un fichier dataSort.csv là ou se trouve le .exe
 * Dans ce fichier sont conservé les données calculé par la machine sur le temps
 * que mettent les programmes pour trier des tableaux généré aléatoirement entre MIN et MAX.
 */
int initData() {
    int size;
    double iSort, sSort, mSort, qSort,irSort,srSort;
    FILE *csv = fopen("dataSort.csv", "w");
    fprintf(csv, "#Size_of_tab;insertSort;selectSort;insertSortRec;selectSortRec;fusionSort;fastSort\n");
    for (int k=1; k<=NMax_echantillons; k++) {
        size = (int) pow(X, k);
        printf("Begining calculations for tab of %d elements\n", size);
        iSort=testSortsAlgo(insertSort,(int) pow(X,k));
        sSort=testSortsAlgo(selectSort,(int) pow(X,k));
        mSort=testSortsAlgo(fusionSort,(int) pow(X,k));
        qSort=testSortsAlgo(fastSort,(int) pow(X,k));
        irSort=testSortsAlgo(insertSortRecursive,(int) pow(X,k));
        srSort=testSortsAlgo(selectSortRecursive,(int) pow(X,k));
        fprintf(csv, "%d;%.12f;%.12f;%.12f;%.12f,;%.12f,;%.12f\n", size, iSort, sSort, irSort, srSort,mSort,qSort);
    }

    fclose(csv);
    printf("Finished calculations\n");
    return 0;
}

/**
 * Cette fonction lis les données généré par initData et sauvegardé dans dataSort.csv
 * Ensuite elle appelle le programme GNUPLOT auquel on enverra des instructions grâce à fprintf.
 *
 * L'idée sera de récupéré donc les données généré précédemment de temps et de quantité testé.
 * Afin de comparer les différentes fonctions et leur efficacité.
 */
int graphShow() {
    FILE *gnuplot = popen("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persistent", "w");
    if (gnuplot == NULL) {
        fprintf(stderr, "Erreur : impossible de lancer Gnuplot.\n");
        return 1;
    }

    // Envoyer des commandes à Gnuplot
    fprintf(gnuplot, "set datafile separator \";\"\n");
    fprintf(gnuplot, "set title 'Comparaison O(n) d algorithmes de tri'\n");
    fprintf(gnuplot, "set xlabel 'Taille du tableau'\n");
    fprintf(gnuplot, "set ylabel 'Temps (s)'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "plot 'dataSort.csv' using 1:2 with linespoints title 'insertSort', "
    "'dataSort.csv' using 1:3 with linespoints title 'selectSort', "
    "'dataSort.csv' using 1:4 with linespoints title 'insertSortRec', "
    "'dataSort.csv' using 1:5 with linespoints title 'selectSortRec', "
    "'dataSort.csv' using 1:6 with linespoints title 'quickSort', "
    "'dataSort.csv' using 1:7 with linespoints title 'fusionSort'\n"
        );

    fflush(gnuplot);  // S'assurer que tout est envoyé

    pclose(gnuplot);  // Fermer proprement
    return 0;
}


int main(){
    initData();
    graphShow();
    return 0;
}



