import pandas as pd
import matplotlib.pyplot as plt


df_cpp = pd.read_csv("../Data/tempos_cpp.csv")
df_vector_cpp = pd.read_csv("../Data/tempos_cpp_vector.csv")
df_c = pd.read_csv("../Data/tempos_c.csv")
df_f = pd.read_csv("../Data/tempos_fortran.csv", skipinitialspace=True)
# tempo
fig = plt.figure(figsize = (15, 6))

ax = fig.add_axes([0, 0, 1, 1])

ax.plot(df_cpp['size'], df_cpp['time'], color = 'b', label = 'C++')
ax.plot(df_vector_cpp['size'], df_cpp['time'], color = 'g', label = 'STL-C++')
ax.plot(df_c['size'], df_c['time'], color = 'r', label = 'C')
ax.plot(df_f['size'], df_f['time'], color = 'k', label = 'Fortran')
ax.legend(fontsize = 15)
ax.grid(True)
ax.set_xlabel("Numero de equações", fontsize = 15)
ax.set_ylabel("Tempo medio", fontsize = 15)
ax.set_xlim(0, 23000)

# flops
fig = plt.figure(figsize = (15, 6))

ax = fig.add_axes([0, 0, 1, 1])

ax.plot(df_cpp['size'], df_cpp['flop'], color = 'b', label = 'C++')
ax.plot(df_vector_cpp['size'], df_cpp['flop'], color = 'g', label = 'STL-C++')
ax.plot(df_c['size'], df_c['flop'], color = 'r', label = 'C')
ax.plot(df_f['size'], df_f['flop'], color = 'k', label = 'Fortran')
ax.legend(fontsize = 15)
ax.grid(True)
ax.set_xlabel("Numero de equações", fontsize = 15)
ax.set_ylabel("GFlops", fontsize = 15)
ax.set_xlim(0, 23000)


# loadsores
fig = plt.figure(figsize = (15, 6))

ax = fig.add_axes([0, 0, 1, 1])


ax.plot(df_cpp['size'], df_cpp['bandwith'], color = 'b', label = 'C++')
ax.plot(df_vector_cpp['size'], df_cpp['bandwith'], color = 'g', label = 'STL-C++')
ax.plot(df_c['size'], df_c['bandwith'], color = 'r', label = 'C')
ax.plot(df_f['size'], df_f['bandwith'], color = 'k', label = 'Fortran')
ax.legend(fontsize = 15)
ax.grid(True)
ax.set_xlabel("Numero de equações", fontsize = 15)
ax.set_ylabel("Bandwith GBytes", fontsize = 15)
ax.set_xlim(0, 23000)


#fig.show()


