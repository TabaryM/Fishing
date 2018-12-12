#include "Event.hpp"

Event::Event(){
}

Event::~Event(){
}

int const Event::getType() const {
  return item.type;
}

SDL_Scancode const Event::getScancode() const {
  return item.key.keysym.scancode;
}

Uint8 const Event::getButton() const{
  return item.button.button;
}

void Event::poll() {
  SDL_PollEvent(&item);
}
