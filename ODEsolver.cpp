#include <armadillo>
#include <cstdlib>
#include <cmath>

using namespace std;
using namespace arma;

const double _pi = atan(1)*4;
const double _G = 4*_pi*_pi;

// vec derivatives(vec X, double t);

void rk4solver(mat &u, vec t, double h, vec (*derivatives)(vec,double))
{
  double h2 = h/2;
  double h6 = h/6;
  vec k1,k2,k3,k4;
  for (int i = 0; i < u.n_cols-1; i++)
    {
      k1 = derivatives(u.col(i),t(i));
      k2 = derivatives(u.col(i)+h2*k1,t(i)+h2);
      k3 = derivatives(u.col(i)+h2*k2,t(i)+h2);
      k4 = derivatives(u.col(i)+h*k3,t(i)+h);
      
      u.col(i+1) = u.col(i) + h6*(k1 + 2*k2 + 2*k3 +k4);
    }
}


void verlet(mat &u, vec t, double h, vec v0,  vec (*dderiv)(vec,double))
{
  
  u.col(1) = u.col(0) + v0*h + 0.5*h*h*dderiv(u.col(0),t(0));
  for (int i = 1; i < (u.n_cols-1); i++)
    { u.col(i+1) = 2*u.col(i) - u.col(i-1) + h*h*dderiv(u.col(i),t(i));}
}

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
  int n = 100;
  mat system(4,n);
  mat verletsystem(2,n);
  
  double h = 1.0/(n-1);
  vec time(n);
  for(int i = 0; i<n; i++)
    { time(i) = i*h; }
  
  //initial conditions
  system(0,0) = 1;
  system(1,0) = 0;
  system(2,0) = 0;
  system(3,0) = 2*_pi;
  
  //verlet inits
  verletsystem(0,0) = 1;
  verletsystem(1,0) = 0;
  vec v0(2);
  v0(0) = 0;
  v0(1) = 2*_pi;
  
  rk4solver(system, time, h, *derivatives);
  system.save("system.dat",raw_ascii);
  
  verlet(verletsystem,time, h,v0, *doublederivatives); 
  verletsystem.save("verlet.dat",raw_ascii);
  

  return 0;
}
