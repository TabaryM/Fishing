#include "Texture.hpp"

Texture::Texture(Renderer const& r, Surface* s, Vector2D<int> const& coord) : item(0), position(s->getSize(), coord) {
  item = r.getTexture(s);
}

Texture::Texture(Texture& t) {
  item = t ;
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

Vector2D<int> const& Texture::getCoord() const {
  return position.getCoord();
}

void Texture::setCoord(Vector2D<int> const& coord){
  position.setCoord(coord);
}
