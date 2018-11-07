#include "Hook.hpp"

Hook::Hook(Renderer const& r, int const& x, int const& y, float const& z) : Object(r, new Surface("sprites/Hook.png"), x, y, z) {

}

Hook::~Hook(){
}
