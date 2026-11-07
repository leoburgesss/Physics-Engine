#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "physics/physics.h"
#include "renderer/render.h"
#include "clock/clock.h"

constexpr int screenWidth = 1920;
constexpr int screenHeight = 1080;

int main(int argc, char* argv[]){
SDL_Init(SDL_INIT_VIDEO);

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_CreateWindowAndRenderer("Physics Engine", screenWidth, screenHeight, 0, &window, &renderer);

bool running  = true;
Uint64 lastTime =  SDL_GetPerformanceCounter();

Renderer r = Renderer(window, renderer, screenWidth, screenHeight);
Physics p = Physics();

SDL_Event event;
while(running){
  while (SDL_PollEvent(&event)){
    switch(event.type){
      case SDL_EVENT_QUIT:
        running = false;
      case SDL_EVENT_MOUSE_BUTTON_DOWN:
        p.newRigidBody(event.button.x, event.button.y, 10, 1);

    }
  }

  SDL_SetRenderDrawColor(renderer, 20, 30, 60, 255);
  SDL_RenderClear(renderer);
  
  float dt = Clock::getDt(lastTime);
  
  p.integrateRigidBodies(dt);
  
  for(RigidBody& b: p.rigidBodies()){
    r.drawRigidBody(b);
  }

  SDL_RenderPresent(renderer);

}
return 0;
}
