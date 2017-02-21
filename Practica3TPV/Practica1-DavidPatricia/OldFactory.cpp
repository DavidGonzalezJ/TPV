#include "OldFactory.h"
#include "GlobosPG.h"
#include "Premio.h"
#include "Mariposa.h"

OldFactory::OldFactory()
{
}


OldFactory::~OldFactory()
{
}

ObjetoJuego* OldFactory::createNormalElement(int px, int py, JuegoPG* game) {
	return new GlobosPG(px, py, game);
}

ObjetoJuego* OldFactory::createSpecialElement(int px, int py, JuegoPG* game){
	return new Mariposa(px, py, game);
}

ObjetoJuego* OldFactory::createPrizeElement(int px, int py, JuegoPG* game) {
	return new Premio(px, py, game);
}