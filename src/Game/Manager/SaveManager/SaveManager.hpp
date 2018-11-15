#pragma once

#include "../GameManager/GameManager.hpp"

class SaveManager {
  protected:
    Stage* s;
  public:
    SaveManager(Stage* s);
    ~SaveManager() = default;

    void save(std::vector<Fish*>& fishs);
    void load(std::vector<Fish*>& fishs);
};
