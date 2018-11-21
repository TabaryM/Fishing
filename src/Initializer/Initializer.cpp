#include "Initializer.hpp"

Initializer::Initializer(): sdlInit(false),sdl_ttfInit(false){
}


Initializer::~Initializer() {
  if(sdlInit){
    SDL_Quit();
  }
}

void Initializer::initializeSDL() {
  if (!sdlInit) {
    int err = SDL_Init(SDL_INIT_VIDEO);
    assert(err == 0);
    sdlInit = true;
  }
  if (!sdl_ttfInit) {
    int err = TTF_Init();
    assert(err == 0);
    sdl_ttfInit = true;
  }
}
