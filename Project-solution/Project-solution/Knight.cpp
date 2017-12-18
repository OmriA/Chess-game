#include "Knight.h"

Knight::Knight(int color) : Tool(color, 'N') {}

char Knight::isLegal(Board& board, int turn, Location src, Location dst)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if (abs(Location(srcRow, srcCol + 1) - dst) == 2 && (srcRow != dstRow || srcCol != dstCol))
		{
			flag = knightMove(board, turn, src, dst);
		}
		else if (abs(Location(srcRow, srcCol + 2) - dst) == 1 && (srcRow != dstRow || srcCol != dstCol))
		{
			flag = knightMove(board, turn, src, dst);
		}
		else if (abs(Location(srcRow, srcCol - 1) - dst) == 2 && (srcRow != dstRow || srcCol != dstCol))
		{
			flag = knightMove(board, turn, src, dst);
		}
		else if (abs(Location(srcRow, srcCol - 2) - dst) == 1 && (srcRow != dstRow || srcCol != dstCol))
		{
			flag = knightMove(board, turn, src, dst);
		}
		else
		{
			return INVALID_MOVE;
		}
	}
	else
	{
		return SRC_HAS_NO_TURNS_TOOL;
	}

	if (flag == VALID_CHECK || flag == VALID_MOVE)
	{
		move(board, src, dst);
	}

	return flag;
}