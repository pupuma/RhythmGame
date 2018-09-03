#pragma once

#include "DLinkedList.h"

class Sprite;
class Note;


class Track
{
private:
	int _judgeStartTick;
	int _judgeEndTick;
	int _score;
private:
	DLinkedList<Note*> _noteList;
	

	Sprite* _backgroundSprite;
	Sprite* _judgeLineSprite;
	Sprite* _explosionSprite;
	Sprite* _failEffectSprite;
public:
	Track();
	~Track();

	void Init(int x);
	void Init(int x, int index);
	void Update(int deltaTime);
	void Render();
	void Deinit();

	// Input
private:
	bool _isKeyDown;

public:
	void KeyDown();
	void KeyUp();

	int GetScore();
	
};