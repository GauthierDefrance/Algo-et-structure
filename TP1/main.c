//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include <time.h>
#include "../Tools/FileReading.h"
#include "../Tools/Tools.h"

int const MIN=100;
int const MAX=200;

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


int main(){

    printf("%f;",testSortsAlgo(insertSort,100000));
    printf("%f;",testSortsAlgo(selectSort,100000));
    printf("%f",testSortsAlgo(fusionSort,100000));

}



