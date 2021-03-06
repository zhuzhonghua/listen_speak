#pragma  once
#include "scene.h"

namespace Zengine{
enum GameState
{
	PLAY,
	EXIT
};

class Game
{
protected:
	static Game* instance;
	
	Game();
	
	// Actual size of the screen
	static int width;
	static int height;

	
	// Density: mdpi=1, hdpi=1.5, xhdpi=2...
	static float density;

	static float timeScale;
	static float elapsed;

	static GameState state;
public:
	static Game* inst();
	virtual ~Game();

	void init();
	void run();
	void processInput();
public:
	void switchScene(Scene* sce);
	Scene* scene() { return _scene; }

	static void vibrate(int milliseconds);

	void finish();

	SDL_Renderer* getRender() { return _renderer; }

	static int getWidth();
	static int getHeignt();
protected:
	void switchScene();
	void step();
	void update();
	void draw();

protected:
	long	_now;
	long	_step;
	Scene* _scene;
	Scene* _requestedScene;
	bool _requestedReset;

	float	_fps;
protected:
	SDL_Window* _window;
  SDL_Renderer* _renderer;

	std::vector<SDL_Event>	_motionEvents;
};
}
