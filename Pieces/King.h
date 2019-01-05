#include "ChessPiece.h"

#ifndef KING_H
#define KING_H

class King : public ChessPiece{
public:
	King();
	King(Color pieceColor);

	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:
	bool moveVectorPermitted(std::pair<int,int> positionChange);
	bool noInterveningPieces(int moveRow, int moveCol);
	bool castlingCoordinatesPermitted(ChessBoard& chessboard, int moveRow, int moveCol);
	bool castlingPiecesUnmoved(ChessBoard& chessboard, int moveRow, int moveCol);
};

#endif