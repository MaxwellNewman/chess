#ifndef ENUMS_H
#define ENUMS_H

enum Color{
	WHITE,
	BLACK,
	INVALID_COLOR,
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
	INVALID_PIECE,
};

enum Sizes{
	CELL_LENGTH = 5,
	CELL_HEIGHT = 3,
	BOARD_DIMENSION = 8,
};

#endif