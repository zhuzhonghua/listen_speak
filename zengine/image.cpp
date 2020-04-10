#include "zengine.h"

#include "image.h"
#include "texturecache.h"
#include "util.h"
#include "game.h"

using namespace Zengine;

Image::Image()
{
	init();
}

Image::Image(const std::string& tx)
{
	texture(tx);
	init();
}

void Image::init()
{
	dst.x = 100;
	dst.y = 100;
	dst.w = 100;
	dst.h = 100;
}

void Image::texture(const std::string& tx)
{
	tex = TextureCache::getTexture(tx);
}

void Image::draw()
{
	SDL_RenderCopy(Game::inst()->getRender(), tex->getTex(), NULL, &dst);
}
