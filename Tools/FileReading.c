#include <stdio.h>
#include <stdlib.h>
#include "FileReading.h" 

void printLines(){
    FILE* file = fopen("../Tools/test.txt", "r");
    char line[100]; //on se limite à 100 caractère, on peut faire bcp moins
    if (file != NULL) {

        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        printf("\n");

        //Ne pas oublier de fermer le fichier
        fclose(file);
    }
    else {
        printf("Impossible d'ouvrir le fichier!\n");
    }
}

void tabFichier(){
    FILE* file = fopen("../Tools/test.txt", "r");
    char line[100]; //on se limite à 100 caractère, on peut faire bcp moins
    if (file != NULL) {
        char *endptr; //vérification en cas d'erreur
        
        int ligne1=strtol (fgets(line, sizeof(line), file),&endptr, 10);
        printf("%d", ligne1);

        //Ne pas oublier de fermer le fichier
        fclose(file);
    }
    else {
        printf("Impossible d'ouvrir le fichier!\n");
    }
}