#include "confPG.h"



confPG::confPG(JuegoPG* juego) : EstadoPG(juego)
{
	oldFact = new Boton(juego, oldFactC, 120, TGlobosBoton);
	newFact = new Boton(juego, newFactC, 220, TBolaBoton);
	PBBFact = new Boton(juego, PBBFactC, 320, TGlobosBoton);

	pObjetos.emplace_back(oldFact);
	pObjetos.emplace_back(newFact);
	pObjetos.emplace_back(PBBFact);

}


confPG::~confPG()
{
	delete oldFact;
	delete newFact;
	delete PBBFact;
}

void confPG::oldFactC(JuegoPG* juego) {
	juego->factoria(1);
	juego->popState();
}
void confPG::newFactC(JuegoPG* juego) {
	juego->factoria(0);
	juego->popState();
}
void confPG::PBBFactC(JuegoPG* juego) {
	juego->factoria(2);
	juego->popState();
}