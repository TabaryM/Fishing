#include "Initializer.hpp"

Initializer::Initializer(): sdlInit(false){
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
}
