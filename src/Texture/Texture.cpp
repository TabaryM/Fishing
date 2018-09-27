#include "Texture.hpp"
#include "../Stage/Renderer/Renderer.hpp"

Texture::Texture( Renderer const& r, Surface* s, int const& x, int const& y) : item(0), position(s->getW(), s->getH(), x, y) {
  item = r.getTexture(s);
}

Texture::~Texture() {
  SDL_DestroyTexture(item);
}

SDL_Texture* Texture::getItem(){
  return item;
}

Rectangle const& Texture::getPosition() const {
  return position;
}

void Texture::setPosition(int const& x, int const& y){
  position.setX(x);
  position.setY(y);
}

void Texture::setX(int const& x) {
  position.setX(x);
}

void Texture::setY(int const& y) {
  position.setX(y);
}
