#include "PlayPG.h"
#include "Mariposa.h"
#include "Premio.h"
#include "GloboA.h"
#include "GameOver.h"
#include "OldFactory.h"
#include "NewFactory.h"
#include "PBBFactory.h"
#include "ProgrammableBouncingBall.h"

PlayPG::PlayPG(JuegoPG* juego) :EstadoPG(juego)
{

	sonido = juego->getSound();
	pRender = juego->getRender();
	if (juego->getFactory() == 1) {
		factory = new OldFactory();
	}else if(juego->getFactory() == 0) 
		factory = new NewFactory();
	else { 
		PBBVMprog::compile(rand() % 10 > 4 ? "prog1.vm" : "prog2.vm", "binProg.vm");
		factory = new PBBFactory();
	};

	initGlobos();
}

PlayPG::~PlayPG()
{
	freeGlobos();
	delete factory;
}

void PlayPG::newBaja(ObjetoJuego* po) {
	if (typeid(*po) == typeid(GlobosPG) || typeid(*po) == typeid(Bouncing_Ball) || typeid(*po) == typeid(ProgrammableBouncingBall)) {
		--numGlobos;
	}
	else if (typeid(*po) == typeid(Premio)) {
		sonido->playEffect();
	}
}

void PlayPG::newPuntos(ObjetoJuego* po) {
	sonido->playEffect();
	puntos+=dynamic_cast<ObjetoPG*>(po)->puntos;
}

void PlayPG::newPremio(ObjetoJuego* po) {
	pObjetos.emplace_back(factory->createPrizeElement(rand() % 720, rand() % 480, juego));
	dynamic_cast<Premio*>(pObjetos[pObjetos.size() - 1])->reiniciarP();
}

bool PlayPG::initGlobos() {
	bool success = true;

	for (int n = 0; n < numGlobos; ++n) {
		pObjetos.emplace_back(factory->createNormalElement(rand() % (juego->getWindowWidth()-51), rand() % (juego->getWindowHeight() - 51), juego));
	}

	for (int i = 0; i < 2; i++){
		pObjetos.emplace_back(factory->createSpecialElement(rand() % 720, rand() % 480, juego));
	}
	return success;
}

void PlayPG::freeGlobos() {
	for (unsigned int n = 0; n < pObjetos.size(); ++n) {
		delete pObjetos[n];
		pObjetos[n] = nullptr;
	}
}

bool PlayPG::gameOver() {
	return numGlobos <= 0;
}

void PlayPG::draw()const {
	SDL_Renderer* pRender = juego->getRender();
	SDL_RenderClear(pRender);
	juego->getTextura(TFondo)->draw(pRender, nullptr, nullptr);

	for each (ObjetoJuego* g in pObjetos)
	{
		g->draw();
	}
	juego->getPuntosText()->renderText(pRender, std::to_string(puntos));
	SDL_RenderPresent(pRender);
}

void PlayPG::update() {
		EstadoPG::update();
		if (gameOver())
			juego->changeState(new GameOver(juego, puntos));
}