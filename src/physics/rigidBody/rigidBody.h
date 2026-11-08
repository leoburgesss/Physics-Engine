#pragma once
#include <glm/glm.hpp>


class RigidBody{
public:
  RigidBody(float px, float py, int size, float density, int ppm);

  void integrate(float dt);
  
  glm::vec2 center();
  glm::vec2 vel();
  int size();
  double density();

private:
  glm::vec2 pos_, vel_, acc_;
  float size_, ppm_;
  float density_;
};
