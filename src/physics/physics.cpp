#include "physics.h"
#include "physics/rigidBody/rigidBody.h"

#include <vector>

Physics::Physics(){
  ppm_ = 100;
  rigidBodies_.push_back(RigidBody(960, 540, 10, 1, ppm_));
};

std::vector<RigidBody> Physics::rigidBodies(){return rigidBodies_;}

void Physics::integrateRigidBodies(float dt){
  for(RigidBody& b: rigidBodies_){
    b.integrate(dt);
  }
}

void Physics::newRigidBody(double x, double y, int size, double density){
  rigidBodies_.push_back(RigidBody(x, y, size, density, ppm_));
}
