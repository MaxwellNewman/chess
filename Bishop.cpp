#include "Bishop.h"

Bishop::Bishop(){
	// do nothing
}

Bishop::Bishop(Color pieceColor) : ChessPiece(pieceColor, BISHOP){
	//do nothing
}

bool Bishop::validateMove(ChessBoard& chessboard, int moveRow, int moveCol){
	std::pair<int,int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	std::cout << "moveVectorPermitted: " << moveVectorPermitted(positionChange) << std::endl;
	std::cout << "moverow: " << moveRow << "	moveCol: " << moveCol << std::endl;

	if(!moveVectorPermitted(positionChange)) return false;

	std::pair<int,int> moveVector = moveUnitVector(positionChange);

	int magnitude = 0;
	magnitude = std::max(abs(positionChange.first), abs(positionChange.second));

	return ChessPiece::noInterveningPieces(chessboard, moveVector, magnitude);
}

bool Bishop::moveVectorPermitted(std::pair<int,int> positionChange){
	return abs(positionChange.first) == abs(positionChange.second);
}

std::pair<int,int> Bishop::moveUnitVector(std::pair<int,int> positionChange){
	int absRowChange = abs(positionChange.first);
	positionChange.first /= absRowChange;
	positionChange.second /= absRowChange;

	return positionChange;
}