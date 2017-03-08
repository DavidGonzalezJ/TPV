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
//	std::string nombre = rand() % 10 > 4 ? "prog1.vm" : "prog2.vm"​;
	return new ProgrammableBouncingBall(px, py, game, "prog1.vm");
}

ObjetoJuego* PBBFactory::createSpecialElement(int px, int py, JuegoPG* game){
	return new Vago();
}

ObjetoJuego* PBBFactory::createPrizeElement(int px, int py, JuegoPG* game) {
	return new Vago();
}