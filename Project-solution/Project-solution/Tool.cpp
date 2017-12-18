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
char Tool::vertical(Board board, int turn, Location src, Location dst)
{
	if (src != dst)	//(1)
	{
		if (board.getIndex(dst)->getColor() != turn)	//checking if dst has no tool from player's tool (2)
		{
			if (src.getRow() > dst.getRow())	//if src is above dst (3)
			{
				for (unsigned int i = src.getRow() - 1; i > dst.getRow(); i--)	//checking if there is any tool between src to dst
				{
					if (board.getIndex(Location(i, src.getCol() + 'a'))->getSign() != '#')	//checking between src to dst
					{
						return INVALID_MOVE;
					}
				}
			}
			else	//src is underneath dst (3)
			{
				for (unsigned int i = src.getRow() + 1; i < dst.getRow(); i++)	//checking if there is any tool between src to dst
				{
					if (board.getIndex(Location(i, src.getCol() + 'a'))->getSign() != '#')	//checking between src to dst
					{
						return INVALID_MOVE;
					}
				}
			}	//end of else
			return VALID_MOVE;
		}
		else	//(2)
		{
			return DST_HAS_TURNS_TOOL;
		}
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
char Tool::horizontal(Board board, int turn, Location src, Location dst)
{
	if (src != dst)	//(1)
	{
		if (board.getIndex(src)->getColor() == turn)	//checking if the tool int the src location is the player's tool (2)
		{
			if (board.getIndex(dst)->getColor() != turn)	//checking if dst has no tool from player's tool (3)
			{
				if (src.getCol() > dst.getCol())	//if src is right to dst
				{
					for (unsigned int i = src.getCol() - 1; i > dst.getCol(); i--)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(Location(src.getRow(), i + 'a'))->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;
						}
					}
				}
				else	//src is left to dst.
				{
					for (unsigned int i = src.getCol() + 1; i < dst.getCol(); i++)	//checking if there is any tool between src to dst
					{
						if (board.getIndex(Location(src.getRow(), i + 'a'))->getSign() != '#')	//checking between src to dst
						{
							return INVALID_MOVE;
						}
					}
				}
				return VALID_MOVE;
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
Checking if the tool can move in it's up diagonal y=x+b
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
char Tool::diagonalUp(Board board, int turn, Location src, Location dst)
{
	if (src != dst)	//(1)
	{
		if (board.getIndex(src)->getColor() == turn)	//checking if the tool int the src location is the player's tool (2)
		{
			if (board.getIndex(dst)->getColor() != turn)	//checking if dst has no tool from player's tool (3)
			{
				if (src.getCol() < dst.getCol())	//checking if going up
				{
					for (unsigned int i = 0; i < dst.getCol() - src.getCol() - 1; i++)
					{
						if (board.getIndex(Location(src.getRow() - i - 1, src.getCol() + i + 1 + 'a'))->getSign() != '#')
						{
							return INVALID_MOVE;
						}
					}
				}
				else	//checking if going down
				{
					for (unsigned int i = 0; i < src.getCol() - dst.getCol() - 1; i++)
					{
						if (board.getIndex(Location(src.getRow() + i + 1, src.getCol() - i - 1 + 'a'))->getSign() != '#')
						{
							return INVALID_MOVE;
						}
					}
				}
				return VALID_MOVE;
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
Checking if the tool can move in it's down diagonal. y=-x+b
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
char Tool::diagonalDown(Board board, int turn, Location src, Location dst)
{
	if (src != dst)	//(1)
	{
		if (board.getIndex(src)->getColor() == turn)	//checking if the tool int the src location is the player's tool (2)
		{
			if (board.getIndex(dst)->getColor() != turn)	//checking if dst has no tool from player's tool (3)
			{
				if (src.getRow() > dst.getRow() && src.getCol() > dst.getCol())	//checking if going up.
				{
					for (unsigned int i = 0; i < src.getRow() - dst.getRow() - 1; i++)
					{
						if (board.getIndex(Location(src.getRow() - i - 1, src.getCol() - i - 1 + 'a'))->getSign() != '#')
						{
							return INVALID_MOVE;
						}
					}
				}
				else	//checking if going down
				{
					for (unsigned int i = 0; i < dst.getRow() - src.getRow() - 1; i++)
					{
						if (board.getIndex(Location(src.getRow() + i + 1, src.getCol() + i + 1 + 'a'))->getSign() != '#')
						{
							return INVALID_MOVE;
						}
					}
				}
				return VALID_MOVE;
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
Tool::Tool(int color, char sign) : _color(color), _sign(sign)
{
	if (color == BLACK)	//checking if the color is black.
	{
		_sign += 'a' - 'A';
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

void Tool::move(Board& board, Location src, Location dst)
{
	Tool* temp = board.getIndex(dst);

	board.setIndex(dst, board.getIndex(src));
	if (temp->getSign() != '#')	//checking if the tool is eating any other player.
	{
		delete temp;
		board.setIndex(src, new Empty());
	}
	else
	{
		board.setIndex(src, temp);
	}
}
