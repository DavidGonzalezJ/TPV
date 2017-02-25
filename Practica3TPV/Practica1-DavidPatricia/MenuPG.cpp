#include "MenuPG.h"
#include "PlayPG.h"
#include "confPG.h"

MenuPG::MenuPG(JuegoPG* juego):EstadoPG(juego)
{
	play = new Boton(juego,playC, 120,TBotonJugar);
	conf = new Boton(juego, configC, 220, TConfiguracion);
	exit = new Boton(juego,exitC, 320, TBotonSalir);
	pObjetos.emplace_back(play);
	pObjetos.emplace_back(conf);
	pObjetos.emplace_back(exit);
}


MenuPG::~MenuPG()
{
	delete play;
	delete conf;
	delete exit;
}

void MenuPG::playC(JuegoPG* juego) {
	juego->changeState(new PlayPG(juego));
}

void MenuPG::exitC(JuegoPG* juego) {
	juego->onExit();
}
void MenuPG::configC(JuegoPG* juego) {
	juego->pushState(new confPG(juego));
}