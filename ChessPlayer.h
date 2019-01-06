#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include "Enums.h"
#include "ChessMove.h"

class ChessPlayer{
public:
	ChessPlayer();
	ChessPlayer(Color playerColor);
	virtual ChessMove selectMove() = 0;

private:
	Color playerColor;
};

#endif