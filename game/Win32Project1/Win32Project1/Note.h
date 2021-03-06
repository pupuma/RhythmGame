#pragma once

enum eNoteType
{
	NOTE_NONE,						// �⺻
	NOTE_TRANSPARENT,				// ����
	NOTE_LONG,						// �� 
};

class Sprite;

class Note
{
private:
	Sprite* _sprite;
	int _updateDuration;
	int _x;
	int _y;

	int _trackHeight;
	int _judgeLineOffset;

	bool _isLive;
	bool _isPassed;

public:
	Note(float startSec, int judgeLineOffset,int x);
	~Note();

	void Update(int deltaTime);
	void Render();

	void UpdatePosition(int deltaTime);

	bool IsLive();
	void SetLive(bool isLive);
	void Passed();
	bool IsPassed();

	int GetCurrentTime();
};
