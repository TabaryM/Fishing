#include "Boat.hpp"

Boat::Boat(Renderer const& r, int const& x, int const& y, int const& z) : Object(r, new Surface("Boat.png"), x, y, z) {
  //we'll need to set back the boat image;
}

Boat::~Boat(){
}
