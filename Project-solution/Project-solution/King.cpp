#include "King.h"

/**
Constractor to the king.
Input:	color - the color of the tool.
Output:	None.
**/
King::King(int color) : Tool(color, 'K'), _moved(false) {}

char King::isLegal(Board& board, int turn, Location src, Location dst)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if (abs(dstRow - srcRow) == 1 && srcCol == dstCol)	//checking if the src and the dest are vertical and the move is a single move.
		{
			flag = vertical(board, turn, src, dst);
		}
		else if (abs(dstCol - srcCol) == 1 && srcRow == dstRow)	//checking if the src and the dest are horizontal and the move is a single move.
		{
			flag = horizontal(board, turn, src, dst);
		}
		else if (abs(src - dst) == 0)	//checking if y=x+b
		{
			if ((srcRow < dstRow && srcCol > dstCol) || (srcRow > dstRow && srcCol < dstCol))
			{
				flag = diagonalUp(board, turn, src, dst);
			}
			else
			{
				return INVALID_MOVE;
			}
		}
		else if (abs(src - dst) == 2)	//checking if y=-x+b
		{
			if ((srcRow > dstRow && srcCol > dstCol) || (srcRow < dstRow && srcCol < dstCol))	//cheking if y=-x+b
			{
				flag = diagonalDown(board, turn, src, dst);
			}
			else
			{
				return INVALID_MOVE;
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