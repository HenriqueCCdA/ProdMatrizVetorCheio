#ifndef _RANDOMCC_H
  #define _RANDOMCC_H
  #include<random>
  #include<array>

  #include"MatVec.h"

  using std::default_random_engine;
  using std::uniform_real_distribution;
  using std::vector;

  void makeMatrixAndVector(Matrix &a, Vector &x); 
  void makeMatrixAndVector(vector <double> &a, vector<double> &x); 

#endif