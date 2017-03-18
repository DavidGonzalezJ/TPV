#pragma once
#include "Bouncing_Ball.h"
#include "PBBVM.h"
#include "PlayPG.h"
class ProgrammableBouncingBall :
	public Bouncing_Ball,  public PBBExternAccess
{
public:
	ProgrammableBouncingBall(int px, int py, JuegoPG* game, std::string nombreProg);
	~ProgrammableBouncingBall();
	virtual bool onClick();

// Consultar y cambiar las direcciones dx​ y dy
	virtual int getX(){ return dx; };
	virtual void setX(int x){ dx = x; };
	virtual int getY(){ return dy; };
	virtual void setY(int x){ dy = x; };

// Consultar el número de clics sobre el objeto hasta el momento
	virtual int getClicks(){ return clicks; };

// Consultar y cambiar los puntos asignados al objeto
	virtual int getPuntos(){ return puntos; };
	virtual void setPuntos(int punt){ puntos = punt; };

// Añadir puntos al contador global de puntos.
	virtual void addPoints(int puntos);

// Desactivar el objeto
	virtual void disable() { expl = true; static_cast<PlayPG*>(juego->getState())->newBaja(this); };

private:
	int clicks;
	PBBVMprog prog;
	PBBVM VM;
};