#include "Manager.hpp"

Manager::Manager(Stage* s, Input* i) : s(s), i(i) {}

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
    if(o->isActive()){
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
