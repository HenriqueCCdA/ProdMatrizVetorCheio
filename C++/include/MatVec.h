#ifndef _MATVEC_H
  #define _MATVEC_H

  #include<iostream>
  #include<string>

 
  using std::cout;
  using std::endl;
  using std::bad_alloc;
  using std::string;
  using std::ostream;


  class Vector {
  
    private:
      double *coef = nullptr;
      int nLin;
      string name;
    
    public:
  
      void alloc(const int nLin, string name);
  
      double getCoef(int i) const;
  
      double* data(void) const;

      void setCoef(int i, double a);
        
      void dim(int &nLin) const;

      double& operator[](const int i) const;

      friend ostream& operator<<(ostream& os, Vector &x);

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
  
      double getCoef(int i, int j) const;

      double* data(void) const;
  
      void setCoef(int i, int j, double a);
      
      void dim(int &nLin, int &nCol) const;

      void dealloc();
  
      double& operator[](const int i) const;

      Vector& matVec(Vector& x, Vector& y, bool transp = false) const;
      
      friend ostream& operator<<(ostream& os, Matrix &x);

      ~Matrix(); 
  };


#endif
