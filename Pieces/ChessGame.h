#include <unordered_map>

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

class ChessGame{
public:

private:
	ChessBoard chessboard;
	ChessPlayer* whitePlayer;
	ChessPlayer* blackPlayer;
	std::vector<ChessPiece*> pieces;
	std::vector<ChessPiece*> blackPieces;
	std::vector<ChessPiece*> whitePieces;

	bool checkForCheckmate();

}

#endif