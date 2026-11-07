#include "rigidBody.h"
#include <utility>

RigidBody::RigidBody(double px, double py, int size, double density, int ppm): px_(px), py_(py), size_(size), density_(density), ppm_(ppm) {vel_ = 0; acc_ = 9.812;}

void RigidBody::integrate(double dt){
  py_ += vel_ * dt * ppm_;
  vel_ += acc_ * dt;
}

std::pair<double, double> RigidBody::center(){return {px_, py_};}
double RigidBody::vel(){return vel_;}
int RigidBody::size(){return size_;}
