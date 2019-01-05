
#include <string>
#include <algorithm>
#include <iostream>
#include <locale>
#include "ChessMove.h"

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

class HumanPlayer : public ChessPlayer{
public:
	HumanPlayer();
	ChessMove selectMove();

private:
	static const char[] charsToRemove = ",:-.; ";
	static const int charsToRemoveSize = 6;

	std::pair<int,int> getCoordinates(std::string& messagePrompt)
	void removeExtraCharacters(std::string& initialPosition);
	void removeCharFromString(std::string& str, char toRemove);

	std::pair<int,int> HumanPlayer::extractPosition(std::string positionString)
};

#endif