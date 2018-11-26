#include "Font.hpp"

Font::Font() : item(0) {
  item = TTF_OpenFont("sprites/04B_30__.TTF",40);
  assert(item != NULL);
  c = {0,0,0} ;
  text = "Score : 0";
}

Font::~Font(){
  TTF_CloseFont(item);
}

TTF_Font* Font::getFont() {
  return item;
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
