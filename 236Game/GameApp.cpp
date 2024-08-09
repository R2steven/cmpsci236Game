/**
 * Launches a console game. Should handle all game-specific 
 * configuration and then launch the game engine.
 * 
 * Ryan Stevens 
 * restevens52@gmail.com
 * 8/6/2024
 */
#include <memory>

#include <GameEngine.h>
#include <Engine.h>

using namespace Game236;
const int SCREEN_WIDTH = 90;
const int SCREEN_HEIGHT = 26;

/**
 * configure and run a specific game instance
 */
int main() {
  std::shared_ptr<GameEngine> game = 
    std::make_shared<Engine>(SCREEN_WIDTH, SCREEN_HEIGHT);
  game->run();
  return 0;
}
