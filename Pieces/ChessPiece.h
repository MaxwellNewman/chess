#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <vector>
#include <string>
#include <iostream>

#include "../Enums.h"

class ChessPiece{
public:
	ChessPiece();
	ChessPiece(Color pieceColor, PieceType type);
	bool getHasMoved();
	char getSymbol();
	Color getColor();
	PieceType getType();

private:
	Color color;
	PieceType type;
	bool hasMoved;
	char symbol;

	void setSymbol();
};

#endif