#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class ChessBoard;

class Bishop : public ChessPiece{
public:
	Bishop();
	Bishop(Color pieceColor);
	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:
	bool moveVectorPermitted(std::pair<int,int> positionChange);
	std::pair<int,int> moveUnitVector(std::pair<int,int> positionChange);
	//bool noInterveningPieces(ChessBoard& chessboard, std::pair<int,int>& moveUnitVector, int moveMagnitude);
};

#endif