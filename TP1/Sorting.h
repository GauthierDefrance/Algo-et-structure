// Sorting.h
#ifndef SORTING_H
#define SORTING_H

// Définition du type Telement (modifiable si besoin)
#include "../Tools/Types.h"

/**
 * Permute deux éléments dans un tableau de Telement aux indices a et b.
 *
 * @param tab Le tableau dans lequel effectuer la permutation
 * @param n La taille du tableau
 * @param a L'indice du premier élément à permuter
 * @param b L'indice du second élément à permuter
 */
void permutation(TElement tab[], int n, int a, int b);

/**
 * Trouve l'élément minimum dans un tableau de Telement entre les indices i et n-1.
 *
 * @param tab Le tableau dans lequel chercher
 * @param n La taille du tableau
 * @param i L'indice de départ pour la recherche
 * @return Le plus petit élément trouvé entre i et n-1
 */
TElement findMinIndex(TElement tab[], int n, int i);


/**
 * Fonction qui effectue un tri par sélection d'un tableau de Telement.
 * Complexité de la fonction : n
 *
 * @param tab
 * @param n
 */
void selectSort(TElement tab[], int n);


/**
 * Fonction qui effectue un tri par sélection d'un tableau de Telement.
 * Complexité de la fonction : n
 *
 * @param tab
 * @param n
 */
void insertSort(TElement tab[], int n);


/**
 * Fonction qui trie un tableau de Telement par fusion
 * @param tab
 * @param n 
 * @param debut 
 * @param fin 
 */
void fusionSort(TElement tab[], int n, int debut, int fin);

#endif // SORTING_H