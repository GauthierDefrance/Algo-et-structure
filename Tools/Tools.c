#include <stdio.h>
#include "Tools.h"

typedef int Telement;

void printTab(Telement tab[], int n){
    for(int i=0; i<n; i++){
        printf("%d,",tab[i]);
    }
    printf("\n");
}