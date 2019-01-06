#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>
#include <unordered_map>

#include "Enums.h"
#include "ChessPiece.h"
#include "ChessSquare.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "ChessMove.h"

class ChessPiece;
class ChessSquare;

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
	std::vector<std::pair<int,int> > getDirectionVectors();
	bool makeMove(ChessMove move);
	bool pieceCanAttack(std::pair<int,int>& attackerPos, std::pair<int,int>& defenderPos);
	bool knightsCanAttack(std::pair<int,int>& defenderPos, Color defenderColor);
	bool makeMove(ChessMove& move);
	bool coordinatesOffBoard(int row, int col);

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
	bool checkForCheckmate(ChessPiece* kingToCheck);
	bool takePiece(std::pair<int,int>& attackerPos, std::pair<int,int>& defenderPos);
};

#endif