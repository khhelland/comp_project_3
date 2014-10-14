#pragma once
#include <armadillo>
#include <vector>
#include "planet.h"

//Class for modeling
//solarsystem

class solarsystem
{
private:
  void update_planets();

public:
  solarsystem(): t(0), use_verlet(0), sun_in_origin(0) {}
  std::vector<planet>  planets;
  arma::vec init;
  arma::vec state;
  double t;
  double T ;
  double h;
  
  bool use_verlet;
 
  bool sun_in_origin;
  
  void rk4(const char*);
  void verlet(const char*);
  arma::vec derivatives(arma::vec);
  arma::vec doublederivatives(arma::vec);
  void add_planet(planet);
  void initialize();
  void reset();
  void simulate(const char*);
};
