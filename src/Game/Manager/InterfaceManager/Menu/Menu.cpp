#include "Menu.hpp"

Menu::Menu(Renderer const& r, Vector2D<int> const& coord) : Object(r, new Surface(Vector2D<int> (1,1), 0, 0, 0, 0), coord, 0) {}

Menu::~Menu() {}

int Menu::getType(){
  return MENU;
}
