/**
 * Ryan Stevens 
 * restevens52@gmail.com
 * 8/6/2024
 */

#ifndef GAME236_GAME_ENGINE_H
#define GAME236_GAME_ENGINE_H

#include <memory>

#include "RenderEngine.h"
#include "EventManager.h"

namespace Game236   {

class GameEngine    {
  public:
    virtual void run() = 0;
};
}
#endif