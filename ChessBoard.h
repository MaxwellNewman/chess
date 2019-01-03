#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

class ChessBoard{
public:
	ChessBoard(Color playerColor);
	void initializeBoard();
	void createBoard();
	void placePiece(int i, int j);

private:
	enum Color{
		WHITE,
		BLACK,
	};

	std::vector<std::vector<ChessSquare> > board;
	int sideLength;
	Color playerColor;
};

#endif