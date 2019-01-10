#include "ChessPiece.h"
#include <stdlib.h>

#ifndef KNIGHT_H
#define KNIGHT_H

class ChessBoard;

class Knight : public ChessPiece{
public:
	Knight();
	Knight(Color pieceColor);
	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:

	bool locationIsValid(ChessBoard& board, std::pair<int,int> positionChange);
};

#endif