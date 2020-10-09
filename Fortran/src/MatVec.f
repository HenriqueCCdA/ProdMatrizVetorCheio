c********************************************************************* 
c* Data de criacao    : 09/10/2020                                   *
c* Data de modificaco : 00/00/0000                                   *
c*-------------------------------------------------------------------*
c* MATVECFULL : operacao matriz vetor para matriz cheias             * 
c*-------------------------------------------------------------------* 
c* Parametros de entrada:                                            * 
c*-------------------------------------------------------------------* 
c* a          - vetor a                                              * 
c* x          - vetor b                                              * 
c* y          - indefinido                                           * 
c* n_lin      - numero de linhas                                     *
c* n_col      - numero de colunas                                    *   
c* fTranspose - multipicar pela matriz transposta                    *
c* ------------------------------------------------------------------* 
c* Parametros de saida:                                              * 
c*-------------------------------------------------------------------* 
c* y  - produto vetoria entre a e b                                  * 
c*-------------------------------------------------------------------* 
c* OBS:                                                              * 
c*-------------------------------------------------------------------* 
c*********************************************************************/      
      subroutine matvec(a, x, y, nLin, nCol, fTranspose)
      implicit none
      logical fTranspose
      integer i, j, nLin, nCol      
      real(8) a(nLin, *), x(*), y(*), xi, tmp
c ...
      if(fTranspose) then
        do j = 1, nCol
          tmp  = 0.e0
          do i = 1, nLin
            tmp = tmp + a(i, j) * x(i)
          enddo
          y(j) = tmp
        enddo
c .....................................................................
c
c ...
      else
        do j = 1, nCol
          xi = x(j)
          y(j) = 0.e0
          do i = 1, nLin
            y(j) = y(j) + a(i, j) * xi
          enddo
        enddo
      endif
c .....................................................................
c
c ...
      return
      end
c *********************************************************************
c
c********************************************************************* 
c* Data de criacao    : 09/10/2020                                   *
c* Data de modificaco : 00/00/0000                                   *
c*-------------------------------------------------------------------*
c* loadStore : Calculo do numero numero de load e store              * 
c*-------------------------------------------------------------------* 
c* Parametros de entrada:                                            * 
c*-------------------------------------------------------------------* 
c* nLin -> numero de linhas                                          * 
c* nCol -> numero de colunas                                         * 
c*-------------------------------------------------------------------* 
c* Parametros de saida:                                              * 
c*-------------------------------------------------------------------* 
c* Numero de load store                                              * 
c*-------------------------------------------------------------------* 
c* OBS:                                                              * 
c*-------------------------------------------------------------------* 
c*********************************************************************/ 
      integer(8) function flop_matvec_full(n_lin, n_col)
      implicit none
      integer n_lin, n_col
      flop_matvec_full = n_lin * ( 2*n_col - 1)
      return
      end
c *********************************************************************
c
c*********************************************************************
c* Data de criacao    : 09/10/2020                                   *
c* Data de modificaco : 00/00/0000                                   *
c*-------------------------------------------------------------------*
c* FLOPMATVECFULL : Calculo do numero de flops da operacao de matiz  * 
c* por um vetor, onde a matriz e uma matriz densa                    * 
c*-------------------------------------------------------------------* 
c* Parametros de entrada:                                            * 
c*-------------------------------------------------------------------* 
c* nLin -> numero de linhas                                          * 
c* nCol -> numero de colunas                                         * 
c*-------------------------------------------------------------------* 
c* Parametros de saida:                                              * 
c*-------------------------------------------------------------------* 
c* Numero de flops                                                   * 
c*-------------------------------------------------------------------* 
c* OBS:                                                              * 
c*-------------------------------------------------------------------* 
c*********************************************************************
      integer(8) function load_store(n_lin, n_col)
      implicit none
      integer n_lin, n_col
      load_store = n_lin * ( 2*n_col + 1)
      return
      end
c *********************************************************************