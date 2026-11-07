#pragma once
#include "physics/rigidBody/rigidBody.h"

#include <vector>

class Physics{
  public:
    Physics();
    std::vector<RigidBody> rigidBodies();
    void integrateRigidBodies(float dt);
    void newRigidBody(double x, double y, int size, double density);

  private:
    std::vector<RigidBody> rigidBodies_;
    int ppm_;

};
