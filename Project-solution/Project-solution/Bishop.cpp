#include "Bishop.h"

Bishop::Bishop(int color) : Tool(color, 'B') {}

char Bishop::isLegal(Board& board, int turn, Location src, Location dst)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if ((srcRow < dstRow && srcCol > dstCol) || (srcRow > dstRow && srcCol < dstCol)) //checking if y=x+b
		{
			flag = diagonalUp(board, turn, src, dst);
		}
		else if ((srcRow > dstRow && srcCol > dstCol) || (srcRow < dstRow && srcCol < dstCol)) //cheking if y=-x+b
		{
			// flag = diagonalDown(board, turn, src, dst);
		}
		else	//the move is not a diagonal.
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