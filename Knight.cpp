#include "Knight.h"

Knight::Knight(){
	// do nothing
}

Knight::Knight(Color pieceColor) : ChessPiece(pieceColor, KNIGHT){
	//do nothing
}

bool Knight::validateMove(ChessBoard& board, int moveRow, int moveCol){
	std::pair<int, int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	if(!locationIsValid(board, positionChange)) return false;

	return board.getPieceColor(moveRow, moveCol) != this->color;
}

bool Knight::locationIsValid(ChessBoard& board, std::pair<int,int> positionChange){
	int absRowChange = abs(positionChange.first);
	int absColChange = abs(positionChange.second);

	std::cout << "abs row: " << absRowChange << "	abs col: " << absColChange << std::endl;

	bool locationValid = (absRowChange == 2 || absColChange == 2);
	std::cout << std::boolalpha << "locationValid: " << locationValid << std::endl;

	locationValid &= (absRowChange == 1 || absColChange == 1);
	std::cout << std::boolalpha << "locationValid: " << locationValid << std::endl;

	locationValid &= (absRowChange != absColChange);
	std::cout << std::boolalpha << "locationValid: " << locationValid << std::endl;


	return locationValid;
}