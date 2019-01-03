
#include "ChessSquare.h"

bool ChessSquare::isOccupied(){
	return this->currentPiece != NULL;
}

std::string ChessSquare::getName(){
	return this->name;
}