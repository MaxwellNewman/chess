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