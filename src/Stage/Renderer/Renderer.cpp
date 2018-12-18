#include "Renderer.hpp"

Renderer::Renderer(Window const& w) : item(0) {
  item = w.getRenderer(-1, SDL_RENDERER_TARGETTEXTURE);
  assert(item != 0);
  int err = SDL_SetRenderDrawBlendMode(item, SDL_BLENDMODE_BLEND) ;
  assert(err == 0);
}

Renderer::~Renderer() {
  if(item != nullptr){
    SDL_DestroyRenderer(item);
    item = nullptr;
  }
}



SDL_Texture* Renderer::getTexture(Surface* s, bool destroyOnload) const {
  SDL_Texture* res = SDL_CreateTextureFromSurface(item, s->getItem());
  if (destroyOnload) {
    delete s;
    s = nullptr;
  }
  return res;
}

void Renderer::draw(Texture& t) {
  SDL_Rect r = t.getPosition().getRect();
  int err = SDL_RenderCopy(item, t.getItem(), NULL, &r);
  assert(err == 0);
}

void Renderer::draw(int const& x1, int const& y1, int const& x2, int const& y2){
  SDL_SetRenderDrawColor(item, 255, 255, 255, 255);
  int err = SDL_RenderDrawLine(item, x1, y1, x2, y2);
  SDL_SetRenderDrawColor(item, 0, 0, 0, 255);
  assert(err == 0);
}

void Renderer::flip(Texture& t){
  SDL_Rect r = t.getPosition().getRect() ;
  int err = SDL_RenderCopyEx(item, t.getItem(), NULL, &r, 0, 0, SDL_FLIP_HORIZONTAL);
  assert(err ==0);
}

void Renderer::clear() {
  int err = SDL_RenderClear(item);
  assert(err == 0);
}

void Renderer::update() {
  SDL_RenderPresent(item);

}
