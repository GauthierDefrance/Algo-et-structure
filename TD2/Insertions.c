//
// Created by defra on 22/09/2025.
//

#include "Insertions.h"


void insertionsTrie(TElement *tab, int * n, TElement elt){
      int i= *n;
      while (i>0 && elt<tab[i]){
        tab[i+1]=tab[i];
        i--;
      }
      tab[i+1]=elt;
      n = n+1;
  }


//Cette fonctions n'incrémente pas le n.
//On utilise N comme indice de position
void insertionTrieRec(TElement *tab, int n, TElement elt){
    if (n==0 || elt>=tab[n]){
      tab[n+1]=elt;
      }
    else{
      tab[n+1]=tab[n];
      insertionTrieRec(tab,n-1,tab[n]);
    }
  }





