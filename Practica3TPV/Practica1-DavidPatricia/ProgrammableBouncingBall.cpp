#include "ProgrammableBouncingBall.h"
#include "PlayPG.h"

ProgrammableBouncingBall::ProgrammableBouncingBall(int px, int py, JuegoPG* game, std::string nombreProg) : Bouncing_Ball(px, py, game), prog(nombreProg),clicks(0){

}

ProgrammableBouncingBall::~ProgrammableBouncingBall()
{
}

bool ProgrammableBouncingBall::onClick(){
	//bool clicked = Bouncing_Ball::onClick();
	int x, y;
	juego->getMousePos(x, y);
	bool clicked = !expl && dentro(x, y);
	if (clicked){
		clicks++;
		VM.run(prog, *this);
	}
	return clicked;
	
	/*llamar a la máquina virtual (que explicamos abajo) para ejecutar
	una funcionalidad programada desde fuera.*/
}

void ProgrammableBouncingBall::addPoints(int puntos){ 
	static_cast<PlayPG*>(juego->getState())->addPuntos(puntos);
}
