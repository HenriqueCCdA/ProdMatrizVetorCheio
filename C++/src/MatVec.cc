#include"../include/MatVec.h"

void Vector::alloc(const int nLin, string name) {
      
  this->nLin = nLin;
  this->name = name;
  try{
    this->coef = new double[nLin];
  }
  catch (bad_alloc E){
    cout << "N�o h� memoria suficiente" << this->name << endl;
  }

}

double Vector::getCoef(int i){
  return this->coef[ i ];
}

void Vector::setCoef(int i, double a){
  this->coef[ i ] = a;
}

void Vector::dealloc() {
  
  int nl = this->nLin;

  if(this->coef){
    delete [] this->coef;
    this->coef = nullptr;
  }
}

Vector::~Vector() {
  cout<< "chamando destrutor para "<< this->name << '.' << endl; 
  this->dealloc();
}


/********************************************************************* 
 * Data de criacao    : 03/10/2020                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * alloc : inicializado e alocando a matriz                          * 
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * nLin   - numero de linhas                                         *
 * nCol   - numero de colunas                                        *
 * name   - nome do arranjo                                          * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
 *********************************************************************/
void Matrix::alloc(const int nLin, const int nCol, string name) {
  
  this->nLin = nLin;
  this->nCol = nLin;
  this->name = name;

  try{
    this->coef = new double[nLin*nCol];
  }
  catch (bad_alloc E){
    cout << "N�o h� memoria suficiente" << this->name << endl;
  }

}
/********************************************************************/

double Matrix::getCoef(int i, int j){
  return this->coef[ i * this->nCol + j];
}

void Matrix::setCoef(int i, int j, double a){
  this->coef[ i * this->nCol + j] = a;
}

void Matrix::dealloc() {
  
  int nl = this->nLin;
  int nc = this->nCol;
  if(this->coef){
    delete [] this->coef;
    this->coef = nullptr;
  }
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
Vector& Matrix::matVec(Vector& x, Vector& y, bool transp) {

  int nl = this->nLin;
  int nc = this->nCol;
  double tmp = 0.e0;

  if(transp)
    for (int i = 0; i < nc; i++) {
      tmp = 0.e0;
      for (int j = 0; j < nl; j++) 
        tmp += this->getCoef(j, i) * x.getCoef(i);
      y.setCoef(i, tmp);
    }

  else
    for (int i = 0; i < nl; i++) {
      tmp = 0.e0;
      for (int j = 0; j < nc; j++) 
        tmp += this->getCoef(i, j) * x.getCoef(i);
      y.setCoef(i, tmp);
    }
  


  return y;

}

Matrix::~Matrix() {
  cout<< "chamando destrutor para " << this->name << '.' << endl;    
  this->dealloc();
}
