#include "TexturasSDL.h"
#include "Error.h"

TexturasSDL::TexturasSDL()
{
	pTextura = nullptr;
}


TexturasSDL::~TexturasSDL()
{
	SDL_DestroyTexture(pTextura);
}

bool TexturasSDL::load(SDL_Renderer* pRender, std::string const& nombArch) {
	//The image we will load es nombArch
	//std::string imgName{ nombArch };

	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Loading success flag

	//Load image
	pTempSurface = IMG_Load(nombArch.c_str());
	if (pTempSurface == nullptr) {
		std::cout << "Unable to load image " << nombArch << "! \nSDL Error: " << SDL_GetError() << '\n';
		throw ErrorTextura("Couldn't load image");
		success = false;
	}
	else {
		SDL_DestroyTexture(pTextura);
		pTextura = SDL_CreateTextureFromSurface(pRender, pTempSurface);
		//La siguiente funci�n me devuelve el ancho y el alto de la textura
		SDL_QueryTexture(pTextura, NULL, NULL, &Ancho, &Alto);
		SDL_FreeSurface(pTempSurface);
		success = pTextura != nullptr;
	}
	return success;
}

void TexturasSDL::draw(SDL_Renderer* pRender, SDL_Rect* rect, SDL_Rect*const vent) {
	// Draw objets 
	SDL_RenderCopy(pRender, pTextura, vent, rect);  // nullptr, nullptr -> toda la textura en toda la ventana
}

void TexturasSDL::daTama�o(int & alto, int & ancho) {
	alto = Alto;
	ancho = Ancho;
}
SDL_Texture* TexturasSDL::daTextura() {
	return pTextura;
}

///////////////////////////////////////////////////////////////////////
//METODOS SOBRE LA FUENTE
///////////////////////////////////////////////////////////////////////

//Llamo a la constructora de font
Fuente TexturasSDL::font;

bool TexturasSDL::loadFuente(std::string nombreArchivo, int tama�o) {
	font.load(nombreArchivo, tama�o);
	return true;
}

bool TexturasSDL::loadFromText(SDL_Renderer * pRender, std::string texto, SDL_Color color) {
	SDL_Surface* pTempSurface = nullptr;
	bool success = true;  //Loading success flag

	//Load font
	pTempSurface = font.textSolid(texto, color);
	if (pTempSurface == nullptr) {
		std::cout << "Unable to load texto";
		throw ErrorFuente("Unable to read text");
		success = false;
	}
	else {
		pTextura = SDL_CreateTextureFromSurface(pRender, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		success = pTextura != nullptr;
	}
	return success;
}

void TexturasSDL::closeFuente() {
	font.close();
}

void TexturasSDL::renderText(SDL_Renderer * pRender, std::string texto) {
	//Primero carga la textura con loadFromText() y luego la muestra.
	SDL_Color colorLetra{255, 255, 255, 255};
	SDL_Rect rectLetra{50, 50,50,50};
	loadFromText(pRender, texto, colorLetra);
	SDL_RenderCopy(pRender, pTextura, nullptr, &rectLetra);
}