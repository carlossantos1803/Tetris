#include "Configuracion.h"
#include "General.h"
#include "Juego.h"

void Juego::init() {
	SetConsoleTitle(TEXT("TETRIS Game")); //He keeps compiling with UNICODE, so he needs to use some Windows macros around his string literals...
}
	
void Juego::portada() {
	system("cls");
	unsigned short int i,j;
	string tetris[9] = { "  ________________________________     ___   ______",
							" /__/__/__// ___//__/__/__//  ___  \\  /__/ (       /",
							"   /__/   / /_     /__/   /  /__/  | /__/ (  _____/",
							"  /__/   /  _/    /__/   /  _   __/ /__/ (_____  ) ",
							" /__/   /  /__   /__/   /  / |  |  /__/ /       )  ",
							"/__/   /_____/  /__/   /__/  |__|_/__/_/_______)",
							"",
							"                   by",
							"              Carlos Santos"
	};
	for (i = 0; i < 9; i++) {
		General::gotoxy(10, 1 + i);
		cout << tetris[i];
	}

	unsigned char block = 177;
	General::colores(General::rojo);
	for (i = 0; i < 20; i++) {// ancho del tablero de la portada
		General::gotoxy(20 + i, 11);
		cout << block;
	}
	for (i = 0; i < 20; i++) {// ancho del tablero de la portada
		General::gotoxy(20 + i, 27);
		cout << block;
	}
	for (i = 0; i < 17; i++) { // alto del tablero
		General::gotoxy(20, 11 + i);
		cout << block;
	}
	for (i = 0; i < 17; i++) { // alto del tablero
		General::gotoxy(40, 11 + i);
		cout << block;
	}

	//ingresando algunas piezas. T
	General::colores(General::rojo);
	block = 178;
	for (i = 0; i < 3; i++) {
		General::gotoxy(22 + i, 26);
		cout << block;
	}
	General::gotoxy(23, 25);
	cout << block;

	//ingresando L;
	General::colores(General::verde);
	for (i = 0; i < 3; i++) {
		General::gotoxy(25 + i, 26);
		cout << block;
	}
	General::gotoxy(27, 25);
	cout << block;
	//ingresando z
	General::colores(General::azul);
	for (i = 0; i < 2; i++) {
		General::gotoxy(28, 26 - i);
		cout << block;
	}
	for (i = 0; i < 2; i++) {
		General::gotoxy(29, 25 - i);
		cout << block;
	}
	//ingresando |;
	General::colores(General::blanco);
	for (i = 0; i < 4; i++) {
		General::gotoxy(30, 26 - i);
		cout << block;
	}
	//ingresando cuadrito
	General::colores(General::amarillo);
	for ( j = 0; j < 2; j++) {
		for (i = 0; i < 2; i++) {
			General::gotoxy(31 + j, 26 - i);
			cout << block;
		}
	}
	//ingresando L mirrored;
	General::colores(General::purpura);
	for (i = 0; i < 3; i++) {
		General::gotoxy(33 + i, 26);
		cout << block;
	}
	General::gotoxy(33, 25);
	cout << block;
	//ingresando z mirrored;
	General::colores(General::aqua_marina);
	for (i = 0; i < 2; i++) {
		General::gotoxy(36 + i, 26);
		cout << block;
	}
	for (i = 0; i < 2; i++) {
		General::gotoxy(37 + i, 25);
		cout << block;
	}
	//ingresando L en caida;
	General::colores(General::verde);
	for (i = 0; i < 3; i++) {
		General::gotoxy(33, 13 + i);
		cout << block;
	}
	General::gotoxy(34, 15);
	cout << block;

	General::gotoxy(1, 29);
	General::colores(General::blanco);
	cout << "\t\tPresione enter para Iniciar";
	cin.get();
	system("cls");
}

void Juego::actualizar(const unsigned short int& tipo, const unsigned short int& rotacion, const unsigned short int& x, const unsigned short int& y) {
	unsigned short int tipo_anterior = 0, rotacion_anterior = 0, pos_x_ant = 0, pos_y_ant = 0;
	tablero->limpiarMatriz(tipo_anterior, rotacion_anterior, pos_x_ant, pos_y_ant);
	tablero->cargoTablero(tipo, rotacion, x, y);
	tablero->dibujarTablero();
	tipo_anterior = tipo;
	rotacion_anterior = rotacion;
	pos_x_ant = x;
	pos_y_ant = y;
}

void Juego::gameLoop() {
	Tablero* tablero = new Tablero();
	unsigned short int tipo, rotacion, tempo = 1000, z = INICIO, old_z = INICIO, lineas = 0, rise = 10, divisor = 2;
	short int move = 0, old_pos_x = 0, old_pos_y = INICIO, old_rotacion = 0, old_move = 0;
	bool out = true, nueva_pieza = false, block_d = false, repeat = true;
	char ch;

	tipo = tablero->getRand(7);
	rotacion = 0;

	auto start = chrono::system_clock::now();
	auto end = chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration;

	while (repeat)
	{
		end = chrono::system_clock::now();
		duration = end - start;

		if (duration.count() > tempo) { //usar 30 y dividirlo entre 10 velocidades 
			start = end;
			z++;
			block_d = true;
		}


		if (nueva_pieza) {
			z = INICIO;
			move = 0;
			old_move = 0;
			old_pos_x = 0;
			old_pos_y = 0;
			tipo = tablero->getRand(7);
			rotacion = 0;
			lineas += tablero->verificarLinea();
			nueva_pieza = false;
		}

		if (lineas > rise&& divisor < 10) {
			tempo -= 150;
			divisor++;
			rise += 10;
		}

		if (_kbhit())
		{
			ch = _getch();

			switch (ch)
			{
			case 27:               // press ESC to exit
				repeat = false;
				break;
			case 32:               // press SPACE to clear screen
				//system("cls");// clrscr();
				break;
			case ('s'):
				move++;
				break;
			case ('S'):
				move++;
				break;
			case ('a'):
				move--;
				break;
			case ('A'):
				move--;
				break;
			case ('l'):
				rotacion++;
				if (rotacion > 3) rotacion = 0;
				break;
			case ('L'):
				rotacion++;
				if (rotacion > 3) rotacion = 0;
				break;
			case ('d'):
				if (!block_d) {
					z++;
				}
				block_d = false;
				break;
			}
		}

		tablero->limpiarMatriz(tipo, old_rotacion, PUNTO_INICIAL + old_pos_x, old_pos_y);

		if (!tablero->colision(tipo, old_rotacion, PUNTO_INICIAL + move, z)) {
			old_move = move;
			old_pos_x = move;
		}
		else {
			if (PUNTO_INICIAL + move > PUNTO_INICIAL + old_move)
				move--;
			else {
				move++;
			}
		}

		if (!tablero->colision(tipo, rotacion, PUNTO_INICIAL + move, z)) { //a la final es una sola colision cambia es los 
			old_rotacion = rotacion;
		}
		else {
			rotacion--; //devolver la rotacion
			if (rotacion < 0) {
				rotacion = 3;
			}
		}

		if (!tablero->colision(tipo, old_rotacion, PUNTO_INICIAL + old_move, z)) {
			old_z = z;
			old_pos_y = z;
		}
		else {
			nueva_pieza = true;
		}

		if (z < 5 && nueva_pieza == true) {
			repeat = false;
		}

		tablero->cargoTablero(tipo, old_rotacion, PUNTO_INICIAL + old_move, old_z);
		tablero->dibujarTablero();
		tablero->marcador(lineas);

	}
}

/*int Juego::getRand(const int& x) {
	return (rand() % (x - 0) + 0);
}*/

/*
void Juego::marcador(const unsigned short int& lineas) {
	General::gotoxy(40, 4);
	cout << " LINEAS ";
	General::gotoxy(43, 5);
	cout << lineas;
	//General::gotoxy(40, 7);
	//cout << " SCORE ";
}*/

void Juego::gameOver() {
	unsigned short int i;
	string gameover[] = { "            ____                       ___",
		            	  "       	/ ___| __ _ _ __ ___   ___ / _ \\__   _____ _ __ ",
			              "          | |  _ / _` | '_ ` _ \\ / _ \\ | | \\ \\ / / _ \\ '__| ",
		            	  "	       | |_| | (_| | | | | | |  __/ |_| |\\ V /  __/ | ",
			              "           \\____|\\__|_|_| |_| |_|\\___|\\___/  \\_/ \\___|_|" };
	General::colores(General::amarillo);
	for (i = 0; i < 5; i++) {
		General::gotoxy(45, 10 + i);
		cout << gameover[i];
	}
}