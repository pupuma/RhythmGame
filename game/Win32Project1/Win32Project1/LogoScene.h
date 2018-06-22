#pragma once
#include "Scene.h"


class LogoScene
	: public Scene
{
private:
	int _waitTick;
	int _updateTick;
public:
	LogoScene();
	~LogoScene();
public:
	void Init();
	void Update(int deltaTime);
	void Render();
	void Deinit();
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
};