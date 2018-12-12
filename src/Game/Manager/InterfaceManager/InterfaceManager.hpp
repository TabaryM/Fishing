#pragma once

#include "../Manager.hpp"
#include "../../Object/GameOver/GameOver.hpp"
#include "Menu/Menu.hpp"

class InterfaceManager : public Manager {
  protected :
  bool pauseActive;
  bool winActive;
  bool loseActive;

  public:
  InterfaceManager(Stage* s, Input* i);
  ~InterfaceManager() = default;
  void create() override;
  void update() override;
  void render() override;
  void destroy() override;
  bool getUpdate();
  void setWin(bool b);
  void setPause(bool b);
  void setLose(bool b);
};
