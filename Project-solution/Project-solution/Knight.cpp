#include "Knight.h"

/**
Constractor for the knight.
Input:	color - the color of the tool.
Output:	None.
**/
Knight::Knight(int color) : Tool(color, 'N') {}

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
char Knight::isLegal(Board& board, int turn, Location src, Location dst, bool test)
{
	char flag = 0;
	int dstRow = dst.getRow(), dstCol = dst.getCol();
	int srcRow = src.getRow(), srcCol = src.getCol();

	if (board.getIndex(src)->getColor() == turn)
	{
		if (abs(Location(srcRow, srcCol + 'a' + 1) - dst) == 2 && (srcRow != dstRow && srcCol != dstCol))	//*in knight.txt (1)
		{
			flag = knightMove(board, turn, src, dst);
		}
		else if (abs(Location(srcRow, srcCol + 'a' + 2) - dst) == 1 && (srcRow != dstRow && srcCol != dstCol))	//*in knight.txt (2)
		{
			flag = knightMove(board, turn, src, dst);
		}
		else if (abs(Location(srcRow, srcCol + 'a' - 1) - dst) == 2 && (srcRow != dstRow && srcCol != dstCol))	//*in knight.txt (3)
		{
			flag = knightMove(board, turn, src, dst);
		}
		else if (abs(Location(srcRow, srcCol + 'a' - 2) - dst) == 1 && (srcRow != dstRow && srcCol != dstCol))	//*in knight.txt (4)
		{
			flag = knightMove(board, turn, src, dst);
		}
		else	//if not knight's move
		{
			return INVALID_MOVE;
		}
	}
	else	//not color's turn
	{
		return SRC_HAS_NO_TURNS_TOOL;
	}

	if ((flag == VALID_CHECK || flag == VALID_MOVE) && !test)
	{
		move(board, src, dst);
	}

	return flag;
}