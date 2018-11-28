#include "Hitbox.hpp"

Hitbox::Hitbox(Renderer const& r,  Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/Wave.png"), coord, z) {

}

Hitbox::~Hitbox(){
}
int Hitbox::getType() {
  return HITBOX;
}
