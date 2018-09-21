#include "Event.hpp"

Event::Event(){

}

Event::~Event(){

}

int const Event::getType() const {
  return item.type;
}

void Event::poll() {
  SDL_PollEvent(&item);
}
