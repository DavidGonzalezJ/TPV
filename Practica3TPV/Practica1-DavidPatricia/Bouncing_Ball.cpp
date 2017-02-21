#include "Bouncing_Ball.h"


Bouncing_Ball::Bouncing_Ball()
{

	textura = TPelota;
	juego = game;
	puntos = 10;
	if (rand() % 100 < PVIS) vis = true; else vis = false;
	expl = false;
	rect->x = px;
	rect->y = py;
	juego->getTextura(textura)->daTama�o(rect->h, rect->w);
}


Bouncing_Ball::~Bouncing_Ball()
{
}

void Bouncing_Ball::draw() const {
	if (vis && !expl) {
		juego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
	}
}

//Devuelve true si el globo desaparece
bool Bouncing_Ball::onClick(){
	bool desaparece = false;
	int x, y;
	juego->getMousePos(x, y);
	if (!expl && vis && dentro(x, y)) {
		expl = true;
		desaparece = true;
		vis = false;
		dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
		dynamic_cast<PlayPG*>(juego->getState())->newPuntos(this);
	}
	return desaparece;
}

//Devuelve true si el globo desaparece
void Bouncing_Ball::update(){
	bool desaparece = false;
	if (vis && !expl){
		//Aqu� se genera un aleatorio para ver si el globo se deshincha o no
		if (rand() % 100 < PDES) {
			rect->h -= DT;
			rect->w -= DT;
			puntos += AP;
			if (rect->h <= 10 || rect->w <= 10) {
				vis = false;
				desaparece = true;
				expl = true;
				dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
			}
		}
	}
	if (!expl)
		//Generamos un aleatorio nueva para ver si un globo invisible se vuelve visible
		if (rand() % 100 < PVIS) vis = true; else vis = false;
}