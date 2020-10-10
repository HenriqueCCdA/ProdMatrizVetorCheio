#include"../include/HccaBlas.h"


/********************************************************************* 
 * Data de criacao    : 02/10/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * loadStore : Calculo do numero numero de load e store              * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * nLin -> numero de linhas                                          * 
 * nCol -> numero de colunas                                         * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 * Numero de load store                                              * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
long loadStore(int const nLin,int const nCol){
  return nLin*(2*nCol + 1);
}
/*********************************************************************/ 

/********************************************************************* 
 * Data de criacao    : 24/09/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * FLOPMATVECFULL : Calculo do numero de flops da operacao de matiz  * 
 * por um vetor, onde a matriz e uma matriz densa                    * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * nLin -> numero de linhas                                          * 
 * nCol -> numero de colunas                                         * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 * Numero de flops                                                   * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
long flopMatVecFull(int const nLin,int const nCol){
  return (long) nLin*((long) (2*nCol-1));
}
/*********************************************************************/ 

/********************************************************************* 
 * Data de criacao    : 24/09/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * DOT: produto interno entre dois vetores                           * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * x1 - vetor x1                                                     * 
 * x2 - vetor x2                                                     * 
 * n  - numero de dimensoes                                          * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 *                                                                   * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
double dot(double *RESTRICT x1, double *RESTRICT x2, int const n)
{
  int i;
  double tmp=0.0;
  for(i = 0; i < n; i++)
    tmp += x1[i]*x2[i];
  return tmp;
} 
/*********************************************************************/ 

/*==================================================================*/

/*======================== level 2 =================================*/

/********************************************************************* 
 * Data de criacao    : 24/09/2020                                   *
 * Data de modificaco : 10/10/2020                                   *
 *-------------------------------------------------------------------*
 * MATVECFULL : operacao matriz vetor para matriz cheias             * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * a  - vetor a                                                      * 
 * x  - vetor b                                                      * 
 * y  - indefinido                                                   * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 * y  - produto vetoria entre a e b                                  * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
void matVecFull( double *RESTRICT a
               , double *RESTRICT x
               , double *RESTRICT y
               , int const nLin , int const nCol
               , short const code)
{
  int i,j;
  double tmp, xi;

/*... */  
  if(!code){
    for(i=0;i<nLin;i++){
      tmp = 0.e0;
      for(j=0;j<nCol;j++){
        tmp += MAT2D(i,j,a,nCol)*x[j];
      }
      y[i] = tmp;
    }
  }
/*...................................................................*/

/*... matriz transposta*/  
  else{
    for(j=0;j<nCol;j++)
      y[j] = 0.e0;

    for(i=0;i<nCol;i++){
      xi = x[i];
      for(j=0;j<nLin;j++){
        y[j] += MAT2D(i,j,a,nLin)*xi;
      }
  
    }

  }
/*...................................................................*/
}
/*********************************************************************/ 


