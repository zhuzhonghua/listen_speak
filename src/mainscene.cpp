#include "stdafx.h"

#include "mainscene.h"
#include "imagemanager.h"
#include "gizmo.h"

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
	Image* img = ImageManager::inst()->getSolid(10, 10, 100, 100, 100, 100);
	add(img);
}
