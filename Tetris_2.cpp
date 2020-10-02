#include "Configuracion.h"
#include "Juego.h"
#include "General.h"
#include "Pieza.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO lpCursor;


int main()
{

	lpCursor.bVisible = false;
	lpCursor.dwSize = 10;
	SetConsoleCursorInfo(console, &lpCursor);
	
	Juego* juego = new Juego();
	//Tablero* tablero = new Tablero();
	bool out = true;
	char ch;

	juego->init();
	juego->portada();
	//while (out) {
	juego->gameLoop();
	juego->gameOver();
		//cin.get(ch);
	ch = _getch();
	/*	//if (_kbhit())
		//{
			ch = _getch();

		switch (ch)
		{
		case ('y'):
			//tablero->reset();
			system("cls");
			//goto inicio;
			//break;
		case ('n'):
			out = false;
			//return 0;
			break;
		}
	}*/
	cout << ch;
	cin.get(); 
	return 0;
}

