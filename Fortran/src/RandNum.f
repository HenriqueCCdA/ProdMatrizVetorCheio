c********************************************************************* 
c * Data de criacao    : 02/10/2020                                   *
c * Data de modificaco : 00/00/0000                                   *
c *-------------------------------------------------------------------*
c * makeMatrixAndVector : gera o matriz e vetor x com numeros         *
c * aletorios entre -100.0 e 100.0                                    * 
c *-------------------------------------------------------------------* 
c * Parametros de entrada:                                            * 
c *-------------------------------------------------------------------*
c * a - nao definido                                                  *
c * x - nao definido                                                  *
c * n - numero de elementos                                           *  
c *-------------------------------------------------------------------* 
c * Parametros de saida:                                              * 
c *-------------------------------------------------------------------* 
c * a - matriz                                                        *
c * x - vetor x                                                       *
c *-------------------------------------------------------------------* 
c * OBS:                                                              * 
c *-------------------------------------------------------------------* 
c *********************************************************************      
      subroutine make_matrix_vector(a, x, n)
      implicit none
      integer n, i, j, clock, status
      integer isize
      integer, allocatable :: new_seed(:)
      real(8) a(n, *), x(*)
      real(8) random_number_double
c ...................................................................
c
c ...
      clock = 1
      call random_seed(size = isize)
      allocate (new_seed(isize), stat = status)
      if ( status .ne. 0 ) then
        print*,'Erro na setar a semente'
        stop(-1)
      endif
c ...
      do i = 1, isize
        new_seed(i) = clock + 37 * (i-1)
      enddo
c     new_seed = clock + 37 * (/ (i - 1, i = 1, isize) /)
c ...
      call random_seed(put = new_seed)
      deallocate(new_seed)
c ...................................................................
c
c ...
      do j = 1, n
        x(j) = random_number_double(1.d0)
        do i = 1, n
          a(i, j) = random_number_double(100.d0)
        enddo
      enddo
c ...................................................................
c
c ...
      return
      end
c ********************************************************************
c
c********************************************************************* 
c* Data de criacao    : 09/10/2020                                   *
c* Data de modificaco : 00/00/0000                                   *
c*-------------------------------------------------------------------*
c* randNum : gera o numero aletorio entre -100 e 100                 * 
c*-------------------------------------------------------------------* 
c* Parametros de entrada:                                            * 
c*-------------------------------------------------------------------* 
c*-------------------------------------------------------------------* 
c* Parametros de saida:                                              * 
c*-------------------------------------------------------------------* 
c* numero aletorio entre -100.0 e 100.0                              * 
c*-------------------------------------------------------------------* 
c* OBS:                                                              * 
c*-------------------------------------------------------------------* 
c*********************************************************************/
      real(8) function random_number_double(limt)
      implicit none
      integer signal
      real(8) num, limt
      
      call random_number(num)
c ... sinal
      signal = int(num * 10)
      if ( mod(signal, 2) .eq. 0 ) then
        signal = -1
      else
        signal = 1
      endif
c ....................................................................
      random_number_double =  signal * limt * num
      return
      end
c ********************************************************************
       
      