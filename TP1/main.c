//
// Created by defra on 08/09/2025.
//
#include <stdio.h>
#include "Sorting.h"
#include "../Tools/Tools.h"

int main(){
    Telement tab[]={45,15,3,4,5,6,7,8,9, 1501, -43, 0};
    selectSort(tab,12);
    printTab(tab, 12);
}



