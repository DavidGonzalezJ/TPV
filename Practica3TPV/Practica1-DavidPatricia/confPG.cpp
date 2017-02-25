#include "confPG.h"



confPG::confPG(JuegoPG* juego) : EstadoPG(juego)
{
	oldFact = new Boton(juego, oldFactC, 120, TGlobosBoton);
	newFact = new Boton(juego, newFactC, 220, TBolaBoton);

	pObjetos.emplace_back(oldFact);
	pObjetos.emplace_back(newFact);

}


confPG::~confPG()
{
	delete oldFact;
	delete newFact;
}

void confPG::oldFactC(JuegoPG* juego) {
	juego->factoria(1);
	juego->popState();
}
void confPG::newFactC(JuegoPG* juego) {
	juego->factoria(0);
	juego->popState();
}