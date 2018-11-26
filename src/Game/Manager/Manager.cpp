#include "Manager.hpp"

Manager::Manager(Stage* s, Input* i, Font* f) : s(s), i(i), f() {}

Manager::~Manager(){
  for (auto& o : objets) {
    delete o.second;
  }
}

void Manager::create(){
  sortObject();
}

void Manager::render(){
  for (Object* o : draws) {
    if(o->isFliped() && (o->getType() == FISH)){
      s->flip(*o);
    }else{
      s->draw(*o);
    }
  }
}

void Manager::sortObject() {
  for (auto& o : objets) {
      draws.push_back(o.second);
  }
  std::sort(draws.begin(), draws.end(), Object::ObjectCompare());
}

Score* Manager::getScore(){
  return static_cast <Score*>(objets["Score"]);
}

Font* Manager::getFont(){
  return static_cast <Score*>(objets["Score"])->getFont() ;
}
