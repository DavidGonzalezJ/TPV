#include "ProgrammableBouncingBall.h"
#include "PlayPG.h"

ProgrammableBouncingBall::ProgrammableBouncingBall(int px, int py, JuegoPG* game, std::string nombreProg) : Bouncing_Ball(px, py, game), prog(nombreProg){

}

ProgrammableBouncingBall::~ProgrammableBouncingBall()
{
}

bool ProgrammableBouncingBall::onClick(){
	bool clicked = Bouncing_Ball::onClick();
	if (clicked){
		clicks++;
		VM.run(prog, *this);
	}
	return clicked;
	
	/*llamar a la máquina virtual (que explicamos abajo) para ejecutar
	una funcionalidad programada desde fuera.*/
}

void ProgrammableBouncingBall::addPoints(){ 
	static_cast<PlayPG*>(juego->getState())->newPuntos(this); 
}
