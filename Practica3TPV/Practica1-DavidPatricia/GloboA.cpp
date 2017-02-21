#include "GloboA.h"
#include "PlayPG.h"

GloboA::GloboA(int px, int py, JuegoPG* game) :GlobosPG(px, py, game)
{
	puntos = 0;
}


GloboA::~GloboA()
{
}

void GloboA::update(){
	bool desaparece = false;
	if (!expl){
		//Aqu� se genera un aleatorio para ver si el globo se deshincha o no
		if (rand() % 100 < PDES) {
			rect->h -= DT;
			rect->w -= DT;
			//Aqu� hago que ascienda (si no est� arriba)
			if (rect->y > 10){
				rect->y -= DT * 3;
				puntos += AP;
			}
			else puntos -= 5*AP;

			if (rect->h <= 10 || rect->w <= 10) {
				vis = false;
				desaparece = true;
				expl = true;
				dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
			}
		}
	}
}
