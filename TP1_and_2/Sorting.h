#ifndef SORTING_H
#define SORTING_H

// Définition du type Telement (modifiable si besoin)
#include "../Tools/Types.h"

/**
 * Permute deux éléments dans un tableau de Telement aux indices a et b.
 *
 * @param tab Le tableau dans lequel effectuer la permutation
 * @param a L'indice du premier élément à permuter
 * @param b L'indice du second élément à permuter
 */
void permutation(TElement tab[], int a, int b);

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
 * Cette fonction tri son tableau comme un hummain trierai un jeu de cartes.
 * Elle parcourt le tableau et insère i à une position x du tableau,
 * puis décale tout les élememnts à droite de x avec x inclus pour
 * pouvoir insérer l'élement i.
 *
 * Fonction de tri très peu efficace pour de grandes quantités de données.
 *
 * @param tab
 * @param n
 */
void selectSort(TElement tab[], int n);


/**
 * Fonction qui effectue un tri par sélection d'un tableau de Telement.
 * Complexité de la fonction : n
 *
 * Une fonction de tri assez basique, qui va en boucle chercher l'élement le plus petit
 * et va l'échanger avec l'élement le plus à gauche + i.
 * Jusqu'à avoir parcouru en entier le tableau.
 *
 * Fonction de tri très peu efficace pour de grandes quantités de données.
 *
 * @param tab
 * @param n
 */
void insertSort(TElement tab[], int n);


/**
 * Fonction comme selectSort mais juste en récursif.
 * on remplace juste une des boucles for par une récursion.
 * @param tab 
 * @param n 
 */
void selectSortRecursive(TElement tab[], int n);

/**
 *  Fonction comme insertSort mais juste en récursif.
 *  on remplace juste une des boucles for par une récursion.
 * @param tab
 * @param n 
 */
void insertSortRecursive(TElement tab[], int n);


/**
 * Fonction qui trie un tableau de Telement par fusion
 * Complexité de la fonction : log n
 *
 * Cette fonction marche en 2 étapes :
 * 1) Diviser : on divise chaque tableau en sous tableau jusqu'à avoir qu'un seul élement
 * 2) Fusionner : on compare les tableaux à chaque niveaux en utilisant 3 compteurs i (tab1), j (tab2), k(tab_out)
 *
 * Ce programme tri de manière très efficace et rapidement des tableaux de toutes tailles.
 * Mais, dû à sa récursivté peut avoir un coût fort dans la mémoire.
 *
 * @param tab Le tableau a trier
 * @param n Le nombre d'élements
 */
void fusionSort(TElement tab[], int n);


/**
 * Fonction qui trie un tableau de TElement par tri rapide.
 * Complexité de la fonction : log n
 *
 * Cette fonction ressemble un peu dans sa structure au tri fusion.
 * la différence clé étant le système de pivot vu dans la sous-fonction "partition".
 * Au lieu de diviser le tableau en deux simplement comme dans le tri fusion,
 * on tri et on divise intelligement le tableau.
 *
 * Probablement la meilleure fonction de tri pour un cas d'utilisation général.
 * Implémenté de base en C avec l'appel "qsort()"
 *
 * @param tab
 * @param n 
 */
void fastSort(TElement tab[], int n);




#endif // SORTING_H