#pragma once

#include "Scene.h"

class Sprite;
class BMSParser;



class TitleScene
	: public Scene
{
private:
	BMSParser* _bms;

public:
	TitleScene();
	~TitleScene();
public:
	void Init();
	void Update(int deltaTime);
	void Render();
	void Deinit();
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
};