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
    vec position;
    vec velocity;
    double mass;
    planet(double m, double x, double y, double z, double vx, double vy, double vz)   
      {
        mass = m;
        position.set_size(3);
        velocity.set_size(3);
        position(0) = x;
        position(1) = y;
        position(2) = z;
        velocity(0) = vx;
        velocity(1) = vy;
        velocity(2) = vz;        
      }
};

