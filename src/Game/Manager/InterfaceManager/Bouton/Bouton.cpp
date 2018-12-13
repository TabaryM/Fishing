#include "Bouton.hpp"

Bouton::Bouton(Renderer const& r, Vector2D<int> const& coord, bool cliquable) : Object(r, new Surface(Vector2D<int> (1, 1), 0, 0, 0, 0), coord, 0), cliquable(cliquable) {}

Bouton::~Bouton() {}

int Bouton::getType(){
  return BOUTON;
}

bool Bouton::isHit(Vector2D<int> hit){
  return getTexture().getPosition().pointIn(hit);
}
