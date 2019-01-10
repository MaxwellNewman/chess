#include "Pawn.h"

const std::vector<std::pair<int,int> > Pawn::lowerMoveVectors = {std::make_pair(-1,0), std::make_pair(-2,0), std::make_pair(-1,-1), std::make_pair(-1,1)};
const std::vector<std::pair<int,int> > Pawn::upperMoveVectors = {std::make_pair(1,0), std::make_pair(2,0), std::make_pair(1,-1), std::make_pair(1,1)};

Pawn::Pawn(){
	// do nothing
}

Pawn::Pawn(Color pieceColor) : ChessPiece(pieceColor, PAWN){
	//do nothing
}

bool Pawn::validateMove(ChessBoard& chessboard, int moveRow, int moveCol){
	std::cout << "pawn row: " << moveRow << "	pawn col: " << moveCol << std::endl;

	std::pair<int, int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	std::cout << std::boolalpha << "vector permitted: " << moveVectorPermitted(chessboard, positionChange) << std::endl;
	std::cout << "no intervengin: " << noInterveningPieces(chessboard, positionChange, moveRow, moveCol) << std::endl;

	if(!moveVectorPermitted(chessboard, positionChange)) return false;
	if(!noInterveningPieces(chessboard, positionChange, moveRow, moveCol)) return false;

	return true;
}

bool Pawn::moveVectorPermitted(ChessBoard& chessboard, std::pair<int,int> positionChange){
	const std::vector<std::pair<int,int> >* moveVectors = &upperMoveVectors;

	std::cout << "row: " << positionChange.first << "	col: " << positionChange.second << std::endl;


	std::cout << std::boolalpha << (chessboard.getLowerColor() == this->color) << std::endl;
	if(chessboard.getLowerColor() == this->color) moveVectors = &lowerMoveVectors;

	for(int i=0; i<moveVectors->size(); ++i){
		std::cout << "vector row: " << (*moveVectors)[i].first << std::endl;
		if(positionChange == (*moveVectors)[i]) return true;
	}

	return false;
}

bool Pawn::noInterveningPieces(ChessBoard& chessboard, std::pair<int,int> positionChange, int moveRow, int moveCol){
	if(abs(positionChange.second) == 1){
		if(enPassantPossible(chessboard, moveRow, moveCol)) return true;
		else if(!chessboard.squareIsOccupied(moveRow, moveCol)) return false;
		else if(chessboard.getPieceColor(moveRow, moveCol) == this->color) return false;
	}
	else if(abs(positionChange.first) == 2){
		if(this->hasMoved) return false;
		if(chessboard.squareIsOccupied(this->row + positionChange.first/2, this->col)) return false;
		if(chessboard.squareIsOccupied(moveRow, moveCol)) return false;
	}
	else{
		return !chessboard.squareIsOccupied(moveRow, moveCol);
	}

	return true;
}

bool Pawn::enPassantPossible(ChessBoard& chessboard, int moveRow, int moveCol){
	if(!chessboard.squareIsOccupied(this->row, moveCol)) return false;
	if(chessboard.getPieceType(this->row, moveCol) != PAWN) return false;
	if(!chessboard.lastMoved(this->row, moveCol)) return false;
	return chessboard.getPieceColor(this->row, moveCol) != this->color;
}