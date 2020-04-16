#include "zengine.h"

#include "mainscene.h"
#include "image.h"
#include "button.h"
#include "bitmaptext.h"

// Minimum virtual display size for portrait orientation

float MainScene::defaultZoom = 0;
float MainScene::minZoom;
float MainScene::maxZoom;

Camera* MainScene::uiCamera;

using namespace Zengine;

MainScene::MainScene()
{
}

MainScene::~MainScene()
{

}

void MainScene::init()
{
	//Image* img = new Image("./test.jpg");
	//add(img);

	//Button* btn = new Button("./test.jpg");
	//add(btn);

	BitmapText* bt = new BitmapText("hello");
	add(bt);
}
