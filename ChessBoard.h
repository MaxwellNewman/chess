#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>

#include "Enums.h"
#include "ChessSquare.h"
#include "Pieces/Pawn.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Rook.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"

class ChessBoard{
public:
	ChessBoard(Color playerColor);
	void printBoard();

private:
	std::vector<std::vector<ChessSquare> > board;
	Color playerColor;

	void initializeBoard();
	void createBoard();
	ChessPiece* placePiece(int i, int j);
	PieceType determinePieceType(int row, int col);
	Color determinePieceColor(int row, int col);
	void colorBoard();
	void printRow(int row);
	Color reverseColor(Color currentColor);
	ChessPiece* pieceFactory(Color pieceColor, PieceType pieceType);
};

#endif