#include <stdio.h>
#include "Sprite.h"
#include "ResultScene.h"
#include "GameSystem.h"
#include "SceneManager.h"
#include "Font.h"
ResultScene::ResultScene()
{
	printf("ResultScene.\n");

}
ResultScene::~ResultScene()
{

}
void ResultScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);

	int finalScore = GameSystem::GetInstance()->GetFinalScore();
	
	_text = new Font("arialbd.ttf", 35);
	

	char text[256];
	
	sprintf(text, "Final Score %0d", finalScore);
	_text->SetText(text);
	
	


}
void ResultScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);

}
void ResultScene::Render()
{
	_backgroundSprite->Render();
	_text->Render();


}
void ResultScene::Deinit()
{
	delete _backgroundSprite;
	delete _text;

}
void ResultScene::KeyDown(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_LOGO);
		break;
	}
}
void ResultScene::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_SPACE:
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_LOGO);
		break;
	}
}