#pragma once
#include <utility>


class RigidBody{
public:
  RigidBody(double px, double py, int size, double density, int ppm);

  void integrate(double dt);
  
  std::pair<double,double> center();
  double vel();
  int size();
  double density();

private:
  double px_, py_;
  double vel_, acc_;
  int size_, ppm_;
  double density_;
};
