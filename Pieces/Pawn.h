#include "ChessPiece.h"
#include <stdlib.h>

#ifndef PAWN_H
#define PAWN_H

class Pawn : public ChessPiece{
public:
	Pawn();
	Pawn(Color pieceColor);
	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:
	static const std::vector<std::pair<int,int> > upperMoveVectors;
	static const std::vector<std::pair<int,int> > lowerMoveVectors;
	bool moveVectorPermitted(std::pair<int,int> positionChange);
	bool enPassantPossible(Chessboard& chessboard, int moveRow, int moveCol);
	bool noInterveningPieces(ChessBoard& chessboard, std::pair<int,int> positionChange, int moveRow, int moveCol);
};

#endif