#include "Pausa.h"
#include "MenuPG.h"

Pausa::Pausa(JuegoPG* juego):EstadoPG(juego)
{
	Resume = new Boton(juego, ResumeC, 120,TBotonContinuar);
	Menu = new Boton(juego, MenuC, 220,TBotonMenu);
	pObjetos.emplace_back(Resume);
	pObjetos.emplace_back(Menu);
}


Pausa::~Pausa()
{
	delete Resume;
	delete Menu;
}

void Pausa::ResumeC(JuegoPG* juego) {
	juego->popState();
}

void Pausa::MenuC(JuegoPG* juego) {
	juego->popState();
	juego->changeState(new MenuPG(juego));
}