#include "Empty.h"

/**
Constractor to the empty tool.
Input:	None.
Output:	None.
**/
Empty::Empty() : Tool(EMPTY, '#', vector<int>()) {}

char Empty::isLegal(Board board, int turn, Location src, Location dest)
{
	return SRC_HAS_NO_TURNS_TOOL;
}