#include "Font.hpp"

Font::Font() : font(0) {
  font = TTF_OpenFont("sprites/04B_30__.TTF",16);
  assert(font != 0);
}

Font::~Font(){
  TTF_CloseFont(font);
}

TTF_Font& Font::getFont() const {
  return font;
}
