#include "Fish.hpp"

Fish::Fish(Renderer const& r, int const& x, int const& y, int const& z) : Object(r, new Surface(100, 100, 255, 0, 255, 255), x, y, z) {
  //return imBoat;
}

Fish::~Fish(){
}
