#include <armadillo>
//#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "ODE.h"

using namespace std;
using namespace arma;

const double _pi = atan(1)*4;
const double _G = 4*_pi*_pi;

// vec derivatives(vec X, double t);

ODE::ODE(vec S, double Time, double d):
  state(S),  T(Time), h(d) {}

void ODE::rk4(vec (*derivatives)(vec,double), char* outfile)
{
  ofstream outf(outfile); 
    
  double h2 = h/2;
  double h6 = h/6;
  vec k1,k2,k3,k4;
  
  outf<<state.t();
  while (t<T)
    {
      k1 = derivatives(state,t);
      k2 = derivatives(state+h2*k1,t+h2);
      k3 = derivatives(state+h2*k2,t+h2);
      k4 = derivatives(state+h*k3,t+h);
      
      state +=  h6*(k1 + 2*k2 + 2*k3 +k4);
      
      outf<<state.t();
      t+=h;
    }
}


void ODE::verlet( vec v0,  vec (*dderiv)(vec,double), char* outfile)
{
  ofstream outf(outfile);

  vec laststate,nextstate;
  laststate = state;
  
  outf<<state.t();
  state = laststate + v0*h + 0.5*h*h*dderiv(laststate,t);
  outf<<state.t();
  while (t<T)
    { 
      nextstate = 2*state - laststate + h*h*dderiv(state,t);
      
      laststate = state;
      state = nextstate;
      
      outf<<state.t();
      t+=h;
    }
}

