#include "Tool.h"
#include "Empty.h"

/**
Checking if the tool can move forward or backwards.
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
int vertical(Board board, int turn, Location src, Location dst)
{
	if (src != dst)	//(1)
	{
		if (board.getIndex(src.getRow(), src.getCol())->getColor() == turn)	//checking if the tool int the src location is the player's tool (2)
		{
			if (board.getIndex(dst.getRow(), dst.getCol())->getColor() != turn)	//checking if dst has no tool from player's tool (3)
			{
				if (src.getRow() > dst.getRow())	//if src is above dst
				{
					for (unsigned int i = src.getRow() - 1; i > dst.getRow(); i--)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(i, src.getCol())->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;	//check with kfir
						}
					}
				}
				else	//src is underneath dst
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

/**
Checking if the tool can move right or left.
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
int horizontal(Board board, int turn, Location src, Location dst)
{
	if (src != dst)	//(1)
	{
		if (board.getIndex(src.getRow(), src.getCol())->getColor() == turn)	//checking if the tool int the src location is the player's tool (2)
		{
			if (board.getIndex(dst.getRow(), dst.getCol())->getColor() != turn)	//checking if dst has no tool from player's tool (3)
			{
				if (src.getCol() > dst.getCol())	//if src is right to dst
				{
					for (unsigned int i = src.getCol() - 1; i > dst.getCol(); i--)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(i, src.getRow())->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;	//check with kfir
						}
					}
				}
				else	//src is left to dst.
				{
					for (unsigned int i = src.getCol() + 1; i < dst.getCol(); i++)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(i, src.getRow())->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;	//check with kfir
						}
					}
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
	}
	return SAME_SRC_DST;	//(1)
}

/**
Constractor for the tool
Input:	color - the color of the tool
		sign - the sign of the tool
Output:	None.
**/
Tool::Tool(int color, char sign, vector<int> moves) : _color(color), _sign(sign)
{
	if (!color)
	{
		_sign -= 'a' - 'A';
	}

	for (unsigned int i = 0; i < moves.size(); i++)
	{
		switch (moves[i])
		{
		case VERTICAL:
			_moves["vertical"] = vertical;
			break;

		case HORIZONTAL:
			_moves["horizontal"] =  horizontal;
			break;

		case DIAGONAL:
			_moves["diagonal"] = diagonal;
			break;

		default:
			throw std::invalid_argument("Vector of moves has an invalid move value: " + moves[i]);
			break;
		}
	}
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
