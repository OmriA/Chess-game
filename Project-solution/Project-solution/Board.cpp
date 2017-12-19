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

Board::~Board()
{
	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			delete _board[i][j];
		}
	}
	std::cout << "Bye Bye!" << std::endl;
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

		case 'B':
			setIndex(Location(row, char(col + 'a')), new Bishop(color));
			break;

		case 'K':
			setIndex(Location(row, char(col + 'a')), new King(color));
			break;

		case 'N':
			setIndex(Location(row, char(col + 'a')), new Knight(color));
			break;

		//case 'Q':
		//	setIndex(Location(row, char(col + 'a')), new Queen(color));
		//	break;

		//case 'P':
		//	setIndex(Location(row, char(col + 'a')), new Pawn(color));
		//	break;

		default:
			setIndex(Location(row, char(col + 'a')), new Empty());
			break;
		}
	}
	reverseBoard();
}

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