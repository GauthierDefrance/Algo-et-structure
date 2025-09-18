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

int const X=10; //The number pow NMax_echantillons = the size of the last tab that will be randomly generated.
int const NMax_echantillons=6;

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
    fprintf(csv, "Size_of_tab;insertSort;selectSort;fusionSort\n");
    for (int k=1; k<=NMax_echantillons; k++) {
        size = (int) pow(10, k);
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


int main(){
    initData();
    return 0;
}



