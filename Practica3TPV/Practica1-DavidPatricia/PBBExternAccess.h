#pragma once
class PBBExternAccess
{
public:

	PBBExternAccess()
	{
	}

	virtual ~PBBExternAccess()
	{
	}

	// Consultar y cambiar las direcciones dx​ y dy
	virtual int getX() = 0;
	virtual void setX(int x) = 0;
	virtual int getY() = 0;
	virtual void setY(int x) = 0;

	// Consultar el número de clics sobre el objeto hasta el momento
	virtual int getClicks() = 0;

	// Consultar y cambiar los puntos asignados al objeto
	virtual int getPuntos() = 0;
	virtual void setPuntos(int punt) = 0;

	// Añadir puntos al contador global de puntos.
	virtual void addPoints(int point) = 0;

	// Desactivar el objeto
	virtual void disable() = 0;
};

