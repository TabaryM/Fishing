#pragma once

#include "../Surface.hpp"

class Renderer;

class Text{
  private:
    Surface s;
    std::string str;
    Font* f ;

  public:
    Text(Font* f, std::string const& str);
    ~Text();
    void update(Renderer const& r, std::string const& nt);
    Surface* getSurface();
};
