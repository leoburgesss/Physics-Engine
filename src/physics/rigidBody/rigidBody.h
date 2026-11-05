#pragma once
#include <utility>


class RigidBody{
public:
  RigidBody(double px, double py, int size, double density);
  
  std::pair<double,double> center();
  int size();
  double density();

private:
  double px_, py_;
  int size_;
  double density_;
};
