#include "Font.hpp"

Font::Font() : font() {

  std::cout << "create FONT" << std::endl;

  font = TTF_OpenFont("sprites/04B_30__.TTF",40);
  assert(font != NULL);
  c = {0,0,0} ;
}

Font::~Font(){
  TTF_CloseFont(font);
}

TTF_Font* Font::getFont() {
  return font;
}

SDL_Color Font::getColor(){
  return c;
}
