import numpy as np
import matplotlib.pyplot as plt
import os,sys

#make programs


error = os.system('make')
if error:
    print 'make funket ikke'
    sys.exit(1)

run = './main.x'
error = os.system(run)
if error:
    print 'runtime error'
    sys.exit(1)

#Fetch simulation
system = np.loadtxt('system.dat')
verlet = np.loadtxt('verlet.dat')


#Plot data 
plt.figure()
plt.plot(system[:,0],system[:,2],'-')
plt.title('rk4')
plt.figure()
plt.plot(verlet[:,0],verlet[:,1],'-')
plt.title('verlet')
plt.show()

