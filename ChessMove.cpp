
#include "ChessMove.h"

ChessMove::ChessMove(std::pair<int,int> init, std::pair<int,int> dest, Color player){
	this->attackerPos = init;
	this->defenderPos = dest;
	this->movingPlayer = player;
}