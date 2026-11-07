#include <SDL3/SDL.h>

namespace Clock{

float getDt(Uint64& lastTime){
  Uint64 currentTime = SDL_GetPerformanceCounter();
  float dt = (float)(currentTime - lastTime) / (float)SDL_GetPerformanceFrequency();
  lastTime = currentTime;
  return dt;
}

};
