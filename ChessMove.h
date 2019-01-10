
#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <iostream>
#include "Enums.h"

class ChessMove{
public:
	ChessMove(std::pair<int,int> init, std::pair<int,int> dest, Color player);

	std::pair<int,int> attackerPos;
	std::pair<int,int> defenderPos;
	Color movingPlayer;
};

#endif