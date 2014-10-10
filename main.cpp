#include <cmath>
#include "planet.h"
#include "solarsystem.h"

using namespace std;


const double _pi = atan(1)*4;

int main()
{
  solarsystem sys;
  planet earth(1,1,0,0,0,2*_pi,0);
  sys.add_planet(earth);
  sys.h = 0.01;
  sys.T = 2;
  sys.initialize();
  sys.rk4("system.dat");
    
  return 0;
}
