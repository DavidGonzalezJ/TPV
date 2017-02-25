#include "NewFactory.h"
#include "Bouncing_Ball.h"
#include "Vago.h"
#include "Mariposa.h"
#include "Premio.h"

NewFactory::NewFactory()
{
}


NewFactory::~NewFactory()
{
}
ObjetoJuego* NewFactory::createNormalElement(int px, int py, JuegoPG* game) {
	return new Bouncing_Ball(px,py,game);///BOLAS
}

ObjetoJuego* NewFactory::createSpecialElement(int px, int py, JuegoPG* game) {
	return new Vago();
}

ObjetoJuego* NewFactory::createPrizeElement(int px, int py, JuegoPG* game) {
	return new Vago();
}