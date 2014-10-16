#pragma once
#include <armadillo>

//planet class for model of solar system
//class is so simple that it is defined
//here in its entirety

class planet
{
public:
  planet(){}
  arma::vec position;
  arma::vec velocity;
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

  planet(double m, double x, double y, double vx, double vy)
  {
    mass = m;
    
    position.set_size(2);
    velocity.set_size(2);
    
    position(0) = x;
    position(1) = y;
    
    velocity(0) = vx;
    velocity(1) = vy;
  }
  
};

