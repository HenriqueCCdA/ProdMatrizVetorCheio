#include<iostream>
#include<string>
#include<chrono>
#include"../include/MatVec.h"
#include"../include/HccaTimeCc.h"
#include"../include/RandomCc.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
  
  TimeCc timer;
  const int n = 5000, nSamples = 10;
  Matrix a;
  Vector x, y;
  double time;


/*... alocando memoria*/
  a.alloc(n, n, "a");
  x.alloc(n, "x");
  y.alloc(n, "y");
/*...................................................................*/
 
/*...*/
  makeMatrixAndVector(a, x);
/*...................................................................*/
  
/*...*/    
  time = 0.e0;
  for(int i = 0; i< nSamples; i++){
    timer.tic();
    y = a.matVec(x, y);
    time += timer.toc();
  }
/*...................................................................*/

  
/*... liberando a memoria*/
  y.dealloc();
  x.dealloc();
  a.dealloc();
/*...................................................................*/

  cout << "Time:" << time << endl;

  return 0;

}