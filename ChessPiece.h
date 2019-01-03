#include <vector>
#include <string>
#include "ChessBoard.h"
#include "ChessSquare.h"

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class ChessPiece{
public:
	ChessPiece(ChessBoard& board, int row, int col);
	virtual void updateValidMoves() = 0;

private:
	ChessBoard board;
	ChessSquare location;
	bool color;
};

#endif