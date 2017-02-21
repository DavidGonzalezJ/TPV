#pragma once
#include "EstadoPG.h"
#include "Boton.h"
#include "checkML.h"

class GameOver : public EstadoPG
{

public:
	GameOver(JuegoPG* juego, int puntos);
	~GameOver();
	Boton* Score;
	Boton* Menu;
	static void ScoreC(JuegoPG* juego);
	static void MenuC(JuegoPG* juego);

private:
	static int puntos;

};

