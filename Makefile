
O_FILES_DIR = oFiles/
BINDIR = ./
PIECES_DIR = Pieces/
CPP_FLAGS = g++ -g -Wall -std=c++11

all: main

main:  main.cpp ChessBoard.o ChessSquare.o ChessMove.o ChessPiece.o Pawn.o Knight.o Bishop.o Rook.o Queen.o King.o ChessGame.o ChessPlayer.o HumanPlayer.o
	$(CPP_FLAGS) main.cpp *.o -o main

# ChessBoard.o: ChessBoard.cpp ChessBoard.h
# 	$(CPP_FLAGS) ChessBoard.

%.o: %.cpp
	$(CPP_FLAGS) $^ -c -o $@

.PHONY: clean

clean: 
	rm -f *.o