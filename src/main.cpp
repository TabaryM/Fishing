#include "Game/Game.hpp"
#include "Math/Vector2D.hpp"

int main(int argc, char **argv) {
  Initializer i;
  Game game(i);

  game.launch();

  return 0;
}
