#include <armadillo>
#include <cmath>
#include "ODE.h"
#include "planet.h"
#include "solarsystem.h"

using namespace std;
using namespace arma;

const double _pi = atan(1)*4;

// vec derivatives(vec X, double t)
// {
//   //x is on form x,vx,y,vy
//   int n = X.n_elem;
//   vec k(n);
  
//   k(0) = X(1);
//   k(1) = -(4*_pi*_pi/pow((X(0)*X(0) + X(2)*X(2)),1.5))*X(0);
//   k(2) = X(3);
//   k(3) = -(4*_pi*_pi/pow((X(0)*X(0) + X(2)*X(2)),1.5))*X(2);
  
//   return k;
// }

// vec doublederivatives(vec X, double t)
// {
//   //x is on form x,y
//   int n = X.n_elem;
//   vec k(n);
  
//   k(0) = -(4*_pi*_pi/pow((X(0)*X(0) + X(1)*X(1)),1.5))*X(0);
//   k(1) = -(4*_pi*_pi/pow((X(0)*X(0) + X(1)*X(1)),1.5))*X(1);
  
//   return k;
// }



int main()
{
  // //dette passer ikke lenger:
  // int n = 100;
  // vec system(4);
  // vec verletsystem(2);
  
  // double h = 2.0/(n-1);
      
  // system(0) = 1;
  // system(1) = 0;
  // system(2) = 0;
  // system(3) = 2*_pi;
  
  // // //verlet inits
  // //finn ut om initializer lists
  // verletsystem(0) = 1;
  // verletsystem(1) = 0;
  // vec v0(2);
  // v0(0) = 0;
  // v0(1) = 2*_pi;

  // ODE sys(system,n,h);
  // ODE ver(verletsystem,n,h);
      
  // sys.rk4(*derivatives,"system.dat");
  // ver.verlet(v0,*doublederivatives, "verlet.dat");

  solarsystem sys;
  planet earth(1,1,0,0,0,2*_pi,0);
  sys.add_planet(earth);
  sys.h = 0.1;
  sys.T = 2;
  sys.RK4("system.dat");


    
  return 0;
}
