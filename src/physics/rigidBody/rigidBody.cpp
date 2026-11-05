#include "rigidBody.h"
#include <utility>

RigidBody::RigidBody(double px, double py, int size, double density): px_(px), py_(py), size_(size), density_(density) {}

std::pair<double, double> RigidBody::center(){return {px_, py_};}
int RigidBody::size(){return size_;}
