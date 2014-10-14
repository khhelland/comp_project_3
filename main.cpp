#include <cmath>
#include "planet.h"
#include "solarsystem.h"

using namespace std;


const double _pi = atan(1)*4;

int main()
{
  solarsystem sys;
  
  // planet sun(1,0,0,0,0,(2*_pi*5.2*pow(10,-3)/12) - 2*_pi*3*pow(10,-6),0);
  // sys.add_planet(sun);

  planet earth(3*pow(10,-6),1,0,0,0,2*_pi,0);
  sys.add_planet(earth);
 
  planet jupiter(pow(10,-3),-5.2,0,0,0,-2*_pi*5.2/12,0);
  sys.add_planet(jupiter);
  
  // planet comet(pow(10,-7),2,2,0,0,0,0);
  // sys.add_planet(comet);

  sys.h = 0.01;
  sys.T = 36;
  sys.sun_in_origin = 1;
  sys.use_verlet = 1;
  sys.initialize();

  sys.simulate("system.dat");
  
  
  
  return 0;
}

