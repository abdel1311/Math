import numpy as np
import pylab as plt
import math 
#Question 2.1
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
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler pour N=50)")
plt.legend()
plt.draw()
plt.savefig('Euler.png')
plt.show()

#Question2.2
Erreur = np.loadtxt('Erreur_euler.dat',delimiter=';')
Xe = Erreur[:,0]
Ye = Erreur[:,1]


plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='v', label='Euler')
plt.xlabel('Pas')
plt.ylabel('Erreur')
plt.yscale('log')
plt.xscale('log')
plt.grid()
plt.title("Erreur en fonction du Pas avec la méthode D'Euler en échelle log-log")
plt.legend()
plt.draw()
plt.savefig('Erreur_Euler.png')
plt.show()


#Euler 100 
Euler = np.loadtxt('vel_euler_100.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler pour N=100)")
plt.legend()
plt.draw()
plt.savefig('Euler_100.png')
plt.show()

#Euler 200 
Euler = np.loadtxt('vel_euler_200.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler pour N=200)")
plt.legend()
plt.draw()
plt.savefig('Euler_200.png')
plt.show()



#Euler 400 
Euler = np.loadtxt('vel_euler_400.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler pour N=400)")
plt.legend()
plt.draw()
plt.savefig('Euler_400.png')
plt.show()


#RK2 50
RK2 = np.loadtxt('vel_RK2.dat',delimiter=';')
Xk = RK2[:,0]
Yk = RK2[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('vel_euler.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xk, Yk, lw=2, marker='.', label='RK2')
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler et Runge Kunta 2 pour N=50)")
plt.legend()
plt.draw()
plt.savefig('RK2_50.png')
plt.show()

#RK2 100
RK2 = np.loadtxt('vel_RK2_100.dat',delimiter=';')
Xk = RK2[:,0]
Yk = RK2[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('vel_euler_100.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xk, Yk, lw=2, marker='.', label='RK2')
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler et Runge Kunta 2 pour N=100)")
plt.legend()
plt.draw()
plt.savefig('RK2_100.png')
plt.show()

#RK2 200
RK2 = np.loadtxt('vel_RK2_200.dat',delimiter=';')
Xk = RK2[:,0]
Yk = RK2[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('vel_euler_200.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xk, Yk, lw=2, marker='.', label='RK2')
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler et Runge Kunta 2 pour N=200)")
plt.legend()
plt.draw()
plt.savefig('RK2_200.png')
plt.show()


#RK2 400
RK2 = np.loadtxt('vel_RK2_400.dat',delimiter=';')
Xk = RK2[:,0]
Yk = RK2[:,1]

Euler = np.loadtxt('Ana.dat',delimiter=';')
Xe = Euler[:,0]
Ye = Euler[:,1]

Euler = np.loadtxt('vel_euler_400.dat',delimiter=';')
Xa = Euler[:,0]
Ya = Euler[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xk, Yk, lw=2, marker='.', label='RK2')
plt.plot(Xe, Ye, lw=2, marker='.', label='Euler')
plt.plot(Xa, Ya, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("Vitesse en fonction du temps (calcul Analytique et schema d'Euler et Runge Kunta 2 pour N=400)")
plt.legend()
plt.draw()
plt.savefig('RK2_400.png')
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

#VO
V0 = np.loadtxt('Euler_V0_0.dat',delimiter=';')
Xe = V0[:,0]
Ye = V0[:,1]
Ana = np.loadtxt('Euler_V0_10.dat',delimiter=';')
Xa = Ana[:,0]
Ya = Ana[:,1]

plt.figure(figsize=(8,8))
plt.plot(Xe, Ye, lw=2, marker='.', label='V0=0')
plt.plot(Xa, Ya, lw=2, marker='.', label='V0=10')

plt.xlabel('t (s)')
plt.ylabel('v (m/s)')
plt.grid()
plt.title("vitesse en fonction du temps")
plt.legend()
plt.draw()
plt.savefig('Euler_V0.png')
plt.show()

#quest 6
V0 = np.loadtxt('pos.dat',delimiter=';')
X = V0[:,0]
Y1 = V0[:,1]
Y2 = V0[:,2]
Ana = np.loadtxt('Ana_x.dat',delimiter=';')
Y3 = Ana[:,1]

plt.figure(figsize=(8,8))
plt.plot(X, Y1, lw=2, marker='', label='trapeze')
plt.plot(X, Y2, lw=2, marker='', label='point milieu')
plt.plot(X, Y3, lw=2, marker='', label='Analytique')

plt.xlabel('t (s)')
plt.ylabel('x (m)')
plt.grid()
plt.title("vitesse en fonction du temps")
plt.legend()
plt.draw()
plt.savefig('Position.png')
plt.show()




#quest 7
Euler = np.loadtxt('Accel_Euler.dat',delimiter=';')
X = Euler[:,0]
Y1 = Euler[:,1]
Ana = np.loadtxt('Ana_a.dat',delimiter=';')
Y2 = Ana[:,1]
Ana = np.loadtxt('Accel_ANA.dat',delimiter=';')
Y3 = Ana[:,1]
plt.figure(figsize=(8,8))
plt.plot(X, Y1, lw=2, marker='.', label='Euler')
plt.plot(X, Y2, lw=2, marker='.', label='Analytique')
plt.plot(X, Y3, lw=2, marker='.', label='dérivé progressive d\'Analytique')

plt.xlabel('t (s)')
plt.ylabel('x (m)')
plt.grid()
plt.title("vitesse en fonction du temps")
plt.legend()
plt.draw()
plt.savefig('Accélération.png')
plt.show()