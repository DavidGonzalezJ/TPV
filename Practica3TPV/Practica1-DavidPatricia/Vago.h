#pragma once
#include "ObjetoPG.h"
class Vago :
	public ObjetoPG
{
public:
	Vago();
	virtual ~Vago();
	virtual void draw() const {};
	virtual bool onClick() { return false; };
	virtual void update() {};
};

