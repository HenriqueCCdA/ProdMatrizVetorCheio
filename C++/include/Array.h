#ifndef _MATVEC_H
  #define _MATVEC_H

  #include<iostream>
  #include<string>

 
  using std::cout;
  using std::endl;
  using std::bad_alloc;
  using std::string;
  using std::ostream;


  class Array {
  
    protected:
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

      friend ostream& operator<<(ostream& os, Array &x);

      void dealloc(); 
  
      ~Array();
  };
  
  
  class Array2D : public Array{
  
    private:
      int nCol; 

    public:
  
      void alloc(const int nLin, const int nCol, string name);
  
      double getCoef(int i, int j) const;
 
      void setCoef(int i, int j, double a);
      
      void dim(int &nLin, int &nCol) const;
 
      Array& matVec(Array& x, Array& y, bool transp = false) const;
      
      long loadStore(void) const;

      long flopMatVecFull(void) const;

      friend ostream& operator<<(ostream& os, Array2D &x);
  };


#endif
