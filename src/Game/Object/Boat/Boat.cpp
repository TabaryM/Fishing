#include "Boat.hpp"

Boat::Boat(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/Boat.png"), coord, z) {

}

Boat::~Boat(){
}

int Boat::getType() {
  return BOAT;
}
