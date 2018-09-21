#include "Game/Game.hpp"

int main(int argc, char **argv) {
  Initializer i;
  Game fish(i);

  fish.mainLoop();
  
  return 0;
}
