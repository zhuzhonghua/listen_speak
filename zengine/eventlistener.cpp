#include "zengine.h"
#include "listenermanager.h"

using namespace Zengine;

std::vector<EventListener*> EventListener::listeners;

EventListener::EventListener()
{
  ListenerManager::add(this);
}

EventListener::~EventListener()
{
  ListenerManager::remove(this);
}

Event::Event(SDL_Event* e)
{

}

void Event::update(SDL_Event* e)
{

}