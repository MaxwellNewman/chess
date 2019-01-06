#include "ChessPiece.h"

ChessPiece::ChessPiece(){};

ChessPiece::ChessPiece(Color pieceColor, PieceType type){
	this->color = pieceColor;
	this->type = type;
	this->hasMoved = false;
	setSymbol();
}

bool ChessPiece::getHasMoved(){
	return this->hasMoved;
}

Color ChessPiece::getColor(){
	return this->color;
}

char ChessPiece::getSymbol(){
	return symbol;
}

void ChessPiece::setSymbol(){
	switch(type){
		case PAWN: symbol = 'P'; break;
		case KNIGHT: symbol = 'N'; break;
		case BISHOP: symbol = 'B'; break;
		case ROOK: symbol = 'R'; break;
		case QUEEN: symbol = 'Q'; break;
		case KING: symbol = 'K'; break;
	}
}

PieceType ChessPiece::getType(){
	return type;
}

void ChessPiece::setLocation(int row, int col){
	this->row = row;
	this->col = col;
}

virtual bool noInterveningPieces(ChessBoard& chessboard, std::pair<int,int>& moveUnitVector, int moveMagnitude){
	int currentRow = this->row;
	int currentCol = this->col;

	for(int i=0; i<moveMagnitude; ++i){
		currentRow += moveUnitVector->first;
		currentCol += moveUnitVector->second;

		if(chessboard.squareIsOccupied(currentRow, currentCol)){
			if(chessboard.getPieceColor(currentRow, currentCol) == this->color) return false;
			else if (i != moveMagnitude - 1) return false;
		}
	}

	return true;
}

virtual bool isInDanger(ChessBoard& chessboard){
	std::vector<std::pair<int,int> > directionVectors = chessboard.getDirectionVectors();

	for(int i=0; i<directionVectors.size(); ++i){
		if(isInDangerFromDirection(chessboard, directionVectors[i])) return true;
	}

	if(chessboard.knightsCanAttack(this->getLocation(), this->color)) return true;

	return false;
}

bool isInDangerFromDirection(ChessBoard& chessboard, std::pair<int,int>& directionVector){
	int currRow = this->row + directionVector.first;
	int currCol = this->col + directionVector.second;

	while(!chessboard.coordinatesOffBoard(currRow, currCol)){
		if(squareIsOccupied(currRow, currCol)){
			if(chessboard.getPieceColor(currRow, currCol) == this->color) return false;

			std::pair<int,int> attackerPos = std::make_pair(currRow, currCol);
			std::pair<int,int> defenderPos = std::make_pair(this->row, this->col);

			return chessboard.pieceCanAttack(attackerPos, defenderPos);
		}

		currRow += directionVector.first;
		currCol += directionVector.second;
	}

	return false;
}

std::pair<int,int> ChessPiece::getLocation(){
	return std::make_pair(this->row, this->col);
}

bool ChessPiece::isAlive(){
	return this->alive;
}