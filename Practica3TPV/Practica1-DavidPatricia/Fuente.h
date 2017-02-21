#pragma once
#include "checkML.h"
#include <SDL.h>
#include "SDL_ttf.h"
#include <string>
class Fuente
{
public:
	Fuente();
	~Fuente();
	void load(std::string nombreArch, int tama�o);
	void close();
	SDL_Surface* textSolid(std::string texto, SDL_Color color);

private:
	TTF_Font* pFont;
};