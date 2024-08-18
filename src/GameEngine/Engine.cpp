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
#include "ConsoleRenderer.h"

using namespace std::chrono_literals;
namespace Game236 {

  ConsoleEngine::ConsoleEngine()  :
    renderer(new ConsoleRenderer())//,
    //eventManager(std::make_unique<EventManager>())  
  {
    _running = false;
  }

  ConsoleEngine::ConsoleEngine(int width, int height) : 
    renderer(new ConsoleRenderer(width, height))//,
    //eventManager(std::make_unique<EventManager>()) 
  {
    _running = false;
  }

  void ConsoleEngine::run()  {
    _running = true;
    while(_running) {
      renderer->render();
      getInput();
      std::this_thread::sleep_for(20ms);
    }
  }

  RenderEngine* ConsoleEngine::getRenderer() {
    return renderer.get();
  }

  /**EventManager* ConsoleEngine::getEventManager() {
    return eventManager.get();
  }*/

  void ConsoleEngine::getInput() {
    if(_kbhit()){
      char current = _getch();

      switch(current){
      case 'q': _running = false;
        break;
      case 'Q': _running = false;
        break;
      //default: eventManager->processInput(current);
      }
    }
  }
}