#include "Game.h"

#include "GameSystem.h"
#include "Texture.h"
#include "ResourceManager.h"

Texture::Texture(const char* fileName)
{
	char filePath[256];
	sprintf_s(filePath, "../Resources/images/%s", fileName);

	//_texture = IMG_LoadTexture(GameSystem::GetInstance()->GetRenderer(), filePath);
	// ResourceManager�� �̱���
	_texture = ResourceManager::GetInstance()->FindTexture(filePath);
	SDL_QueryTexture(_texture, NULL, NULL, &_srcRect.w, &_srcRect.h);

	_srcRect.x = 0;
	_srcRect.y = 0;
	_destRect.w = _srcRect.w;
	_destRect.h = _srcRect.h;
}

Texture::~Texture()
{
}

void Texture::Render()
{
	SDL_RenderCopy(GameSystem::GetInstance()->GetRenderer(), _texture, &_srcRect, &_destRect);
}

void Texture::SetScale(float scaleW, float scaleH)
{
	_destRect.w = _srcRect.w * scaleW;
	_destRect.h = _srcRect.h * scaleH;
}

void Texture::SetPosition(int x, int y)
{
	_destRect.x = x;
	_destRect.y = y;
}

int Texture::GetRenderWidth()
{
	return _destRect.w;
}

int Texture::GetRenderHeight()
{
	return _destRect.h;
}
