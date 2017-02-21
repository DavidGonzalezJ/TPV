#include "MenuPG.h"
#include "PlayPG.h"

MenuPG::MenuPG(JuegoPG* juego):EstadoPG(juego)
{
	play = new Boton(juego,playC, 120,TBotonJugar);
	exit = new Boton(juego,exitC, 220, TBotonSalir);
	pObjetos.emplace_back(play);
	pObjetos.emplace_back(exit);
}


MenuPG::~MenuPG()
{
	delete play;
	delete exit;
}

void MenuPG::playC(JuegoPG* juego) {
	juego->changeState(new PlayPG(juego));
}

void MenuPG::exitC(JuegoPG* juego) {
	juego->onExit();
}