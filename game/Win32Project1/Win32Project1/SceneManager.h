#pragma once

class Scene;

enum eScene
{
	SCENE_LOGO,
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,

};

class SceneManager
{
private:
	Scene* _scene;
private:
	SceneManager();
	~SceneManager();
private:
	static SceneManager* _instance;
public:
	static SceneManager* GetInstance();
public:
	void ChangeScene(eScene sceneType);
	
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
	
	void Update(int deltaTime);
	void Render();
	void Deinit();

};