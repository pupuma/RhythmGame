#include "Game.h"
 
#include "sdl_mixer.h"

#include "GameSystem.h"
#include "SceneManager.h"
#include "Track.h"
#include "GameScene.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include "Font.h"

GameScene::GameScene()
{
	printf("GameScene.\n");

	_prevScore = 0;
	_backgroundSprite = NULL;
}

GameScene::~GameScene()
{
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}
}

void GameScene::Init()
{
	_backgroundSprite = new Sprite("backgroundspr", true);
	_backgroundSprite->SetPosition(GameSystem::GetInstance()->GetWindowWidth() / 2,
		GameSystem::GetInstance()->GetWindowHeight() / 2);


	float totalPlayingSec = GameSystem::GetInstance()->GetTotalPlayingTime() / 1000.0f;

	int BPM = 60;
	float tempo = (float)BPM / 60.0f;

	int trackHeightMin = GameSystem::GetInstance()->GetWindowHeight();
	int trackHeight = (float)trackHeightMin * (float)totalPlayingSec * tempo;
	GameSystem::GetInstance()->SetTrackHeight(trackHeight);

	/*
	_track = new Track();
	_track->Init();
	*/
	int trackCount = 5;
	_trackArray = new Array<Track*>(trackCount);
	
	// 트랙 시작 위치 
	int startX = 300;

	// 트랙 추가? 트랙 정보 ,
	for (int i = 0; i < trackCount; i++)
	{
		// 트랙 위치 ( i * 트랙 간 사이 범위 ) 
		int x = startX + (i * 130) + 15;
		Track* track = new Track();
		//track->Init(x,i);					// 트랙 번호 
		track->Init(x);
		_trackArray->Set(i, track);
	}

	_gameDuration = 0;

	// Font
	/*
	TTF_Font* font = TTF_OpenFont("../Resources/Font/arialbd.ttf", 24);
	SDL_Color fontColor = { 0, 0 , 0 };
	SDL_Surface* fontSurface = TTF_RenderText_Solid(font, "Hello Word", fontColor);
	_fontTexture = SDL_CreateTextureFromSurface(GameSystem::GetInstance()->GetRenderer(), fontSurface);
	*/
	_text = new Font("arialbd.ttf",24);

	int result = Mix_Init(MIX_INIT_MP3);
	if (MIX_INIT_MP3 == result)
	{
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
		Mix_Music* music = Mix_LoadMUS("../Resources/Music/The Concept of Love.mp3");
		if (NULL != music)
		{
			Mix_PlayMusic(music, 1);
		}
		else
		{
			printf("Error LoadMusic!\n");
		}
	}
}

void GameScene::Update(int deltaTime)
{
	_backgroundSprite->Update(deltaTime);
	if (_gameDuration <= GameSystem::GetInstance()->GetTotalPlayingTime() + 500)
	{
		_gameDuration += deltaTime;
		/*
		_track->Update(deltaTime);
		if (_prevScore != _track->GetScore())
		{
			_prevScore = _track->GetScore();
			char text[256];
			sprintf(text, "Score %04d", _track->GetScore());
			_text->SetText(text);
		}
		*/

		int finalScore = 0;
		for (int i = 0; i < _trackArray->Size(); i++)
		{
			Track* track = _trackArray->Get(i);
			track->Update(deltaTime);
			finalScore += track->GetScore();
		}

		if (_prevScore != finalScore)
		{
			_prevScore = finalScore;
			char text[256];
			sprintf(text, "Score %04d", finalScore);
			_text->SetText(text);
		}
	}
	else
	{
		//GameSystem::GetInstance()->Quit();
		Mix_PauseMusic();
		GameSystem::GetInstance()->SetFinalScore(_prevScore);
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_RESULT);
	}
}

void GameScene::Render()
{
	_backgroundSprite->Render();
	//_track->Render();
	for (int i = 0; i < _trackArray->Size(); i++)
	{
		Track* track = _trackArray->Get(i);
		track->Render();
	}
	/*x
	SDL_Rect destRect;
	destRect.x = 100;
	destRect.y = 200;
	destRect.w = 300;
	destRect.h = 50;
	SDL_RenderCopy(GameSystem::GetInstance()->GetRenderer(), _fontTexture,NULL,&destRect);
	*/
	_text->Render();
}

void GameScene::Deinit()
{
	if (NULL != _backgroundSprite)
	{
		delete _backgroundSprite;
		_backgroundSprite = NULL;
	}

	//_track->Deinit();
	for (int i = 0; i < _trackArray->Size(); i++)
	{
		Track* track = _trackArray->Get(i);
		track->Deinit();
		delete track;
	}
	delete _trackArray;
}

void GameScene::KeyDown(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_q:
		_trackArray->Get(0)->KeyDown();
		break;
	case SDLK_w:
		_trackArray->Get(1)->KeyDown();
		break;
	case SDLK_SPACE:
		//_track->KeyDown();
		_trackArray->Get(2)->KeyDown();
		break;
	case SDLK_o:
		_trackArray->Get(3)->KeyDown();
		break;

	case SDLK_p:
		_trackArray->Get(4)->KeyDown();
		break;

	}
}

void GameScene::KeyUp(unsigned int keyCode)
{
	switch (keyCode)
	{
	case SDLK_q:
		_trackArray->Get(0)->KeyUp();
		break;
	case SDLK_w:
		_trackArray->Get(1)->KeyUp();
		break;
	case SDLK_SPACE:
		//_track->KeyUp();
		_trackArray->Get(2)->KeyUp();
		break;
	case SDLK_o:
		_trackArray->Get(3)->KeyUp();
		break;
	case SDLK_p:
		_trackArray->Get(4)->KeyUp();
		break;
	}
}
