#ifndef ENUMS_H
#define ENUMS_H

#include <iostream>

std::string WHITE_SQUARE_UNI = "█";
std::string BLACK_SQUARE_UNI = " ";

enum Color{
	WHITE,
	BLACK,
	INVALID_COLOR,
	WHITE_SQUARE_CHAR = 0xDB,
	BLACK_SQUARE_CHAR = 0xFF,
};

enum PieceType{
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
	INVALID_PIECE,
};

enum Sizes{
	CELL_LENGTH = 5,
	CELL_HEIGHT = 3,
	BOARD_DIMENSION = 8,
};

#endif