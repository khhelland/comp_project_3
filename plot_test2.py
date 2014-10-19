import numpy as np
import matplotlib.pyplot as plt
import os,sys
from plotter import *
from math import pi

error = os.system('make -f make_test2')
if error:
    print "make error"
    sys.exit(1)

error = os.system('./test2.x')
if error:
    print "runtime error"
    sys.exit(1)

rk4 = np.loadtxt('jup_rk4.dat')
plot_rk4(rk4)
planets = "earth","jupiter"
plt.legend(planets)

r = np.sqrt(rk4[:,0]**2 + rk4[:,1]**2)
v = (rk4[:,2]**2 + rk4[:,3]**2)**0.5
dK = abs(v/v[0]-1)
dV = abs(r/r[0]-1)

print "rk4:"
print "Maximum rel diff in v:",max(dK), "max rel diff in r:",max(dV)

verlet = np.loadtxt('jup_verlet.dat')
plot_verlet(verlet)
plt.legend(planets)
r = np.sqrt(verlet[:,0]**2 + verlet[:,1]**2)
vx = (verlet[1:,0]-verlet[:-1,0])/0.001
vy = (verlet[1:,1]-verlet[:-1,1])/0.001
v = (vx**2 + vy**2)**0.5
dK = v/v[0]-1
dV = r/r[0]-1

print "verlet:"
print "Maximum rel diff in v:",max(dK), "max rel diff in r:",max(dV)





plt.show()
