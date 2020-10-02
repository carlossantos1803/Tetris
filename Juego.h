#pragma once
#include "Tablero.h"
#include "General.h"
class Juego
{
	Tablero* tablero = new Tablero();
public:

	void init();
	void portada();
	//int getRand(const int& x);
	void gameLoop();
	//void marcador(const unsigned short int& );
	void gameOver();
	void actualizar(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y);

	

};

