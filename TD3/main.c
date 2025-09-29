//
// Created by defra on 29/09/2025.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "fibonaci.h"


#define NMax_echantillons 45

double testFibonaciAlgo(void (*fonction)(int), int n) {
  struct timespec start, end;
  clock_gettime(CLOCK_MONOTONIC, &start);

  fonction(n);

  clock_gettime(CLOCK_MONOTONIC, &end);

  return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9; // Durée en secondes
}



/**
 * Fonction qui initialise un fichier dataSort.csv là ou se trouve le .exe
 * Dans ce fichier sont conservé les données calculé par la machine sur le temps
 * que mettent les programmes pour trier des tableaux généré aléatoirement entre MIN et MAX.
 */
int initData() {
  int size;
  double fExp, fLin;
  FILE *csv = fopen("dataFibonaci.csv", "w");
  fprintf(csv, "#Size;fibonaciExp;fibonaciLineaire\n");
  for (int k=1; k<=NMax_echantillons; k++) {
    size = (int) k;
    printf("Begining calculations for tab of %d elements\n", size);
    fExp=testFibonaciAlgo(fibonaciExp, k);
    fLin=testFibonaciAlgo(fibonaciLineaire,k);
    fprintf(csv, "%d;%.12f;%.12f\n", size, fExp, fLin);
  }

  fclose(csv);
  printf("Finished calculations\n");
  return 0;
}

int graphShow() {
  FILE *gnuplot = popen("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persistent", "w");
  if (gnuplot == NULL) {
    fprintf(stderr, "Erreur : impossible de lancer Gnuplot.\n");
    return 1;
  }

  // Envoyer des commandes à Gnuplot
  fprintf(gnuplot, "set datafile separator \";\"\n");
  fprintf(gnuplot, "set title 'Algorithmes de Fibonacci'\n");
  fprintf(gnuplot, "set xlabel 'Taille'\n");
  fprintf(gnuplot, "set ylabel 'Temps (s)'\n");
  fprintf(gnuplot, "set grid\n");
  fprintf(gnuplot, "plot 'dataFibonaci.csv' using 1:2 with linespoints title 'fibonaciExp', "
  "'dataFibonaci.csv' using 1:3 with linespoints title 'fibonaciLineaire'\n"
      );

  fflush(gnuplot);  // S'assurer que tout est envoyé

  pclose(gnuplot);  // Fermer proprement
  return 0;
}





int main() {

  initData();
  graphShow();

}