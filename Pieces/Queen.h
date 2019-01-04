#include "ChessPiece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen : public ChessPiece{
public:
	Queen();
	Queen(Color pieceColor);
	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:
	bool moveVectorPermitted(std::pair<int,int> positionChange);
	std::pair<int,int> moveUnitVector(std::pair<int,int> positionChange);
};

#endif