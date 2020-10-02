#include "Configuracion.h"
#include "Pieza.h"

Pieza::Pieza() {
		//pieza 0: Cuadrado, rotacion: 0
		for (int i = 0; i < 5; i++) {
			strcpy_s(mPieces[0][i][0], "00000");
			strcpy_s(mPieces[0][i][1], "00000");
			strcpy_s(mPieces[0][i][2], "00120");
			strcpy_s(mPieces[0][i][3], "00110");
			strcpy_s(mPieces[0][i][4], "00000");
		}
		//pieza 1: Palito, rotacion: 0
		strcpy_s(mPieces[1][0][0], "00000");
		strcpy_s(mPieces[1][0][1], "00100");
		strcpy_s(mPieces[1][0][2], "00200");
		strcpy_s(mPieces[1][0][3], "00100");
		strcpy_s(mPieces[1][0][4], "00100");
		//pieza 1: Palito, rotacion: 1
		strcpy_s(mPieces[1][1][0], "00000");
		strcpy_s(mPieces[1][1][1], "00000");
		strcpy_s(mPieces[1][1][2], "11210");
		strcpy_s(mPieces[1][1][3], "00000");
		strcpy_s(mPieces[1][1][4], "00000");
		//pieza 1: Palito, rotacion: 2
		strcpy_s(mPieces[1][2][0], "00100");
		strcpy_s(mPieces[1][2][1], "00100");
		strcpy_s(mPieces[1][2][2], "00200");
		strcpy_s(mPieces[1][2][3], "00100");
		strcpy_s(mPieces[1][2][4], "00000");
		//pieza 1: Palito, rotacion: 3
		strcpy_s(mPieces[1][3][0], "00000");
		strcpy_s(mPieces[1][3][1], "00000");
		strcpy_s(mPieces[1][3][2], "01211");
		strcpy_s(mPieces[1][3][3], "00000");
		strcpy_s(mPieces[1][3][4], "00000");
		//pieza 2: L, rotacion: 0
		strcpy_s(mPieces[2][0][0], "00000");
		strcpy_s(mPieces[2][0][1], "00100");
		strcpy_s(mPieces[2][0][2], "00200");
		strcpy_s(mPieces[2][0][3], "00110");
		strcpy_s(mPieces[2][0][4], "00000");
		//pieza 2: L, rotacion: 1
		strcpy_s(mPieces[2][1][0], "00000");
		strcpy_s(mPieces[2][1][1], "00000");
		strcpy_s(mPieces[2][1][2], "01210");
		strcpy_s(mPieces[2][1][3], "01000");
		strcpy_s(mPieces[2][1][4], "00000");
		//pieza 2: L, rotacion: 2
		strcpy_s(mPieces[2][2][0], "00000");
		strcpy_s(mPieces[2][2][1], "01100");
		strcpy_s(mPieces[2][2][2], "00200");
		strcpy_s(mPieces[2][2][3], "00100");
		strcpy_s(mPieces[2][2][4], "00000");
		//pieza 2: L, rotacion: 3
		strcpy_s(mPieces[2][3][0], "00000");
		strcpy_s(mPieces[2][3][1], "00010");
		strcpy_s(mPieces[2][3][2], "01210");
		strcpy_s(mPieces[2][3][3], "00000");
		strcpy_s(mPieces[2][3][4], "00000");
		//pieza 3: L mirrored, rotacion: 0
		strcpy_s(mPieces[3][0][0], "00000");
		strcpy_s(mPieces[3][0][1], "00100");
		strcpy_s(mPieces[3][0][2], "00200");
		strcpy_s(mPieces[3][0][3], "01100");
		strcpy_s(mPieces[3][0][4], "00000");
		//pieza 3: L mirrored, rotacion: 1
		strcpy_s(mPieces[3][1][0], "00000");
		strcpy_s(mPieces[3][1][1], "00000");
		strcpy_s(mPieces[3][1][2], "01210");
		strcpy_s(mPieces[3][1][3], "00010");
		strcpy_s(mPieces[3][1][4], "00000");
		//pieza 3: L mirrored, rotacion: 2
		strcpy_s(mPieces[3][2][0], "00000");
		strcpy_s(mPieces[3][2][1], "00110");
		strcpy_s(mPieces[3][2][2], "00200");
		strcpy_s(mPieces[3][2][3], "00100");
		strcpy_s(mPieces[3][2][4], "00000");
		//pieza 3: L mirrored, rotacion: 3
		strcpy_s(mPieces[3][3][0], "00000");
		strcpy_s(mPieces[3][3][1], "01000");
		strcpy_s(mPieces[3][3][2], "01210");
		strcpy_s(mPieces[3][3][3], "00000");
		strcpy_s(mPieces[3][3][4], "00000");
		//pieza 4: Z, rotacion: 0
		strcpy_s(mPieces[4][0][0], "00000");
		strcpy_s(mPieces[4][0][1], "00010");
		strcpy_s(mPieces[4][0][2], "00210");
		strcpy_s(mPieces[4][0][3], "00100");
		strcpy_s(mPieces[4][0][4], "00000");
		//pieza 4: Z, rotacion: 1
		strcpy_s(mPieces[4][1][0], "00000");
		strcpy_s(mPieces[4][1][1], "00000");
		strcpy_s(mPieces[4][1][2], "01200");
		strcpy_s(mPieces[4][1][3], "00110");
		strcpy_s(mPieces[4][1][4], "00000");
		//pieza 4: Z, rotacion: 2
		strcpy_s(mPieces[4][2][0], "00000");
		strcpy_s(mPieces[4][2][1], "00100");
		strcpy_s(mPieces[4][2][2], "01200");
		strcpy_s(mPieces[4][2][3], "01000");
		strcpy_s(mPieces[4][2][4], "00000");
		//pieza 4: Z, rotacion: 3
		strcpy_s(mPieces[4][3][0], "00000");
		strcpy_s(mPieces[4][3][1], "01100");
		strcpy_s(mPieces[4][3][2], "00210");
		strcpy_s(mPieces[4][3][3], "00000");
		strcpy_s(mPieces[4][3][4], "00000");
		//pieza 5: Z mirrored, rotacion: 0
		strcpy_s(mPieces[5][0][0], "00000");
		strcpy_s(mPieces[5][0][1], "00100");
		strcpy_s(mPieces[5][0][2], "00210");
		strcpy_s(mPieces[5][0][3], "00010");
		strcpy_s(mPieces[5][0][4], "00000");
		//pieza 5: Z mirrored, rotacion: 1
		strcpy_s(mPieces[5][1][0], "00000");
		strcpy_s(mPieces[5][1][1], "00000");
		strcpy_s(mPieces[5][1][2], "00210");
		strcpy_s(mPieces[5][1][3], "01100");
		strcpy_s(mPieces[5][1][4], "00000");
		//pieza 5: Z mirrored, rotacion: 2
		strcpy_s(mPieces[5][2][0], "00000");
		strcpy_s(mPieces[5][2][1], "01000");
		strcpy_s(mPieces[5][2][2], "01200");
		strcpy_s(mPieces[5][2][3], "00100");
		strcpy_s(mPieces[5][2][4], "00000");
		//pieza 5: Z mirrored, rotacion: 3
		strcpy_s(mPieces[5][3][0], "00000");
		strcpy_s(mPieces[5][3][1], "00110");
		strcpy_s(mPieces[5][3][2], "01200");
		strcpy_s(mPieces[5][3][3], "00000");
		strcpy_s(mPieces[5][3][4], "00000");
		//pieza 6: T, rotacion: 0
		strcpy_s(mPieces[6][0][0], "00000");
		strcpy_s(mPieces[6][0][1], "01110");
		strcpy_s(mPieces[6][0][2], "00200");
		strcpy_s(mPieces[6][0][3], "00000");
		strcpy_s(mPieces[6][0][4], "00000");
		//pieza 6: T, rotacion: 1
		strcpy_s(mPieces[6][1][0], "00000");
		strcpy_s(mPieces[6][1][1], "00100");
		strcpy_s(mPieces[6][1][2], "01200");
		strcpy_s(mPieces[6][1][3], "00100");
		strcpy_s(mPieces[6][1][4], "00000");
		//pieza 6: T, rotacion: 2
		strcpy_s(mPieces[6][2][0], "00000");
		strcpy_s(mPieces[6][2][1], "00100");
		strcpy_s(mPieces[6][2][2], "01210");
		strcpy_s(mPieces[6][2][3], "00000");
		strcpy_s(mPieces[6][2][4], "00000");
		//pieza 6: T, rotacion: 3
		strcpy_s(mPieces[6][3][0], "00000");
		strcpy_s(mPieces[6][3][1], "00100");
		strcpy_s(mPieces[6][3][2], "00210");
		strcpy_s(mPieces[6][3][3], "00100");
		strcpy_s(mPieces[6][3][4], "00000");
		//cuadrito
		for (int i = 0; i < 4; i++) {
			mPiecesInitialPosition[0][i][0] = { -2 };
			mPiecesInitialPosition[0][i][1] = { -3 };
		};
		//palito
		for (int i = 0; i < 4; i++) {
			mPiecesInitialPosition[1][i][0] = { -2 };
			mPiecesInitialPosition[1][i][1] = { -(i % 2) - 2 };
		}
		//L
		for (int i = 0; i < 3; i++) {
			mPiecesInitialPosition[2][i][0] = { -2 };
			mPiecesInitialPosition[2][i][1] = { -3 };
		}
		mPiecesInitialPosition[2][3][0] = { -2 };
		mPiecesInitialPosition[2][3][1] = { -2 };
		//L mirrored
		for (int i = 0; i < 2; i++) {
			mPiecesInitialPosition[3][i][0] = { -2 };
			mPiecesInitialPosition[3][i][1] = { (i % 2) - 3 };
		}
		for (int i = 2; i < 3; i++) {
			mPiecesInitialPosition[3][i][0] = { -2 };
			mPiecesInitialPosition[3][i][1] = { -3 };
		}
		//N
		for (int i = 2; i < 3; i++) {
			mPiecesInitialPosition[4][i][0] = { -2 };
			mPiecesInitialPosition[4][i][1] = { -3 };
		}
		mPiecesInitialPosition[4][3][0] = { -2 };
		mPiecesInitialPosition[4][3][1] = { -2 };
		//N mirrored
		for (int i = 2; i < 3; i++) {
			mPiecesInitialPosition[5][i][0] = { -2 };
			mPiecesInitialPosition[5][i][1] = { -3 };
		}
		mPiecesInitialPosition[5][3][0] = { -2 };
		mPiecesInitialPosition[5][3][1] = { -2 };
		//T
		for (int i = 2; i < 3; i++) {
			mPiecesInitialPosition[6][i][0] = { -2 };
			mPiecesInitialPosition[6][i][1] = { -3 };
		}
		mPiecesInitialPosition[6][3][0] = { -2 };
		mPiecesInitialPosition[6][3][1] = { -2 };
	}
	int Pieza::GetBlockType(const int& pPiece, const int& pRotacion, const int& pX, const int& pY) {
		return  mPieces[pPiece][pRotacion][pX][pY];
	};
	int Pieza::GetXInitialPosition(const int& pPiece, const int& pRotacion) {
		return mPiecesInitialPosition[pPiece][pRotacion][0];
	};
	int Pieza::GetYInitialPsotion(const int& pPiece, const int& pRotacion) {
		return mPiecesInitialPosition[pPiece][pRotacion][1];
	};


