/**
 * Launches a console game. Should handle all game-specific 
 * configuration and then launch the game engine.
 * 
 * Ryan Stevens 
 * restevens52@gmail.com
 * 8/6/2024
 */
#include "Engine.h"
#include "scenes.cpp"

using namespace Game236;
const int SCREEN_WIDTH = 90;
const int SCREEN_HEIGHT = 70;

/**
 * configure and run a specific game instance
 */
int main() {
  std::unique_ptr<GameEngine> game = 
    std::make_unique<ConsoleEngine>();
  RenderEngine*  engine = game->getRenderer();
  auto obj = makeCellRenderable();
  engine->registerRenderable(obj);
  engine->updateWorld(obj->id, 'a');
  game->run();
  return 0;
}
