#pragma once
#include <armadillo>
#include <vector>
#include "planet.h"
#include "ODE.h"

using namespace arma;
//Class for modeling
//solarsystem

class solarsystem
{
 public:
  //tror systemet kan bestaa av mange planeter
  //og en ODE
  solarsystem(){}
  vector<planet>  planets;
  vec init;
  double T;
  char* method;
  int rk4 = 1;
  int verlet = 0;
  //maybe change ODE so that U is here
  //also let user decide if U shoulf be 
  //held in memory, or let it not be with no option
  mat states;
  vec state;
  
  solarsystem(int);//argument is number of "planets"
  solarsystem(vector<planet>);//
  vec derivatives(vec,double);
  vec doublederivatives(vec,double);
  void add_planet(planet);
  void use_rk4(int); //kanskje kan disse bli til en?
  void use_verlet(int);
  void reset();
  void simulate();
  void simulate(double T);
  
};
