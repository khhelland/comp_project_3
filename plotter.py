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
rk4 = np.loadtxt('rk4.dat')
verlet = np.loadtxt('verlet.dat')


#Plot data 
plt.figure()
plt.hold(1)

for i in range((len(rk4[0,:])/4)):
    plt.plot(rk4[:,4*i],rk4[:,4*i+1],'-')
plt.title('rk4')



plt.figure()
plt.hold(1)

for i in range((len(verlet[0,:])/2)):
    plt.plot(verlet[:,2*i],verlet[:,2*i+1],'-')
plt.title('verlet')


# plt.figure()
# plt.plot(verlet[:,0],verlet[:,1],'-')
# plt.title('verlet')
plt.show()

