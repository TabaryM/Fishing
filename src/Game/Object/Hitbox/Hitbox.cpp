#include "Hitbox.hpp"

Hitbox::Hitbox(Renderer const& r,  Vector2D<int> const& coord, float const& z) : Object(r, new Surface(Vector2D<int>(20,40), 100, 100, 100, 1), coord, z) {
}

Hitbox::~Hitbox(){
}
int Hitbox::getType() {
  return HITBOX;
}
