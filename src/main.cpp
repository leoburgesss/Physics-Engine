#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "physics/rigidBody/rigidBody.h"
#include "renderer/render.h"

constexpr int screenWidth = 1920;
constexpr int screenHeight = 1080;

int main(int argc, char* argv[]){
SDL_Init(SDL_INIT_VIDEO);

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_CreateWindowAndRenderer("Physics Engine", screenWidth, screenHeight, 0, &window, &renderer);

bool running  = true;

Renderer r = Renderer(window, renderer, screenWidth, screenHeight);
RigidBody b1 = RigidBody(960, 540, 5, 1);

SDL_Event event;
while(running){
  while (SDL_PollEvent(&event)){
    if (event.type == SDL_EVENT_QUIT){ running = false;}
  }

  SDL_SetRenderDrawColor(renderer, 20, 30, 60, 255);
  SDL_RenderClear(renderer);

  r.drawRigidBody(b1);

  SDL_RenderPresent(renderer);

}
return 0;
}
