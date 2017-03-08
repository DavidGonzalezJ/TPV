#pragma once
#include "Factory.h"
class PBBFactory :
	public Factory
{
public:
	PBBFactory();
	virtual ~PBBFactory();
	virtual ObjetoJuego* createNormalElement(int px, int py, JuegoPG* game);
	virtual ObjetoJuego* createSpecialElement(int px, int py, JuegoPG* game);
	virtual ObjetoJuego* createPrizeElement(int px, int py, JuegoPG* game);
};

