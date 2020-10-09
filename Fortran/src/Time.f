c *********************************************************************     
      real*8 function get_time()
      implicit none
      include 'omp_lib.h'
      real*8 time
      time = 0.d0
c$    time = omp_get_wtime()
      get_time = time
      return
      end
c *********************************************************************