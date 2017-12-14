#include "Tool.h"
#include "Empty.h"

#define VALID_MOVE 0
#define VALID_CHECK 1
#define SRC_HAS_NO_TURNS_TOOL 2
#define DST_HAS_TURNS_TOOL 3
#define INVALID_CHECK 4
#define INVALID_MOVE 6
#define SAME_SRC_DST 7
#define CHECKMATE 8

/**
Checking if the tool can move forward or backwards.
Input:	board - the board
		turn - whose turn
		src - the source location
		dst - the destination location
Output:	True if the tool can move, False if not.
**/
int vertical(Board board, int turn, Location src, Location dst)
{
	if(src != dst)	//(1)
	{
		if (board.getIndex(src.getRow(), src.getCol())->getColor() == turn)	//checking if the tool is the player's tool (2)
		{
			if (board.getIndex(dst.getRow(), dst.getCol())->getColor() != turn)	//checking if dst has no tool from player's tool (3)
			{

				if (src.getRow() > dst.getRow())
				{
					for (unsigned int i = src.getRow() - 1; i > dst.getRow(); i--)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(i, src.getCol())->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;	//check with kfir
						}
					}
				}
				else
				{
					for (unsigned int i = src.getRow() + 1; i < dst.getRow(); i++)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(i, src.getCol())->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;	//check with kfir
						}
					}
				}	//end of else
				return VALID_MOVE;
			}
		}
		else	//(3)
		{
			return DST_HAS_TURNS_TOOL;
		}
	}
	else	//(2)
	{
		return SRC_HAS_NO_TURNS_TOOL;
	}
	return SAME_SRC_DST;	//(1)
}

bool horizontal(Board board, int turn, Location src, Location dst)
{
	if (board.getIndex(src.getRow(), src.getCol())->getColor() == turn)	//checking if the tool is the player's tool
	{

	}
}

/**
Constractor for the tool
Input:	color - the color of the tool
		sign - the sign of the tool
Output:	None.
**/
Tool::Tool(int color, char sign) : _color(color), _sign(sign)
{
	_moves["vertical"] = vertical;
}

/**
Getter to the tool sign.
Input:	None.
Output:	The tool's sign.
**/
char Tool::getSign() const
{
	return _sign;
}

/**
Getter for the color.
Input:	None.
Output:	The tool's color.
**/
int Tool::getColor() const
{
	return _color;
}
