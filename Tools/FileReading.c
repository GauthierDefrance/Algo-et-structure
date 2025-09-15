#include <stdio.h>
#include <stdlib.h>
#include "FileReading.h"
#include <string.h>
#include "Tools.h"

void split_string(char *str, const char *delim) {
    char *token = strtok(str, delim);
    while (token != NULL) {
        printf("'%s'\n", token);
        token = strtok(NULL, delim);
    }
}


void printLines(char *FilePath){
    FILE* file = fopen(FilePath, "r");
    char line[252]; //on se limite à 100 caractère, on peut faire bcp moins
    if (file != NULL) {

        while (fgets(line, sizeof(line), file)) {
            printf("%s ", line);
        }
        printf("\n");

        //Ne pas oublier de fermer le fichier
        fclose(file);
    }
    else {
        printf("Impossible d'ouvrir le fichier!\n");
    }
}

TElement* tabFichier(char *FilePath, int * n){
    FILE* file = fopen(FilePath, "r");
    char line[100]; //on se limite à 100 caractère, on peut faire bcp moins
    if (file != NULL) {
        char *endptr; //vérification en cas d'erreur
        char* ligne1=fgets(line, sizeof(line), file);
        *n=strtol(ligne1,&endptr,10); // n correspond au nombres de valeurs.

        char* ligne2=fgets(line, sizeof(line), file);
        char *token = strtok(ligne2, ",");

        TElement* tab=initTab(*n);
        int i=0;
        while (token != NULL) {
            tab[i]=strtol(token,&endptr,10);
            token = strtok(NULL, ",");
            i++;
        }
        //Ne pas oublier de fermer le fichier
        fclose(file);
        return tab;
    }
    else {
        printf("Impossible d'ouvrir le fichier!\n");
        return NULL;
    }
}


int countLinesFile(char *FilePath){
  FILE* file = fopen(FilePath, "r");
  char line[65536];

  if (file == NULL) {printf("Erreur lors de la lecture du fichier.");return -1;}

  int compteur=0;
  while(fgets(line, sizeof(line), file)){
    compteur++;
  }

  fclose(file);
  return compteur;
}