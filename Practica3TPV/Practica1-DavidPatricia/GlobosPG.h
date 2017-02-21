//#pragma once
//#include "TexturasSDL.h"
#ifndef H_GlobosPG_H
#define H_GlobosPG_H
#include <SDL.h>
#include "ObjetoPG.h"
#include "checkML.h"
class GlobosPG: public ObjetoPG{
public:
	GlobosPG(int px, int py, JuegoPG* game);
	~GlobosPG();
	virtual void draw() const;
	virtual bool onClick();
	virtual void update();


protected:
	bool expl;
	bool vis;
	static const int PVIS = 70; //La probabilidad de que un globo est� visible
	static const int PDES = 30; //La probabilidad de que se desinfle
	static const int DT = 5; //Disminuci�n tama�o
	static const int AP = 5; //Puntos que suma cada vez que se desinfle

};
#endif