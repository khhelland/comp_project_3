#include <cmath>
#include "planet.h"
#include "solarsystem.h"

using namespace std;


const double _pi = atan(1)*4;

int main()
{
  solarsystem sys;
  
  planet earth(3*pow(10,-6),1,0,0,2*_pi);
  sys.add_planet(earth);
 
  planet jupiter(pow(10,-3),0,-5.2,2*_pi*5.2/12,0);
  sys.add_planet(jupiter);
  
  planet comet(pow(10,-7),2,2,-1,1);
  sys.add_planet(comet);
  
  planet twin_earth(3*pow(10,-6),-1.5,0,0,-2*_pi);
  sys.add_planet(twin_earth);
  
  planet small(pow(10,-6),0,0.3,-4*_pi,0);
  sys.add_planet(small);

  //husk at p = 0:
  planet sun(1,0,0,pow(10,-7)-(2*_pi*5.2*pow(10,-3)/12) + pow(10,-6)*4*_pi, - pow(10,-7));
  sys.add_planet(sun);


  sys.h = 0.01;
  sys.T = 10;
  //sys.sun_in_origin = 1;
  sys.initialize();
  sys.simulate("rk4.dat");

  sys.reset();
  sys.use_verlet = 1;
  sys.simulate("verlet.dat");
  
  
  
  
  return 0;
}

