#include "Window.hpp"


Window::Window(Initializer & i) : item(0){
  i.initializeSDL();
  item = SDL_CreateWindow("Titre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
  assert(item != 0);
}

Window::~Window() {
  SDL_DestroyWindow(item);
}

SDL_Renderer* Window::getRenderer(int const& index, int const& flags) const{
  return SDL_CreateRenderer(item, index, flags);
}
