#pragma once
#include "Factory.h"
//#include "JuegoPG.h"

class OldFactory :
	public Factory
{
public:
	OldFactory();
	virtual ~OldFactory();
	virtual ObjetoJuego* createNormalElement(int px, int py, JuegoPG* game);
	virtual ObjetoJuego* createSpecialElement(int px, int py, JuegoPG* game);
	virtual ObjetoJuego* createPrizeElement (int px, int py, JuegoPG* game);
};

