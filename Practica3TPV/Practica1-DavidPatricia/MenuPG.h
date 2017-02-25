#pragma once
#include "EstadoPG.h"
#include "checkML.h"
#include "Boton.h"
class MenuPG : public EstadoPG
{
public:
	MenuPG(JuegoPG* juego);
	~MenuPG();
	Boton* play; Boton* exit; Boton* conf;
	static void playC(JuegoPG* juego);
	static void exitC(JuegoPG* juego);
	static void configC(JuegoPG* juego);
};

