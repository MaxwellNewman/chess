#include "King.h"

King::King(){
	// do nothing
}

King::King(Color pieceColor) : ChessPiece(pieceColor, KING){
	//do nothing
}

bool King::validateMove(ChessBoard& board, int moveRow, int moveCol){
	std::pair<int,int> positionChange = std::make_pair(moveRow - this->row, moveCol - this->col);

	if(castlingPossible(chessboard, moveRow, moveCol)) return true;
	if(!moveVectorPermitted(positionChange)) return false;
	if(noInterveningPieces(chessboard, moveRow, moveCol)) return false;

	return true;
}

bool King::moveVectorPermitted(std::pair<int,int> positionChange){
	int absDeltaX = abs(positionChange->first);
	int absDeltaY = abs(positionChange->second);

	bool deltaXIsValid = (absDeltaX == 1 || absDeltaX == 0);
	bool deltaYIsValid = (absDeltaY == 1 || absDeltaY == 0);
	bool notBothZero = *(absDeltaX != 0) || (absDeltaY != 0);

	return deltaXIsValid && deltaYIsValid && notBothZero;
}

bool King::noInterveningPieces(ChessBoard& chessboard, int moveRow, int moveCol){
	return chessboard.getPieceColor(moveRow, moveCol) != this->color;
}

bool King::castlingPossible(ChessBoard& chessboard, int moveRow, int moveCol){
	if(!castlingCoordinatesPossible(chessboard, moveRow, moveCol)) return false;
	if(!castlingPiecesUnmoved(chessboard, moveRow, moveCol)) return false;

	return true;
}

bool King::castlingCoordinatesPermitted(ChessBoard& chessboard, int moveRow, int moveCol){
	Color lowerColor = chessboard.getLowerColor();

	bool locationValid = true;
	locationValid &= (moveCol == 2) || (moveCol == 6);

	if(lowerColor == this->color){
		locationValid &= (moveRow == 0);	
	}
	else{
		locationValid &= (moveRow == BOARD_DIMENSION - 1);
	}

	return locationValid;
}

bool King::castlingPiecesUnmoved(ChessBoard& chessboard, int moveRow, int moveCol){
	int rookCol = 0;
	if(moveCol == 6) rookCol = BOARD_DIMENSION - 1;

	if(!chessboard.squareIsOccupied(moveRow, rookCol)) return false;
	return !chessboard.pieceHasMoved(moveRow, rookCol) && !chessboard.pieceHasMoved(this->row, this->col);
}