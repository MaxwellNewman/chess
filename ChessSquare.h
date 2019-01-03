#include <string>

#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

class ChessSquare{
public:
	bool isOccupied();
	std::string getName();

private:
	const std::string name;
	int row;
	int col;
	bool occupied;
	ChessPiece* currentPiece;
}

#endif