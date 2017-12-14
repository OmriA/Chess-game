#include "Empty.h"

/**
Constractor to the empty tool.
Input:	None.
Output:	None.
**/
Empty::Empty() : Tool(-1, '#') {}

bool Empty::isLegal(Location src, Location dest)
{
	return false;
}