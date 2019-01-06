
#include "ChessMove.h"

ChessMove::ChessMove(std::pair<int,int> init, std::pair<int,int> dest){
	this->attackerPos = init;
	this->defenderPos = dest;
}