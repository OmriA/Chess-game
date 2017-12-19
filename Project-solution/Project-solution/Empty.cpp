#include "Empty.h"

/**
Constractor to the empty tool.
Input:	None.
Output:	None.
**/
Empty::Empty() : Tool(EMPTY, '#') {}

/**
return always 2 (invalid move, src hasn't turn's tool) because it is an empty tool.
Input:	board - the board
		turn - whose turn
		src - the source location
		dst - the destination location
Output:	always 2 (invalid move, src hasn't turn's tool) because it is an empty tool.
**/
char Empty::isLegal(Board& board, int turn, Location src, Location dest)
{
	return SRC_HAS_NO_TURNS_TOOL;
}