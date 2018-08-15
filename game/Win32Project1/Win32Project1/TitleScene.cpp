#include <stdio.h>

#include "Sprite.h"
#include "TitleScene.h"
#include "GameSystem.h"
#include "SceneManager.h"
#include "BMSParsing.h"

TitleScene::TitleScene()
{
	printf("TitleScene.\n");
	printf("Parsing \n");
}
TitleScene::~TitleScene()
{

}
void TitleScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	_bms = new BMSParsing("_sp_chilltrap_00_blank");

}
void TitleScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
}
void TitleScene::Render()
{
	_backgroundSprite->Render();
}
void TitleScene::Deinit()
{
	delete _backgroundSprite;
}
void TitleScene::KeyDown(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME);
		break;
	}
}
void TitleScene::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_GAME);
		break;
	}
}