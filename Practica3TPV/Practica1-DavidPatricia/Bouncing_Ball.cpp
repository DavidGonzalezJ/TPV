#include "Bouncing_Ball.h"
#include "PlayPG.h"


Bouncing_Ball::Bouncing_Ball(int px, int py, JuegoPG* game)
{

	textura = TPelota;
	juego = game;
	puntos = 20;
	expl = false;
	rect->x = px;
	rect->y = py;
	juego->getTextura(textura)->daTamaño(rect->h, rect->w);
	sentido();

}


Bouncing_Ball::~Bouncing_Ball()
{
}

void Bouncing_Ball::sentido() {
	//Inicializa el sentido de la pelota
	int sentido = rand() % 2;
	dx = (rand() % 10) + 1;
	if (sentido = 1) {
		dx *= -1;
	}
	sentido = rand() % 2;
	dy = (rand() % 10) + 1;
	if (sentido = 1) {
		dy *= -1;
	}
}

void Bouncing_Ball::draw() const {
	if (!expl) {
		juego->getTextura(textura)->draw(juego->getRender(), rect, nullptr);
	}
}

//Devuelve true si el globo desaparece
bool Bouncing_Ball::onClick(){
	bool desaparece = false;
	int x, y;
	juego->getMousePos(x, y);
	if (!expl && dentro(x, y)) {
		expl = true;
		desaparece = true;
		dynamic_cast<PlayPG*>(juego->getState())->newPuntos(this);
		dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
	}
	return desaparece;
}

//Devuelve true si el globo desaparece
void Bouncing_Ball::update(){
	bool desaparece = false;
	if (!expl){
		bool aux = false;
		//Aquí se genera un aleatorio para ver hacia donde avanza la bola
		if (rect->x + dx > juego->getWindowWidth() - 50 || rect->x + dx < 0) {
			dx *= -1;
			aux = true;
			puntos -= AP;
			
		}
		if (rect->y + dy > juego->getWindowHeight() - 50 || rect->y + dy < 0) {
			dy *= -1;
			if (!aux) {
				puntos -= AP;
			}
		}
		
		rect->x += dx;
		rect->y += dy;
		if (puntos <= 0 ) {
			desaparece = true;
			expl = true;
			dynamic_cast<PlayPG*>(juego->getState())->newBaja(this);
		}
	}
}