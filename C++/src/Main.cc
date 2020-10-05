#include<iostream>
#include<string>
#include<chrono>
#include<vector>
#include"../include/MatVec.h"
#include"../include/HccaTimeCc.h"
#include"../include/RandomCc.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void matVec(vector <double> &a, vector<double> &x
          , vector<double> &y, bool transp);


int main(int argc, char *argv[]) {
  
  TimeCc timer;
  const int n = 6000, nSamples = 10;
  Matrix a;
  Vector x, y;
  double time1, time2;
  bool transpose = true;

/*... Versao com minha class*/

/*... alocando memoria*/
  a.alloc(n, n, "a");
  x.alloc(n, "x");
  y.alloc(n, "y");
/*...................................................................*/
 
/*...*/
  makeMatrixAndVector(a, x);
/*...................................................................*/
  
/*...*/    
  time1 = 0.e0;
  for(int i = 0; i< nSamples; i++){
    timer.tic();
    y = a.matVec(x, y, transpose);
    time1 += timer.toc();
  }
  time1 /= static_cast <double> (nSamples); 
/*...................................................................*/

  
/*... liberando a memoria*/
  y.dealloc();
  x.dealloc();
  a.dealloc();
/*...................................................................*/

  cout << "Time1: " << time1 << endl;

/*... Versao com arrat*/
  vector<double> a1;
  vector<double> x1, y1;

/*...*/
  a1.resize(n*n);
  x1.resize(n);
  y1.resize(n);
/*...................................................................*/

/*...*/
  makeMatrixAndVector(a1, x1);
/*...................................................................*/
  
/*...*/    
  time2 = 0.e0;
  for(int i = 0; i< nSamples; i++){
    timer.tic();
    matVec(a1, x1, y1, transpose);
    time2 += timer.toc();
  }
  time2 /= static_cast <double> (nSamples); 
/*...................................................................*/


  cout << "Time2: " << time2 << endl;

  return 0;

}

/********************************************************************* 
 * Data de criacao    : 03/10/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * MATVEC : operacao matriz vetor para matriz cheias                 * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * x      - vetor x                                                  *
 * y      - indefinido                                               *
 * transp - matriz transposta                                        * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 * y  - produto vetoria entre a e x                                  * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
void matVec(vector <double> &a, vector<double> &x
          , vector<double> &y, bool transp) {

  int n = x.size();
  double tmp = 0.e0;

/*... transposta*/
  if(transp)
    for (int i = 0; i < n; i++) {
      tmp = 0.e0;
      for (int j = 0; j < n; j++) 
        tmp += a[j * n + i] * x[i];
      y[i] = tmp;
    }
/*...................................................................*/

/*...*/
  else
    for (int i = 0; i < n; i++) {
      tmp = 0.e0;
      for (int j = 0; j < n; j++) 
        tmp += a[i * n + j] * x[i];
      y[i] = tmp;
    }
/*...................................................................*/ 

}
/********************************************************************/