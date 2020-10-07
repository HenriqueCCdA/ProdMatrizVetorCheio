#include<stdlib.h>
#include<stdio.h>

#include"../include/Error.h"
#include"../include/HccaBlas.h"
#include"../include/HccaTime.h"

void makeMatrixAndVector(double *a, double *x, int const n);

int main(int argc, char *argv[]) {

  short transp = 0;
  int n, nSamples = 10, i, j;
  double *a, *x, *y;
  double time0, time, gm = 1.e+9;
  double flop, ls;
  const int size[] = {  200,  500, 900 , 1300, 1700, 2100, 2500,
                       2900, 3300, 3700, 4100, 4500, 4900, 5300,
                       5700, 6100, 6500, 6900, 7300, 7700, 8100,
                       8500, 8900, 9300, 9700,10100,10500,10900,
                      11300,11700,12100,12500,12900,13300,13700,
                      14100,14500,14900,15300,15700,16100,16500,
                      16900,17300,17700,18100,18300,18500,19300,
                      19700,20500,20900,21300,22100,22500,23000};
  const int nn = 56;
  FILE *fileOut = NULL;

/*... abrindo arquivo*/
  fileOut = fopen("tempos_c.csv", "w");
  if (fileOut == NULL) {
    printf("Erro na arbertura do arquivo!\n");
    exit(-1);
  }
  fprintf(fileOut, "size,time,flop,bandwith\n");
/*...................................................................*/

/*...*/
  for(j = 0; j < nn; j++){
    n = size[j];

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
    time = getTimeC();   
    for (i = 0; i < nSamples; i++)
      matVecFull(a, x, y, n, n, transp);     
    time = getTimeC() - time;
/*...................................................................*/

/*...*/
    flop = flopMatVecFull(n, n);
    ls   = 8.0*loadStore(n, n);
    time /= (double) nSamples;
/*...................................................................*/

/*...*/
    printf("Time      = %16.4lf\n", time);
    printf("flops     = %16.4lf GFlops\n", (flop/time)/gm);
    printf("bandwithd = %16.4lf GBytes/s\n", (ls/time)/gm);
/*...................................................................*/
  
/*...*/
    fprintf(fileOut, "%d,%lf,%lf,%lf\n", n, time, (flop/time)/gm
                  , (ls/time)/gm);

/*... liberando memoria*/
    free(a);
    free(x);
    free(y);
/*...................................................................*/

  }
/*...................................................................*/

  return 0;
}