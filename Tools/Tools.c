#include <stdio.h>
#include "Tools.h"

typedef int Telement;

void printTab(Telement tab[], int n){
<<<<<<< Updated upstream
=======
    printf("Size of tab : %d, 0x%p",n, &tab[0]);
    printf("\n");
>>>>>>> Stashed changes
    for(int i=0; i<n; i++){
        printf("%d,",tab[i]);
    }
    printf("\n");
}