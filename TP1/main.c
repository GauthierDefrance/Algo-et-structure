//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include "Sorting.h"
#include "../Tools/FileReading.h"
#include "../Tools/Tools.h"

int main(){
    int N = 12;
    int MIN = 100;
    int MAX = 200;
    Telement *tab = initTab(N);
    nullTab(tab,N);
    randomiseTab(tab, N, MIN, MAX);
    selectSort(tab,N);
    printTab(tab, N);

    int n=0;
    Telement * newTab = tabFichier("../Tools/test.txt", &n);

    printTab(newTab, n);
    selectSort(newTab, n);
    printTab(newTab, n);

}



