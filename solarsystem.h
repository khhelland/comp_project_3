#pragma once
#include <armadillo>
#include <vector>
#include "planet.h"

//Class for modeling solarsystem

class solarsystem
{
public:
  solarsystem(): t(0), use_verlet(0), sun_in_origin(0) {}
  
  //properties
  std::vector<planet>  planets;
  arma::vec init; //initial state vector
  arma::vec state;
  double t; //current time
  double T; //total time
  double h; //timestep

  //options:
  bool use_verlet;
  bool sun_in_origin;
  
  //methods
  void rk4(const char*);
  void verlet(const char*);
  arma::vec derivatives(arma::vec);
  arma::vec doublederivatives(arma::vec);
  void add_planet(planet);
  void initialize();
  void reset();
  void simulate(const char*);
  void update_planets();


};
