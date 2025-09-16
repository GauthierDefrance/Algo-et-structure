//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include "Sorting.h"
#include "../Tools/FileReading.h"
#include "../Tools/Tools.h"

int main(){
    int N = 6;
    int MIN = 100;
    int MAX = 200;
    TElement *tab = initTab(N);
    nullTab(tab,N);
    randomiseTab(tab, N, MIN, MAX);
    printTab(tab, N);

    //int n=0;
    //TElement * newTab = tabFichier("../Tools/test.txt", &n);
    //printf("test %d \n", n);
    //printTab(newTab, n);

    //selectSort(newTab, n);
    //printTab(newTab, n);

    printf("Test :\n");
    //insertSort(tab, n);

    fusionSort(tab, N);
    printTab(tab, N);
}



