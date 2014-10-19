#include <cmath>
#include "planet.h"
#include "solarsystem.h"

using namespace std;


int main()
{
  const double pi = atan(1)*4;
  
  solarsystem circular;
  
  planet earth(3.04*pow(10,-6),1,0,0,2*pi);
  circular.add_planet(earth);
  
  circular.sun_in_origin = 1;
  
  circular.h = 1e-3;
  circular.T = 50;
  
  circular.initialize();
  circular.simulate("circular_rk4.dat");
  
  circular.reset();
  circular.use_verlet = 1;
  //circular.h = e-3;
  circular.simulate("circular_verlet.dat");
  
  return 0;
}
