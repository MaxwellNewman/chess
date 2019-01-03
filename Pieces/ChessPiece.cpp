#include "ChessPiece.h"

ChessPiece::ChessPiece(){};

ChessPiece::ChessPiece(Color pieceColor, PieceType type){
	this->color = pieceColor;
	this->type = type;
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