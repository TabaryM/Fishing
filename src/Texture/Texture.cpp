#include "Texture.hpp"
#include "../Stage/Renderer/Renderer.hpp"

Texture::Texture(Renderer const& r, Surface* s, Vector2D<int> const& coord, bool destroyOnload) : item(0), position(s->getSize(), coord) {
  int alpha = s->getAlpha();
  item = r.getTexture(s, destroyOnload);
  int err = SDL_SetTextureBlendMode(item, SDL_BLENDMODE_BLEND);
  assert(err == 0);
  err = SDL_SetTextureAlphaMod(item, alpha);
  assert(err == 0);
}

Texture::~Texture() {
  free();
}

void Texture::free() {
  if (item != 0) {
      SDL_DestroyTexture(item);
      item = nullptr;
  }
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

void Texture::update(Renderer const& r, Surface* s) {
  free();
  item = r.getTexture(s, false);
  position.setSize(s->getSize());
}
