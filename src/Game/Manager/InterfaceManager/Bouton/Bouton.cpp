#include "Bouton.hpp"

Bouton::Bouton(Renderer const& r, Vector2D<int> const& coord, Surface* s) : Object(r, s, coord, 0) {}

Bouton::~Bouton() {}

int Bouton::getType(){
  return BOUTON;
}

bool Bouton::isHit(Vector2D<int> hit){
  return getTexture().getPosition().pointIn(hit);
}
