//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include "Sorting.h"
#include "../Tools/Tools.h"

int main(){
<<<<<<< Updated upstream
    Telement tab[]={45,15,3,4,5,6,7,8,9, 1501, -43, 0};
    selectSort(tab,12);
    printTab(tab, 12);
=======
    int N = 12;
    int MIN = 100;
    int MAX = 200;
    Telement *tab = initTab(N);
    nullTab(tab,N);
    randomiseTab(tab, N, MIN, MAX);
    selectSort(tab,N);
    printTab(tab, N);
    destroyTab(&tab);
    printf("\n");
    printLines("../Tools/test.txt");
    tabFichier("../Tools/test.txt");
    printf("\n");
    printf("nb lignes = %d",countLinesFile("../Tools/test.txt"));
>>>>>>> Stashed changes
}



