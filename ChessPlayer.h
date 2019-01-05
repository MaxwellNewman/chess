#include "ChessMove.h"

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

class ChessPlayer{
public:
	ChessPlayer(Color playerColor);
	virtual ChessMove selectMove() = 0;

private:
	Color playerColor;
};

#endif