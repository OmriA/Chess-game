#include "Board.h"
#include "AllTools.h"

/**
Constractor for the board.
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
Distractor for the board.
Input:	None.
Output:	None.
**/
void Board::freeBoard()
{
	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			delete _board[i][j];
			_board[i][j] = nullptr;
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

/**
The index returns the tool in a specific index in the board.
Input:	cell - the location of the tool in the board.
Output:	pointer to the tool in the board.
**/
Tool* Board::getIndex(const Location cell) const
{
	return _board[cell.getRow()][cell.getCol()];
}

/**
Inserting the new tool to the board.
Input:	cell - the location to insert to.
		newTool - pointer to the new to insert into the table.
Output:	None.
**/
void Board::setIndex(const Location cell, Tool* newTool)
{
	_board[cell.getRow()][cell.getCol()] = newTool;
}

/**
Getting a string of the board and initzalsing it into the board
Input:	str - the str from frontend
Output:	None.
**/
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

		case 'B':
			setIndex(Location(row, char(col + 'a')), new Bishop(color));
			break;

		case 'K':
			setIndex(Location(row, char(col + 'a')), new King(color));
			break;

		case 'N':
			setIndex(Location(row, char(col + 'a')), new Knight(color));
			break;

		case 'Q':
			setIndex(Location(row, char(col + 'a')), new Queen(color));
			break;

		case 'P':
			setIndex(Location(row, char(col + 'a')), new Pawn(color));
			break;

		default:
			setIndex(Location(row, char(col + 'a')), new Empty());
			break;
		}
	}
	reverseBoard();
}

/**
Reversing the board
Input:	None.
Output:	None.
**/
void Board::reverseBoard()
{
	Tool* temp = nullptr;
	for (unsigned int i = 0; i < BOARD_SIZE / 2; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			temp = _board[i][j];
			_board[i][j] = _board[i][BOARD_SIZE - j - 1];
			_board[i][BOARD_SIZE - j - 1] = temp;
		}
	}
}
/**
Checking where is the sign given in input and returning the tool that sign is in it
Input:	sign - the sign we want to look for (tool)
Output:	the tool that owns the sign
**/
Tool* Board::getTool(char sign)
{
	Tool* toReturn = nullptr;
	for (unsigned int i = 0; i < BOARD_SIZE / 2; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			if (_board[i][j]->getSign() == sign)
			{
				toReturn = _board[i][j];
			}
		}
	}
	return toReturn;
}