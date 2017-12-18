#include "Rook.h"

Rook::Rook(int color) : Tool(color, 'R'), _moved(false) {}

char Rook::isLegal(Board& board, int turn, Location src, Location dst)
{
	int flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (srcCol == dstCol)	//checking if the src and the dest are vertical.
	{
		flag = vertical(board, turn, src, dst);
	}
	else if (srcRow == dstRow)	//checking if the src and the dest are horizontal.
	{
		flag = horizontal(board, turn, src, dst);
	}
	else	//the move is not vertical or horizontal.
	{
		return INVALID_MOVE;
	}

	if (flag == VALID_CHECK || flag == VALID_MOVE)
	{
		move(board, src, dst);
	}

	return flag;
}