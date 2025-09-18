//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include <math.h>
#include <time.h>
#include "../Tools/FileReading.h"
#include "../Tools/Tools.h"

int const MIN= -200;
int const MAX=  200;

int const X=2; //The number pow NMax_echantillons = the size of the last tab that will be randomly generated.
int const NMax_echantillons=16;
int const MAX_DATA=100;

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

int initData() {
    int size;
    double iSort, sSort, mSort;
    FILE *csv = fopen("dataSort.csv", "w");
    fprintf(csv, "#Size_of_tab;insertSort;selectSort;fusionSort\n");
    for (int k=1; k<=NMax_echantillons; k++) {
        size = (int) pow(X, k);
        printf("Begining calculations for tab of %d elements\n", size);
        iSort=testSortsAlgo(insertSort,(int) pow(X,k));
        sSort=testSortsAlgo(selectSort,(int) pow(X,k));
        mSort=testSortsAlgo(fusionSort,(int) pow(X,k));
        fprintf(csv, "%d;%.6f;%.6f;%.6f\n", size, iSort, sSort, mSort);
    }

    fclose(csv);
    printf("Finished calculations\n");
    return 0;
}


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
    // Optional: set logscale if you have exponential sizes
    //fprintf(gnuplot, "set logscale x\n");
    //fprintf(gnuplot, "set logscale y\n");
    fprintf(gnuplot, "plot 'dataSort.csv' using 1:2 with linespoints title 'insertSort', "
    "'dataSort.csv' using 1:3 with linespoints title 'selectSort', "
    "'dataSort.csv' using 1:4 with linespoints title 'fusionSort'\n"
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



