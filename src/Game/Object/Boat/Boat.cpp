#include "Boat.hpp"

Boat::Boat(Renderer const& r, int const& x, int const& y, float const& z) : Object(r, new Surface("sprites/Boat.png"), x, y, z) {

}

Boat::~Boat(){
}
