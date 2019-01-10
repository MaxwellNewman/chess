
#include "ChessSquare.h"

ChessSquare::ChessSquare(int row, int col){
	this->row = row;
	this->col = col;
}

bool ChessSquare::isOccupied(){
	return this->piece != NULL;
}

std::string ChessSquare::getName(){
	return this->name;
}

std::string ChessSquare::getOutputLine(int row){
	if(row >= CELL_HEIGHT) return "";
	std::string outputLine = "";

	for(int i=0; i<CELL_LENGTH; ++i){
		if(row == CELL_HEIGHT / 2 && i == CELL_LENGTH / 2) outputLine += getPieceSymbol();
		else outputLine += char(outputColor);
	}

	return outputLine;
}

void ChessSquare::setColor(Color color){
	this->colorName = color;
	color == WHITE ? this->outputColor = WHITE_SQUARE : this->outputColor = BLACK_SQUARE;
}

void ChessSquare::setPiece(ChessPiece* piece){
	this->piece = piece;
}

char ChessSquare::getPieceSymbol(){
	if(piece == NULL) return char(outputColor);
	return piece->getSymbol();
}

ChessPiece* ChessSquare::replacePiece(ChessPiece* replacement){
	ChessPiece* previousPiece = this->piece;

	this->piece = replacement;
	this->occupied = (bool)replacement;

	if(replacement){
		replacement->setLocation(this->row, this->col);
	}

	return previousPiece;
}