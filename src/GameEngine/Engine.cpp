 /**
  * Game Engine should manage the game loop and all functions
  * related to managing the game.
  * 
  * Ryan Stevens 
  * restevens52@gmail.com
  * 8/6/2024
  */

#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>

#include "Engine.h"

 using namespace std::chrono_literals;
namespace Game236 {

  Engine::Engine()  {
    renderer = std::make_shared<RenderEngine>();
    _running = true;
  }

  Engine::Engine(int width, int height) {
    renderer = std::make_shared<RenderEngine>(width, height);
    _running = true;
  }

  void Engine::run()  {
    std::string hWorld = "Hello World!";
    renderer->pushRenderable(&hWorld);
    while(_running) {
      renderer->render();
      getInput();
      std::this_thread::sleep_for(50ms);
    }
  }

  void Engine::getInput() {
    if(_kbhit()){
      char current = _getch();

      switch(current){
      case 'q': _running = false;
        break;
      case 'Q': _running = false;
        break;
      //default: eventManager->input(current);
      }
    }
  }
}