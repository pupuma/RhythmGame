#include "GameSystem.h"
#include "Album.h"

GameSystem* GameSystem::_instance = 0;

GameSystem::GameSystem()
{
	_trackHeight = 0;
}

GameSystem::~GameSystem()
{

}

GameSystem* GameSystem::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new GameSystem();
	}
	return _instance;
}

int GameSystem::GetWindowWidth()
{
	return 1024;
}

int GameSystem::GetWindowHeight()
{
	return 800;
}

void GameSystem::Quit()
{
	
	SDL_Event newEvent;
	newEvent.type = SDL_QUIT;
	SDL_PushEvent(&newEvent);
	
}

int GameSystem::GetTotalPlayingTime()
{
	return 60 *1000 * 3 ;
	//return 40000;
	//return 60 * 100;
}

void GameSystem::SetTrackHeight(int trackHeight)
{
	_trackHeight = trackHeight;
}

int GameSystem::GetTrackHeight()
{
	return _trackHeight;
}

void GameSystem::SetFinalScore(int score)
{
	_finalScore = score;
}
int GameSystem::GetFinalScore()
{
	return _finalScore;
}


void GameSystem::SetRenderer(SDL_Renderer* sdlRenderer)
{
	_sdlRenderer = sdlRenderer;
}

SDL_Renderer* GameSystem::GetRenderer()
{
	return _sdlRenderer;
}


void GameSystem::InitAlbum()
{
	_album = new Album();
}

Album* GameSystem::GetAlbum()
{
	return _album;
}