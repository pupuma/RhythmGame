#include "Game.h"

#include "SDL.h"
#include "SDL_ttf.h"
#include "GameSystem.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "SceneManager.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
	if (TTF_Init() < 0)
	{
		printf("Error init SDL font\n");
	}
	atexit(TTF_Quit);

	// 윈도우 생성
	SDL_Window* sdlWindow = SDL_CreateWindow("RythmGame",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		GameSystem::GetInstance()->GetWindowWidth(), GameSystem::GetInstance()->GetWindowHeight(),
		SDL_WINDOW_OPENGL);
	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, 0);
	GameSystem::GetInstance()->SetRenderer(sdlRenderer);

	SDL_SetRenderDrawColor(sdlRenderer, 0, 124, 0, 255);

	/*
	GameScene* scene = new GameScene();
	TitleScene* scene = new TitleScene();
	//Scene* scene = new TitleScene();
	*/
	/*
	Scene* scene = new TitleScene();
	scene->Init();
	*/
	SceneManager::GetInstance()->ChangeScene(eScene::SCENE_LOGO);

	int frame = 0;	// 현재 프레임
	int prevFrame = frame; // 이전 프레임
	int currentTick = SDL_GetTicks();	// 현재 시간
	int prevTick = currentTick;	// 이전 프레임 시간

	SDL_Event sdlEvent;
	while (1)
	{
		// 현재 시간 구한다.
		currentTick = SDL_GetTicks();

		// 현재 프레임을 구한다.
		frame = (currentTick % 1000) * 60;
		frame /= 1000;

		if (prevFrame != frame)
		{
			prevFrame = frame;

			int deltaTime = currentTick - prevTick;
			prevTick = currentTick;

			if (SDL_PollEvent(&sdlEvent))
			{
				if (SDL_QUIT == sdlEvent.type)
				{
					break;
				}

				if (SDL_KEYDOWN == sdlEvent.type)
				{
					//scene->KeyDown(sdlEvent.key.keysym.sym);
					SceneManager::GetInstance()->KeyDown(sdlEvent.key.keysym.sym);
				}

				if (SDL_KEYUP == sdlEvent.type)
				{
					if (SDLK_ESCAPE == sdlEvent.key.keysym.sym)
					{
						SDL_Event newEvent;
						newEvent.type = SDL_QUIT;
						SDL_PushEvent(&newEvent);
					}
					else
					{
						//scene->KeyUp(sdlEvent.key.keysym.sym);
						SceneManager::GetInstance()->KeyUp(sdlEvent.key.keysym.sym);
					}
				}
			}

			//scene->Update(deltaTime);
			SceneManager::GetInstance()->Update(deltaTime);
			// 화면을 그려준다.
			SDL_RenderClear(sdlRenderer);
			{
				//scene->Render();
				SceneManager::GetInstance()->Render();
			}
			SDL_RenderPresent(sdlRenderer);
		}
	}

	//scene->Deinit();
	SceneManager::GetInstance()->Deinit();

	//delete scene;

	return 0;
}
