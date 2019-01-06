#include <unordered_map>

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

class ChessGame{
public:
	void playGame();

private:
	ChessBoard chessboard;
	ChessPlayer* currPlayer;
	ChessPlayer* whitePlayer;
	ChessPlayer* blackPlayer;

	ChessMove& getPlayerMove();
	void swapPlayer();
}

#endif