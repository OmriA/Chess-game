#include "Empty.h"

/**
Constractor to the empty tool.
Input:	None.
Output:	None.
**/
Empty::Empty() : Tool(-1, '#') {}

int Empty::isLegal(Location src, Location dest)
{
	return SRC_HAS_NO_TURNS_TOOL;
}