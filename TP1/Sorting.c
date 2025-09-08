//
// Created by defra on 08/09/2025.
//

#include "Sorting.h"
#include <stdio.h>

typedef int Telement;


/**
*  Fonction qui permute deux Telement dans un  tab de Telement aux indices a et b.
**/
void permutation(Telement tab[], int n, int a, int b){
  Telement tmp = tab[a];
  tab[a] = tab[b];
  tab[b] = tmp;
}

/**
*  Fonction qui trouve l'élément minimum d'un tableau Telement, compris entre i et n.
**/
Telement findMin(Telement tab[], int n, int i){
  Telement champion=tab[i];
    for(int j=i; j<n; j++){
      if(champion>tab[j]) champion=tab[j];
    }
  return champion;
}






