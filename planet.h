#pragma once
#include <armadillo>

using namespace arma;

//planet class for model of solar system
//Class is simple enough that it is defined
//completely here

class planet
{
  public:
    planet(){}
    char* name;
    vec position;
    vec velocity;
    double mass;
    planet(char* nm,vec p, vec v, double m)
      {
        name = nm;
        position = p;
        velocity = v;
        mass = m;
      }
};

