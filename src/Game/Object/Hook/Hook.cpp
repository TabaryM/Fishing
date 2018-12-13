#include "Hook.hpp"

Hook::Hook(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/Hook.png"), coord, z) {

}

Hook::~Hook(){
}

int Hook::getType() {
  return HOOK;
}
