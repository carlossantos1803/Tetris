#include "Tablero.h"
#include "Pieza.h"
#include "General.h"

Tablero::Tablero() {
	unsigned short int i, j;
	for ( i = 0; i < ALTO_TABLERO ; i++) { // ancho del tablero
		for ( j = 0; j < ANCHO_TABLERO ; j++) {//alto del tablero
			tablero[i][j] = '0';
		}
	}
	for (j = 0; j < 2; j++) {
		for (i = 0; i < ANCHO_TABLERO; i++) {//linea izquirda y deracha superior e inferior dibujable;
			//tablero[j][i] = General::blanco;
			tablero[ALTO_TABLERO - 1 - j][i] = General::blanco;
		}
	}
	
	for (j = 0; j < 2; j++) {
		for (i = 2; i < ALTO_TABLERO - 2; i++) {//linea izquirda y deracha superior e inferior dibujable;
			tablero[i][j] = General::blanco;
			tablero[i][ANCHO_TABLERO - 1 - j] = General::blanco;
		}
	}
}
void Tablero::cargoTablero(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x , const unsigned short int& y )
{
	short int i, j;
	for (i = 4; i >= 0; i--) { //LEER LA MATRIZ DEL FINAL AL INICIO
		if (y + i - 2 < 2) {
				break;
		}
		else{
			for (j = 4; j >= 0; j--) {
				if (pieza->GetBlockType(tipo, rotacion, i, j) != '0') {
					tablero[y + i - 2][x + j - 2] = tipo + 1;
				}
			}
		}
	}
}

void Tablero::limpiarMatriz(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y) {
	short int i, j;
	for (i = 4; i >= 0; i--) { 
		for (j = 4; j >= 0; j--) {
			if (pieza->GetBlockType(tipo, rotacion, i,j) != '0') {
				tablero[y+i-2][x+j-2] = '0';
			}
		}
	}
}

/*void Tablero::verificarLinea() {
	short int i, j, k,l , linea = 0;
	for (j = ALTO_TABLERO - 3; j >= 1; j--) {
		for (i = ANCHO_TABLERO - 3; i >= 2; i--) {
			if (tablero[j][i] != '0') {
				linea++;
			}
		}
		if (linea == ANCHO_TABLERO - 4) {
			for (k = j; k >= 2; k--) {
				for (l = ANCHO_TABLERO - 3; l >= 2; l--) {
					tablero[k][l] = tablero[k - 1][l];
				}
			}
			j++;
		}
		linea = 0;
	}
}*/

void Tablero::reset() {
	unsigned short int i, j;
	for (i = 0; i < ALTO_TABLERO; i++) { // ancho del tablero
		for (j = 0; j < ANCHO_TABLERO; j++) {//alto del tablero
			tablero[i][j] = '0';
		}
	}
	for (j = 0; j < 2; j++) {
		for (i = 0; i < ANCHO_TABLERO; i++) {//linea izquirda y deracha superior e inferior dibujable;
			//tablero[j][i] = General::blanco;
			tablero[ALTO_TABLERO - 1 - j][i] = General::blanco;
		}
	}

	for (j = 0; j < 2; j++) {
		for (i = 2; i < ALTO_TABLERO - 2; i++) {//linea izquirda y deracha superior e inferior dibujable;
			tablero[i][j] = General::blanco;
			tablero[i][ANCHO_TABLERO - 1 - j] = General::blanco;
		}
	}
}

int Tablero::verificarLinea() {
	short int i, j, k, l, linea = 0, lineas = 0;
	for (j = ALTO_TABLERO - 3; j >= 1; j--) {
		for (i = ANCHO_TABLERO - 3; i >= 2; i--) {
			if (tablero[j][i] != '0') {
				linea++;
			}
		}
		if (linea == ANCHO_TABLERO - 4) {
			for (k = j; k >= 2; k--) {
				for (l = ANCHO_TABLERO - 3; l >= 2; l--) {
					tablero[k][l] = tablero[k - 1][l];
				}
			}
			j++;
			lineas++;
		}
		linea = 0;
	}
	return lineas;
}

bool Tablero::colision(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y) {
	short int i, j;
	for (i = 4; i >= 0; i--) {
		for (j = 4; j >= 0; j--) {
			if (pieza->GetBlockType(tipo, rotacion, i, j) != '0' && tablero[y + i - 2][x + j - 2] != '0') {
				return true;
			}
		}
	}
	return false;
}

bool Tablero::gameOver(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y) {
	short int i, j;
	if (y <= 1) {
		for (i = 4; i >= 0; i--) {
			for (j = 4; j >= 0; j--) {
				if (pieza->GetBlockType(tipo, rotacion, i, j) != '0' && tablero[y + i - 2][x + j - 2] != '0') {
					return true;
				}
			}
		}
	}
	else {
		return false;
	}
}

bool Tablero::primeraLinea(){
	short int i;
	for (i = 2; i < ANCHO_TABLERO - 2; i++) {
		if (tablero[2][i] != '0') {
			return true;
		}
	}
	return false;
}
void Tablero::dibujarTablero() {
	char block = 178;
	for (int i = 0; i < ALTO_TABLERO; i++) {
		for (int j = 0; j < ANCHO_TABLERO; j++) {
			General::gotoxy(20 + j, 2 + i);
			if (tablero[i][j] != '0') {
				General::colores(tablero[i][j]);
				cout << block;
			}
			else {
				//General::colores(General::rojo);
				cout << " ";
				//cin.get();
			}
		}
	}
}

void Tablero::marcador(const unsigned short int& lineas) {
	General::gotoxy(40, 4);
	cout << " LINEAS ";
	General::gotoxy(43, 5);
	cout << lineas;
	//General::gotoxy(40, 7);
	//cout << " SCORE ";
}

int Tablero::getRand(const int& x) {
	return (rand() % (x - 0) + 0);
}

void Tablero::marcoTablero() {
	unsigned short int i, j;
	char block = 178;
	for (j = 0; j < 2; j++) {
		for (i = 0; i < ANCHO_TABLERO; i++) {//linea izquirda y deracha superior e inferior dibujable;
			//tablero[j][i] = General::blanco;
			General::gotoxy(20 + i, 2 + j);
			cout << block;/*
			General::gotoxy(20 + i, 2 + j+ ALTO_TABLERO - 1);
			cout << block;*/
			//tablero[ALTO_TABLERO - 1 - j][i] = General::blanco;
		}
	}
		
	for (j = 0; j < 2; j++) {
		for (i = 2; i < ALTO_TABLERO - 2; i++) {//linea izquirda y deracha superior e inferior dibujable;
			/*General::gotoxy(20 + i, 2 + j);
			cout << block;*/
			/*General::gotoxy(20 + i + ANCHO_TABLERO - 1, 2 + j);
			cout << block;*/
		}
	}
		
}
	

