#include "Board.h"

/**
Constractor to the board.
Input: None.
Output: None.
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