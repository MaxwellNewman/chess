
#include "HumanPlayer.h"

const char HumanPlayer::charsToRemove[] = ",:-.; ";

HumanPlayer::HumanPlayer(){

}

ChessMove HumanPlayer::selectMove(){
	std::string initialPositionMessage = "Select the piece you would like to move by its starting coordinates.  Use the format RC (Row Letter, Column Number)";
	std::string destinationPositionMessage = "Select the destination of your piece.  Use the format RC (Row letter, Column number).";

	std::pair<int,int> initialPosition = getCoordinates(initialPositionMessage);
	std::pair<int,int> destinationPosition = getCoordinates(destinationPositionMessage);

	return ChessMove(initialPosition, destinationPosition);
}

std::pair<int,int> HumanPlayer::getCoordinates(std::string& messagePrompt){
	bool positionValid = false;
	std::pair<int,int> position;

	while(!positionValid){
		std::cout << messagePrompt << std::endl;
		std::string positionString;
		std::cin >> positionString;

		this->removeExtraCharacters(positionString);
		positionValid = isValidPosition(positionString);

		if(positionValid){
			position = extractPosition(positionString);
		}
		else{
			std::cout << "The cell you entered was invalid.  Please try again.";
		}
	}

	return position;
}

void HumanPlayer::removeExtraCharacters(std::string& positionString){
	for(int i=0; i<6; ++i){
		char currChar = charsToRemove[i];
		removeCharFromString(positionString, currChar);
	}
}

// function that removes all instances of toRemove from the string str
void HumanPlayer::removeCharFromString(std::string& str, char toRemove){
	str.erase(std::remove(str.begin(), str.end(), toRemove), str.end());
}

bool HumanPlayer::isValidPosition(std::string& initialPosition){
	if(initialPosition.size() > 2) return false;

	bool firstIndexIsLetter = (initialPosition[0] <= 'H' && initialPosition[0] >= 'A');
	firstIndexIsLetter |= (initialPosition[0] <= 'h' || initialPosition[0] >= 'a');

	bool secondIndexIsNumber = (initialPosition[1] <= '9' && initialPosition[1] >= '0');

	return firstIndexIsLetter & secondIndexIsNumber;
}

std::pair<int,int> HumanPlayer::extractPosition(std::string positionString){
	positionString[0] = std::tolower(positionString[0]);

	int row = positionString[0] - 'a';
	int col = positionString[1] - '0';

	return std::make_pair(row,col);
}