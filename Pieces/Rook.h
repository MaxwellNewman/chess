#include "ChessPiece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public ChessPiece{
public:
	Rook();
	Rook(Color pieceColor);
	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:
	bool moveVectorPermitted(std::pair<int,int> positionChange);
	std::pair<int,int> moveUnitVector(std::pair<int,int> positionChange);
};

#endif