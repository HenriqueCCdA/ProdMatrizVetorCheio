#ifndef _RANDOMCC_H
  #define _RANDOMCC_H
  #include<random>

  #include"MatVec.h"

  using std::default_random_engine;
  using std::uniform_real_distribution;

  void makeMatrixAndVector(Matrix &a, Vector &x); 

#endif