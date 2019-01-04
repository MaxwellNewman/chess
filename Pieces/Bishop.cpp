#include "Bishop.h"

Bishop::Bishop(){
	// do nothing
}

Bishop::Bishop(Color pieceColor) : ChessPiece(pieceColor, BISHOP){
	//do nothing
}

bool Bishop::validateMove(ChessBoard& board, int moveRow, int moveCol){
	if(!moveVectorPermitted) return false;

	std::pair moveUnitVector = moveUnitVector(positionChange);
}

bool Bishop::moveVectorPermitted(std::pair<int,int> positionChange){
	return abs(positionChange->first) == abs(positionChange->second);
}

std::pair<int,int> Bishop::moveUnitVector(std::pair<int,int> positionChange){
	int absRowChange = abs(positionChange->first);
	positionChange->first /= absRowChange;
	positionChange->second /= absRowChange;

	return positionChange;
}