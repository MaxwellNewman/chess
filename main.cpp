#include <iostream>
#include "ChessBoard.h"

int main(){
	std::cerr << "I am in main here " << std::endl;
	std::cout << "now here " << std::endl;
	Color playerColor = BLACK;

	ChessBoard board(playerColor);

	board.printBoard();

	std::cout << "here" << std::endl;
}