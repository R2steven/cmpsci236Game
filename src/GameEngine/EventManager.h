/**
 * all things event related should live here. should have 
 * functions for navigating events and manage flow of control
 * based off of game state
 */

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "RenderEngine.h"

namespace Game236{

class EventManager  {
  public:
    EventManager(std::shared_ptr<RenderEngine>);

    virtual void input(char in) = 0;

  private:
    virtual void pushRenderables() = 0;

    std::shared_ptr<RenderEngine> renderer; //subject to change
};
}
#endif