#include "Hook.hpp"

Hook::Hook(Renderer const& r, Vector2D<int> const& coord, float const& z) : Object(r, new Surface("sprites/Hook.png"), coord, z) {
  this->hitbox = new Hitbox(r,Vector2D<int>(coord.getX(),coord.getY()-20+this->getH()/2), 10);
  static_cast<Object*> (this)->link(static_cast<Object*> (hitbox));
}

Hook::~Hook(){
}

int Hook::getType() {
  return HOOK;
}
Rectangle Hook::getHitbox(){
  return hitbox->getHitbox() ;
}
