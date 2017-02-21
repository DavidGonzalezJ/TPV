#pragma once
#include "ObjetoPG.h"
class Bouncing_Ball :
	public ObjetoPG
{
public:
	Bouncing_Ball();
	virtual ~Bouncing_Ball();
	virtual void draw() const;
	virtual bool onClick();
	virtual void update();
};

