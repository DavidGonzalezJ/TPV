//#pragma once
#ifndef H_JuegoPG_H
#define H_JuegoPG_H
#include <SDL.h>
#include <vector>
#include "EstadoJuego.h"
#include "TexturasSDL.h"
#include "Sound_SDL.h"
#include "checkML.h"
#include <stack>

enum Texturas_t { TFondo, TGlobo, TMariposa, TPremio, TBotonMenu, TBotonJugar, TBotonSalir, TBotonScore,
	TBotonContinuar, TPelota, TConfiguracion, TGlobosBoton, TBolaBoton};

class JuegoPG {
public:
	JuegoPG();
	~JuegoPG();
	void run();

	std::vector<std::string> archText;
	TexturasSDL* getTextura(Texturas_t et) const { return pTexturaG[et]; };
	SDL_Renderer* getRender() const { return pRender; };
	void getMousePos(int & mpx, int & mpy) const;
	void initMedia();
	void freeMedia();
	void changeState(EstadoJuego* newSt);
	void pushState(EstadoJuego* newState);
	void popState();
	void onExit();
	int getWindowWidth() { return SCREEN_WIDTH; };
	int getWindowHeight() { return SCREEN_HEIGHT; };
	void muestraMensaje(std::string info, std::string boton);
	Sound_SDL* getSound()const { return sonido; };
	TexturasSDL* getPuntosText() { return pTexturaG[pTexturaG.size()-1]; };
	EstadoJuego* getState() { return pilaEstados.top(); };
	void factoria(int fac) { factory = fac; };////Si recibe 1 es oldFactory si recibe 0 es newFactory
	int getFactory() {return factory;};


private:

	int factory=1;//POR DEFECTO ESTA LA ANTIGUA FACTORIA
	std::stack<EstadoJuego*> pilaEstados;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Renderer* pRender = nullptr;
	SDL_Window* pWindow = nullptr;
	SDL_Rect* fRect = nullptr; //Este será el rectangulo de fondo de la textura
	std::vector<TexturasSDL*> pTexturaG;
	Sound_SDL* sonido = nullptr;
	int mouseX;
	int mouseY;

	bool error, exit;
	bool initSDL();
	void closeSDL();
	void handle_event();
	void initMusic();
	void closeMusic();
	void rellenaArch();
};

#endif