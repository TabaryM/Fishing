#include "Font.hpp"

Font::Font() : font(0) {
  font = TTF_OpenFont("sprites/04B_30__.TTF",85);
  assert(font != NULL);
  c = {200,0,0} ;
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

SDL_Surface* Font::getSurface(){
  return TTF_RenderText_Solid(getFont(),"Hello World!", getColor());
}
