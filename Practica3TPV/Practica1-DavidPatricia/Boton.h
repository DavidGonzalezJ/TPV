#pragma once
#include "ObjetoPG.h"

class Boton : public ObjetoPG
{
public:
	typedef void CallBack_t(JuegoPG* jg);
	Boton(JuegoPG* game,CallBack_t* callback, int py, Texturas_t textur);
	~Boton();
	virtual void draw()const;
	virtual void update();
	virtual bool onClick();

protected:
	CallBack_t * cb;
	
};

