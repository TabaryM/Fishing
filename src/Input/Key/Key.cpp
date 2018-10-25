#include "Key.hpp"

Key::Key() : active(false), flip(false){
}

bool const& Key::isActive() const{
  return active;
}

void Key::setActive(bool a){
  active = a;
}

void Key::keyUp(){
  if (!flip) {
    setActive(false);
  }
}

void Key::keyDown(){
  if (!flip) {
    setActive(true);
  } else {
    setActive(!active);
  }
}

void Key::isFlip(){
  flip = true;
}
