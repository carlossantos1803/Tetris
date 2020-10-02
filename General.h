#pragma once
#include "Configuracion.h"
class General

{
public:
	enum color { rojo = 1, azul, verde, blanco, amarillo, purpura, aqua_marina };
	static void colores(const int& color);
	static void gotoxy(const int& x, const int& y);
};
