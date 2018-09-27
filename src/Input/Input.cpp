#include "Input.hpp"

Input::Input() : quit(false) {
  keyKB = new bool[SDL_NUM_SCANCODES]{false};
  keyMouse = new bool[SDL_BUTTON_X2 + 1]{false};
}

Input::~Input() {
  delete[] keyKB;
  delete[] keyMouse;
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
    }
    case SDL_KEYDOWN:{
      keyKB[e.getScancode()] = true;
     break;
     }
     case SDL_KEYUP: {
       keyKB[e.getScancode()] = false;
       break;
     }
    default: {
    }
  }
}

bool const& Input::getKeyKB(SDL_Scancode const& i){
  return keyKB[i];
}
