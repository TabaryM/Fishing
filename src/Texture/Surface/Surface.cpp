#include "Surface.hpp"

const int Surface::DEPTH = 32;

Surface::Surface(int const& w, int const& h, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a) : item(0) {
  item = SDL_CreateRGBSurface(0, w, h, DEPTH, 0, 0, 0, 0);
  assert(item != 0);
  fillRGBA(Rectangle(w, h), r, g, b, a);
}


Surface::~Surface(){
  SDL_FreeSurface(item);

}

SDL_Surface* Surface::getItem() {
      return item;
    }

int const& Surface::getW() const {
    return item->w;
}

int const& Surface::getH() const {
    return item->h;
}

void Surface::fillRGBA(Rectangle const& rect, unsigned char const& r, unsigned char const& g, unsigned char const& b, unsigned char const& a) {
  int err = SDL_FillRect(item, &(rect.getItem()), SDL_MapRGBA(item->format, r, g ,b, a));
  assert(err == 0);
}
