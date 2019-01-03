#ifndef ENUMS_H
#define ENUMS_H

enum Color{
	WHITE,
	BLACK,
	WHITE_SQUARE = 0xDB,
	BLACK_SQUARE = 0xFF,
};

enum PieceType{
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING,
};

enum Sizes{
	CELL_LENGTH = 5,
	CELL_HEIGHT = 3,
	BOARD_DIMENSION = 8,
};

#endif