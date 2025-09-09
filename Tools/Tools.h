#ifndef TOOLS_H
#define TOOLS_H

typedef int Telement;

void printTab(Telement tab[], int n);

Telement* initTab(int n);

void nullTab(Telement tab[], int n);

void destroyTab(Telement **tab);

void randomiseTab(Telement tab[], int n, int Min, int Max);

int countLinesFile(char *FilePath);

#endif //TOOLS_H
