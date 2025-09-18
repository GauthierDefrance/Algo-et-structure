/**
 * / - - - - - - - - - - - - - - - \
 *            TP1 & 2
 *       Algorithmes de tri et
 *       complexités
 * \ - - - - - - - - - - - - - - - |
 * Code par Thomas Hornung et Gauthier Defrance
 * Le 18/09/2025
*/

#include "Sorting.h"
#include "../Tools/Tools.h"
#include <stdlib.h>

/**
 * Dans ce code, 4 fonctions de tri sont vues.
 * - Le tri par insertion (itératif et récursif) : O(n²)
 * - Le tri par sélection (itératif et récusrif) : O(n²)
 * - Le tri par fusion                           : O(log n)
 * - Le tri par pivot, dit tri rapide            : O(log n)
 */


void permutation(TElement tab[], int a, int b){
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
    permutation(tab, k, i);
  }
}

void insertSort(TElement tab[], int n) {
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

void fusionRec(TElement tab[], TElement tmp[], int debut, int fin) {
  if (debut<fin) {
    int milieu=(debut+fin)/2;
    fusionRec(tab,tmp,debut,milieu);
    fusionRec(tab,tmp,milieu+1,fin);
    fusion(tab,tmp,debut,milieu,fin);
  }
}

void fusionSort(TElement tab[], int n) {
  TElement *tmpTab = initTab(n+2);
  nullTab(tmpTab,n);
  fusionRec(tab,tmpTab,0, n-1);
  destroyTab(&tmpTab);
}

int partition(int tab[], int debut, int fin) {
  int p = tab[debut]; // pivot
  int i = debut;
  int j = fin;
  while (i<j) {
    while (tab[i]<=p && i<fin) {
      i++;
    }
    while (p<tab[j] && debut<j) {
      j--;
    }
    if (i<j) {
      permutation(tab, i, j);
    }
  }
  permutation(tab, debut, j);
  return j;
}

void quickSort(int tab[], int debut, int fin) {
  if (debut < fin) {
    //Un peu à la manière du mergeSort, on trouve un pivot mais pas le milieu à chaque fois
    int p = partition(tab, debut, fin);
    //Ensuite, le tableau est divisé en deux à partir du pivot.
    quickSort(tab, debut, p - 1);
    quickSort(tab, p + 1, fin);
  }
}

void fastSort(TElement tab[], int n) {
  quickSort(tab, 0, n-1);
}

void selectSortRec(TElement tab[], int n, int j) {
  if (j<n-1) {
    int i = findMinIndex(tab, n, j);
    permutation(tab, j, i);
    selectSortRec(tab, n, j+1);
  }
}

void selectSortRecursive(TElement tab[], int n) {
  selectSortRec(tab, n, 0);
}

void insertSortRec(TElement tab[], int n, int i) {
  if (i<n) {
    int currentValue = tab[i];
    int j = i-1;
    while (j >= 0 && tab[j] > currentValue) {
      tab[j + 1] = tab[j];
      j = j - 1;
    }
    tab[j + 1] = currentValue;
    insertSortRec(tab, n, i+1);
  }
}

void insertSortRecursive(TElement tab[], int n) {
  insertSortRec(tab, n, 1);
}