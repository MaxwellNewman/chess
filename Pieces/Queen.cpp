#include "Queen.h"

Queen::Queen(){
	// do nothing
}

Queen::Queen(Color pieceColor) : ChessPiece(pieceColor, QUEEN){
	//do nothing
}

bool Queen::validateMove(ChessBoard& board, int moveRow, int moveCol){
	std::pair<int,int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	if(!moveVectorPermitted(positionChange)) return false;

	std::pair<int,int> moveUnitVector = moveUnitVector(positionChange);

	int magnitude = max(abs(positionChange->first, positionChange->second));
	return noInterveningPieces(chessboard, moveUnitVector, magnitude);
}

std::pair<int,int> Queen::moveUnitVector(std::pair<int,int> positionChange){
	int divisor = 0;

	divisor = max(abs(positionChange->first), abs(positionChange->second));
	positionChange->first /= divisor;
	positionChange->second /= divisor;

	return positionChange;
}

bool Queen::moveVectorPermitted(std::pair<int,int> positionChange){
	if(positionChange->first == 0 && positionChange->second == 0) return false;
	if(positionChange->first == 0 != positionChange->second == 0) return true;

	int absDeltaX = abs(positionChange->first);
	int absDeltaY = abs(positionChange->second);

	return absDeltaX == absDeltaY;
}