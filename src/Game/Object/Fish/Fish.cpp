#include "Fish.hpp"

Fish::Fish(Renderer const& r, int const& x, int const& y, float const& z) : Object(r, new Surface(50, 20, 255, 150, 120, 255), x, y, z) {
  //return imBoat;
}

Fish::~Fish(){
}
