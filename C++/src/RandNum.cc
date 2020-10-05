#include"../include/RandomCc.h"

/********************************************************************* 
 * Data de criacao    : 05/10/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * makeMatrixAndVector : gerando a matriz e vetor com numetros       *
 * aleatorios de -100 e 100                                          * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * a      - matriz a                                                 *
 * x      - vetor                                                    * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
void makeMatrixAndVector(Array2D &a, Array &x) 
{

  unsigned int seed = 1;

  default_random_engine defEngine(seed);
  uniform_real_distribution<double> af(-100.0,100.0);
  uniform_real_distribution<double> xf(-1.0,1.0);
  int n;  

  x.dim(n);

  for (int i = 0; i < n; i++) {
    x.setCoef(i, xf(defEngine));
//  x.setCoef(i, i);
    for (int j = 0; j < n; j++) 
    {
      a.setCoef(i, j, af(defEngine));
//    a.setCoef(i, j, 1 + i);
    }
  }

}
/********************************************************************/

/********************************************************************* 
 * Data de criacao    : 05/10/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * makeMatrixAndVector : gerando a matriz e vetor com numetros       *
 * aleatorios de -100 e 100                                          * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * a      - matriz a                                                 *
 * x      - vetor                                                    * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
void makeMatrixAndVector(vector <double> &a, vector<double> &x) 
{
  unsigned int seed = 1;
  default_random_engine defEngine(seed);
  uniform_real_distribution<double> af(-100.0,100.0);
  uniform_real_distribution<double> xf(-1.0,1.0);
  int n = x.size();

  for (int i = 0; i < n; i++) {
    x[i] = xf(defEngine);
//  x[i] = i;
    for (int j = 0; j < n; j++) 
    {
      a[i * n + j ] = af(defEngine);
//    a[i * n + j ] = 1 + i;
    }
  }

}
/********************************************************************/