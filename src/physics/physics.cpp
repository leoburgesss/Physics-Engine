#include "physics.h"
#include "physics/rigidBody/rigidBody.h"

#include <vector>
#include <glm/glm.hpp>

Physics::Physics(){
  ppm_ = 120;
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

bool Physics::hasCollided(const RigidBody& b1, const RigidBody& b2) const{
  vec2 a = b1.center(); vec2 b = b2.center();
  int w1 = b1.size(); int w2 = b2.size();
  return (std::abs(a.x - b.x) < (w1 + w2) / 2.0f &&
            std::abs(a.y - b.y) < (w1 + w2) / 2.0f);
}

