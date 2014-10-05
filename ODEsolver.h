#pragma once
#include armadillo

using namespace arma;
//Solver for system of coupled ODEs
// dUdt = F(U,t)


class ODEsolver
{
 public:
  ODEsolver(){}
  ODEsolver(mat, vec, double);
  mat U;
  vec t;
  double h;
  void rk4(vec (*derivatives)(vec,double));
  void verlet(vec v0, vec (*doublederivatives)(vec, double));
  void set_init(vec init){U.col(0) = init}
};
            
