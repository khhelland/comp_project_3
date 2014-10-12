#pragma once
#include <armadillo>
#include <vector>
#include "planet.h"

//Class for modeling
//solarsystem

class solarsystem
{
 public:
  //tror systemet kan bestaa av mange planeter
  //og en ODE
  solarsystem(): t(0) {}
  std::vector<planet>  planets;
  arma::vec init;
  arma::vec state;
  double t;
  double T ;
  double h;
 
  void rk4(const char*);
  void verlet(const char*);
  arma::vec derivatives(arma::vec);
  arma::vec doublederivatives(arma::vec);
  void add_planet(planet);
  void initialize();
  void update_planets();
  void reset();
  
  
};
