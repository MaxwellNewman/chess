#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include <unordered_map>
#include "ChessPlayer.h"
#include "ChessBoard.h"
#include "HumanPlayer.h"

class ChessGame{
public:
	ChessGame(Color playerColor);
	void playGame();

private:
	ChessBoard* chessboard;
	ChessPlayer* currPlayer;
	ChessPlayer* whitePlayer;
	ChessPlayer* blackPlayer;

	ChessMove getPlayerMove();
	void swapPlayer();
	void translateFromAlgebraicToBoardCoordinates(ChessMove& move);
};

#endif