#include "GameOver.h"
#include "MenuPG.h"

int GameOver::puntos = 0;

GameOver::GameOver(JuegoPG* juego, int punto) :EstadoPG(juego)
{
	Score = new Boton(juego,ScoreC, 120, TBotonScore);
	Menu = new Boton(juego,MenuC, 220, TBotonMenu);
	pObjetos.emplace_back(Score);
	pObjetos.emplace_back(Menu);
	puntos = punto;
}


GameOver::~GameOver()
{
	delete Score;
	delete Menu;
}

void GameOver::ScoreC(JuegoPG* juego) {
	juego->muestraMensaje("Puntos:", std::to_string(puntos));
	juego->changeState(new GameOver(juego,puntos));
}

void GameOver::MenuC(JuegoPG* juego) {
	juego->changeState(new MenuPG(juego));
}