import numpy as np
import matplotlib.pyplot as plt
import os,sys

def plot_rk4(rk4):
    plt.figure()
    plt.hold(1)

    for i in range((len(rk4[0,:])/4)):
        plt.plot(rk4[:,4*i],rk4[:,4*i+1],'-')
    plt.title('rk4')
    plt.xlabel('x [AU]')
    plt.ylabel('y [AU]')
    plt.hold(0)

def plot_verlet(verlet):
    
    plt.figure()
    plt.hold(1)

    for i in range((len(verlet[0,:])/2)):
        plt.plot(verlet[:,2*i],verlet[:,2*i+1],'-')
    plt.title('verlet')
    plt.xlabel('x [AU]')
    plt.ylabel('y [AU]')
    plt.hold(0)




if __name__ == "__main__":
    error = os.system('make')
    if error:
        print 'make funket ikke'
        sys.exit(1)

    run = './main.x'
    error = os.system(run)
    if error:
        print 'runtime error'
        sys.exit(1)

    # # uncomment this part to print information about 
    # # the relative changes in position and velocity
    # # of the first planet to screen:
    
    # # #Fetch simulation
    # rk4 = np.loadtxt('rk4.dat')
    # verlet = np.loadtxt('verlet.dat')
    # r = np.sqrt(rk4[:,0]**2 + rk4[:,1]**2)
    # v = (rk4[:,2]**2 + rk4[:,3]**2)**0.5
    # dK = abs(v/v[0]-1)
    # dV = abs(r/r[0]-1)
    
    # print "rk4:"
    # print "Maximum rel diff in v:",max(dK), "max rel diff in r:",max(dV)
    # r = np.sqrt(verlet[:,0]**2 + verlet[:,1]**2)
    # vx = (verlet[1:,0]-verlet[:-1,0])/0.001
    # vy = (verlet[1:,1]-verlet[:-1,1])/0.001
    # v = (vx**2 + vy**2)**0.5
    # dK = v/v[0]-1
    # dV = r/r[0]-1
    
    # print "verlet:"
    # print "Maximum rel diff in v:",max(dK), "max rel diff in r:",max(dV)

    #Plot data 
    plot_rk4(rk4)
    plot_verlet(verlet)
    
   
    plt.show()

