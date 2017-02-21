#pragma once
#include "EstadoPG.h"
#include "checkML.h"
#include "Factory.h"

class PlayPG : public EstadoPG
{
public:
	PlayPG(JuegoPG* juego);
	~PlayPG();
	void newBaja(ObjetoJuego* po);
	void newPuntos(ObjetoJuego* po);
	void newPremio(ObjetoJuego* po);
	virtual void draw() const;
	virtual void update();

private:
	int puntos = 0;
	bool cambioPuntos;
	int numGlobos = 6;
	bool gameOver();
	bool initGlobos();
	void freeGlobos();
	Sound_SDL* sonido;
	SDL_Renderer* pRender;
	EstadoJuego* actualState;
	Factory* factory;
};

