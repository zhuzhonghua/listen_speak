#include "zengine.h"

using namespace Zengine;

std::vector<EventListener*> ListenerManager::listeners;
std::map<int, Event*> ListenerManager::pointers;

void ListenerManager::add(EventListener* listener)
{
  std::vector<EventListener*>::iterator itr = std::find(listeners.begin(), listeners.end(), this);  
	if (itr == listeners.end())
  {
    listeners.push_back(this);
  }  
}

void ListenerManager::remove(EventListener* listener)
{
  std::vector<EventListener*>::iterator itr = std::find(listeners.begin(), listeners.end(), this);  
	if (itr != listeners.end())
	{
		listeners.erase(itr);
	}
}

void ListenerManager::dispatch(Event* event)
{
  canceled = false;

  for (int i = 0; i < listeners.size(); i++) 
	{
		EventListener* listener = listeners[i];

		listener->onEvent(event);
		if (canceled) 
		{
			return;
		}
	}
}

void ListenerManager::processTouchEvents(std::vector<SDL_Event>& events)
{
  for (int i = 0; i < events.size(); i++)
  {
    SDL_Event& e = events[i];

    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
      {
        // TODO：多个手指点击
        std::map<int, Event*>::iterator itr = pointers.find(0);
        if (itr == pointers.end())
        {
          Event* event = new Event(&e);
          pointers.insert(std::make_pair(0, event));
          dispatch(event);
        }
      }
      break;
    case SDL_MOUSEBUTTONUP:
      {
        std::map<int, Event*>::iterator itr = pointers.find(0);
        if (itr != pointers.end())
        {          
          Event* event = itr->second;
          pointers.erase(itr);
          event->up();
          dispatch(event);
          delete itr->second;
        }
      }
      break;
    case SDL_MOUSEMOTION:
      {
        std::map<int, Event*>::iterator itr = pointers.find(0);
        if (itr != pointers.end())
        {
          Event* event = itr->second;
          event->update(&e);
          dispatch(event);
        }
      }
      break;
    }
  }
}

void ListenerManager::cancel()
{
	canceled = true;
}