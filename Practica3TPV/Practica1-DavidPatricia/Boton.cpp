#include "Boton.h"

Boton::Boton(JuegoPG* game,CallBack_t* callback, int py, Texturas_t textur):cb(callback)
{
	juego = game;
	textura = textur;
	rect->x = juego->getWindowWidth()/2 - 120;
	rect->y = py;
	juego->getTextura(textura)->daTamaño(rect->h, rect->w);
}


Boton::~Boton()
{
}

void Boton::draw()const {
	juego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
}

void Boton::update() {
}

bool Boton::onClick() {
	int x, y;
	bool pulsa= false;
	juego->getMousePos(x, y);
	if (dentro(x, y)) {
		cb(juego);
		pulsa = true;
	}
	return pulsa;
}