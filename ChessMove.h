
#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

class ChessMove{
public:
	ChessMove(std::pair<int,int> init, std::pair<int,int> dest);

	std::pair<int,int> initialPosition;
	std::pair<int,int> destinationPosition;
private:

}

#endif