#include <armadillo>
#include <cmath>
#include "ODE.h"
#include "planet.h"

using namespace std;
using namespace arma;



vec derivatives(vec X, double t)
{
  //x is on form x,vx,y,vy
  int n = X.n_elem;
  vec k(n);
  
  k(0) = X(1);
  k(1) = -(4*_pi*_pi/pow((X(0)*X(0) + X(2)*X(2)),1.5))*X(0);
  k(2) = X(3);
  k(3) = -(4*_pi*_pi/pow((X(0)*X(0) + X(2)*X(2)),1.5))*X(2);
  
  return k;
}

vec doublederivatives(vec X, double t)
{
  //x is on form x,y
  int n = X.n_elem;
  vec k(n);
  
  k(0) = -(4*_pi*_pi/pow((X(0)*X(0) + X(1)*X(1)),1.5))*X(0);
  k(1) = -(4*_pi*_pi/pow((X(0)*X(0) + X(1)*X(1)),1.5))*X(1);
  
  return k;
}



int main()
{
  //dette passer ikke lenger:
  int n = 100;
  mat system(4,n);
  mat verletsystem(2,n);
  
  double h = 1.0/(n-1);
  vec time(n);
  for(int i = 0; i<n; i++)
    { time(i) = i*h; }
  
    
  vec sys_init(4);
  sys_init(0) = 1;
  sys_init(1) = 0;
  sys_init(2) = 0;
  sys_init(3) = 2*_pi;
  
  // //verlet inits
  //finn ut om initializer lists
  vec ver_init(2);
  ver_init(0) = 1;
  ver_init(1) = 0;
  vec v0(2);
  v0(0) = 0;
  v0(1) = 2*_pi;

  ODE sys(system,time,h);
  ODE ver(verletsystem,time,h);
  
  sys.set_init(sys_init);
  ver.set_init(ver_init);
  
  sys.rk4(*derivatives);
  ver.verlet(v0,*doublederivatives);
  
  //rk4solver(system, time, h, *derivatives);
  sys.U.save("system.dat",raw_ascii);
  
  //verlet(verletsystem,time, h,v0, *doublederivatives); 
  ver.U.save("verlet.dat",raw_ascii);
  

  return 0;
}
