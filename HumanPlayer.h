#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <string>
#include <algorithm>
#include <iostream>
#include <locale>
#include "ChessMove.h"
#include "ChessPlayer.h"

class HumanPlayer : public ChessPlayer{
public:
	HumanPlayer(Color playerColor);
	ChessMove selectMove();

private:
	static const char charsToRemove[];

	std::pair<int,int> getCoordinates(std::string& messagePrompt);
	void removeExtraCharacters(std::string& positionString);
	void removeCharFromString(std::string& str, char toRemove);

	std::pair<int,int> extractPosition(std::string& positionString);
	bool isValidPosition(std::string& initialPosition);
};

#endif