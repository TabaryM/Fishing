#include "Font.hpp"

Font::Font(char const* s) : font(0) {
  font = TTF_OpenFont("sprites/04B_30__.TTF",40);
  assert(font != NULL);
  c = {0,0,0} ;
  text = s;
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
  return TTF_RenderText_Solid(getFont(),text, getColor());
}

void Font::setText(char const* c){
  text = c;
}
