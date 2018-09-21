#include "Stage.hpp"

Stage::Stage(Initializer & i) : w(i), r(w){

}

Stage::~Stage(){

}

Renderer const& Stage::getRenderer() const {
  return r;
}

void Stage::draw(Texture& t){
  r.draw(t);
}

void Stage::update() {
  r.update();
}

void Stage::clear() {
  r.clear();
}
