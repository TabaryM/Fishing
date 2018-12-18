#pragma once

#include "../Manager.hpp"
#include "../../Object/GameOver/GameOver.hpp"
#include "Bouton/Bouton.hpp"

class InterfaceManager : public Manager {
  protected :
  bool pauseActive;
  bool winActive;
  bool loseActive;
  bool nxtLvl;
  bool reloadLvl;

  public:
  InterfaceManager(Stage* s, Input* i);
  ~InterfaceManager() = default;
  void create() override;
  void update() override;
  void render() override;
  bool getUpdate();
  void setWin(bool b);
  void setPause(bool b);
  void setLose(bool b);
  bool nextLvl();
  bool doReloadLvl();
  void resetBool();
};
