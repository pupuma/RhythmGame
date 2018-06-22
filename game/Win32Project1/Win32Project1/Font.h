#pragma once

#include "SDL_ttf.h"
#include "Texture.h"

class Font
	: public Texture
{
private:
	TTF_Font* _font;
	SDL_Color _fontColor;
public:
	Font(const char* fontName, int fontSize);
	~Font();
public:
	void SetText(const char* text);
	
};