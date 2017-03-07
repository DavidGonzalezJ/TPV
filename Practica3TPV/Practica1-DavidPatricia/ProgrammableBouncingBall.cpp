#include "ProgrammableBouncingBall.h"
#include "PlayPG.h"

ProgrammableBouncingBall::ProgrammableBouncingBall(int px, int py, JuegoPG* game) : Bouncing_Ball(px, py, game)
{
}


ProgrammableBouncingBall::~ProgrammableBouncingBall()
{
}

bool ProgrammableBouncingBall::onClick(){
	clicks++;
	/*llamar a la máquina virtual (que explicamos abajo) para ejecutar
	una funcionalidad programada desde fuera.*/	return true;
}

void ProgrammableBouncingBall::addPoints(int point){ 
	static_cast<PlayPG*>(juego->getState())->newPuntos(this); 
}
