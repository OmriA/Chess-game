#include "Tool.h"
#include "Empty.h"

bool forward(Board board, bool turn, Location src, Location dst)
{
	if (board.getIndex(src.getRow(), src.getCol())->getColor() == turn)	//checking if the tool is the player's tool
	{
		if (board.getIndex(dst.getRow(), dst.getCol())->getColor() != turn)	//checking if dst has no tool from player's tools
		{
			if (src.getRow() > dst.getRow())
			{
				for (unsigned int i = src.getRow() - 1; i > dst.getRow(); i--)
				{
					if (board.getIndex(i, src.getCol())->getSign() != '#')
					{
						return false;
					} 
				}
			}
			else
			{
				for (unsigned int i = src.getRow() + 1; i < dst.getRow(); i++)
				{
					if (board.getIndex(i, src.getCol())->getSign() != '#')
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	return false;
}

/**
Constractor for the tool
Input:	color - the color of the tool
		sign - the sign of the tool
Output:	None.
**/
Tool::Tool(bool color, char sign) : _color(color), _sign(sign)
{
	_moves["forward"] = forward;
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
bool Tool::getColor() const
{
	return _color;
}
