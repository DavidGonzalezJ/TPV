#pragma once
#include <string>
class Error
{
public:
	Error(std::string mensaje);
	~Error();
	std::string showMensaje() const;
protected:
	std::string mensaje;
};

class ErrorTextura :public Error
{
public:
	ErrorTextura(std::string mensaje) :Error(mensaje){};
};

class ErrorSonido :public Error
{
public:
	ErrorSonido(std::string mensaje) :Error(mensaje){};
};

class ErrorFuente :public Error
{
public:
	ErrorFuente(std::string mensaje) :Error(mensaje){};
};

class ErrorInit :public Error
{
public:
	ErrorInit(std::string mensaje) :Error(mensaje){};
};