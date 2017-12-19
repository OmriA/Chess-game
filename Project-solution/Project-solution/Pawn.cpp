#include "Pawn.h"

/**
Constractor for the knight.
Input:	color - the color of the tool.
Output:	None.
**/
Pawn::Pawn(int color) : Tool(color, 'P'), _moved(false)
{
	
}

/**
Checks if the knight can move from the source location to the destination location.
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
char Pawn::isLegal(Board& board, int turn, Location src, Location dst)
{
	if (src.getCol() == dst.getCol())
	{

	}
	if (!_moved)
	{

	}
}