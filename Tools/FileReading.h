#ifndef FILEREADING_H
#define FILEREADING_H

#include "Types.h"


/**
 * Affiche dans la console toutes les lignes d'un fichier texte.
 * Attention, taille maximale par ligne de 252 char.
 *
 * @param FilePath Le chemin du fichier
 */
void printLines(char *FilePath);


/**
 * Fonction conçu pour convertir un tableau de int écrit dans un fichier texte,
 * en un tableau de Telement. Il faut lui passer l'addresse d'une variable pour
 * obtenir la taille du tableau donné en sortie.
 *
 * Structure exemple du fichier texte :
 * 42                       <-- première ligne, ou vous précisez le nombre d'élements de la deuxième ligne
 * 167,-56,0,-1,18,99       <-- deuxième ligne, chaque int est séparé par une virgule
 *
 * @param FilePath Le chemin du fichier
 * @param n L'addresse de la variable ou stocker la taille
 * @return
 */
TElement* tabFichier(char *FilePath, int * n);


/**
 * Fonction qui compte toutes les lignes d'un fichier texte.
 * Une ligne ne peut dépasser la taille de 65536,
 * si elle dépasse ce nombre de char. Elle sera compté plus d'une fois.
 *
 * @param FilePath Le chemin du fichier
 * @return
 */
int countLinesFile(char *FilePath);


#endif