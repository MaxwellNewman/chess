#include "ChessPiece.h"

ChessPiece::ChessPiece(ChessBoard& board, int row, int col){
	this->board = board;
	this->location.row = row;
	this->location.col = col;
}