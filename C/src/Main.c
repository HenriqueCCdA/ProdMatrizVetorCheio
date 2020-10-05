#include<stdlib.h>
#include<stdio.h>

#include"../include/Error.h"
#include"../include/HccaBlas.h"
#include"../include/HccaTime.h"

void makeMatrixAndVector(double *a, double *x, int const n);

int main(int argc, char *argv[]) {

  short transp = 0;
  int n = 30000, nSamples = 20, i;
  double *a, *x, *y;
  double time0, time, gm = 1.e+9;
  long flop, ls;

/*... alocando*/
  a = (double *) malloc(sizeof(double)*n*n);
  ERRO_MALLOC(a, "a", __LINE__, __FILE__, __func__);
  y = (double *) malloc(sizeof(double)*n);
  ERRO_MALLOC(y, "y", __LINE__, __FILE__, __func__);
  x = (double *) malloc(sizeof(double)*n);
  ERRO_MALLOC(y, "y", __LINE__, __FILE__, __func__);
/*...................................................................*/

/*...*/
  makeMatrixAndVector(a, x, n);
/*...................................................................*/

/*...*/
  time = 0.e0;
  for(i = 0; i < nSamples; i++){
    
    time0 = getTimeC();
    matVecFull(a, x, y, n, n, transp);
    time += getTimeC() - time0;

  }
/*...................................................................*/

/*...*/
  flop = flopMatVecFull(n, n);
  ls   = loadStore(n, n);
  time /= (double) nSamples;
/*...................................................................*/

/*...*/
  printf("Time      = %16.4lf\n", time);
  printf("flops     = %16.4lf GFlops\n", (flop/time)/gm);
  printf("bandwithd = %16.4lf GBytes/s\n", (8*ls/time)/gm);
/*...................................................................*/
  
/*... liberando memoria*/
  free(a);
  free(x);
  free(y);
/*...................................................................*/
  return 0;
}