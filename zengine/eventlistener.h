#pragma once

namespace Zengine{

struct Event{
 Event(SDL_Event* e);
};

typedef void (*OnEvent)(EventListener* listener);

class EventListener{
public:
  EventListener();
  ~EventListener();
  virtual void onEvent(Event* event) = 0;
};
}