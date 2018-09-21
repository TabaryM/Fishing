#include "Input.hpp"

Input::Input() : quit(false) {

}

Input::~Input() {

}

bool const& Input::isQuit() const {
  return quit;
}

void Input::update() {
  e.poll();
  switch(e.getType()) {
    case SDL_QUIT: {
      quit = true;
      break;
    }/*
    case SDL_KEYDOWN:{
      key[e.getKey()] = true; //faire les fonctions et le tablal de bool
    }*/
    default: {
    }
  }
}
