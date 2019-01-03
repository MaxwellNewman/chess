#include "ChessBoard.h"

ChessBoard::ChessBoard(Color playerColor){
	this->playerColor = playerColor;
	createBoard();
	initializeBoard();
	colorBoard();
}

void ChessBoard::createBoard(){
	for(int i=0; i<BOARD_DIMENSION; ++i){
		std::vector<ChessSquare> boardRow;

		for(int j=0; j<BOARD_DIMENSION; ++j){
			ChessSquare square(i,j);
			boardRow.push_back(square);
		}

		board.push_back(boardRow);
	}
}

void ChessBoard::initializeBoard(){
	for(int i=0; i<BOARD_DIMENSION; ++i){
		for(int j=0; j<BOARD_DIMENSION; ++j){
			ChessPiece* piece = placePiece(i,j);
			board[i][j].setPiece(piece);
		}
	}
}

void ChessBoard::colorBoard(){
	Color currentColor = WHITE;

	for(int i=0; i<BOARD_DIMENSION; ++i){
		currentColor = reverseColor(currentColor);
		for(int j=0; j<BOARD_DIMENSION; ++j){
			currentColor = reverseColor(currentColor);
			board[i][j].setColor(currentColor);
		}
	}
}

ChessPiece* ChessBoard::placePiece(int row, int col){
	//pieces only get placed on the first, second, seventh, and eighth rows
	if(row != 0 && row != 1 && row != BOARD_DIMENSION - 2 && row != BOARD_DIMENSION - 1) return NULL;

	Color pieceColor = determinePieceColor(row, col);
	PieceType pieceType = determinePieceType(row, col);
	ChessPiece* pieceToPlace = pieceFactory(pieceColor, pieceType);

	return pieceToPlace;
}

ChessPiece* ChessBoard::pieceFactory(Color pieceColor, PieceType pieceType){
	switch(pieceType){
		case PAWN: return new Pawn(pieceColor);
		case KNIGHT: return new Knight(pieceColor);
		case BISHOP: return new Bishop(pieceColor);
		case ROOK: return new Rook(pieceColor);
		case QUEEN: return new Queen(pieceColor);
		case KING: return new King(pieceColor);
	}

	return NULL;
}

Color ChessBoard::determinePieceColor(int row, int col){
	Color pieceColor;
	(row == 0 || row == 1) ? pieceColor = reverseColor(playerColor) : pieceColor = playerColor;

	return playerColor;
}

PieceType ChessBoard::determinePieceType(int row, int col){
	PieceType pieceType;

	if(row == 1 || row == BOARD_DIMENSION - 2) pieceType = PAWN;
	else if(col == 0 || col == BOARD_DIMENSION - 1) pieceType = ROOK;
	else if(col == 1 || col == BOARD_DIMENSION -2) pieceType = KNIGHT;
	else if(col == 2 || col == BOARD_DIMENSION - 3) pieceType = BISHOP;
	else{
		if(playerColor == WHITE){
			if(col == 3) pieceType = QUEEN;
			else pieceType = KING;
		}
		else{
			if(col == 3) pieceType = KING;
			else pieceType = QUEEN;
		}
	}

	return pieceType;
}

void ChessBoard::printBoard(){

	for(int i=0; i<BOARD_DIMENSION; ++i){
		printRow(i);
	}
}

void ChessBoard::printRow(int row){
	for(int i=0; i<CELL_HEIGHT; ++i){
		std::string outputRow = "";
		for(int j=0; j<BOARD_DIMENSION; ++j){
			outputRow += board[row][j].getOutputLine(i);
		}

		std::cout << outputRow << std::endl;
	}
}

Color ChessBoard::reverseColor(Color currentColor){
	if(currentColor == WHITE) return BLACK;
	else if(currentColor == BLACK) return WHITE;
	else if(currentColor == WHITE_SQUARE) return BLACK_SQUARE;
	else return WHITE_SQUARE;
}