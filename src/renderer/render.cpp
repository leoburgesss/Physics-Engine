#include "render.h"
#include "physics/rigidBody/rigidBody.h"

#include <glm/glm.hpp>

Renderer::Renderer(SDL_Window* window, SDL_Renderer* renderer, int width, int height): window_(window), renderer_(renderer), width_(width), height_(height){}

void Renderer::drawRigidBody(RigidBody& r){
  int s = r.size();
  glm::vec2 c = r.center();
  SDL_FRect rect = {c.x-s, c.y-s, static_cast<float>(2*s), static_cast<float>(2*s)};
  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer_, &rect);

  if(r.vel().y>0){SDL_RenderLine(renderer_, c.x, c.y+s, c.x, c.y + s + 2*r.vel().y);}
}
