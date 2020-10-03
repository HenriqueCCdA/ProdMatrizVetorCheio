#include"../include/RandomCc.h"

void makeMatrixAndVector(Matrix &a, Vector &x, int const n) 
{
  default_random_engine defEngine;
  uniform_real_distribution<double> unif(-100.0,100.0);

  for (int i = 0; i < n; i++) {
    x.setCoef(i, unif(defEngine));
    for (int j = 0; j < n; j++) 
    {
      a.setCoef(i, j, unif(defEngine));
    }
  }

}