#include "Bishop.h"

/**
Constractor to the bishop.
Input:	color - the color of the tool.
Output:	None.
**/
Bishop::Bishop(int color) : Tool(color, 'B') {}

/**
Checks if the bishop can move from the source location to the destination location.
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
char Bishop::isLegal(Board& board, int turn, Location src, Location dst)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if (abs(srcRow - dstRow) == abs(srcCol - dstCol))	//if the move is diagonal
		{
			if ((srcRow < dstRow && srcCol > dstCol) || (srcRow > dstRow && srcCol < dstCol)) //checking if y=x+b
			{
				flag = diagonalUp(board, turn, src, dst);
			}
			else if ((srcRow > dstRow && srcCol > dstCol) || (srcRow < dstRow && srcCol < dstCol)) //cheking if y=-x+b
			{
				flag = diagonalDown(board, turn, src, dst);
			}
			else	//the move is not a bishop move.
			{
				return INVALID_MOVE;
			}
		}
		else	//the move is not a bishop move.
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
	}

	return flag;
}