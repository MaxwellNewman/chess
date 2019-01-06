
#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <iostream>

class ChessMove{
public:
	ChessMove(std::pair<int,int> init, std::pair<int,int> dest);

	std::pair<int,int> attackerPos;
	std::pair<int,int> defenderPos;
};

#endif