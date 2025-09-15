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
  int n1 = milieu - debut + 1;
  int n2 = fin - milieu;

  // Tableaux temporaires
  int *tabG = malloc(n1 * sizeof(int));
  int *tabD = malloc(n2 * sizeof(int));

  // Copier les données
  for (int i = 0; i < n1; i++)
    tabG[i] = tab[debut + i];
  for (int j = 0; j < n2; j++)
    tabD[j] = tab[milieu + 1 + j];

  int i = 0, j = 0, k = debut;

  // Fusionner les deux sous-tableaux
  while (i < n1 && j < n2) {
    if (tabG[i] <= tabD[j]) {
      tab[k] = tabG[i];
      i++;
    } else {
      tab[k] = tabD[j];
      j++;
    }
    k++;
  }

  // Copier les éléments restants
  while (i < n1) {
    tab[k] = tabG[i];
    i++;
    k++;
  }

  while (j < n2) {
    tab[k] = tabD[j];
    j++;
    k++;
  }

  // Libérer la mémoire
  free(tabG);
  free(tabD);
}

void fusionSort(TElement tab[],int n, int debut, int fin) {
  if (debut < fin) {
    int milieu = (debut + fin) / 2;
    fusion(tab,n, debut, milieu);
    fusion(tab,n, milieu + 1, fin);
    fusion(tab, debut, milieu, fin);
  }
}
