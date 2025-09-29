//
// Created by defra on 24/09/2025.
//

#ifndef LISTS_H
#define LISTS_H

#include "../Tools/Types.h"

#define NBELTSMAX 100

typedef struct {
  int nbElts;
  TElement tab[NBELTSMAX];
} ListStatique;

typedef struct {
  int nbElts;
  int nbEltsMax;
  TElement *tab;
} ListDynamique;


typedef struct cellule * Liste;

struct cellule {
  TElement donnee;
  struct cellule *suivant;
};


#endif //LISTS_H
