#include <iostream>
#include "ChessBoard.h"

int main(){
	Color playerColor = BLACK;
	ChessBoard board(playerColor);

	board.printBoard();
}