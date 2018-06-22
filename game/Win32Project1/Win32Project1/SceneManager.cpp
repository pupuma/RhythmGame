#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "ResultScene.h"
#include "LogoScene.h"
SceneManager* SceneManager::_instance = 0;

SceneManager::SceneManager()
{

}
SceneManager::~SceneManager()
{

}
SceneManager* SceneManager::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new SceneManager();
	}
	return _instance;
}
void SceneManager::ChangeScene(eScene sceneType)
{
	switch (sceneType)
	{
	case SCENE_LOGO:
		_scene = new LogoScene();
		_scene->Init();
		break;
	case SCENE_TITLE:
		_scene = new TitleScene();
		_scene->Init();
		break;
	case SCENE_GAME:
		_scene = new GameScene();
		_scene->Init();
		break;
	case SCENE_RESULT:
		_scene = new ResultScene();
		_scene->Init();
		break;
	}
}
void SceneManager::KeyDown(unsigned int keyCode)
{
	_scene->KeyDown(keyCode);
}
void SceneManager::KeyUp(unsigned int keyCode)
{
	_scene->KeyUp(keyCode);
}
void SceneManager::Update(int deltaTime)
{
	_scene->Update(deltaTime);
}
void SceneManager::Render()
{
	_scene->Render();
}
void SceneManager::Deinit()
{
	_scene->Deinit();
}