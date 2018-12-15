#include "Bouton.hpp"

Bouton::Bouton(Renderer const& r, Vector2D<int> const& coord, Surface* s) : Object(r, s, coord, 0), cliquable(true) {}

Bouton::~Bouton() {}

int Bouton::getType(){
  return BOUTON;
}

bool Bouton::isHit(Vector2D<int> hit){
  if(cliquable){
    std::cout << "is cliquable " << std::endl;
    return getTexture().getPosition().pointIn(hit);
  } else {
    return false;
  }
}

void Bouton::setActive(bool a) {
  active = a;
  cliquable = a;
  for (Object* o : Object::getChild()) {
    static_cast<Bouton*>(o)->setActive(a);
  }
}
