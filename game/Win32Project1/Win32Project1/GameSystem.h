#pragma once

#include "SDL.h"

class GameSystem
{
private:
	GameSystem();
	~GameSystem();
private:
	static GameSystem* _instance;
	int _finalScore;

public:
	static GameSystem* GetInstance();
	
	int GetWindowWidth();
	int GetWindowHeight();
	void Quit();

private:
	int _trackHeight;

public:
	int GetTotalPlayingTime();
	void SetTrackHeight(int trackHeight);
	int GetTrackHeight();

	void SetFinalScore(int score);
	int GetFinalScore();



private:
	SDL_Renderer* _sdlRenderer;

public:
	void SetRenderer(SDL_Renderer* sdlRenderer);
	SDL_Renderer* GetRenderer();
};
