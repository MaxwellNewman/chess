#include "ChessSquare.h"

const std::string ChessSquare::WHITE_SQUARE_UNI = "█";
const std::string ChessSquare::BLACK_SQUARE_UNI = " ";

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
		if(row == CELL_HEIGHT / 2 && i == CELL_LENGTH / 2){
			std::string symbol = getPieceSymbol();

			if(symbol != BLACK_SQUARE_UNI && symbol != WHITE_SQUARE_UNI) outputLine += char(std::stoi(symbol));
			else outputLine += symbol;
		}
		else outputLine += outputColor;
	}

	return outputLine;
}

void ChessSquare::setColor(Color color, bool useUnicode){
	this->colorName = color;

	if(color == WHITE){
		if(useUnicode) outputColor = WHITE_SQUARE_UNI;
		else outputColor = WHITE_SQUARE_CHAR;
	}
	else{
		if(useUnicode) outputColor = BLACK_SQUARE_UNI;
		else outputColor = BLACK_SQUARE_CHAR;
	}
	//color == WHITE ? this->outputColor = WHITE_SQUARE_CHAR : this->outputColor = BLACK_SQUARE_CHAR;
}

void ChessSquare::setPiece(ChessPiece* piece){
	this->piece = piece;
}

std::string ChessSquare::getPieceSymbol(){
	if(piece == NULL) return outputColor;
	return std::to_string(char(piece->getSymbol()));
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