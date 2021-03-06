#include "Window.hpp"

int Window::WIDTH = 1280;
int Window::HEIGHT = 720;

Window::Window(Initializer & i) : item(0){
  i.initializeSDL();
  item = SDL_CreateWindow("Nearly Real Fishing Simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
  assert(item != 0);
}

Window::~Window() {
  if(item != nullptr){
    SDL_DestroyWindow(item);
    item = nullptr;
  }
}

SDL_Renderer* Window::getRenderer(int const& index, int const& flags) const{
  return SDL_CreateRenderer(item, index, flags);
}
