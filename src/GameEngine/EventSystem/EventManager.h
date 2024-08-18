/**
 * all things event related should live here. should have 
 * functions for navigating events and manage flow of control
 * based off of game state
 */

#ifndef GAME236_EVENT_MANAGER_H
#define GAME236_EVENT_MANAGER_H

#include <memory>
#include <vector>

#include "Event.h"

namespace Game236{

class EventManager : public Event  {
  public:
    EventManager();

    virtual void processInput(char in) = 0;

    virtual void loadEvents() = 0;

  private:

    //observing pointer
    std::unique_ptr<Event> currentEvent;

    //must associate an event with a view data structure up to us. (Graph?)
    std::unique_ptr<std::vector<Event>> events;
};
}
#endif