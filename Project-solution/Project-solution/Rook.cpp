#include "Rook.h"

Rook::Rook(int color) : Tool(color, 'R', vector<int>(VERTICAL, HORIZONTAL)), _moved(false) {}

int Rook::isLegal(Board board, int turn, Location src, Location dst)
{
	if (src.getCol() == dst.getCol())	//checking if the src and the dest are vertical.
	{
		
	}
}