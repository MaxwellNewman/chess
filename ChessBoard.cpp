#include "ChessBoard.h"

const std::vector<std::pair<int,int> > ChessBoard::directionVectors = {std::make_pair(1,1), std::make_pair(-1,1), std::make_pair(1,-1), std::make_pair(-1,-1),
	std::make_pair(1,0), std::make_pair(-1,0), std::make_pair(0,1), std::make_pair(0,-1)};

ChessBoard::ChessBoard(Color lowerColor, bool useUnicode){
	this->lowerColor = lowerColor;
	createBoard();
	initializeBoard();
	colorBoard(useUnicode);
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
			storePiecePointer(piece);
		}
	}
}

void ChessBoard::storePiecePointer(ChessPiece* piece){
	if(!piece) return;

	pieces.push_back(piece);

	if(piece->getType() == KING){
		if(piece->getColor() == BLACK) blackKing = piece;
		else whiteKing = piece;
	}
	else if(piece->getType() == KNIGHT){
		if(piece->getColor() == BLACK) blackKnights.push_back(piece);
		else whiteKnights.push_back(piece);
	}
}

void ChessBoard::colorBoard(bool useUnicode){
	Color currentColor = WHITE;

	for(int i=0; i<BOARD_DIMENSION; ++i){
		currentColor = reverseColor(currentColor);
		for(int j=0; j<BOARD_DIMENSION; ++j){
			currentColor = reverseColor(currentColor);
			board[i][j].setColor(currentColor, useUnicode);
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

	return pieceColor;
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
	for(int i=0; i<BOARD_DIMENSION; ++i){
		printRow(i);
	}

	std::cout << std::endl << algebraicColumns() << std::endl;
}

void ChessBoard::printRow(int row){
	for(int i=0; i<CELL_HEIGHT; ++i){
		std::string outputRow = "";
		for(int j=0; j<BOARD_DIMENSION; ++j){
			outputRow += board[row][j].getOutputLine(i);
		}

		if(i == CELL_HEIGHT/2) {
			outputRow += "	" + currentAlgebraicRow(row);
		}

		std::cout << outputRow << std::endl;
	}
}

std::string ChessBoard::algebraicColumns(){
	std::string algebraicColumns = "";
	for(int i=0; i<BOARD_DIMENSION; ++i){
		for(int j=0; j<CELL_LENGTH; ++j){
			if(j == CELL_LENGTH/2) algebraicColumns += currentAlgebraicColumn(i);
			else algebraicColumns += ' ';
		}
	}
	return algebraicColumns;
}

char ChessBoard::currentAlgebraicColumn(int col){
	if(this->lowerColor == BLACK) return char('H' - col);
	else return char('A' + col);
}

std::string ChessBoard::currentAlgebraicRow(int row){
	if(this->lowerColor == BLACK) return std::to_string(row+1);
	else return std::to_string(8-row);
}

Color ChessBoard::reverseColor(Color currentColor){
	if(currentColor == WHITE) return BLACK;
	else if(currentColor == BLACK) return WHITE;
	else if(currentColor == WHITE_SQUARE_CHAR) return BLACK_SQUARE_CHAR;
	else return WHITE_SQUARE_CHAR;
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

	bool knightsCanAttack = false;

	std::vector<ChessPiece*>* knightsVec = &blackKnights;
	if(defenderColor == BLACK) knightsVec = &whiteKnights;

	for(unsigned int i=0; i<knightsVec->size(); ++i){

		ChessPiece* knight = (*knightsVec)[i];

		if(!knight->isAlive()) return false;

		std::pair<int,int> attackerPos = knight->getLocation();

		knightsCanAttack = pieceCanAttack(attackerPos, defenderPos);
		if(knightsCanAttack) return true;
	}

	return knightsCanAttack;
}

bool ChessBoard::checkForCheckmate(ChessPiece* kingToCheck){
	std::pair<int,int> kingPos = kingToCheck->getLocation();

	for(int i=0; i<directionVectors.size(); ++i){
		int defenderRow = kingPos.first + directionVectors[i].first;
		int defenderCol = kingPos.second + directionVectors[i].second;

		std::pair<int,int> defenderPos = std::make_pair(defenderRow, defenderCol);
		ChessPiece* defender = takePiece(kingPos, defenderPos);

		if(defender == NULL) continue;

		bool kingSafe = false;
		kingSafe |= !kingToCheck->isInDanger(*this);

		board[defenderRow][defenderCol].replacePiece(defender);
		board[kingPos.first][kingPos.second].replacePiece(kingToCheck);

		if(kingSafe) return false;
	}

	return true;
}

std::vector<std::pair<int,int> > ChessBoard::getDirectionVectors(){
	return this->directionVectors;
}

ChessPiece* ChessBoard::takePiece(std::pair<int,int>& attackerPos, std::pair<int,int>& defenderPos){
	if(pieceCanAttack(attackerPos, defenderPos)){
		ChessPiece* attacker = board[attackerPos.first][attackerPos.second].piece;
		ChessPiece* defender = board[defenderPos.first][defenderPos.second].replacePiece(attacker);
		board[attackerPos.first][attackerPos.second].replacePiece(NULL);
		return defender;
	}else{
		return NULL;
	}
}

bool ChessBoard::makeMove(ChessMove& move){
	ChessPiece* movingPiece = board[move.attackerPos.first][move.attackerPos.second].piece;
	if(!movingPiece) return false;
	if(movingPiece->getColor() != move.movingPlayer) return false;

	bool attackingPieceSucceeded = takePiece(move.attackerPos, move.defenderPos);

	std::cout << "in danger: " << movingPiece->isInDanger(*this) << std::endl;

	return attackingPieceSucceeded;
}

bool ChessBoard::castleRook(ChessMove& move){
	ChessPiece* rook = board[move.attackerPos.first][move.attackerPos.second].piece;

	board[move.defenderPos.first][move.defenderPos.second].replacePiece(rook);
	board[move.attackerPos.first][move.attackerPos.second].replacePiece(NULL);
	return true;
}