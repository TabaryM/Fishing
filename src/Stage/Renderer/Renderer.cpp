#include "Renderer.hpp"
#include "../../Texture/Texture.hpp"

Renderer::Renderer(Window const& w) : item(0) {
  item = w.getRenderer(-1, SDL_RENDERER_TARGETTEXTURE);
  assert(item != 0);
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(item);
}



SDL_Texture* Renderer::getTexture(Surface* s) const {
  SDL_Texture* res = SDL_CreateTextureFromSurface(item, s->getItem());
  delete s;
  s = 0;
  return res;
}

void Renderer::draw(Texture & t) {
  int err = SDL_RenderCopy(item, t.getItem(), NULL, &(t.getPosition().getItem()));
  assert(err == 0);
}

void Renderer::clear() {
  int err = SDL_RenderClear(item);
  assert(err == 0);
}
void Renderer::update() {
  SDL_RenderPresent(item);

}
