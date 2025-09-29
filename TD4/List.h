//
// Created by defra on 29/09/2025.
//

#ifndef LIST_H
#define LIST_H

typedef struct{
  int fact ; // indique le facteur premier
  int nbOcc ; // nombre d’occurrences du facteur premier
}FactPremier;

typedef struct cellule{
  FactPremier donnee;
  struct cellule *suivant ;
}*Liste;

typedef struct {
  int number;
  Liste ldfp;
} TElement;

typedef struct {
  int nbElts;
  TElement *tab;
} TabListes;



#endif //LIST_H
