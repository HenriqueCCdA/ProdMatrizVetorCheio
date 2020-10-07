#include<iostream>
#include<string>
#include<chrono>
#include<vector>
#include<fstream>

#include"../include/Array.h"
#include"../include/HccaTimeCc.h"
#include"../include/RandomCc.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

void matVec(vector <double> &a, vector<double> &x
          , vector<double> &y, bool transp);


int main(int argc, char *argv[]) {
  
  TimeCc timer;
  const int nSamples = 20;
  int n;
  const int size[] = {160, 320, 640, 1280, 2560, 5120, 10240};
  Array2D a;
  Array x, y;
  double time1, time2;
  const bool transpose = false;
  double flop, ls;
  const double gm = 1.e+9;

/*... abrindo arquivo para escrita*/


/*... Versao com minha class*/
  ofstream fOut;
  fOut.open("tempos_cpp.csv");
  if (!fOut.is_open()) {
    cout << "Erro na arbertura do arquivo!" << endl;
    exit(-1);
  }
  fOut << "size,time,flop,bandwith" << endl;
/*...................................................................*/

/*...*/
  for(int j = 0; j < 7; j++){
    n = size[j];
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

/*...*/
    flop = a.flopMatVecFull();
    ls = a.loadStore();
/*...................................................................*/

/*... liberando a memoria*/
    y.dealloc();
    x.dealloc();
    a.dealloc();
/*...................................................................*/

/*...*/
    cout << endl;
    cout << "Time1    = " << time1   << endl;
    cout << "flops    = " << (flop/time1)/gm << " GFlops" << endl;
    cout << "bandwith = " << (ls/time1)/gm   << " GBytes/s" << endl;
/*...................................................................*/

/*...*/
    fOut << n <<","<< time1 <<","<<(flop/time1)/gm<<","<<(ls/time1)/gm
         << endl;
/*...................................................................*/
  }
/*...................................................................*/

/*...*/
  fOut.close();
/*...................................................................*/

/*... Versao com stl*/
  vector<double> a1;
  vector<double> x1, y1;

/*...*/ 
  fOut.open("tempos_cpp_vector.csv");
  if (!fOut.is_open()) {
    cout << "Erro na arbertura do arquivo!" << endl;
    exit(-1);
  }
  fOut << "size,time,flop,bandwith" << endl;
/*...................................................................*/


/*...*/
  for(int j = 0; j < 11; j++){
    n = size[j];
  
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

/*...*/
    cout << endl;
    cout << "Time2    = " << time2   << endl;
    cout << "flops    = " << (flop/time2)/gm  << " GFlops"   << endl;
    cout << "bandwith = " << (ls/time2)/gm    << " GBytes/s" << endl;
/*...................................................................*/
  }
/*...................................................................*/

/*...*/
  fOut.close();
/*...................................................................*/

  return 0;

}
/********************************************************************/

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
        tmp += a[j * n + i] * x[j];
      y[i] = tmp;
    }
/*...................................................................*/

/*...*/
  else
    for (int i = 0; i < n; i++) {
      tmp = 0.e0;
      for (int j = 0; j < n; j++) 
        tmp += a[i * n + j] * x[j];
      y[i] = tmp;
    }
/*...................................................................*/ 

}
/********************************************************************/