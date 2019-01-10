#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include <string>
#include <stdlib.h>

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "Enums.h"

class ChessPiece;

class ChessSquare{
public:
	ChessSquare(int row, int col);
	bool isOccupied();
	std::string getName();
	std::string getOutputLine(int row);
	void setColor(Color color);
	void setPiece(ChessPiece* piece);
	ChessPiece* replacePiece(ChessPiece* replacement);
	bool removePiece();

	ChessPiece* piece;

protected:
	const std::string name;
	int row;
	int col;
	bool occupied;
	Color colorName;
	Color outputColor;

	char getPieceSymbol();
};

#endif