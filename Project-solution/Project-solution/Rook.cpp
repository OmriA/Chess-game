#include "Rook.h"

Rook::Rook(int color) : Tool(color, 'R', vector<int>(VERTICAL, HORIZONTAL)), _moved(false) {}

int Rook::isLegal(Board board, int turn, Location src, Location dst)
{
	int flag = 0;
	if (src.getCol() == dst.getCol())	//checking if the src and the dest are vertical.
	{
		_moves["vertical"](board, turn, src, dst);
	}
	else if (src.getRow() == dst.getRow())	//checking if the src and the dest are horizontal.
	{
		_moves["horizontal"](board, turn, src, dst);
	}
}