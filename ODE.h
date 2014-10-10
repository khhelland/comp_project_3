#pragma once
#include <armadillo>

using namespace arma;
//Solver for system of coupled ODEs
// dUdt = F(U,t)


class ODE
{
 public:
  ODE(){}
  ODE(vec, double, double);
  vec state;
  double t=0;
  double T ;
  double h;
  void rk4(vec (*derivatives)(vec,double),char*);
  void verlet(vec v0, vec (*doublederivatives)(vec, double),char*);
};
            
