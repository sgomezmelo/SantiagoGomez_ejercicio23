import matplotlib.pyplot as plt
import numpy as np

datos = np.loadtxt('datos.txt')

x = datos[1:,0]
u_1 = datos[1:,1]
u_2 = datos[1:,2]
u_3 = datos[1:,3]
u_4 = datos[1:,4]

plt.figure()
plt.plot(x,u_1, label = 't = ' + str(datos[0,1]))
plt.plot(x,u_2,label = 't = ' + str(datos[0,2]))
plt.plot(x,u_3,label = 't = ' + str(datos[0,3]))
plt.plot(x,u_4,label = 't = ' + str(datos[0,4]))
plt.legend()
plt.savefig('onda.pdf')
