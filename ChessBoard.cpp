#include "ChessBoard.h"

ChessBoard::ChessBoard(Color playerColor){
	this->playerColor = playerColor;
	createBoard();
	initializeBoard();
}

void ChessBoard::createBoard(){
	this->sideLength = 8;

	for(int i=0; i<sideLength; ++i){
		std::vector<ChessSquare> boardRow;

		for(int j=0; j<sideLength; ++j){
			ChessSquare square;
			boardRow.push_back(square);
		}

		board.push_back(boardRow);
	}
}

void ChessBoard::initializeBoard(){
	for(int i=0; i<sideLength; ++i){
		for(int j=0; j<sideLength; ++j){
			placePiece(playerColor, i, j);
		}
	}
}