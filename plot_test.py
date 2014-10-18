import numpy as np
import matplotlib.pyplot as plt
import os,sys
from plotter import *
from math import pi

error = os.system('make -f make_test')
if error:
    print "make error"
    sys.exit(1)

error = os.system('./test.x')
if error:
    print "runtime error"
    sys.exit(1)

circular_rk4 = np.loadtxt('circular_rk4.dat')
#plot_rk4(circular_rk4)

r = np.sqrt(circular_rk4[:,0]**2 + circular_rk4[:,1]**2)
v2 = circular_rk4[:,2]**2 + circular_rk4[:,3]**2
dE_rk4 = abs(2*r - v2/(4*pi**2)-1)
print max(dE_rk4)
# plt.figure()
# plt.plot(dE_rk4)
# plt.xlabel('timesteps')
# plt.ylabel('relative error in energy')
# plt.title('rk4')

circular_verlet = np.loadtxt('circular_verlet.dat')
#plot_verlet(circular_verlet)

r = np.sqrt(circular_verlet[:,0]**2 + circular_verlet[:,1]**2)
vx = (circular_verlet[1:,0]-circular_verlet[:-1,0])/0.01
vy = (circular_verlet[1:,1]-circular_verlet[:-1,1])/0.01
print vx[0],vy[0]
print vx[0]**2+ vy[0]**2

v2 = vx**2 + vy**2
dE_verlet = abs(2*r[:-1] - v2/(4*pi**2) -1)
print max(dE_verlet)
# plt.figure()1
# plt.plot(dE_verlet)
# plt.xlabel('timesteps')
# plt.ylabel('relative error in energy')
# plt.title('verlet')


# plt.show()
