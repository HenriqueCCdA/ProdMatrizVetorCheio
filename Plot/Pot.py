import pandas as pd
import matplotlib.pyplot as plt


def read(prefix, n = 6):

    df_t  = pd.DataFrame()
    df_fp = pd.DataFrame()
    df_f  = pd.DataFrame()
    for i in range(0, n):
        name = f'{prefix}_{i}.csv'
        df = pd.read_csv("../Data/"+name, skipinitialspace=True)    
        df_t[f'time_{i}'] = df['time'] 
        df_fp[f'flop_{i}'] = df['flop'] 

    media = df_t.mean(axis=1)
    desvio_padrao = df_t.std(axis=1)
    
    media_fp = df_fp.mean(axis=1)
    desvio_padrao_fp = df_fp.std(axis=1)
           
    df_f['media_time'] = media
    df_f['desvio_padrao_time'] = desvio_padrao

    df_f['media_fp'] = media_fp
    df_f['desvio_padrao_fp'] = desvio_padrao_fp


    df_f['size'] = df['size']

    
    return df_f


df_c = read('tempos_c', n = 7)
df_f = read('tempos_fortran', n = 7)
df_cpp = read('tempos_cpp', n = 5)
df_stl_cpp = read('tempos_cpp_vector', n = 5)
df_python = read('tempos_python', n = 6)
print(df_f.tail())
print(df_c.tail())
print(df_cpp.tail())
print(df_stl_cpp.tail())

# tempo

fig = plt.figure(figsize = (15, 6))
#fig = plt.figure()

ax = fig.add_axes([0, 0, 1, 1])

ax.plot(df_cpp['size'], df_cpp['media_time'], color = 'b', label = 'C++', marker = 'x')
ax.plot(df_stl_cpp['size'], df_cpp['media_time'], color = 'g', label = 'STL-C++', marker = 'v')
ax.plot(df_c['size'], df_c['media_time'], color = 'r', label = 'C', marker = '^')
ax.plot(df_f['size'], df_f['media_time'], color = 'k', label = 'Fortran', marker = 's')
ax.plot(df_python['size'], df_python['media_time'], color = 'magenta', label = 'Python-mkl', marker = 'o')
ax.legend(fontsize = 15)
ax.grid(True)
ax.set_xlabel("Numero de equações", fontsize = 15)
ax.set_ylabel("Tempo (s)", fontsize = 15)
ax.set_xlim(900, 23000)

fig.savefig("../Fig/tempos.png", dpi = 300, bbox_inches='tight', pad_inches = 0)
plt.close(fig) 

# flops
fig = plt.figure(figsize = (15, 6))

ax = fig.add_axes([0, 0, 1, 1])

ax.plot(df_cpp['size'], df_cpp['media_fp'], color = 'b', label = 'C++', marker = 'x')
ax.plot(df_stl_cpp['size'], df_cpp['media_fp'], color = 'g', label = 'STL-C++', marker = 'v')
ax.plot(df_c['size'], df_c['media_fp'], color = 'r', label = 'C', marker = '^')
ax.plot(df_f['size'], df_f['media_fp'], color = 'k', label = 'Fortran', marker = 's')
ax.plot(df_python['size'], df_python['media_fp'], color = 'magenta', label = 'Python-mkl', marker = 'o')
ax.legend(fontsize = 15)
ax.grid(True)
ax.set_xlabel("Numero de equações", fontsize = 15)
ax.set_ylabel("GFlops", fontsize = 15)
ax.set_ylim(0, 6)
ax.set_xlim(900, 23000)

fig.savefig("../Fig/flops.png", dpi = 300, bbox_inches='tight', pad_inches = 0)
plt.close(fig) 

# loadsores
#fig = plt.figure(figsize = (15, 6))

#ax = fig.add_axes([0, 0, 1, 1])


#ax.plot(df_cpp['size'], df_cpp['bandwith'], color = 'b', label = 'C++')
#ax.plot(df_vector_cpp['size'], df_cpp['bandwith'], color = 'g', label = 'STL-C++')
#ax.plot(df_c['size'], df_c['bandwith'], color = 'r', label = 'C')
#ax.plot(df_f['size'], df_f['bandwith'], color = 'k', label = 'Fortran')
#ax.legend(fontsize = 15)
#ax.grid(True)
#ax.set_xlabel("Numero de equações", fontsize = 15)
#ax.set_ylabel("Bandwith GBytes", fontsize = 15)
#ax.set_xlim(0, 23000)


#fig.show()


