#include "Queen.h"

/**
Constractor for the queen.
Input:	color - the color of the tool.
Output:	None.
**/
Queen::Queen(int color) : Tool(color, 'Q') {}

/**
Checks if the queen can move from the source location to the destination location.
Input:	board - the board
		turn - whose turn
		src - the source location
		dst - the destination location
Output:	0 - valid move
		2 - invalid move, src hasn't turn's tool
		3 - invalid move, dst has turn's tool
		6 - invalid move, invalid tool's movement
		7 - invalid move, src and dst are the same.
**/
char Queen::isLegal(Board& board, int turn, Location src, Location dst)
{

}