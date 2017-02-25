#pragma once
#include "ObjetoPG.h"
class Bouncing_Ball :
	public ObjetoPG
{
public:
	Bouncing_Ball(int px, int py, JuegoPG* game);
	virtual ~Bouncing_Ball();
	virtual void draw() const;
	virtual bool onClick();
	virtual void update();

private:
	bool expl;
	int dx, dy;
	static const int AP = 10; //Puntos que resta cada vez que se mueve
	void sentido();
};

