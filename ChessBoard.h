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
#include "ChessMove.h"

class ChessBoard{
public:
	ChessBoard(Color playerColor);
	void printBoard();
	Color getPieceColor(int row, int col);
	bool squareIsOccupied(int row, int col);
	PieceType getPieceType(int row, int col);
	Color getLowerColor();
	bool lastMoved(int row, int col);
	bool pieceHasMoved(int row, int col);

private:
	std::vector<std::vector<ChessSquare> > board;
	Color lowerColor;
	ChessPiece* lastMovedPiece;

	Color reverseColor(Color currentColor);
	ChessPiece* pieceFactory(Color pieceColor, PieceType pieceType);
	ChessPiece* placePiece(int i, int j);
	PieceType determinePieceType(int row, int col);
	Color determinePieceColor(int row, int col);
	void initializeBoard();
	void createBoard();
	void colorBoard();
	void printRow(int row);
	bool coordinatesOffBoard(int row, int col);
	bool checkForCheckmate();
};

#endif