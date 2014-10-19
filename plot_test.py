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
plot_rk4(circular_rk4)

r = np.sqrt(circular_rk4[:,0]**2 + circular_rk4[:,1]**2)
v2 = circular_rk4[:,2]**2 + circular_rk4[:,3]**2
dK = abs(v2/v2[0]-1)
dV = abs(r[0]/r-1)

print "rk4:"
print "Maximum rel err in K:",max(dK), "max rel err in V:",max(dV)

circular_verlet = np.loadtxt('circular_verlet.dat')
plot_verlet(circular_verlet)

r = np.sqrt(circular_verlet[:,0]**2 + circular_verlet[:,1]**2)
vx = (circular_verlet[1:,0]-circular_verlet[:-1,0])/0.001
vy = (circular_verlet[1:,1]-circular_verlet[:-1,1])/0.001
v2 = vx**2 + vy**2
dK = v2/v2[0]-1
dV = r[0]/r-1

print "verlet:"
print "Maximum rel err in K:",max(dK), "max rel err in V:",max(dV)


plt.title('verlet')


plt.show()
