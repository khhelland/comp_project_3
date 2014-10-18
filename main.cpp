#include "planet.h"
#include "solarsystem.h"

/*

Simulation of the solarsystem. The sun, the planets and pluto are included.
The orbits are assumed to be co-planar. Initial positions and velocities
taken from NASA JPL-Horizons service for the 01/10/14.

Data are written to files rk4.dat and verlet.dat

*/ 

int main()
{
  solarsystem sys;
  
  planet mercury(1.66*pow(10,-7),2.891579653089670909e-01, -2.973035768768551024e-01,
                 5.328211478776806231e+00, 7.653104362788712756e+00);
  sys.add_planet(mercury);
  
  planet venus(2.45*pow(10,-6),-7.120321017868672664e-01, 9.534957023690887601e-02,
               -1.020587871423627169e+00, -7.354826898708207494e+00);
  sys.add_planet(venus);
  
  planet earth(3.04*pow(10,-6),0.9926598236134114295, 0.1314535015514286531,
               -0.9294900967962320681, 6.205920252093473977);
  sys.add_planet(earth);

  planet mars(3.22*pow(10,-7),5.054321898365009558e-01, -1.323108635735029459e+00,
              4.968438385776908994e+00, 2.263252553556237334e+00);
  sys.add_planet(mars);
  
   
  planet jupiter(9.54*pow(10,-4),-3.195948618635423344e+00, 4.215460718186131217e+00,
                 -2.231558133501658769e+00, -1.536277437379472310e+00);
  sys.add_planet(jupiter);

  planet saturn(2.86*pow(10,-4),-5.803524428416712233e+00, -8.057934342432369945e+00,
                1.541109276807109518e+00, -1.197785582409434557e+00);
  sys.add_planet(saturn);
  
  planet uranus(4.37*pow(10,-5), 1.939869839402791740e+01, 4.918716656512554408e+00,
                -3.651243978316410788e-01, 1.323882720750786390e+00);
  sys.add_planet(uranus);
 
  planet neptune(5.15*pow(10,-5),2.741374814978993868e+01, -1.210889881163006621e+01,
                 4.541296864159617419e-01, 1.054022781736224212e+00);
  sys.add_planet(neptune);
 
  planet pluto(7.40*pow(10,-9),7.110848056998247735e+00, -3.192380177445107492e+01,
               1.136967060820863296e+00, 1.058507732076280523e-02);
  sys.add_planet(pluto);
 
  // Give the sun an initial velocity so that the total momentum of the system is zero:

  double vx = 0;
  double vy = 0;
  for(int i = 0; i<sys.planets.size();i++)
    {
      vx -= sys.planets[i].mass*sys.planets[i].velocity(0);
      vy -= sys.planets[i].mass*sys.planets[i].velocity(1);
    }

  planet sun(1,0,0,vx,vy);
  sys.add_planet(sun);
  

  sys.h = 0.001;  //timestep (in years)
  sys.T = 50;     //simulated time (in years)
  
  sys.initialize();
  //perform simulation with rk4 integration
  sys.simulate("rk4.dat");

  sys.reset();
  sys.use_verlet = 1;
  //perform simulation with verlet integration
  sys.simulate("verlet.dat");
  
  
  
  
  return 0;
}

