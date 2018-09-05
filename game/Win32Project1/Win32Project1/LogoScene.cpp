#include <stdio.h>

#include "LogoScene.h"

#include "GameSystem.h"
#include "SceneManager.h"
#include "Sprite.h"

LogoScene::LogoScene()
{
	_updateTick = 0;
	_waitTick = 3000;
	printf("LogoScene.\n");

}
LogoScene::~LogoScene()
{

}
void LogoScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	int finalScore = GameSystem::GetInstance()->GetFinalScore();
	GameSystem::GetInstance()->InitAlbum();

}
void LogoScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);

	if (_waitTick < _updateTick)
	{
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_TITLE);
	}
	_updateTick += deltaTime;

}
void LogoScene::Render()
{
	_backgroundSprite->Render();
}
void LogoScene::Deinit()
{
	delete _backgroundSprite;

}
void LogoScene::KeyDown(unsigned int keyCode)
{

}
void LogoScene::KeyUp(unsigned int keyCode)
{
	
}