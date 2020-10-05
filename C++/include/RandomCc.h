#ifndef _RANDOMCC_H
  #define _RANDOMCC_H
  #include<random>
  #include<array>

  #include"Array.h"

  using std::default_random_engine;
  using std::uniform_real_distribution;
  using std::vector;

  void makeMatrixAndVector(Array2D &a, Array &x); 
  void makeMatrixAndVector(vector <double> &a, vector<double> &x); 

#endif