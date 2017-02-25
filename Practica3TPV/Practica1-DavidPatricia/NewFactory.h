#pragma once
#include "Factory.h"

class NewFactory :
	public Factory
{
public:
	NewFactory();
	virtual ~NewFactory();
	virtual ObjetoJuego* createNormalElement(int px, int py, JuegoPG* game);
	virtual ObjetoJuego* createSpecialElement(int px, int py, JuegoPG* game);
	virtual ObjetoJuego* createPrizeElement(int px, int py, JuegoPG* game);
};

