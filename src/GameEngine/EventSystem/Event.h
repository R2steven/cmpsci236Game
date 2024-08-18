

#ifndef EVENT_H
#define EVENT_H

namespace Game236 {
class Event {
  public:
    virtual void processInput() = 0;
};
}

#endif