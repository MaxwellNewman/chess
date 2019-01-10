#include "ChessPiece.h"

#ifndef KING_H
#define KING_H

class ChessBoard;

class King : public ChessPiece{
public:
	King();
	King(Color pieceColor);

	bool validateMove(ChessBoard& board, int moveRow, int moveCol);

private:
	bool moveVectorPermitted(std::pair<int,int> positionChange);
	bool noInterveningPieces(ChessBoard& chessboard, int moveRow, int moveCol);
	bool castlingCoordinatesPermitted(ChessBoard& chessboard, int moveRow, int moveCol);
	bool castlingPiecesUnmoved(ChessBoard& chessboard, int moveRow, int moveCol);
	bool castlingPossible(ChessBoard& chessboard, int moveRow, int moveCol);
	void orderRookToCastle(ChessBoard& chessboard, int moveCol);
};

#endif