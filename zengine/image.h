#pragma once

#include "gizmo.h"

#include <string>

namespace Zengine{
class Texture;
class Image :public Gizmo{
public:
	Image();
	
	Image(const std::string& tx);

	void texture(const std::string& tx);

	virtual void draw();

	Rect getDstRect() { return dst; }
	
protected:
	void init();
protected:

	Texture* tex;
	Rect src;
	Rect dst;
};
};
