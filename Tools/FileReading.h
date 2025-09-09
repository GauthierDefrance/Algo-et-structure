#ifndef FILEREADING_H
#define FILEREADING_H

typedef int Telement;

void printLines(char *FilePath);
Telement* tabFichier(char *FilePath, int * n);
int countLinesFile(char *FilePath);


#endif