#pragma once


class Pieza {
	char mPieces[7/*pieza*/][4/* rotacion*/][5/*bloques_horizontales*/][6/*bloques verticales*/];
	int mPiecesInitialPosition[7/*pieza*/][4/*rotacion*/][2/*posicion x y*/];
public:
	Pieza();
	int GetBlockType(const int& pPiece, const int& pRotacion, const int& pX, const int& pY);
	int GetXInitialPosition(const int& pPiece, const int& pRotacion);
	int GetYInitialPsotion(const int& pPiece, const int& pRotacion);

};

