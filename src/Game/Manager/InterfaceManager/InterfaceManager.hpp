#pragma once

#include "../../Object/Object.hpp"
#include "../../Object/Fish/Fish.hpp"
#include "../../Object/Boat/Boat.hpp"
#include "../../Object/Hook/Hook.hpp"
#include "../Manager.hpp"

class InterfaceManager : public Manager {

  public:
  InterfaceManager(Stage* s, Input* i);
  ~InterfaceManager();
  void create() override;
  void update() override;
  void render() override;
  void destroy() override;

};
