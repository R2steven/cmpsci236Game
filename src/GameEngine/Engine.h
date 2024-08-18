
#ifndef GAME236_CONSOLE_ENGINE_H
#define GAME236_CONSOLE_ENGINE_H

#include <memory>
#include <string>

#include "GameEngine.h"

namespace Game236   {

typedef std::string T;

//TODO:
  //X 1) get organized! --Done! (for now)
  // 2) finish RenderEngine arch
    //X   i) create ConsoleRenderer (refactor) (should renderer be an Event?) 
    //X  ii) char[][] buffers (for clarity)
    //X iii) renderable data should be object * (string) (mutable)
    //  iv) register/unregister objs
    //   V) render objects to screen (render queue)
    //  vi) scenes should be renderable obj (list of renderable obj)
  // 3) implement Event Manager (should handle navigating game map graph)
    //   i) subscribe/unsubscribe events
    //  ii) define game event navigation
    // iii) define screen obj update interaction
  // 4/5) refactor out a world/ object manager
  // 4/5) prepare game demo
  // 6) create renderable factory and loader
  // 7) create Event factory and loader
  // 8) create base class to put custom datastructures into
  // 9) Engine done!

class ConsoleEngine : public GameEngine {
  public:
    ConsoleEngine();
    ConsoleEngine(int width, int height);

    virtual void run();

    virtual RenderEngine* getRenderer(); 
    //virtual EventManager* getEventManager();

  private:
    virtual void getInput();

    bool _running;
    
    std::unique_ptr<RenderEngine> renderer;
    //std::unique_ptr<EventManager> eventManager;
};
}

#endif