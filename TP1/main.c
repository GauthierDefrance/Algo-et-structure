//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include "Sorting.h"
#include "../Tools/Tools.h"
#include "../Tools/FileReading.h"

int main(){
    int N = 16;
    Telement *tab = initTab(N);
    nullTab(tab,N);
    selectSort(tab,N);
    printTab(tab, N);
    destroyTab(&tab);
    printf("\n");
    printLines();
    tabFichier();
}



