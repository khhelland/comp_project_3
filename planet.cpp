#include <armadillo>

using namespace arma;

class planet
{
  public:
    planet(){};
    char* name;
    vec position;
    vec velocity;
    double mass;
    planet(char*,vec, vec, double);
};

planet::planet(char* name, vec position, vec velocity, double mass)
{
  this->name = name;
  this->position = position;
  this->velocity = velocity;
  this->mass = mass;
}
