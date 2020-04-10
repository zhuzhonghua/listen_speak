#pragma once

#include "eventlistener.h"

namespace Zengine{
class Button: public Group, public EventListener{
public:
  virtual void onEvent(SDL_Event* event);
};
}