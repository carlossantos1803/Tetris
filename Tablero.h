#pragma once
#include "Pieza.h"
#include "Configuracion.h"
class Tablero {
	Pieza *pieza = new Pieza();
	unsigned short int tablero[ALTO_TABLERO][ANCHO_TABLERO];
	
public:
	Tablero();
	void marcoTablero();
	void cargoTablero(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y);
	void limpiarMatriz(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y);
	void reset();
	int getRand(const int& x);
	//void verificarLinea();
	int verificarLinea();
	bool primeraLinea();
	bool colision(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y);
	bool gameOver(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y);
	void dibujarTablero();

	void marcador(const unsigned short int& lineas);
	
};



