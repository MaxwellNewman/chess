#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <vector>
#include <string>
#include <iostream>

#include "../ChessBoard.h"
#include "../Enums.h"

class ChessPiece{
public:
	ChessPiece();
	ChessPiece(Color pieceColor, PieceType type);
	bool getHasMoved();
	char getSymbol();
	Color getColor();
	PieceType getType();
	void setLocation(int row, int col);
	virtual bool validateMove(ChessBoard& board, int moveRow, int moveCol) = 0;

protected:
	Color color;
	PieceType type;
	bool hasMoved;
	char symbol;
	int row;
	int col;

	void setSymbol();
	virtual bool noInterveningPieces(ChessBoard& chessboard, std::pair<int,int>& moveUnitVector, int moveMagnitude);
};

#endif