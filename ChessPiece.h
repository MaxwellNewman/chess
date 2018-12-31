#include <vector>
#include "ChessBoard.h"

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

class ChessPiece{
public:
	std::vector<std::pair<int,int> > validMoves;

	ChessPiece(ChessBoard& board);
	virtual void updateValidMoves() = 0;

private:
	ChessBoard board;
};

#endif