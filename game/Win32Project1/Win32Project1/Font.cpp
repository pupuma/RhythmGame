#include "sdl_ttf.h"
#include "GameSystem.h"
#include "Font.h"

Font::Font(const char* fontName, int fontSize)
{
	_font = TTF_OpenFont("../Resources/Font/arialbd.ttf", fontSize);
	_fontColor = { 0, 0 , 0 };
	SetText("Score 0000");
	/*
	SDL_Surface* fontSurface = TTF_RenderText_Solid(font, "Hello Word", fontColor);
	_texture = SDL_CreateTextureFromSurface(GameSystem::GetInstance()->GetRenderer(), fontSurface);

	SDL_QueryTexture(_texture, NULL, NULL, &_srcRect.w, &_srcRect.h);

	_srcRect.x = 0;
	_srcRect.y = 0;

	_destRect.x = 100;
	_destRect.y = 500;
	_destRect.w = _srcRect.w;
	_destRect.h = _srcRect.h;
	*/
}
Font::~Font()
{

}

void Font::SetText(const char* text)
{
	SDL_Surface* fontSurface = TTF_RenderText_Solid(_font, text, _fontColor);
	_texture = SDL_CreateTextureFromSurface(GameSystem::GetInstance()->GetRenderer(), fontSurface);

	SDL_QueryTexture(_texture, NULL, NULL, &_srcRect.w, &_srcRect.h);

	_srcRect.x = 0;
	_srcRect.y = 0;

	_destRect.x = 100;
	_destRect.y = 500;
	_destRect.w = _srcRect.w;
	_destRect.h = _srcRect.h;
}
