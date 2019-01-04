#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include <string>
#include <stdlib.h>

#include "Pieces/ChessPiece.h"
#include "Enums.h"

class ChessSquare{
public:
	ChessSquare(int row, int col);
	bool isOccupied();
	std::string getName();
	std::string getOutputLine(int row);
	void setColor(Color color);
	void setPiece(ChessPiece* piece);

protected:
	const std::string name;
	int row;
	int col;
	bool occupied;
	ChessPiece* piece;
	Color colorName;
	Color outputColor;
	bool hasMoved;

	char getPieceSymbol();
};

#endif