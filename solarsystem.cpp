#include "solarsystem.h"
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iomanip>


using namespace arma;
using namespace std;

const double _pi = atan(1)*4;
const double _G = 4*_pi*_pi;

void solarsystem::add_planet(planet p){planets.push_back(p);}

void solarsystem::reset()
{
  //reset system to initial state
  state = init;
  t = 0;
  update_planets();
}

vec solarsystem::derivatives(vec X)
{
  //find the right hand side of all the
  //first order ODEs for rk4 method
  //input vector has shape like: x1,y1,vx1,vy1,x2,y2.....

  int n = X.n_elem;
  vec k(n);
  vec F = zeros<vec>(n/2);
  double x,y,r,f,m;
  
  //Find forces between planets
  for(int i = 0; i < (n/4); i++)
    {
      for(int j = i+1; j < (n/4); j++)
        {
          
          x = X(4*i) - X(4*j);
          y = X(4*i+1) - X(4*j+1);
          r = sqrt(x*x + y*y);
          
          f = -_G*planets[i].mass*planets[j].mass/(r*r*r);
          
          F(2*i) += f*x; 
          F(2*i+1) += f*y; 
          F(2*j) -= f*x; 
          F(2*j+1) -= f*y; 
              
        }
  
      
      //Find acceleration and velocities of the planet
      m = planets[i].mass;
      
      k(4*i) = X(4*i+2);
      k(4*i+1) = X(4*i+3);      
      
      k(4*i+2) = F(2*i)/m; 
      k(4*i+3) = F(2*i+1)/m; 
    }
  
  if (sun_in_origin)
    {
      //add effects from sun fixed in origin
      for(int i = 0; i<(n/4); i++)
        {
          x = X(4*i);
          y = X(4*i+1);
          r = sqrt(x*x + y*y);
          f = -_G/(r*r*r);
          k(4*i+2) += f*x;
          k(4*i+3) += f*y;
        }
    }
    
  return k;
}


vec solarsystem::doublederivatives(vec X)
{
  //find the right hand side of the second
  //order ODEs needed for the verlet method
  //Input vector has shape: x1,y1,x2,y2....

  int n = X.n_elem;
  vec k = zeros<vec>(n);
  vec F = zeros<vec>(n/2);
  double x,y,r,f,m;
  
  //Find forces between planets
  for(int i = 0; i < (n/4); i++)
    {
      for(int j = i+1; j < (n/4); j++)
        {
          
          x = X(4*i) - X(4*j);
          y = X(4*i+1) - X(4*j+1);
          r = sqrt(x*x + y*y);
          
          f = -_G*planets[i].mass*planets[j].mass/(r*r*r);
          
          F(2*i) += f*x; 
          F(2*i+1) += f*y; 
          F(2*j) -= f*x; 
          F(2*j+1) -= f*y; 
              
        }
 
      //find acceleration of planet
      m = planets[i].mass;
      k(4*i) = F(2*i)/ m; 
      k(4*i+1) = F(2*i+1)/=m; 
    }
  
  if (sun_in_origin)
    {
      for(int i = 0; i<(n/4); i++)
        {
          //add sun effects
          x = X(4*i);
          y = X(4*i+1);
          r = sqrt(x*x + y*y);
          f = -_G/(r*r*r);
          k(4*i) += f*x;
          k(4*i+1) += f*y;
        }
    }
  
  return k;}


void solarsystem::rk4(const char* outfile)
{
  //method for performing rk4 simulation of 
  //ODEs. The state of the system is updated
  //untill t = T
  //all states are written to outfile

  ofstream outf(outfile); 
    
  double h2 = h/2;
  double h6 = h/6;
  vec k1,k2,k3,k4;
  
  outf<<state.t();
  while (t<T)
    {
      k1 = derivatives(state);
      k2 = derivatives(state+h2*k1);
      k3 = derivatives(state+h2*k2);
      k4 = derivatives(state+h*k3);
      
      state += h6*(k1 + 2*k2 + 2*k3 +k4);
      
      outf<<state.t();
      t+=h;
    }
  
  update_planets();
}


void solarsystem::verlet( const char* outfile)
{
  //method for performing verlet simulation of 
  //ODEs. The state of the system is updated
  //untill t = T
  //all states are written to outfile

  ofstream outf(outfile);

  vec laststate,nextstate;
  laststate = state;
 
  
  //Write only positions to file as 
  //velocities are garbage
  for(int i=0;i<state.n_elem/4; i++)
    {
      outf<<state(4*i) << " " << state(4*i+1)<<" ";
    }
  outf<<endl;

  //find first updated state with rk4
  //the Tcopy thing is ugly, but it works
  double Tcopy = T;
  T = h;
  rk4("dump");
  T = Tcopy;
    
  //write positions
  for(int i=0;i<state.n_elem/4; i++)
    {
      outf<<state(4*i) << " " << state(4*i+1)<<" ";
    }
  outf<<endl;
  
  while (t<T)
    { 
      nextstate = 2*state - laststate + h*h*doublederivatives(state);
      
      laststate = state;
      state = nextstate;
      
      //write positions
      for(int i=0;i<state.n_elem/4; i++)
        {
          outf<<state(4*i) << " " << state(4*i+1)<<" ";
        }
      outf<<endl;
      t+=h;
    }

  update_planets();
}

void solarsystem::initialize()
{
  //initialize state vector from information
  //in planets. This doubles the information
  //but makes the rk4 and verlet methods simpler
  state.set_size(planets.size()*4);
  for(int i = 0;i <planets.size();i++)
    {
      state(4*i) = planets[i].position(0);
      state(4*i+1) = planets[i].position(1);
      state(4*i+2) = planets[i].velocity(0);
      state(4*i+3) = planets[i].velocity(1);
    }
  init = state;
}
     
void solarsystem::update_planets()
{
  //inverse of initialize
  for(int i=0;i<planets.size();i++)
    {
      planets[i].position(0) = state(4*i);
      planets[i].position(1) = state(4*i+1);
      planets[i].velocity(0) = state(4*i+2);
      planets[i].velocity(1) = state(4*i+3);
    }
}

void solarsystem::simulate(const char* name)
{
  if(use_verlet)
    {verlet(name);}
  else
    {rk4(name);}
}
