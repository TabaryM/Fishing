#include "Key.hpp"

Key::Key() : active(false), switch(false){
}

bool const& Key::isActive() const{
  return active;
}

void Key::setActive(bool a){
  active = a;
}

void Key::keyUp(){
  setActive(false);
}

void Key::keyDown(){
  setActive(true);
}
