#ifndef TOOLS_H
#define TOOLS_H

#include "Types.h"

/**
 * Fonction qui affiche dans la console,
 * la taille d'un tableau de Telement, son addresse mémoire, puis son contenu.
 *
 * @param tab le tableau de Telement
 * @param n la taille du tableau
 */
void printTab(TElement tab[], int n);

/**
 * Fonction qui initialise et renvoi un tableau de Telement de taille n.
 *
 * @param n la taille du tableau
 * @return un tableau de Telement
 */
TElement* initTab(int n);


/**
 * Procédure qui remplie un tableau de Telement donné de 0.
 *
 * @param tab le tableau
 * @param n la taille du tableau
 */
void nullTab(TElement tab[], int n);

/**
 * Procéduire qui détruit et libère la mémoire prise par un tableau créé.
 * @param tab 
 */
void destroyTab(TElement **tab);


/**
 * Procédure qui remplie un tableau de taille n de valeurs entières comprises entre Min et Max.
 *
 * @param tab le tableau
 * @param n la taille du tableau
 * @param Min la taille minimal des nombres aléatoire
 * @param Max la taille maximal des nombres aléatoire
 */
void randomiseTab(TElement tab[], int n, int Min, int Max);

#endif //TOOLS_H
