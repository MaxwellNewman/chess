#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>
#include <unordered_map>

#include "Enums.h"
#include "ChessSquare.h"
#include "Pieces/Pawn.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Rook.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"
#include "Pieces/ChessPiece.h"
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
	std::vector<std::pair<int,int> >& getDirectionVectors();
	bool makeMove(ChessMove move);

private:
	std::vector<std::vector<ChessSquare> > board;
	Color lowerColor;
	ChessPiece* lastMovedPiece;

	std::vector<ChessPiece*> pieces;
	std::vector<ChessPiece*> blackPieces;
	std::vector<ChessPiece*> whitePieces;
	std::vector<ChessPiece*> blackKnights;
	std::vector<ChessPiece*> whiteKnights;
	ChessPiece* whiteKing;
	ChessPiece* blackKing;

	static const std::vector<std::pair<int,int> > directionVectors;
	

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