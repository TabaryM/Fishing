#include "Wave.hpp"

Wave::Wave(Renderer const& r,  Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/Wave.png"), coord, z) {

}

Wave::~Wave(){
}
