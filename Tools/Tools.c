#include <stdio.h>
#include "Tools.h"
#include "time.h"
#include <stdlib.h>

typedef int Telement;

/**
 * Fonction qui prend un tableau de taille n et en affiche les éléments.
 * @param tab
 * @param n
 */
void printTab(Telement tab[], int n){
    printf("Size of tab %d : 0x%p",n, &tab[0]);
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d,",tab[i]);
    }
    printf("\n");
}

/**
 * Fonction pour créer un tableau de taille n.
 * Renvoi éventuellement une erreur d'allocation mémoire.
 *
 * @param n
 * @return
 */
Telement* initTab(int n) {
    Telement *tab= malloc(n*sizeof(Telement));
    if(tab == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    return tab;
}

/**
 * Fonction pour nullifier un tableau de taille n.
 * @param tab
 * @param n
 */
void nullTab(Telement tab[], int n) {
    for(int i=0; i<n; i++) {
        tab[i] = 0;
    }
}

/**
 * Fonction pour détruire un tableau
 * @param tab
 */
void destroyTab(Telement **tab) {
    free(*tab);
    *tab = NULL;
}


void randomiseTab(Telement tab[], int n, int Min, int Max) {
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        tab[i] = Min + rand()%(Max-Min +1);
    }
}