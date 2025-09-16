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

void fusion(TElement tab[], TElement tmp[], int debut, int milieu, int fin) {

  int n1 = milieu - debut + 1;
  int n2 = fin - milieu;

  TElement *tab1 = tmp;
  TElement *tab2 = tmp + n1 + 1;

  int v=0;
  for (int o = debut; o <= milieu; o++) {
    tab1[v]=tab[o];
    v++;
  }

  v=0;
  for (int o = milieu+1; o <= fin; o++) {
    tab2[v]=tab[o];
    v++;
  }

  tab1[milieu-debut+1] = INT_MAX;
  tab2[fin-milieu] = INT_MAX;

  int i = 0, j = 0;
  for (int k = debut; k <= fin; k++) {
    if (tab1[i] < tab2[j]) {
      tab[k] = tab1[i];
      i++;
    }
    else {
      tab[k] = tab2[j];
      j++;
    }
  }

}


void fusionSort(TElement tab[], TElement tmp[], int debut, int fin) {
  if (debut<fin) {
    int milieu=(debut+fin)/2;
    fusionSort(tab,tmp,debut,milieu);
    fusionSort(tab,tmp,milieu+1,fin);
    fusion(tab,tmp,debut,milieu,fin);
  }
}
