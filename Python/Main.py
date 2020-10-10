import numpy as np
import time as tp
import os
import mkl

from MatVec import matvec, flops, load_store

os.environ['MKL_NUM_THREADS'] = '1'

print(f'Numero de threads {mkl.get_max_threads()}')
print(mkl.verbose(False))


def make_matrix_vector(n):

    x = np.random.rand(n)
    a = np.random.rand(n, n)

    return a, x


def main():

    list_n =  (            900, 1300, 1700, 2100, 2500,
              2900, 3300, 3700, 4100, 4500, 4900, 5300,
              5700, 6100, 6500, 6900, 7300, 7700, 8100,
              8500, 8900, 9300, 9700,10100,10500,10900,
             11300,11700,12100,12500,12900,13300,13700,
             14100,14500,14900,15300,15700,16100,16500,
             16900,17300,17700,18100,18300,18500,19300,
             19700,20500,20900,21300,22100,22500,23000)

    # ...
    n_samples: int = 10
    gm: float = 1.e+9
    # ........................................................................

    # ... abrindo arquivo
    f = open('tempos_python.csv', 'w')
    f.write("size,time,flop,bandwidth\n")
    # ........................................................................

    # ...
    for n in list_n:
        # ...
        a, x = make_matrix_vector(n)
        # ....................................................................

        # ...
        time = 0.0
        for _ in range(0, n_samples):
            tic = tp.time()
            y = matvec(a, x)
            toc = tp.time()
            time += toc - tic
        # .....................................................................

        # ...
        flop = flops(n, n)
        ls   = 8 * load_store(n, n)
        time /= n_samples
        # .....................................................................

        # ...
        print(f'Time      = {time:16.4f}')
        print(f'Flops     = {(flop/time)/gm:16.4f}')
        print(f'Bandwithd = {(ls/time)/gm:16.4f}')
        # .....................................................................

        # ... escrevendo no arquivo
        f.write(f"{n},{time},{(flop/time)/gm},{(ls/time)/gm}\n")
        # .....................................................................

    # ...
    f.close()
    # .........................................................................

if __name__ == '__main__':
    main()