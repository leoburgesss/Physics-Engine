#include "render.h"
#include "physics/rigidBody/rigidBody.h"

Renderer::Renderer(SDL_Window* window, SDL_Renderer* renderer, int width, int height): window_(window), renderer_(renderer), width_(width), height_(height){}

void Renderer::drawRigidBody(RigidBody r){
  int s = r.size();
  std::pair<double, double> c = r.center();
  SDL_FRect rect = {c.first-s, c.second-s, 2*s, 2*s};
  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer_, &rect);
}
