#include "Board.h"
#include "AllTools.h"

/**
Constractor to the board.
Input:	None.
Output:	None.
**/
Board::Board()
{
	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			_board[i][j] = new Empty();
		}
	}
}

/**
The function returns the board string.
Input:	None.
Output:	The board string.
**/
std::string Board::getBoardStr() const
{
	std::string str;

	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			str += _board[i][j]->getSign();
		}
	}

	return str;
}