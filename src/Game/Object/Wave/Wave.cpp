#include "Wave.hpp"

Wave::Wave(Renderer const& r, int const& x, int const& y, float const& z) : Object(r, new Surface("sprites/Wave.png"), x, y, z) {

}

Wave::~Wave(){
}
