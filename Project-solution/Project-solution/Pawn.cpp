#include "Pawn.h"

/**
Constractor for the knight.
Input:	color - the color of the tool.
Output:	None.
**/
Pawn::Pawn(int color) : Tool(color, 'P'), _moved(false), _movingUp(true)
{
	if (color == BLACK)
	{
		_movingUp = false;
	}
}

/**
Checks if the knight can move from the source location to the destination location.
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
char Pawn::isLegal(Board& board, int turn, Location src, Location dst, bool test)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if (_movingUp)	//checking if the pawn is going up.
		{
			if (srcCol == dstCol && board.getIndex(dst)->getSign() == '#')	//checking if it is vertical and dst has no tool.
			{
				if (abs(src - dst) == 1)	//checking if the dst is only 1 cell above the src.
				{
					flag = vertical(board, turn, src, dst);
				}
				else if (!_moved && abs(src - dst) == 2)	//checking if the dst is 2 cells above the src and the pawn didn't move.
				{
					flag = vertical(board, turn, src, dst);
				}
				else	//Invalid move to this pawn.
				{
					return INVALID_MOVE;
				}
			}
			else if (board.getIndex(dst)->getSign() != '#')		//checking if in dst has a tool.
			{
				if (abs(src - dst) == 0)	//checking if y=x+b
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
				else	//Invalid move to this pawn.
				{
					return INVALID_MOVE;
				}
			}
			else	//Invalid move to this pawn.
			{
				return INVALID_CHECK;
			}
		}
		else	//the pawn is going down
		{

		}
	}
	else	//not color's turn
	{
		return SRC_HAS_NO_TURNS_TOOL;
	}
}