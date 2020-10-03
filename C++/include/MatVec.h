#ifndef _MATVEC_H
  #define _MATVEC_H

  #include<iostream>
  #include<string>

 
  using std::cout;
  using std::endl;
  using std::bad_alloc;
  using std::string;


  class Vector {
  
    private:
      double *coef = nullptr;
      int nLin;
      string name;
    
    public:
  
      void alloc(const int nLin, string name);
  
      double getCoef(int i);
  
      void setCoef(int i, double a);
      
      void dealloc(); 
  
      ~Vector();
  };
  
  
  class Matrix {
  
    private:
      double *coef = nullptr;
      int nLin, nCol; 
      string name;
    public:
  
      void alloc(const int nLin, const int nCol, string name);
  
      double getCoef(int i, int j);;
  
      void setCoef(int i, int j, double a);
      
      void dealloc();
  
      Vector& matVec(Vector& x, Vector& y, bool transp = false);
  
      ~Matrix(); 
  };


#endif
