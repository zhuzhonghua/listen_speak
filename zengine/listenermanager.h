#pragma once

namespace Zengine{
class EventListener;
class Event;

class ListenerManager{
protected:
  static std::vector<EventListener*> listeners;
  static std::map<int, Event*> pointers;
  static bool canceled;
  static void dispatch(SDL_Event* event);
public:
  static void add(EventListener* listener);
  static void remove(EventListener* listener);

  static void processTouchEvents(std::vector<SDL_Event>& events);
  static void cancel();
};
}