
#include "ChessGame.h"

ChessGame::ChessGame(Color lowerColor){
	chessboard = new ChessBoard(lowerColor, true);
	whitePlayer = new HumanPlayer(WHITE);
	blackPlayer = new HumanPlayer(BLACK);

	currPlayer = whitePlayer;
}

void ChessGame::playGame(){
	while(true){
		chessboard->printBoard();
		ChessMove move = getPlayerMove();

		translateFromAlgebraicToBoardCoordinates(move);

		if(chessboard->makeMove(move)) swapPlayer();
		else std::cout << "The move you input was invalid. Please try again" << std::endl;
	}
}

ChessMove ChessGame::getPlayerMove(){
	ChessMove move = currPlayer->selectMove();
	return move;
}

void ChessGame::swapPlayer(){
	std::cout << "swapping" << std::endl;
	if(currPlayer == blackPlayer) currPlayer = whitePlayer;
	else currPlayer = blackPlayer;
}

void ChessGame::translateFromAlgebraicToBoardCoordinates(ChessMove& move){
	std::cout << move.attackerPos.first << std::endl;
	std::cout << move.attackerPos.second << std::endl;


	if(chessboard->getLowerColor() == BLACK){
		move.attackerPos.second = BOARD_DIMENSION - move.attackerPos.second - 1;
		move.defenderPos.second = BOARD_DIMENSION - move.defenderPos.second - 1;
	}
	else{
		move.attackerPos.first = 7 - move.attackerPos.first;
		move.defenderPos.first = 7 - move.defenderPos.first;
	}

	std::cout << move.attackerPos.first << std::endl;
	std::cout << move.attackerPos.second << std::endl;

	std::cout << move.defenderPos.first << std::endl;
	std::cout << move.defenderPos.second << std::endl;
}