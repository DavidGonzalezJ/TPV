#include "PBBFactory.h"
#include "Vago.h"
#include "ProgrammableBouncingBall.h"

PBBFactory::PBBFactory()
{
}


PBBFactory::~PBBFactory()
{
}

ObjetoJuego* PBBFactory::createNormalElement(int px, int py, JuegoPG* game) {
	return new ProgrammableBouncingBall(px, py, game, "binProg.vm");
}

ObjetoJuego* PBBFactory::createSpecialElement(int px, int py, JuegoPG* game){
	return new Vago();
}

ObjetoJuego* PBBFactory::createPrizeElement(int px, int py, JuegoPG* game) {
	return new Vago();
}