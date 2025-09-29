//
// Created by defra on 29/09/2025.
//

#include "fibonaci.h"
#include <stdio.h>

int fibonaciExp(int n){
    if(n<=1){
      return n;
    }
    else{
      return fibonaciExp(n-1) + fibonaciExp(n-2);
    }
  }


int fibonaciLineaire(int n) {
  if(n<=1) return n;

  int f1 = 1;
  int f0 = 0;
  int tp;

  while (n>1) {
    tp=f1;
    f1=f0+f1;
    f0=tp;
    n--;
  }

  return f1;
}