#include "Surface.hpp"

const int Surface::DEPTH = 32;

Surface::Surface(Vector2D<int> const& size, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a) : item(0), alpha(a) {
  item = SDL_CreateRGBSurface(0, size.getX(), size.getY(), DEPTH, 0, 0, 0, 0);
  assert(item != 0);
  int err = SDL_SetSurfaceBlendMode(item, SDL_BLENDMODE_BLEND);
  assert(err == 0);
  fillRGBA(Rectangle(size), r, g, b, a);
}

Surface::Surface(std::string s){
  item = IMG_Load(s.c_str());
  int err = SDL_SetSurfaceBlendMode(item, SDL_BLENDMODE_BLEND);
  assert (item != 0);
  assert(err == 0);
}

Surface::Surface(Font* f, std::string const& str){
  item = TTF_RenderText_Solid(f->getFont(), str.c_str(), f->getColor()) ;
  int err = SDL_SetSurfaceBlendMode(item, SDL_BLENDMODE_BLEND);
  assert (item != 0);
  assert(err == 0);
}

Surface::~Surface(){
  free();
}

void Surface::loadText(Font* f, std::string const& str) {
  item = TTF_RenderText_Solid(f->getFont(), str.c_str(), f->getColor()) ;
  assert (item != 0);
}

SDL_Surface* Surface::getItem() {
      return item;
}

Vector2D<int> Surface::getSize() {
  return Vector2D<int>(item->w, item->h);
}

void Surface::fillRGBA(Rectangle const& rect, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a) {
  SDL_Rect re = rect.getRect();
  int err = SDL_FillRect(item, &re, SDL_MapRGBA(item->format, r, g ,b, a));
  assert(err == 0);
}

void Surface::free() {
  if(item != nullptr){
    SDL_FreeSurface(item);
    item = nullptr;
  }
}

unsigned char Surface::getAlpha(){
  return alpha;
}
