#include "Pawn.h"

/**
Constractor for the pawn.
Input:	color - the color of the tool.
Output:	None.
**/
Pawn::Pawn(int color) : Tool(color, 'P'), _moved(false) {}

/**
Checks if the pawn can move from the source location to the destination location.
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
		if (turn == BLACK)	//if the tool is black
		{
			if (src - dst == -2 && !_moved && srcCol == dstCol && board.getIndex(dst)->getSign() == '#')	//checking if first move of black pawn
			{
				flag = vertical(board, turn, src, dst);
			}
			else if (src - dst == -1 && srcCol == dstCol && board.getIndex(dst)->getSign() == '#')	//checking if about to move 1 move down
			{
				flag = mainCheck(board, turn, src, dst);
			}
			else if (src - dst == -2 && (srcRow < dstRow && srcCol < dstCol) && board.getIndex(dst)->getSign() != '#')	//checking if black pawn is about to eat right
			{
				flag = mainCheck(board, turn, src, dst);
			}
			else if (src - dst == 0 && (srcRow < dstRow && srcCol > dstCol) && board.getIndex(dst)->getSign() != '#')	//checking if black pawn is about to eat left
			{
				flag = mainCheck(board, turn, src, dst);
			}
			else	//if not a pawn's move
			{
				return INVALID_MOVE;
			}
		}
		else	//if the tool is white
		{
			if (src - dst == 2 && !_moved && srcCol == dstCol && board.getIndex(dst)->getSign() == '#')	//checking if first move of white pawn
			{
				flag = vertical(board, turn, src, dst);
			}
			else if (src - dst == 1 && srcCol == dstCol && board.getIndex(dst)->getSign() == '#')	//checking if about to move 1 move down
			{
				flag = mainCheck(board, turn, src, dst);
			}
			else if (src - dst == 0 && (srcRow > dstRow && srcCol < dstCol) && board.getIndex(dst)->getSign() != '#')	//checking if white pawn is about to eat right
			{
				flag = mainCheck(board, turn, src, dst);
			}
			else if (src - dst == 2 && (srcRow > dstRow && srcCol > dstCol) && board.getIndex(dst)->getSign() != '#')	//checking if white pawn is about to eat left
			{
				flag = mainCheck(board, turn, src, dst);
			}
			else	//if not a pawn's move
			{
				return INVALID_MOVE;
			}
		}
	}
	else	//not color's turn
	{
		return SRC_HAS_NO_TURNS_TOOL;
	}

	if ((flag == VALID_CHECK || flag == VALID_MOVE) && !test)
	{
		move(board, src, dst);
		_moved = true;
	}

	return flag;
}