#pragma once
#include "ObjetoJuego.h"
#include "JuegoPG.h"
class Factory
{
public:

	Factory()
	{
	}

	virtual ~Factory()
	{
	}

	virtual ObjetoJuego* createNormalElement(int px, int py, JuegoPG* game) = 0;
	virtual ObjetoJuego* createSpecialElement(int px, int py, JuegoPG* game) = 0;
	virtual ObjetoJuego* createPrizeElement(int px, int py, JuegoPG* game) = 0;
};

