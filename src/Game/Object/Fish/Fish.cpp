#include "Fish.hpp"

Fish::Fish(Renderer const& r, int const& x, int const& y) : Object(r, new Surface(100, 100, 255, 0, 255, 255), x, y) {
  //return imBoat;
}

Fish::~Fish(){
}