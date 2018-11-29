#include "InterfaceManager.hpp"


InterfaceManager::InterfaceManager(Stage* s, Input* i) : Manager(s, i) {}

void InterfaceManager::create(){
  objets["MenuPause"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75)) ;
  objets["Pause"] = new Object(s->getRenderer(), new Surface("sprites/Pause.png"), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), 999);
  objets["MenuPause"]->link(objets["Pause"]) ;
  objets["MenuLose"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75)) ;
  objets["Lose"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), &f, std::string("Defaite")) ;
  objets["MenuLose"]->link(objets["Lose"]) ;
  objets["MenuWin"] = new Menu(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75)) ;
  objets["Win"] = new GameOver(s->getRenderer(), Vector2D<int>(Window::WIDTH /2 -305, Window::HEIGHT /2 -75), &f, std::string("Victoire !")) ;
  objets["MenuWin"]->link(objets["Win"]) ;
  //objets["GO"] = new Object
  Manager::create();
}

void InterfaceManager::update(){
  if(SDL_SCANCODE_P){
    for(auto& o : objets){
      if (o.second->getType() == MENU){
        o.second->setActive(false);
      }
    }
    objets["MenuPause"]->setActive(true) ;
  }else{
    for(auto& o : objets){
      if (o.second->getType() == MENU){
        o.second->setActive(true);
      }
    }
    objets["MenuPause"]->setActive(false) ;
  }
  
}

void InterfaceManager::render(){
  Manager::render();
}

void InterfaceManager::destroy(){
}
