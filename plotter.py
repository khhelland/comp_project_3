import numpy as np
import matplotlib.pyplot as plt
import os

#make programs


os.system('make')

run = './ODEsolver.x'
os.system(run)

#Fetch simulation
system = np.loadtxt('system.dat')
x = system[0,:]
y =system[2,:]


#Plot data 
plt.plot(x,y,'-')
plt.show()

