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
Returns the board string.
Input:	None.
Output:	The board string.
**/
void Board::printBoard() const
{
	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << _board[i][j]->getSign();
		}
		std::cout << std::endl;
	}
}

Tool* Board::getIndex(const Location cell) const
{
	return _board[cell.getRow()][cell.getCol()];
}

void Board::setIndex(const Location cell, Tool* newTool)
{
	_board[cell.getRow()][cell.getCol()] = newTool;
}

void Board::initBoard(const char* str)
{
	for (unsigned int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
	{
		int color = WHITE;
		unsigned int row = i / BOARD_SIZE, col = i % BOARD_SIZE;	//*included text file "ezMath.txt"
		char tool = str[i];

		if (tool >= 'a' && tool <= 'z')
		{
			color = BLACK;
			tool -= 'a' - 'A';
		}

		switch (tool)
		{
		case 'R':
			setIndex(Location(row, char(col + 'a')), new Rook(color));
			break;

		default:
			setIndex(Location(row, char(col + 'a')), new Empty());
			break;
		}
	}

}