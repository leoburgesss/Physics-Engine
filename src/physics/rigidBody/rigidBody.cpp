#include "rigidBody.h"
#include <glm/glm.hpp>
#include <cmath>

constexpr float pi = 3.1415926;

RigidBody::RigidBody(float px, float py, int size, float density, int ppm): pos_{px, py}, size_(size), density_(density), ppm_(ppm) {vel_.x = 5 * std::cos(pi/3); vel_.y = -5 * std::sin(pi/3); acc_.y = 9.812; acc_.x = 0;}

void RigidBody::integrate(float dt){
  vel_ += acc_ * dt;
  pos_ += vel_ * dt * ppm_;
}

glm::vec2 RigidBody::center(){return pos_;}
glm::vec2 RigidBody::vel(){return vel_;}
int RigidBody::size(){return size_;}
