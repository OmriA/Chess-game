#include "Rook.h"

/**
Constractor to the rook.
Input:	color - the color of the tool.
Output:	None.
**/
Rook::Rook(int color) : Tool(color, 'R'), _moved(false) {}

/**
Checks if the rook can move from the source location to the destination location.
Input:	board - the board
		turn - whose turn
		src - the source location
		dst - the destination location
Output:	0 - valid move
		2 - invalid move, src hasn't turn's tool
		3 - invalid move, dst has turn's tool
		6 - invalid move, invalid tool's movement
		7 - invalid move, src and dst are the same.
**/
char Rook::isLegal(Board& board, int turn, Location src, Location dst)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
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
	}
	else	//not color's turn
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