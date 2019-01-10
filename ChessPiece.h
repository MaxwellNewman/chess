#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <vector>
#include <string>
#include <iostream>

#include "Enums.h"

class ChessBoard;

class ChessPiece{
public:
	ChessPiece();
	ChessPiece(Color pieceColor, PieceType type);
	bool getHasMoved();
	char getSymbol();
	Color getColor();
	PieceType getType();
	void setLocation(int row, int col);
	std::pair<int,int> getLocation();
	bool isAlive();
	virtual bool validateMove(ChessBoard& board, int moveRow, int moveCol) = 0;
	virtual bool isInDanger(ChessBoard& chessboard);

protected:
	Color color;
	PieceType type;
	bool hasMoved;
	char symbol;
	int row;
	int col;
	bool alive;

	void setSymbol();
	virtual bool noInterveningPieces(ChessBoard& chessboard, std::pair<int,int>& moveUnitVector, int moveMagnitude);
	bool isInDangerFromDirection(ChessBoard& chessboard, std::pair<int,int>& directionVector);
};

#include "ChessBoard.h"

#endif