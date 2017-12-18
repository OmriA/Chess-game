#include "King.h"

King::King(int color) : Tool(color, 'K'), _moved(false) {}

char King::isLegal(Board& board, int turn, Location src, Location dst)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if ((dstRow - srcRow == 1 || srcRow - dstRow == -1) && srcCol == dstCol)	//checking if the src and the dest are vertical and the move is a single move.
		{
			flag = vertical(board, turn, src, dst);
		}
		else if ((dstCol - srcCol == 1 || srcCol - dstCol == -1) && srcRow == dstRow)	//checking if the src and the dest are horizontal and the move is a single move.
		{
			flag = horizontal(board, turn, src, dst);
		}
		else if (abs(dst - src == 2))
		{
			if ((srcCol > dstCol && srcRow < srcRow) || (srcCol < dstCol && srcRow < srcRow))	//checking if y=x
			{

			}
			else	//cheking if y=-x
			{

			}
		}
		else	//the move isnt an available move for this tool.
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
		_moved = true;
	}

	return flag;
}