#include "Text.hpp"
#include "../../../Stage/Renderer/Renderer.hpp"

Text::Text(Font* f, std::string const& str) : s(f, str), str(str), f(f) {
  std::cout << "create text" << std::endl;
}

Text::~Text() {}

void Text::update(Renderer const& r, std::string const& nt){
  if(nt != str) {
    s.free();
    str = nt;
    s.loadText(f, str);
  }
}

Surface* Text::getSurface() {
  return &s;
}
