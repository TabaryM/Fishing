#include "Boat.hpp"

Boat::Boat(Renderer const& r, int const& x, int const& y, int const& z) : Object(r, new Surface(150, 65, 139, 69, 19, 255), x, y, z) {
  //we'll need to set back the boat image;
}

Boat::~Boat(){
}
