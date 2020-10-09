c **********************************************************************      
      program matvec_prog
c ...
      implicit none
      logical fTranspose
      parameter (fTranspose = .true.)
      integer n, status, n_samples, i, j, isize(56), nout
      real(8), allocatable ::  a(:,:), x(:), y(:)
      real(8) time, get_time
      data isize    /200,  500, 900 , 1300, 1700, 2100, 2500,
     1              2900, 3300, 3700, 4100, 4500, 4900, 5300,
     2              5700, 6100, 6500, 6900, 7300, 7700, 8100,
     3              8500, 8900, 9300, 9700,10100,10500,10900,
     4             11300,11700,12100,12500,12900,13300,13700,
     5             14100,14500,14900,15300,15700,16100,16500,
     6             16900,17300,17700,18100,18300,18500,19300,
     7             19700,20500,20900,21300,22100,22500,23000/ 
      integer(8) load_store, flop_matvec_full
      real(8) flop, ls, gm
      integer nn
      parameter(nn = 56)
c .....................................................................
c 
c ...
      n_samples = 10
      gm = 1.d+09
c .....................................................................
c 
c ... open file
      nout = 15
      open(nout, file = "tempos_fortran.csv", err = 5)
      goto 15
5     continue
      print*,'Erro na abertura do arquivo'
      stop(-1)
15    continue
      write(nout,50) 'size','time','flop','bandwith'
c .....................................................................
c
c ...
      do i = 1, nn
c ...
        n = isize(i)
c ... alocalndo memorio
        allocate (a(n, n), x(n), y(n), stat = status)
        if(status .ne. 0) then
          print*, "Nao ha memoria suficente!"
          stop(-1)
        endif
c .....................................................................
c
        call make_matrix_vector(a, x, n)
c .....................................................................
c
c...
        time = get_time()
        do j = 1, n_samples
          call matvec(a, x, y, n, n, fTranspose)
        enddo
        time = get_time() - time
        
c .....................................................................
c
c ...
        time = time/real(n_samples)
        flop = flop_matvec_full(n, n) / time
        ls = 8 * load_store(n, n) / time
c .....................................................................
c
c ...
        write(*,'(a, f16.6, a)') 'Time     = ', time 
        write(*,'(a, f16.6, a)') 'flops    = ', flop / gm, ' GFlops'
        write(*,'(a, f16.6, a)') 'bandwith = ', ls / gm, ' GBytes/s'
c .....................................................................
c
c ...
        write(nout,100) n, time, flop / gm, ls / gm
c ....................................................................
c
c ... desalocando memoria
        deallocate(a, x, y)
c .....................................................................
      enddo
c .....................................................................
c
c ...
      close(nout)
c ... 
      stop
c100   format("i7,a,f16.6,a,f16.6,a,f16.6")
 50   format(3(a16,','), a16)
100   format(i16,3(',',f16.6))
      end
c **********************************************************************

