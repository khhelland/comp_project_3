#include <cmath>
#include "planet.h"
#include "solarsystem.h"

using namespace std;


const double _pi = atan(1)*4;

int main()
{
  solarsystem sys;
  
  planet sun(1,0,0,0,0,(2*_pi*5.2*pow(10,-3)/12) - 2*_pi*3*pow(10,-6),0);
  sys.add_planet(sun);

  planet earth(3*pow(10,-6),1,0,0,0,2*_pi,0);
  sys.add_planet(earth);
 
  planet jupiter(pow(10,-3),-5.2,0,0,0,-2*_pi*5.2/12,0);
  sys.add_planet(jupiter);

  sys.h = 0.01;
  sys.T = 50;
  sys.initialize();

  sys.rk4("system.dat");
    
  return 0;
}

