#include "JuegoPG.h"
#include <iostream>
#include <typeinfo>
#include "GlobosPG.h"
#include "Mariposa.h"
#include "Premio.h"
#include "GloboA.h"
#include "MenuPG.h"
#include "PlayPG.h"
#include "GameOver.h"
#include "Pausa.h"
#include "Error.h"

JuegoPG::JuegoPG()
{
	//Ahora las inicializaciones de la SDL y de Media se hacen al empezar el run
	rellenaArch();
	srand(SDL_GetTicks());
	error = false;
	exit = false;
	mouseX = 0;
	mouseY = 0;	
}


JuegoPG::~JuegoPG()
{	
	freeMedia();
	closeSDL();
}

void JuegoPG::getMousePos(int & mpx, int & mpy)const {
	mpx = mouseX;
	mpy = mouseY;
}


//Inicializa las texturas, la musica y la fuente
void JuegoPG::initMedia() {
	TexturasSDL::loadFuente("..\\fonts\\MONOFONT.TTF", 12);

	for (int i = 0; i < 10; i++){
		pTexturaG.emplace_back(new TexturasSDL());
		pTexturaG[i]->load(pRender, archText[i]);
	}
	//Esta última es la de los puntos
	pTexturaG.emplace_back(new TexturasSDL());


	//Creamos un SDL_Rect para pasarselo después al render (para el fondo)
	fRect = new SDL_Rect();
	fRect->h = SCREEN_HEIGHT;
	fRect->w = SCREEN_WIDTH;
	fRect->x = 0;
	fRect->y = 0;

	initMusic();

}

//Libera lo creado en initMedia()
void JuegoPG::freeMedia() {
	closeMusic();
	if (fRect != nullptr) {
		delete fRect;
		fRect = nullptr;
	}
	for (int n = 0; n < pTexturaG.size(); n++){
		if (pTexturaG[n] != nullptr) {
			delete pTexturaG[n];
			pTexturaG[n] = nullptr;
		}
	}
	TexturasSDL::closeFuente();
}


//Metodo auxiliar que rellena el vector de archivos de texturas
void JuegoPG::rellenaArch() {
	archText.push_back("..\\bmps\\fondo.png");
	archText.push_back("..\\bmps\\Globo.png");
	archText.push_back("..\\bmps\\Mariposa.png");
	archText.push_back("..\\bmps\\Doritos.png");
	archText.push_back("..\\bmps\\menuBoton.png");
	archText.push_back("..\\bmps\\jugarBoton.png");
	archText.push_back("..\\bmps\\salirBoton.png");
	archText.push_back("..\\bmps\\scoreBoton.png");
	archText.push_back("..\\bmps\\continuarBoton.png");
	archText.push_back("..\\bmps\\pelota.png");
}


//Invoca una ventana(info) con un boton(boton)
void JuegoPG::muestraMensaje(std::string info, std::string boton) {
	//SDL_DisplayMode dm;
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, info.c_str(), boton.c_str(), nullptr);
}

void JuegoPG::initMusic() {
	sonido = new Sound_SDL("..\\sounds\\AllStar.wav", "..\\sounds\\Hitmarker.wav");
}

void JuegoPG::closeMusic() {
	Sound_SDL::close();
	if(sonido != nullptr)
		delete sonido;
}


//Este metodo da valor al pRender y al pWindow
bool JuegoPG::initSDL() {

	bool success = true; //Initialization flag

						 //Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		throw ErrorInit("SDL could not initialize");
		success = false;
	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("GloboJuego", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			std::cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			throw ErrorInit("Window could not be created");
			success = false;
		}
		else {
			//Get window surface:
			pRender = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			if (pRender == nullptr) {
				std::cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				throw ErrorInit("Renderer could not be created");
				success = false;
			}
		}
	}
	return success;
}

void JuegoPG::closeSDL() {
	SDL_DestroyRenderer(pRender);
	pRender = nullptr;
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	SDL_Quit();
}

//HABRIA QUE CAMBIARLO
void JuegoPG::run() {
	initSDL();
	initMedia();
	if (!error) {
		Uint32 MSxUpdate = 500;
		std::cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		//muestraMensaje("PLAY", "Ready?");
		pilaEstados.push(new MenuPG(this));
		sonido->playMusic();
		handle_event();
		while (!exit && !error) {
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate) { // while(elapsed >= MSxUpdate)
				pilaEstados.top()->update();
				lastUpdate = SDL_GetTicks();
			}
			pilaEstados.top()->draw();
			handle_event();
		}

		if (exit) std::cout << "EXIT \n";
		popState();
		sonido->close();
		SDL_Delay(1000);
	}
}


void JuegoPG::handle_event() {
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) onExit();
		else if (e.type == SDL_KEYUP){
			if (dynamic_cast<PlayPG*>(pilaEstados.top())!= nullptr){
				if (e.key.keysym.sym == SDLK_ESCAPE) 
					pushState(new Pausa(this));
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				std::cout << "CLICK \n";
				mouseX = e.button.x;
				mouseY = e.button.y;
				pilaEstados.top()->onClick();
			}
		}
	}
}

void JuegoPG::onExit() {
	exit = true;
}
void JuegoPG::changeState(EstadoJuego* newSt) {
	popState();
	pushState(newSt);
}

void JuegoPG::pushState(EstadoJuego* newState) {
	pilaEstados.push(newState);
}

void JuegoPG::popState() {
	delete pilaEstados.top();
	pilaEstados.pop();
}
