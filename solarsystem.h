#pragma once
#include <armadillo>
#include <vector>
#include "planet.h"
#include "ODE.h"

using namespace arma;
//Class for modeling
//solarsystem

class solarsystem: public ODE
{
 public:
  //tror systemet kan bestaa av mange planeter
  //og en ODE
  solarsystem(){}
  std::vector<planet>  planets;
  vec init;
  
      
  /* solarsystem(int);//argument is number of "planets" */
  /* solarsystem(vector<planet>);// */
  static vec derivatives(vec,double);
  static vec doublederivatives(vec,double);
  void add_planet(planet);
  void reset();
  void do_rk4(char*);
  void do_verlet(char*);
  
};
