#include <armadillo>
#include <cstdlib>
#include <cmath>
#include "ODE.h"
using namespace std;
using namespace arma;

const double _pi = atan(1)*4;
const double _G = 4*_pi*_pi;

// vec derivatives(vec X, double t);

ODE::ODE(mat U, vec t, double h)
{
  //skal U kjennes ved referanse eller verdi?
  // verdi paser best?
  this->U = U;
  this->t = t;
  this->h = h;
}

void ODE::rk4(vec (*derivatives)(vec,double))
{
  double h2 = h/2;
  double h6 = h/6;
  vec k1,k2,k3,k4;
  for (int i = 0; i < U.n_cols-1; i++)
    {
      k1 = derivatives(U.col(i),t(i));
      k2 = derivatives(U.col(i)+h2*k1,t(i)+h2);
      k3 = derivatives(U.col(i)+h2*k2,t(i)+h2);
      k4 = derivatives(U.col(i)+h*k3,t(i)+h);
      
      U.col(i+1) = U.col(i) + h6*(k1 + 2*k2 + 2*k3 +k4);
    }
}


void ODE::verlet( vec v0,  vec (*dderiv)(vec,double))
{
   U.col(1) = U.col(0) + v0*h + 0.5*h*h*dderiv(U.col(0),t(0));
  for (int i = 1; i < (U.n_cols-1); i++)
    { U.col(i+1) = 2*U.col(i) - U.col(i-1) + h*h*dderiv(U.col(i),t(i));}
}

