"# chess" 

This is a program designed to run in Windows.  The chessboard will not output properly on Unix-based or Mac OSX systems.
To properly display the unicode chess pieces, use the NSimSun font on Windows.

To Do: 
1. implement algebraic notation for chess
	a. letters go from white's left to white's right, starting from a and ending at h
	b. numbers start from white and end at black, starting from 1 and ending at 8

2. finish implementing a checker for checkmates

3. implement a system that colors the pieces. This can be accomplished using windows commands.

3. finish implementing a checker for stalemates

4. implement the rule stating that a king cannot castle through a check (should be a simple fix, involving checking if a king would be in danger at any point between himself and the destined position when castling)

5. implement the rule that a pawn can transform into another piece when reaching the back row (might just automatically turn it into a queen for now, instead of given the player an option)

6. implement the rule stating that a repeated move three times results in a stalemate