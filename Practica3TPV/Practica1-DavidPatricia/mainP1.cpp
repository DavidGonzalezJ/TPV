//Pr�ctica 3
//Autores: Patricia Cabrero y David Gonz�lez
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif
#include "SDL.h"
#include "JuegoPG.h"
#include "Error.h"
#include <iostream>


int main(int argc, char* args[]) {  // SDL require esta cabecera 
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	JuegoPG* partida = new JuegoPG();
	//Valora si hay errores dentro del run
	try{
		partida->run();
	}
	catch (ErrorFuente &e){
		partida->muestraMensaje("Error", e.showMensaje());
	}
	catch (ErrorInit &e){
		partida->muestraMensaje("Error", e.showMensaje());
	}
	catch (ErrorSonido &e){
		partida->muestraMensaje("Error", e.showMensaje());
	}
	catch (ErrorTextura &e){
		partida->muestraMensaje("Error", e.showMensaje());
	}
	catch (Error &e){
		partida->muestraMensaje("Error", e.showMensaje());
	}
	delete partida;
	//system("PAUSE");
	//_CrtDumpMemoryLeaks();
	return 0;
}