#include "stdafx.h"

#include "mainscene.h"


// Minimum virtual display size for portrait orientation

float MainScene::defaultZoom = 0;
float MainScene::minZoom;
float MainScene::maxZoom;

Camera* MainScene::uiCamera;

MainScene::MainScene()
{
}

MainScene::~MainScene()
{

}

void MainScene::init()
{
	ImageManager::getSolid();
}
