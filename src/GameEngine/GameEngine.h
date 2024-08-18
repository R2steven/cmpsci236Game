/**
 * Ryan Stevens 
 * restevens52@gmail.com
 * 8/6/2024
 */

#ifndef GAME236_GAME_ENGINE_H
#define GAME236_GAME_ENGINE_H

#include "RenderEngine.h"
#include "EventManager.h"

namespace Game236   {

class GameEngine    {
  public:
    virtual void run() = 0;
    virtual RenderEngine* getRenderer() = 0; 
    //virtual EventManager* getEventManager() = 0;
    //virtual WorldObjManager getWorldObjManager() = 0; //future improvement
};
}
#endif