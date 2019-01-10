#include "Rook.h"

Rook::Rook(){
	// do nothing
}

Rook::Rook(Color pieceColor) : ChessPiece(pieceColor, ROOK){
	//do nothing
}

bool Rook::validateMove(ChessBoard& chessboard, int moveRow, int moveCol){
	std::pair<int,int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	if(!moveVectorPermitted(positionChange)) return false;

	std::pair<int,int> moveVector = moveUnitVector(positionChange);

	int magnitude = 0;
	magnitude = std::max(abs(positionChange.first), abs(positionChange.second));

	return noInterveningPieces(chessboard, moveVector, magnitude);
}

// the movement is valid if the change in x, or the change in y, but not both, are 0
bool Rook::moveVectorPermitted(std::pair<int,int> positionChange){
	bool deltaXIsZero = positionChange.first == 0;
	bool deltaYIsZero = positionChange.second == 0;

	return deltaXIsZero != deltaYIsZero;
}

std::pair<int,int> Rook::moveUnitVector(std::pair<int,int> positionChange){
	int divisor = 0;

	divisor = std::max(abs(positionChange.first), abs(positionChange.second));
	positionChange.first /= divisor;
	positionChange.second /= divisor;

	return positionChange;
}