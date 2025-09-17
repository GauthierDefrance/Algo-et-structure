//
// Created by defra on 15/09/2025.
//

#include <stdio.h>
#include <stdlib.h>

    int main() {
        // Ouvrir un pipe vers Gnuplot
        FILE *gnuplot = popen("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" -persistent", "w");
        if (gnuplot == NULL) {
            fprintf(stderr, "Erreur : impossible de lancer gnuplot.\n");
            return 1;
        }

        // Envoyer des commandes Gnuplot
        fprintf(gnuplot, "set title 'Exemple temps execution'\n");
        fprintf(gnuplot, "set xlabel 'Essai'\n");
        fprintf(gnuplot, "set ylabel 'Temps (s)'\n");
        fprintf(gnuplot, "plot 'data.txt' using 1:2 with linespoints title 'Execution'\n");

        fflush(gnuplot);  // S'assurer que les commandes sont envoyées
        // garder gnuplot ouvert (grâce à -persistent)

        pclose(gnuplot);
        return 0;
    }


