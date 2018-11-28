#pragma once

#include "../Manager.hpp"
#include "../../Object/GameOver/GameOver.hpp"

class InterfaceManager : public Manager {

  public:
  InterfaceManager(Stage* s, Input* i);
  ~InterfaceManager() = default;
  void create() override;
  void update() override;
  void render() override;
  void destroy() override;

};
