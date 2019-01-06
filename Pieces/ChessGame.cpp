
#include "ChessGame.h"

void ChessGame::playGame(){

	while(true){
		ChessMove move = getPlayerMove();
		if(chessboard.makeMove(move)) swapPlayer();
		chessboard.printBoard();
	}
}

ChessMove& ChessGame::getPlayerMove(){
	ChessMove move = currPlayer->selectMove();
	return move;
}

void ChessGame::swapPlayer(){
	if(currPlayer == blackPlayer) currPlayer = whitePlayer;
	else currPlayer = blackPlayer;
}