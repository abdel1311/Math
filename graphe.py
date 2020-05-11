import numpy as np
import pylab as plt

#Euler
Euler = np.loadtxt('vel_euler.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='v', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='.', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitessse en fonction du temps (calcul Analytique et intorpolation d'Euler)")
plt.legend()
plt.draw()
plt.savefig('Euler.png')
plt.show()

#Erreur
Erreur = np.loadtxt('Erreur_euler.dat',delimiter=';')
Xe = Erreur[:,0]
Ye = Erreur[:,1]

Erreur = np.loadtxt('Erreur_RK2.dat',delimiter=';')
Xa = Erreur[:,0]
Ya = Erreur[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='v', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='.', label='RK2')

plt.xlabel('Pas')
plt.ylabel('Erreur')
plt.grid()
plt.title("Erreur en fonction du Pas avec la méthode D'Euler et la méthode RK2")
plt.legend()
plt.draw()
plt.savefig('Erreur.png')
plt.show()

#Alpha
alpha = np.loadtxt('Erreur_alpha.dat',delimiter=';')
Xe = alpha[:,0]
Ye = alpha[:,1]


plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='v', label='Alpha')

plt.xlabel('alpha')
plt.ylabel('Erreur')
plt.grid()
plt.title("Erreur en fonction de alpha pour la méthode d'Euler")
plt.legend()
plt.draw()
plt.savefig('Erreur_alpha.png')
plt.show()

#AlphVOa
Erreur = np.loadtxt('Erreur_V0.dat',delimiter=';')
Xe = Erreur[:,0]
Ye = Erreur[:,1]


plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='v', label='V0')

plt.xlabel('V0')
plt.ylabel('Erreur')
plt.grid()
plt.title("Erreur en fonction de V0 pour la méthode d'Euler")
plt.legend()
plt.draw()
plt.savefig('Erreur_V0.png')
plt.show()

