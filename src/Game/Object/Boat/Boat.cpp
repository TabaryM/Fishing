#include "Boat.hpp"

Boat::Boat(Renderer const& r, int const& x, int const& y) : Object(r, new Surface("Boat.png"), x, y) {
  //return imBoat;
}

Boat::~Boat(){
}
