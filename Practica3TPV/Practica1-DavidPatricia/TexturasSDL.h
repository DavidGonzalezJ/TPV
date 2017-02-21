#pragma once
#include <SDL.h>
#include "checkML.h"
#include <string>
#include <iostream>
#include "SDL_image.h"
#include "Fuente.h"
class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	bool load(SDL_Renderer* pRender, std::string const& nombArch);
	void draw(SDL_Renderer* pRender, SDL_Rect* rect, SDL_Rect*const vent);
	//M�todo necesario para obtener el globRect que necesita la clase globo para el tama�o
	void daTama�o(int & alto, int & ancho);
	SDL_Texture* daTextura();
	//METODO DE LA FUENTE
	void renderText(SDL_Renderer *, std::string texto);

private:
	SDL_Texture* pTextura;
	int Alto, Ancho;

	//METODOS DE LA FUENTE
	static Fuente font;
public:
	static bool loadFuente(std::string nombreArchivo, int tama�o);
	static void closeFuente();
	bool loadFromText(SDL_Renderer * pRender, std::string texto, SDL_Color color);
};