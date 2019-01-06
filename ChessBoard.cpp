#include "ChessBoard.h"

const std::vector<std::pair<int,int> > ChessBoard::directionVectors = {std::make_pair(1,1), std::make_pair(-1,1), std::make_pair(1,-1), std::make_pair(-1,-1),
	std::make_pair(1,0), std::make_pair(-1,0), std::make_pair(0,1), std::make_pair(0,-1)};

ChessBoard::ChessBoard(Color lowerColor){
	std::cout << "Entering constructor" << std::endl;
	this->lowerColor = lowerColor;
	createBoard();
	initializeBoard();
	colorBoard();

	std::cout << "leaving construtor" << std::endl;
}

void ChessBoard::createBoard(){
	for(int i=0; i<BOARD_DIMENSION; ++i){
		std::vector<ChessSquare> boardRow;

		for(int j=0; j<BOARD_DIMENSION; ++j){
			ChessSquare square(i,j);
			boardRow.push_back(square);
		}

		board.push_back(boardRow);
	}
}

void ChessBoard::initializeBoard(){
	for(int i=0; i<BOARD_DIMENSION; ++i){
		for(int j=0; j<BOARD_DIMENSION; ++j){
			ChessPiece* piece = placePiece(i,j);
			board[i][j].setPiece(piece);
		}
	}
}

void ChessBoard::colorBoard(){
	Color currentColor = WHITE;

	for(int i=0; i<BOARD_DIMENSION; ++i){
		currentColor = reverseColor(currentColor);
		for(int j=0; j<BOARD_DIMENSION; ++j){
			currentColor = reverseColor(currentColor);
			board[i][j].setColor(currentColor);
		}
	}
}

ChessPiece* ChessBoard::placePiece(int row, int col){
	//pieces only get placed on the first, second, seventh, and eighth rows
	if(row != 0 && row != 1 && row != BOARD_DIMENSION - 2 && row != BOARD_DIMENSION - 1) return NULL;

	Color pieceColor = determinePieceColor(row, col);
	PieceType pieceType = determinePieceType(row, col);
	ChessPiece* pieceToPlace = pieceFactory(pieceColor, pieceType);
	pieceToPlace->setLocation(row, col);

	return pieceToPlace;
}

ChessPiece* ChessBoard::pieceFactory(Color pieceColor, PieceType pieceType){
	switch(pieceType){
		case PAWN: return new Pawn(pieceColor);
		case KNIGHT: return new Knight(pieceColor);
		case BISHOP: return new Bishop(pieceColor);
		case ROOK: return new Rook(pieceColor);
		case QUEEN: return new Queen(pieceColor);
		case KING: return new King(pieceColor);
		case INVALID_PIECE: return NULL;
	}

	return NULL;
}

Color ChessBoard::determinePieceColor(int row, int col){
	Color pieceColor;
	(row == 0 || row == 1) ? pieceColor = reverseColor(lowerColor) : pieceColor = lowerColor;

	return lowerColor;
}

PieceType ChessBoard::determinePieceType(int row, int col){
	PieceType pieceType;

	if(row == 1 || row == BOARD_DIMENSION - 2) pieceType = PAWN;
	else if(col == 0 || col == BOARD_DIMENSION - 1) pieceType = ROOK;
	else if(col == 1 || col == BOARD_DIMENSION -2) pieceType = KNIGHT;
	else if(col == 2 || col == BOARD_DIMENSION - 3) pieceType = BISHOP;
	else{
		if(lowerColor == WHITE){
			if(col == 3) pieceType = QUEEN;
			else pieceType = KING;
		}
		else{
			if(col == 3) pieceType = KING;
			else pieceType = QUEEN;
		}
	}

	return pieceType;
}

void ChessBoard::printBoard(){
	std::cout << "in fun" << std::endl;

	for(int i=0; i<BOARD_DIMENSION; ++i){
		printRow(i);
	}

	std::cout << "end of func " << std::endl;
}

void ChessBoard::printRow(int row){
	for(int i=0; i<CELL_HEIGHT; ++i){
		std::string outputRow = "";
		for(int j=0; j<BOARD_DIMENSION; ++j){
			outputRow += board[row][j].getOutputLine(i);
		}

		std::cout << outputRow << std::endl;
	}
}

Color ChessBoard::reverseColor(Color currentColor){
	if(currentColor == WHITE) return BLACK;
	else if(currentColor == BLACK) return WHITE;
	else if(currentColor == WHITE_SQUARE) return BLACK_SQUARE;
	else return WHITE_SQUARE;
}

Color ChessBoard::getPieceColor(int row, int col){
	if(coordinatesOffBoard(row,col)) return INVALID_COLOR;
	if(!squareIsOccupied(row,col)) return INVALID_COLOR;

	return board[row][col].piece->getColor();
}

bool ChessBoard::squareIsOccupied(int row, int col){
	if(coordinatesOffBoard(row,col)) return false;

	return board[row][col].isOccupied();
}

bool ChessBoard::coordinatesOffBoard(int row, int col){
	bool rowOffBoard = row < 0 || row >= BOARD_DIMENSION;
	bool colOffBoard = col < 0 || col >= BOARD_DIMENSION;

	return rowOffBoard || colOffBoard;
}

PieceType ChessBoard::getPieceType(int row, int col){
	if(coordinatesOffBoard(row,col)) return INVALID_PIECE;

	return board[row][col].piece->getType();
}

Color ChessBoard::getLowerColor(){
	return this->lowerColor;
}

bool ChessBoard::lastMoved(int row, int col){
	ChessPiece* pieceOnSquare = board[row][col].piece;
	return pieceOnSquare == lastMovedPiece;
}

bool ChessBoard::pieceHasMoved(int row, int col){
	ChessPiece* pieceOnSquare = board[row][col].piece;
	return pieceOnSquare->getHasMoved();
}

bool ChessBoard::pieceCanAttack(std::pair<int,int>& attackerPos, std::pair<int,int>& defenderPos){
	ChessPiece* attacker = board[attackerPos.first][attackerPos.second].piece;

	return attacker->validateMove(*this, defenderPos.first, defenderPos.second);
}

bool ChessBoard::knightsCanAttack(std::pair<int,int>& defenderPos, Color defenderColor){
	std::vector<ChessPiece*>& knightsVec = blackKnights;

	if(defenderColor == BLACK) knightsVec = whiteKnights;

	for(unsigned int i=0; i<knightsVec.size(); ++i){
		if(!knightsVec[i]->isAlive()) return false;

		std::pair<int,int> attackerPos = knightsVec[i]->getLocation();

		return pieceCanAttack(attackerPos, defenderPos);
	}

	return false;
}

bool ChessBoard::checkForCheckmate(ChessPiece* kingToCheck){

	return false;
}

std::vector<std::pair<int,int> > ChessBoard::getDirectionVectors(){
	return this->directionVectors;
}

bool ChessBoard::takePiece(std::pair<int,int>& attackerPos, std::pair<int,int>& defenderPos){
	if(pieceCanAttack(attackerPos, defenderPos)){
		ChessPiece* attacker = board[attackerPos.first][attackerPos.second].piece;
		board[defenderPos.first][defenderPos.second].replacePiece(attacker);
		return true;
	}else{
		return false;
	}
}

bool ChessBoard::makeMove(ChessMove& move){
	return takePiece(move.attackerPos, move.defenderPos);
}