//
// Created by defra on 08/09/2025.
//

#include "Sorting.h"
#include "../Tools/Tools.h"
#include <stdio.h>
#include <stdlib.h>


void permutation(TElement tab[], int n, int a, int b){
  TElement tmp = tab[a];
  tab[a] = tab[b];
  tab[b] = tmp;
}

TElement findMinIndex(TElement tab[], int n, int i){
  TElement champion=tab[i];
  int champion_index=i;
    for(int j=i; j<n; j++){
      if(champion>tab[j]) {
        champion=tab[j];
        champion_index=j;
      }
    }
  return champion_index;
}

void selectSort(TElement tab[], int n) {
  int i;
  for (int k = 0; k < n-1; k++) {
    i = findMinIndex(tab, n, k);
    permutation(tab, n, k, i);
  }
}

void insertSort(int tab[], int n) {
  int currentValue, j;
  for (int i = 1; i < n; i++) {
    currentValue = tab[i];
    j = i - 1;
    while (j >= 0 && tab[j] > currentValue) {
      tab[j + 1] = tab[j];
      j = j - 1;
    }
    tab[j + 1] = currentValue;
  }
}

void fusion(TElement tab[], int debut, int milieu, int fin) {

}


void fusionSort(TElement tab[],int n, int debut, int fin) {

}
