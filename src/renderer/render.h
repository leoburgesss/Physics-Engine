#pragma once
#include "physics/rigidBody/rigidBody.h"
#include <SDL3/SDL.h>


class Renderer{
public:
  Renderer(SDL_Window* window, SDL_Renderer* renderer, int width, int height);
  
  void drawRigidBody(RigidBody& r);

private:
  SDL_Window* window_;
  SDL_Renderer* renderer_;
  int width_, height_;
};
