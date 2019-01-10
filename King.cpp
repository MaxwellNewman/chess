#include "King.h"

King::King(){
	// do nothing
}

King::King(Color pieceColor) : ChessPiece(pieceColor, KING){
	//do nothing
}

bool King::validateMove(ChessBoard& chessboard, int moveRow, int moveCol){
	std::pair<int,int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	if(castlingPossible(chessboard, moveRow, moveCol) && noInterveningPieces(chessboard, moveRow, moveCol)){
		orderRookToCastle(chessboard, moveCol);
		return true;
	}
	if(!moveVectorPermitted(positionChange)) return false;
	if(noInterveningPieces(chessboard, moveRow, moveCol)) return false;

	return true;
}

void King::orderRookToCastle(ChessBoard& chessboard, int moveCol){
	int rookInitRow = this->row;
	int rookInitCol = 0;

	int rookDestRow = this->row;
	int rookDestCol = moveCol;

	std::cout << " pre rook dest col: " << rookDestCol << std::endl;

	if(moveCol < this->col) {
		++rookDestCol;
		rookInitCol = 0;
	}
	else{
		--rookDestCol;
		rookInitCol = BOARD_DIMENSION - 1;
	}

	std::pair<int,int> initialPosition = std::make_pair(rookInitRow, rookInitCol);
	std::pair<int,int> destinationPosition = std::make_pair(rookDestRow, rookDestCol);
	ChessMove move(initialPosition, destinationPosition, this->color);

	std::cout << "rook init col: " << initialPosition.second << std::endl;
	std::cout << "rook dest col: " << initialPosition.second << std::endl;

	chessboard.castleRook(move);
}

bool King::moveVectorPermitted(std::pair<int,int> positionChange){
	int absDeltaX = abs(positionChange.first);
	int absDeltaY = abs(positionChange.second);

	bool deltaXIsValid = (absDeltaX == 1 || absDeltaX == 0);
	bool deltaYIsValid = (absDeltaY == 1 || absDeltaY == 0);
	bool notBothZero = (absDeltaX != 0) || (absDeltaY != 0);

	return deltaXIsValid && deltaYIsValid && notBothZero;
}

bool King::noInterveningPieces(ChessBoard& chessboard, int moveRow, int moveCol){
	return chessboard.getPieceColor(moveRow, moveCol) != this->color;
}

bool King::castlingPossible(ChessBoard& chessboard, int moveRow, int moveCol){
	if(!castlingCoordinatesPermitted(chessboard, moveRow, moveCol)) return false;
	if(!castlingPiecesUnmoved(chessboard, moveRow, moveCol)) return false;

	return true;
}

bool King::castlingCoordinatesPermitted(ChessBoard& chessboard, int moveRow, int moveCol){
	Color lowerColor = chessboard.getLowerColor();
	bool locationValid = true;

	if(lowerColor == this->color){
		locationValid &= (moveRow == BOARD_DIMENSION - 1);	
		locationValid &= (moveCol == 1) || (moveCol == 6);
	}
	else{
		locationValid &= (moveRow == 0);
		locationValid &= (moveCol == 1) || (moveCol == BOARD_DIMENSION - 2);
	}

	return locationValid;
}

bool King::castlingPiecesUnmoved(ChessBoard& chessboard, int moveRow, int moveCol){
	int rookCol = 0;
	if(moveCol == 6) rookCol = BOARD_DIMENSION - 1;

	if(!chessboard.squareIsOccupied(moveRow, rookCol)) return false;
	return !chessboard.pieceHasMoved(moveRow, rookCol) && !chessboard.pieceHasMoved(this->row, this->col);
}