#pragma once
#include "SDL.h"
#include "Array.h"
#include "Scene.h"

class Track;
class Sprite;
class Font;

class GameScene
	: public Scene
{
private:
	//Track* _track;
	Array<Track*>* _trackArray;
	
	//Sprite* _backgroundSprite;
	Font* _text;
	
	int _gameDuration;
	int _prevScore;
public:
	GameScene();
	~GameScene();

	void Init();
	void Update(int deltaTime);
	void Render();
	void Deinit();

	// Input
public:
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
};

