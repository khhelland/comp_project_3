#include "planet.h"
#include "solarsystem.h"


int main()
{
  solarsystem sys;
      
  planet earth(3.04*pow(10,-6),0.9926598236134114295, 0.1314535015514286531,
               -0.9294900967962320681, 6.205920252093473977);
  sys.add_planet(earth);

     
  planet jupiter(100*9.54*pow(10,-4),-3.195948618635423344e+00, 4.215460718186131217e+00,
                 -2.231558133501658769e+00, -1.536277437379472310e+00);
  sys.add_planet(jupiter);

  sys.sun_in_origin = 1;
  
  sys.h = 0.001;  //timestep (in years)
  sys.T = 500;     //simulated time (in years)
  

  sys.initialize();
  //perform simulation with rk4 integration
  sys.simulate("jup_rk4.dat");

  sys.reset();
  sys.use_verlet = 1;
  //perform simulation with verlet integration
  sys.simulate("jup_verlet.dat");
  
  
  
  
  return 0;
}

