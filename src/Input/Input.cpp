#include "Input.hpp"

Input::Input() : quit(false) {
  keyKB = new Key[SDL_NUM_SCANCODES];
  keyMouse = new Key[SDL_BUTTON_X2 + 1];
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
      keyKB[e.getScancode()].keyDown();
     break;
     }
     case SDL_KEYUP: {
       keyKB[e.getScancode()].keyUp();
       break;
     }
    default: {
    }
  }
}

bool const& Input::isActive(SDL_Scancode const& i){
  return keyKB[i].isActive();
}

void Input::isFlip(SDL_Scancode const& i){
  keyKB[i].isFlip();
}

void Input::isFlip(Uint8 const& i){
  keyMouse[i].isFlip();
}

Vector2D<int> Input::getMousePos(){
  return e.getMousePos();
}
